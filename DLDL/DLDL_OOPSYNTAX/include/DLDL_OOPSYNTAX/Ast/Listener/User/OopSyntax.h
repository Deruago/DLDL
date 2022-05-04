#ifndef DLDL_OOPSYNTAX_AST_LISTENER_USER_OOPSYNTAX_H
#define DLDL_OOPSYNTAX_AST_LISTENER_USER_OOPSYNTAX_H

#include "DLDL_OOPSYNTAX/Ast/Listener/EnterExitListener.h"
#include "DLDL_OOPSYNTAX/Ast/Reference/Access.h"
#include "DLDL_OOPSYNTAX/IR/OopSyntax.h"

namespace DLDL_OOPSYNTAX::ast::listener::user
{
	class OopSyntax : public ::DLDL_OOPSYNTAX::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::OopSyntax* OopSyntaxLpd;
		std::vector<std::unique_ptr<DLDL::ir::OopProperty>> oopProperties;
		std::vector<std::unique_ptr<DLDL::ir::ProductionRuleAssignment>>
			productionRuleAssignmentDepth;
		std::vector<std::unique_ptr<DLDL::ir::EmbeddedAssignment>> embeddedAssignmentDepth;

	public:
		OopSyntax()
		{
			OopSyntaxLpd = new ::DLDL::ir::OopSyntax();
		}
		~OopSyntax() override = default;

	public:
		void ListenEntry(const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node) override
		{
			const std::string object =
				reference::Access(node).nonterminal_name().GetContent()[0]->GetText();
			const std::string oopType =
				reference::Access(node).oop_type().GetContent()[0]->GetText();
			AddOopProperty(object, oopType);
		}

		void ListenEntry(const DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node) override
		{
		}

		void ListenEntry(const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node) override
		{
			const std::size_t productionRuleIndex =
				std::stoul(reference::Access(node).NUMBER().GetContent()[0]->GetText());
			AddProductionRule(productionRuleIndex);
		}

		void ListenExit(const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node) override
		{
			const std::string productionRuleIndex =
				reference::Access(node).NUMBER().GetContent()[0]->GetText();
			if (!embeddedAssignmentDepth.empty())
			{
				const auto iter = productionRuleAssignmentDepth.end() - 1;
				embeddedAssignmentDepth[embeddedAssignmentDepth.size() - 1]
					->productionRuleAssignments.push_back(std::move(*iter));
			}
			else
			{
				const auto iter = productionRuleAssignmentDepth.end() - 1;
				GetOopProperty()->productionRuleAssignments.push_back(std::move(*iter));
			}
			RemoveProductionRule();
		}

		void ListenEntry(const DLDL_OOPSYNTAX::ast::node::property_assignment* node) override
		{
		}

		void ListenEntry(const DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node) override
		{
			const std::string object =
				reference::Access(node).terminal_name().GetContent()[0]->GetText();
			const std::string oopType =
				reference::Access(node).oop_type().GetContent()[0]->GetText();
			const std::string oopPropertyType =
				reference::Access(node).property().GetContent()[0]->GetText();
			auto newDirectAssignment = std::make_unique<DLDL::ir::DirectAssignment>();
			newDirectAssignment->object = object;
			newDirectAssignment->oopType = GetOopType(oopType);
			newDirectAssignment->oopProperty = GetOopPropertyType(oopPropertyType);
			GetProductionRule()->directAssignments.push_back(std::move(newDirectAssignment));
		}

		void
		ListenEntry(const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node) override
		{
			const std::string object =
				reference::Access(node).terminal_name().GetContent()[0]->GetText();
			const std::string oopType = "Any";
			const std::string oopPropertyType =
				reference::Access(node).property().GetContent()[0]->GetText();
			auto newDirectAssignment = std::make_unique<DLDL::ir::DirectAssignment>();
			newDirectAssignment->object = object;
			newDirectAssignment->oopType = GetOopType(oopType);
			newDirectAssignment->oopProperty = GetOopPropertyType(oopPropertyType);
			GetProductionRule()->directAssignments.push_back(std::move(newDirectAssignment));
		}

		void ListenEntry(const DLDL_OOPSYNTAX::ast::node::embedded_assignment* node) override
		{
			const std::string object =
				reference::Access(node).nonterminal_name().GetContent()[0]->GetText();
			const std::string oopType =
				reference::Access(node).oop_type().GetContent()[0]->GetText();
			AddEmbeddedAssignment(object, oopType);
		}

		void ListenExit(const DLDL_OOPSYNTAX::ast::node::embedded_assignment* node) override
		{
			const auto iter = embeddedAssignmentDepth.end() - 1;
			GetProductionRule()->embeddedAssignments.push_back(std::move(*iter));
			RemoveEmbeddedAssignment();
		}

	public:
		void AddOopProperty(const std::string& object_, const std::string& oopType)
		{
			oopProperties.push_back(std::make_unique<DLDL::ir::OopProperty>());
			GetOopProperty()->object = object_;
			GetOopProperty()->oopType = GetOopType(oopType);
		}

		void AddProductionRule(const std::size_t& index)
		{
			productionRuleAssignmentDepth.push_back(
				std::make_unique<DLDL::ir::ProductionRuleAssignment>());
			GetProductionRule()->productionRule = index;
		}

		std::string ToLower(const std::string& oopType)
		{
			std::string lowered;
			for (auto character : oopType)
			{
				if (::isalpha(character))
				{
					lowered += ::tolower(character);
				}
				else
				{
					lowered += character;
				}
			}
			return lowered;
		}

		std::optional<deamer::language::type::definition::object::main::OopSyntaxScope>
		GetOopType(const std::string& oopType)
		{
			const auto lowered = ToLower(oopType);

			if (lowered == "struct")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Struct;
			}
			if (lowered == "interface")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Interface;
			}
			if (lowered == "class")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Class;
			}
			if (lowered == "basetypes" || lowered == "basetype" || lowered == "base" ||
				lowered == "bases" || lowered == "base_type" || lowered == "base_types")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::BaseTypes;
			}
			if (lowered == "function")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Function;
			}
			if (lowered == "functionarguments" || lowered == "functionargument" ||
				lowered == "function_arguments" || lowered == "function_argument" ||
				lowered == "function_arg" || lowered == "function_args")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::
					FunctionArguments;
			}
			if (lowered == "property")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Property;
			}
			if (lowered == "enum")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Enum;
			}
			if (lowered == "any")
			{
				return deamer::language::type::definition::object::main::OopSyntaxScope::Any;
			}

			return {};
		}

		deamer::language::type::definition::object::main::OopConceptMemberType
		GetOopPropertyType(const std::string& oopPropertyType)
		{
			const auto lowered = ToLower(oopPropertyType);

			if (lowered == "name")
			{
				return deamer::language::type::definition::object::main::OopConceptMemberType::Name;
			}
			if (lowered == "type")
			{
				return deamer::language::type::definition::object::main::OopConceptMemberType::Type;
			}
			if (lowered == "member")
			{
				return deamer::language::type::definition::object::main::OopConceptMemberType::
					Member;
			}

			throw std::logic_error("Unknown OopConceptMemberType: " + lowered);
		}

		void AddEmbeddedAssignment(const std::string& object_, const std::string& oopType)
		{
			embeddedAssignmentDepth.push_back(std::make_unique<DLDL::ir::EmbeddedAssignment>());
			GetEmbeddedAssignment()->object = object_;
			GetEmbeddedAssignment()->oopType = GetOopType(oopType);
		}

		void RemoveProductionRule()
		{
			if (productionRuleAssignmentDepth.empty())
			{
				return;
			}

			productionRuleAssignmentDepth.erase(productionRuleAssignmentDepth.end() - 1);
		}

		void RemoveEmbeddedAssignment()
		{
			if (embeddedAssignmentDepth.empty())
			{
				return;
			}

			embeddedAssignmentDepth.erase(embeddedAssignmentDepth.end() - 1);
		}

		DLDL::ir::OopProperty* GetOopProperty()
		{
			if (oopProperties.empty())
			{
				throw std::logic_error("Programmer error");
			}

			return oopProperties[oopProperties.size() - 1].get();
		}

		DLDL::ir::EmbeddedAssignment* GetEmbeddedAssignment()
		{
			if (embeddedAssignmentDepth.empty())
			{
				throw std::logic_error("Programmer error");
			}

			return embeddedAssignmentDepth[embeddedAssignmentDepth.size() - 1].get();
		}

		DLDL::ir::ProductionRuleAssignment* GetProductionRule()
		{
			if (productionRuleAssignmentDepth.empty())
			{
				throw std::logic_error("Programmer error");
			}

			return productionRuleAssignmentDepth[productionRuleAssignmentDepth.size() - 1].get();
		}

	public:
		DLDL::ir::OopSyntax* GetOopSyntax()
		{
			OopSyntaxLpd->AddOopProperties(std::move(oopProperties));
			return OopSyntaxLpd;
		}
	};
}

#endif // DLDL_OOPSYNTAX_AST_LISTENER_USER_OOPSYNTAX_H
