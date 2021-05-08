#ifndef DST_GRAMMARTEMPLATE_h
#define DST_GRAMMARTEMPLATE_h

#include <variant>
#include <vector>
#include <string>

namespace DLDL::filetemplate
{

	/*!	\class GrammarTemplate
	 *
	 *	\brief Generates code for "GrammarTemplate"
	 *
	 *	\details This is generated by DST.
	 *	For more information visit: https://github.com/Deruago/DeamerStringTemplate
	 */
	class GrammarTemplate
	{
	public:
		enum class Type
		{
			Unknown,
			Scope,

			// User defined types
			file_,
			header_guard_,
			language_full_name_,
			language_full_name_underscore_,
			left_angle_bracket_,
			left_bracket_,
			left_curly_bracket_,
			nonterminal_,
			nonterminal_declaration_,
			productionrule_,
			productionrule_declaration_,
			right_angle_bracket_,
			right_bracket_,
			right_curly_bracket_,


		};


		enum class ScopeType
		{
			Unknown,

			// Default
			Default_,
			Upper_,
			Lower_,
			Variable_Field_,
			Variable_Field_Separator_,
			Function_Field_,
			Function_Field_Separator_,


		};


		static constexpr const char* ConvertEnumToName(::DLDL::filetemplate::GrammarTemplate::Type enumerationValue)
		{
			switch (enumerationValue)
			{
			case ::DLDL::filetemplate::GrammarTemplate::Type::file_:
			{
				return "file";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::header_guard_:
			{
				return "header_guard";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::language_full_name_:
			{
				return "language_full_name";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::language_full_name_underscore_:
			{
				return "language_full_name_underscore";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::left_angle_bracket_:
			{
				return "left_angle_bracket";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::left_bracket_:
			{
				return "left_bracket";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::left_curly_bracket_:
			{
				return "left_curly_bracket";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::nonterminal_:
			{
				return "nonterminal";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::nonterminal_declaration_:
			{
				return "nonterminal_declaration";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::productionrule_:
			{
				return "productionrule";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::productionrule_declaration_:
			{
				return "productionrule_declaration";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::right_angle_bracket_:
			{
				return "right_angle_bracket";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::right_bracket_:
			{
				return "right_bracket";
			}

			case ::DLDL::filetemplate::GrammarTemplate::Type::right_curly_bracket_:
			{
				return "right_curly_bracket";
			}


			}

			return "";
		}



	public:
		struct VariableBase
		{
			// The value is either a string
			// or a vector of variables.
			std::variant<std::string, std::vector<VariableBase*>> value;
			bool isString = true;

			::DLDL::filetemplate::GrammarTemplate::Type type = ::DLDL::filetemplate::GrammarTemplate::Type::Unknown;

			VariableBase() : VariableBase(std::vector<VariableBase*>())
			{
			}

			virtual ~VariableBase() = default;

			VariableBase(const char* text)
			{
				isString = true;
				value = text;
			}

			VariableBase(const std::string& text)
			{
				isString = true;
				value = text;
			}

			VariableBase(std::vector<VariableBase*> variables)
			{
				isString = false;
				value = variables;
			}

			VariableBase* This()
			{
				return this;
			}

			std::string GetValue()
			{
				if (isString)
				{
					return std::get<std::string>(value);
				}
				else
				{
					std::string output;
					auto& variables = std::get<std::vector<VariableBase*>>(value);
					for (auto* variable : variables)
					{
						output += variable->GetValue();
					}
					return output;
				}
			}

			std::string GetName()
			{
				return ConvertEnumToName(type);
			}

			VariableBase& operator=(const std::string& variable)
			{
				return Set(variable);
			}

			VariableBase& operator=(VariableBase* variable)
			{
				return Set(variable);
			}

			VariableBase& operator+=(VariableBase* variable)
			{
				return Add(variable);
			}

			VariableBase& operator+=(const std::string& variable)
			{
				return Add(variable);
			}

			VariableBase& Set(const std::string& variable)
			{
				value = variable;
				isString = true;

				return *this;
			}

			VariableBase& Set(VariableBase* variable)
			{
				if (variable == this)
				{
					return *this;
				}

				value = variable->value;
				isString = variable->isString;

				return *this;
			}

			VariableBase& Add(const std::string& variable)
			{
				if (isString)
				{
					auto& text = std::get<std::string>(value);
					text += variable;
					value = text;
				}
				else
				{
					auto& vector = std::get<std::vector<VariableBase*>>(value);
					vector.push_back(new VariableBase(variable));
					value = vector;
				}

				return *this;
			}

			VariableBase& Add(VariableBase* variable)
			{
				if (variable == this)
				{
					return *this;
				}

				if (isString)
				{
					// convert current -> variablebase
					// then create a vector.
					auto& currentValue = std::get<std::string>(value);
					auto* currentValueAsVariableBase = new VariableBase(currentValue);
					value = std::vector<VariableBase*>({ currentValueAsVariableBase, variable });

					isString = false;
				}
				else
				{
					auto& vector = std::get<std::vector<VariableBase*>>(value);
					vector.push_back(variable);
					value = vector;
				}

				return *this;
			}

			void Clear()
			{
				if (isString)
				{
					value = "";
				}
				else
				{
					value = std::vector<VariableBase*>();
				}
			}

			void* operator new(size_t size)
			{
				void* newVariable = ::operator new(size);
				variables_to_delete.emplace_back(static_cast<VariableBase*>(newVariable));

				return newVariable;
			}
		};

		static VariableBase* GenerateVariable(VariableBase* variable)
		{
			return variable;
		}


		static VariableBase* GenerateVariable(const std::string& variable)
		{
			return new VariableBase(variable);
		}

		struct VariableScope : public VariableBase
		{
			::DLDL::filetemplate::GrammarTemplate::ScopeType scope_type = ::DLDL::filetemplate::GrammarTemplate::ScopeType::Unknown;
			bool isReserved = false;

			VariableScope(::DLDL::filetemplate::GrammarTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;
			}

			VariableScope(const char* text, ::DLDL::filetemplate::GrammarTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(text), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;
			}

			VariableScope(std::vector<VariableBase*> variable, ::DLDL::filetemplate::GrammarTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(variable), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;
			}
		};

		struct VariableScopes : public VariableBase
		{
			// Default scopes
			VariableBase* default_ = new VariableScope(::DLDL::filetemplate::GrammarTemplate::ScopeType::Default_, true);
			VariableBase* upper_ = new VariableScope(::DLDL::filetemplate::GrammarTemplate::ScopeType::Upper_, true);
			VariableBase* lower_ = new VariableScope(::DLDL::filetemplate::GrammarTemplate::ScopeType::Lower_, true);
			VariableBase* variable_field_ = new VariableScope(::DLDL::filetemplate::GrammarTemplate::ScopeType::Variable_Field_, true);
			VariableBase* variable_field_separator_ = new VariableScope("\n", ::DLDL::filetemplate::GrammarTemplate::ScopeType::Variable_Field_Separator_, true);

			// Ctor
			VariableScopes() : VariableBase() {}

			VariableScopes(const char* text) : VariableBase(text) {}

			VariableScopes(const std::string& text) : VariableBase(text) {}

			VariableScopes(std::vector<VariableBase*> variables) : VariableBase(variables) {}

			// Dtor
			virtual ~VariableScopes() override = default;

			// Calls
			VariableBase* Default()
			{
				return default_;
			}
			VariableBase* Upper()
			{
				std::string upperVariant;
				std::string currentValue = GetValue();

				for (const auto character : currentValue)
				{
					upperVariant += std::toupper(character);
				}

				*upper_ = upperVariant;

				return upper_;
			}

			VariableBase* Lower()
			{
				std::string lowerVariant;
				std::string currentValue = GetValue();

				for (const auto character : currentValue)
				{
					lowerVariant += std::tolower(character);
				}

				*lower_ = lowerVariant;

				return lower_;
			}

			VariableBase* Variable_Field()
			{
				return variable_field_;
			}

			VariableBase* Variable_Field_Separator()
			{
				return variable_field_separator_;
			}

			void ExpandVariableField()
			{
				// currentvalue + separator
				const auto currentValue = GetValue() + Variable_Field_Separator()->GetValue();
				*Variable_Field() += currentValue;
			}
		};

	public:

		struct Variable_file_ : public VariableScopes
		{

			static constexpr auto name = "file_";

			VariableBase* Content_ = GenerateVariable("");
			VariableBase* Class_postfix_ = GenerateVariable("");
			VariableBase* Extension_ = GenerateVariable("");
			VariableBase* File_name_ = GenerateVariable("");
			VariableBase* Namespace_ = GenerateVariable("");
			VariableBase* Target_language_ = GenerateVariable("");


			Variable_file_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::file_;
			}

			virtual ~Variable_file_() override = default;

			Variable_file_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::file_;
				*static_cast<VariableBase*>(Content_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("#ifndef "), GenerateVariable(grammartemplate_->header_guard_->This()), GenerateVariable("\n#define "), GenerateVariable(grammartemplate_->header_guard_->This()), GenerateVariable("\n#include \"Deamer/Language/Generator/Definition/Property/User/Main/Grammar"), GenerateVariable("."), GenerateVariable("h\"\nnamespace "), GenerateVariable(grammartemplate_->language_full_name_->This()), GenerateVariable("\n"), GenerateVariable("{"), GenerateVariable("\n\tclass Language;\n\t/*!\t"), GenerateVariable("\\"), GenerateVariable("class Grammar\n\t *\n\t *\t"), GenerateVariable("\\"), GenerateVariable("brief This contains the grammar LPD of the language "), GenerateVariable(grammartemplate_->language_full_name_->This()), GenerateVariable("\n\t *\n\t *\t"), GenerateVariable("\\"), GenerateVariable("note This is auto-generated via the DLDL definition"), GenerateVariable("."), GenerateVariable("\n\t */\n\tclass Grammar : public ::deamer::language::generator::definition::property::user::Grammar<\n\t\t\t\t\t\t\t\t::"), GenerateVariable(grammartemplate_->language_full_name_->This()), GenerateVariable("::Language>\n\t"), GenerateVariable("{"), GenerateVariable("\n\tpublic:\n\t\t// Non-Terminal declarations\n\t\t"), GenerateVariable(grammartemplate_->nonterminal_declaration_->Variable_Field()), GenerateVariable("\n\t\n\t\t// Production-Rule declarations\n\t\t"), GenerateVariable(grammartemplate_->productionrule_declaration_->Variable_Field()), GenerateVariable("\n\t\n\tpublic:\n\t\tGrammar("), GenerateVariable(grammartemplate_->language_full_name_->This()), GenerateVariable("::Language* language);\n\t\tvoid GenerateObjects() override;\n\t"), GenerateVariable("}"), GenerateVariable(";\n"), GenerateVariable("}"), GenerateVariable("\n#endif // "), GenerateVariable(grammartemplate_->header_guard_->This()), GenerateVariable("\n") }));
				Content_->type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;

				*static_cast<VariableBase*>(Class_postfix_) = VariableBase(std::vector<VariableBase*>({  }));
				Class_postfix_->type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;

				*static_cast<VariableBase*>(Extension_) = VariableBase(std::vector<VariableBase*>({  }));
				Extension_->type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;

				*static_cast<VariableBase*>(File_name_) = VariableBase(std::vector<VariableBase*>({  }));
				File_name_->type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;

				*static_cast<VariableBase*>(Namespace_) = VariableBase(std::vector<VariableBase*>({  }));
				Namespace_->type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;

				*static_cast<VariableBase*>(Target_language_) = VariableBase(std::vector<VariableBase*>({  }));
				Target_language_->type = ::DLDL::filetemplate::GrammarTemplate::Type::Scope;


			}


			VariableBase* Content() const
			{
				return Content_;
			}

			VariableBase* Class_postfix() const
			{
				return Class_postfix_;
			}

			VariableBase* Extension() const
			{
				return Extension_;
			}

			VariableBase* File_name() const
			{
				return File_name_;
			}

			VariableBase* Namespace() const
			{
				return Namespace_;
			}

			VariableBase* Target_language() const
			{
				return Target_language_;
			}


			Variable_file_& operator=(const Variable_file_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;

				*Content_ = *variable.Content_;
				*Class_postfix_ = *variable.Class_postfix_;
				*Extension_ = *variable.Extension_;
				*File_name_ = *variable.File_name_;
				*Namespace_ = *variable.Namespace_;
				*Target_language_ = *variable.Target_language_;


				return *this;
			}

		};

		struct Variable_header_guard_ : public VariableScopes
		{

			static constexpr auto name = "header_guard_";



			Variable_header_guard_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::header_guard_;
			}

			virtual ~Variable_header_guard_() override = default;

			Variable_header_guard_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::header_guard_;

			}



			Variable_header_guard_& operator=(const Variable_header_guard_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_language_full_name_ : public VariableScopes
		{

			static constexpr auto name = "language_full_name_";



			Variable_language_full_name_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::language_full_name_;
			}

			virtual ~Variable_language_full_name_() override = default;

			Variable_language_full_name_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::language_full_name_;

			}



			Variable_language_full_name_& operator=(const Variable_language_full_name_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_language_full_name_underscore_ : public VariableScopes
		{

			static constexpr auto name = "language_full_name_underscore_";



			Variable_language_full_name_underscore_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::language_full_name_underscore_;
			}

			virtual ~Variable_language_full_name_underscore_() override = default;

			Variable_language_full_name_underscore_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::language_full_name_underscore_;

			}



			Variable_language_full_name_underscore_& operator=(const Variable_language_full_name_underscore_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_left_angle_bracket_ : public VariableScopes
		{

			static constexpr auto name = "left_angle_bracket_";



			Variable_left_angle_bracket_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::left_angle_bracket_;
			}

			virtual ~Variable_left_angle_bracket_() override = default;

			Variable_left_angle_bracket_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::left_angle_bracket_;

			}



			Variable_left_angle_bracket_& operator=(const Variable_left_angle_bracket_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_left_bracket_ : public VariableScopes
		{

			static constexpr auto name = "left_bracket_";



			Variable_left_bracket_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::left_bracket_;
			}

			virtual ~Variable_left_bracket_() override = default;

			Variable_left_bracket_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::left_bracket_;

			}



			Variable_left_bracket_& operator=(const Variable_left_bracket_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_left_curly_bracket_ : public VariableScopes
		{

			static constexpr auto name = "left_curly_bracket_";



			Variable_left_curly_bracket_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::left_curly_bracket_;
			}

			virtual ~Variable_left_curly_bracket_() override = default;

			Variable_left_curly_bracket_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::left_curly_bracket_;

			}



			Variable_left_curly_bracket_& operator=(const Variable_left_curly_bracket_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_nonterminal_ : public VariableScopes
		{

			static constexpr auto name = "nonterminal_";



			Variable_nonterminal_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::nonterminal_;
			}

			virtual ~Variable_nonterminal_() override = default;

			Variable_nonterminal_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::nonterminal_;

			}



			Variable_nonterminal_& operator=(const Variable_nonterminal_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_nonterminal_declaration_ : public VariableScopes
		{

			static constexpr auto name = "nonterminal_declaration_";



			Variable_nonterminal_declaration_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::nonterminal_declaration_;
			}

			virtual ~Variable_nonterminal_declaration_() override = default;

			Variable_nonterminal_declaration_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::nonterminal_declaration_;

			}



			Variable_nonterminal_declaration_& operator=(const Variable_nonterminal_declaration_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_productionrule_ : public VariableScopes
		{

			static constexpr auto name = "productionrule_";



			Variable_productionrule_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::productionrule_;
			}

			virtual ~Variable_productionrule_() override = default;

			Variable_productionrule_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::productionrule_;

			}



			Variable_productionrule_& operator=(const Variable_productionrule_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_productionrule_declaration_ : public VariableScopes
		{

			static constexpr auto name = "productionrule_declaration_";



			Variable_productionrule_declaration_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::productionrule_declaration_;
			}

			virtual ~Variable_productionrule_declaration_() override = default;

			Variable_productionrule_declaration_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::productionrule_declaration_;

			}



			Variable_productionrule_declaration_& operator=(const Variable_productionrule_declaration_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_right_angle_bracket_ : public VariableScopes
		{

			static constexpr auto name = "right_angle_bracket_";



			Variable_right_angle_bracket_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::right_angle_bracket_;
			}

			virtual ~Variable_right_angle_bracket_() override = default;

			Variable_right_angle_bracket_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::right_angle_bracket_;

			}



			Variable_right_angle_bracket_& operator=(const Variable_right_angle_bracket_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_right_bracket_ : public VariableScopes
		{

			static constexpr auto name = "right_bracket_";



			Variable_right_bracket_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::right_bracket_;
			}

			virtual ~Variable_right_bracket_() override = default;

			Variable_right_bracket_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::right_bracket_;

			}



			Variable_right_bracket_& operator=(const Variable_right_bracket_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};

		struct Variable_right_curly_bracket_ : public VariableScopes
		{

			static constexpr auto name = "right_curly_bracket_";



			Variable_right_curly_bracket_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::right_curly_bracket_;
			}

			virtual ~Variable_right_curly_bracket_() override = default;

			Variable_right_curly_bracket_(GrammarTemplate* grammartemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarTemplate::Type::right_curly_bracket_;

			}



			Variable_right_curly_bracket_& operator=(const Variable_right_curly_bracket_& variable)
			{
				if (&variable == this)
				{
					return *this;
				}

				value = variable.value;
				isString = variable.isString;



				return *this;
			}

		};


	public:
		static std::vector<VariableBase*> variables_to_delete;

	public:
		std::vector<VariableBase*> variables_;

	public:
		// Members that one can directly access.
		// e.g. GrammarTemplate.member = "auto-generated";
		Variable_file_* file_ = new Variable_file_();
		Variable_header_guard_* header_guard_ = new Variable_header_guard_();
		Variable_language_full_name_* language_full_name_ = new Variable_language_full_name_();
		Variable_language_full_name_underscore_* language_full_name_underscore_ = new Variable_language_full_name_underscore_();
		VariableScopes* language_full_name_slash_ = new VariableScopes();
		Variable_left_angle_bracket_* left_angle_bracket_ = new Variable_left_angle_bracket_();
		Variable_left_bracket_* left_bracket_ = new Variable_left_bracket_();
		Variable_left_curly_bracket_* left_curly_bracket_ = new Variable_left_curly_bracket_();
		Variable_nonterminal_* nonterminal_ = new Variable_nonterminal_();
		Variable_nonterminal_declaration_* nonterminal_declaration_ = new Variable_nonterminal_declaration_();
		Variable_productionrule_* productionrule_ = new Variable_productionrule_();
		Variable_productionrule_declaration_* productionrule_declaration_ = new Variable_productionrule_declaration_();
		Variable_right_angle_bracket_* right_angle_bracket_ = new Variable_right_angle_bracket_();
		Variable_right_bracket_* right_bracket_ = new Variable_right_bracket_();
		Variable_right_curly_bracket_* right_curly_bracket_ = new Variable_right_curly_bracket_();


	public:
		GrammarTemplate()
		{
			*file_ = Variable_file_(this, std::vector<VariableBase*>({  }));
			*header_guard_ = Variable_header_guard_(this, std::vector<VariableBase*>({ GenerateVariable(language_full_name_underscore_->Upper()), GenerateVariable("_GRAMMAR_H") }));
			*language_full_name_ = Variable_language_full_name_(this, std::vector<VariableBase*>({  }));
			*language_full_name_underscore_ = Variable_language_full_name_underscore_(this, std::vector<VariableBase*>({  }));
			*left_angle_bracket_ = Variable_left_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("<") }));
			*left_bracket_ = Variable_left_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("{") }));
			*left_curly_bracket_ = Variable_left_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("(") }));
			*nonterminal_ = Variable_nonterminal_(this, std::vector<VariableBase*>({  }));
			*nonterminal_declaration_ = Variable_nonterminal_declaration_(this, std::vector<VariableBase*>({ GenerateVariable("::deamer::type::SafeReserve"), GenerateVariable(left_angle_bracket_->This()), GenerateVariable("::deamer::language::type::definition::object::main::NonTerminal"), GenerateVariable(right_angle_bracket_->This()), GenerateVariable(" "), GenerateVariable(nonterminal_->This()), GenerateVariable(";") }));
			*productionrule_ = Variable_productionrule_(this, std::vector<VariableBase*>({  }));
			*productionrule_declaration_ = Variable_productionrule_declaration_(this, std::vector<VariableBase*>({ GenerateVariable("::deamer::type::SafeReserve"), GenerateVariable(left_angle_bracket_->This()), GenerateVariable("::deamer::language::type::definition::object::main::ProductionRule"), GenerateVariable(right_angle_bracket_->This()), GenerateVariable(" "), GenerateVariable(productionrule_->This()), GenerateVariable(";") }));
			*right_angle_bracket_ = Variable_right_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(">") }));
			*right_bracket_ = Variable_right_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("}") }));
			*right_curly_bracket_ = Variable_right_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(")") }));


			variables_.emplace_back(file_);
			variables_.emplace_back(header_guard_);
			variables_.emplace_back(language_full_name_);
			variables_.emplace_back(language_full_name_underscore_);
			variables_.emplace_back(left_angle_bracket_);
			variables_.emplace_back(left_bracket_);
			variables_.emplace_back(left_curly_bracket_);
			variables_.emplace_back(nonterminal_);
			variables_.emplace_back(nonterminal_declaration_);
			variables_.emplace_back(productionrule_);
			variables_.emplace_back(productionrule_declaration_);
			variables_.emplace_back(right_angle_bracket_);
			variables_.emplace_back(right_bracket_);
			variables_.emplace_back(right_curly_bracket_);

		}

		virtual ~GrammarTemplate()
		{
			for (auto* variable : variables_to_delete)
			{
				delete variable;
			}
			variables_to_delete.clear();
		}

	public:
		// Default DST functions

		/*!	\fn GetOutput
		 *
		 *	\brief returns the output with the given the current state.
		 */
		std::string GetOutput()
		{
			return file_->Content()->GetValue();
		}

		/*!	\fn GetVariables
		 *
		 *	\brief Returns all top level variables known in this template.
		 */
		std::vector<VariableBase*> GetVariables()
		{
			return variables_;
		}

	public:
	};

	std::vector<DLDL::filetemplate::GrammarTemplate::VariableBase*> DLDL::filetemplate::GrammarTemplate::variables_to_delete;

}

#endif // DST_GRAMMARTEMPLATE_h