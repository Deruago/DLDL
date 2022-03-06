#ifndef DLDL_OOPSYNTAX_BISON_PARSER_H
#define DLDL_OOPSYNTAX_BISON_PARSER_H

#include <Deamer/External/Cpp/Parser/Interface/Parser.h>

namespace DLDL_OOPSYNTAX { namespace parser {

    class Parser : public deamer::external::cpp::parser::Parser
    {
    public:
        Parser() = default;
        ~Parser() override = default;

    public:
        deamer::external::cpp::ast::Tree* Parse(const std::string& text) const override;
    };

}}

#endif // DLDL_OOPSYNTAX_BISON_PARSER_H
