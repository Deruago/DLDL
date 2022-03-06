#ifndef DLDL_OOPSYNTAX_IR_OOPSYNTAX_H
#define DLDL_OOPSYNTAX_IR_OOPSYNTAX_H

#include "DLDL/IR/IR.h"
#include "Deamer/Language/Type/Definition/Object/Main/OOPSyntax/OopConceptMemberType.h"
#include "Deamer/Language/Type/Definition/Object/Main/OOPSyntax/OopSyntaxScope.h"
#include <deque>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	class Language;
	struct OopProperty;
	using EmbeddedAssignment = OopProperty;

	struct DirectAssignment
	{
		std::string object;
		std::optional<deamer::language::type::definition::object::main::OopSyntaxScope> oopType;
		deamer::language::type::definition::object::main::OopConceptMemberType oopProperty;
	};

	struct ProductionRuleAssignment
	{
		std::size_t productionRule;

		// Currently unsupported in the output generator
		std::vector<std::unique_ptr<EmbeddedAssignment>> embeddedAssignments;
		std::vector<std::unique_ptr<DirectAssignment>> directAssignments;
	};

	struct OopProperty
	{
		std::string object;
		std::optional<deamer::language::type::definition::object::main::OopSyntaxScope> oopType;
		std::vector<std::unique_ptr<ProductionRuleAssignment>> productionRuleAssignments;
	};

	class OopSyntax : public DLDL::ir::IR
	{
	private:
		std::vector<std::unique_ptr<OopProperty>> oopProperties;

	public:
		OopSyntax();

	public:
		void AddOopProperty(std::unique_ptr<OopProperty> newOopProperty);
		void AddOopProperties(std::vector<std::unique_ptr<OopProperty>> newOopProperties);

	public:
		const std::vector<std::unique_ptr<OopProperty>>& GetOopProperties() const;
	};
}

#endif // DLDL_OOPSYNTAX_IR_OOPSYNTAX_H
