#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_AST_LISTENER_FILLGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_AST_LISTENER_FILLGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Listener/EnterExitListener.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ArrowGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/NotGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/OptionalGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/OrGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/PlusGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/StarGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ValueGroup.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ast::listener::user
{
	class FillGroup : public EnterExitListener
	{
	public:
		std::vector<std::vector<ir::Group*>> Groups;
		const std::vector<std::string>* terminals;

		FillGroup(const std::vector<std::string>& terminals_ = {})
			: EnterExitListener(),
			  terminals(&terminals_)
		{
			NewScope();
		}

		~FillGroup() override
		{
			DeleteScope();
		}

		void NewScope()
		{
			Groups.emplace_back();
		}

		void DeleteScope()
		{
			Groups.pop_back();
		}

		std::vector<ir::Group*> GetCurrentScope() const
		{
			return Groups[Groups.size() - 1];
		}

		void AddToCurrentScope(const std::string& name) const
		{
			GetCurrentScope().push_back(new ir::ValueGroup(name));
		}

		void AddToCurrentScope(ir::Group* newGroup)
		{
			Groups[Groups.size() - 1].push_back(newGroup);
		}

		void ListenEntry(const node::optional_group* node) override
		{
			NewScope();
		}

		void ListenExit(const node::optional_group* node) override
		{
			auto* const optional_group = new ir::OptionalGroup(GetCurrentScope());
			DeleteScope();
			AddToCurrentScope(optional_group);
		}

		void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node) override
		{
			NewScope();
		}

		void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node) override
		{
			auto* const or_group = new ir::OrGroup(GetCurrentScope());
			DeleteScope();
			AddToCurrentScope(or_group);
		}

		void ListenEntry(
			const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node) override
		{
			NewScope();
		}

		void
		ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node) override
		{
			auto* const star_group = new ir::StarGroup(GetCurrentScope());
			DeleteScope();
			AddToCurrentScope(star_group);
		}

		void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node) override
		{
			NewScope();
		}

		void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node) override
		{
			auto* const nested_group = new ir::Group(GetCurrentScope());
			DeleteScope();
			AddToCurrentScope(nested_group);
		}

		void
		ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node) override
		{
			auto* const plus_group = new ir::PlusGroup(GetCurrentScope());
			DeleteScope();
			AddToCurrentScope(plus_group);
		}

		void
		ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node) override
		{
			NewScope();
		}

		void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::not_group* node) override
		{
			// Not yet implemented,
		}

		void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::not_group* node) override
		{
			// Not yet implemented,
		}

		void
		ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node) override
		{
			auto* const arrow_group = new ir::ArrowGroup(GetCurrentScope());
			DeleteScope();
			AddToCurrentScope(arrow_group);
		}

		void
		ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node) override
		{
			NewScope();
		}

		void ListenEntry(const node::VALUE* node) override
		{
			const std::string nodeName = node->GetValue();
			std::string loweredName;

			for (const auto& character : nodeName)
			{
				loweredName += ::tolower(character);
			}

			if (loweredName == "empty" || loweredName == "epsilon")
			{
				return;
			}

			AddToCurrentScope(new ir::ValueGroup(node->GetValue()));
		}

		[[nodiscard]] ir::Group* GetGroup() const
		{
			auto* const group = new ir::Group(GetCurrentScope());

			return group;
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_AST_LISTENER_FILLGROUP_H
