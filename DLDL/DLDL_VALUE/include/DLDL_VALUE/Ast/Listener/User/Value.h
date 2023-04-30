#ifndef DLDL_VALUE_AST_LISTENER_USER_VALUE_H
#define DLDL_VALUE_AST_LISTENER_USER_VALUE_H

#include "DLDL_VALUE/Ast/Listener/EnterExitListener.h"
#include "DLDL_VALUE/Ast/Reference/Access.h"
#include "DLDL_VALUE/IR/Value.h"
#include <memory>

namespace DLDL_VALUE::ast::listener::user
{
	class Value : public ::DLDL_VALUE::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::Value* ValueLpd;
		DLDL::ir::ValueRule* current_value_rule = nullptr;
		DLDL::ir::ValueCharacteristic* current_value_characteristic_rule = nullptr;
		std::size_t abstraction_count = 0;

		std::vector<DLDL::ir::ValueAbstraction*> valueAbstractions;

	public:
		Value()
		{
			ValueLpd = new ::DLDL::ir::Value();
		}
		~Value() override = default;

	public:
		void ListenEntry(const DLDL_VALUE::ast::node::value_declaration* node) override
		{
			auto acc = reference::Access(node);
			auto rule_name = acc.value_rule_name().GetContent()[0]->GetText();
			auto rule = std::make_unique<DLDL::ir::ValueRule>(rule_name);
			acc.syntactic_context().for_all([&](reference::Access<node::syntactic_context> node) {
				rule->AddSyntaxContent(node.GetContent()[0]->GetText());
			});
			current_value_rule = rule.get();
			ValueLpd->AddValueRule(std::move(rule));
		}

		void ListenExit(const DLDL_VALUE::ast::node::value_declaration* node) override
		{
			current_value_rule = nullptr;
		}

		void
		ListenEntry(const DLDL_VALUE::ast::node::value_charactersitic_declaration* node) override
		{
			auto acc = reference::Access(node);
			auto rule_name = acc.value_rule_name().GetContent()[0]->GetText();
			auto rule = std::make_unique<DLDL::ir::ValueCharacteristic>(rule_name);
			acc.syntactic_context().for_all([&](reference::Access<node::syntactic_context> node) {
				rule->AddSyntaxContent(node.GetContent()[0]->GetText());
			});
			current_value_characteristic_rule = rule.get();
			ValueLpd->AddValueCharacteristic(std::move(rule));
		}

		void
		ListenExit(const DLDL_VALUE::ast::node::value_charactersitic_declaration* node) override
		{
			current_value_characteristic_rule = nullptr;
		}

		void ListenEntry(const DLDL_VALUE::ast::node::value_abstraction* node) override
		{
			auto acc = reference::Access(node);
			auto valueAbstraction = std::make_unique<DLDL::ir::ValueAbstraction>(
				acc.abstraction_name().GetContent()[0]->GetText(), abstraction_count++,
				acc.value().GetContent()[0]->GetText());
			if (valueAbstractions.empty())
			{
				if (current_value_rule != nullptr)
				{
					current_value_rule->AddUnderlyingAbstraction(valueAbstraction.get());
				}
				else
				{
					current_value_characteristic_rule->AddUnderlyingAbstraction(
						valueAbstraction.get());
				}
			}
			valueAbstractions.push_back(valueAbstraction.get());
			ValueLpd->AddValueAbstraction(std::move(valueAbstraction));
		}

		void ListenExit(const DLDL_VALUE::ast::node::value_abstraction* node) override
		{
			if (valueAbstractions.size() > 1)
			{
				valueAbstractions[valueAbstractions.size() - 2]->AddUnderlyingAbstraction(
					valueAbstractions[valueAbstractions.size() - 1]);
			}
			valueAbstractions.pop_back();
		}

	public:
		DLDL::ir::Value* GetValue()
		{
			return ValueLpd;
		}
	};
}

#endif // DLDL_VALUE_AST_LISTENER_USER_VALUE_H
