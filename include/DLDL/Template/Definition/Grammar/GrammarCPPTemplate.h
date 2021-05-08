#ifndef DST_GrammarCPPTemplate_cpp
#define DST_GrammarCPPTemplate_cpp

#include <variant>
#include <vector>
#include <string>

namespace DLDL::filetemplate
{

	/*!	\class GrammarCPPTemplate
	 *
	 *	\brief Generates code for "GrammarCPPTemplate"
	 *
	 *	\details This is generated by DST.
	 *	For more information visit: https://github.com/Deruago/DeamerStringTemplate
	 */
	class GrammarCPPTemplate
	{
	public:
		enum class Type
		{
			Unknown,
			Scope,

			// User defined types
			file_,
			high_level_operation_,
			language_full_name_,
			language_full_name_slash_,
			left_angle_bracket_,
			left_bracket_,
			left_curly_bracket_,
			nonterminal_,
			nonterminal_add_object_,
			nonterminal_initialization_,
			productionrule_,
			productionrule_add_object_,
			productionrule_initialization_,
			productionrule_references_,
			right_angle_bracket_,
			right_bracket_,
			right_curly_bracket_,
			token_references_,


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


		static constexpr const char* ConvertEnumToName(::DLDL::filetemplate::GrammarCPPTemplate::Type enumerationValue)
		{
			switch (enumerationValue)
			{
			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::file_:
			{
				return "file";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::high_level_operation_:
			{
				return "high_level_operation";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::language_full_name_:
			{
				return "language_full_name";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::language_full_name_slash_:
			{
				return "language_full_name_slash";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_angle_bracket_:
			{
				return "left_angle_bracket";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_bracket_:
			{
				return "left_bracket";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_curly_bracket_:
			{
				return "left_curly_bracket";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_:
			{
				return "nonterminal";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_add_object_:
			{
				return "nonterminal_add_object";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_initialization_:
			{
				return "nonterminal_initialization";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_:
			{
				return "productionrule";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_add_object_:
			{
				return "productionrule_add_object";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_initialization_:
			{
				return "productionrule_initialization";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_references_:
			{
				return "productionrule_references";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_angle_bracket_:
			{
				return "right_angle_bracket";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_bracket_:
			{
				return "right_bracket";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_curly_bracket_:
			{
				return "right_curly_bracket";
			}

			case ::DLDL::filetemplate::GrammarCPPTemplate::Type::token_references_:
			{
				return "token_references";
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

			::DLDL::filetemplate::GrammarCPPTemplate::Type type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Unknown;

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
			::DLDL::filetemplate::GrammarCPPTemplate::ScopeType scope_type = ::DLDL::filetemplate::GrammarCPPTemplate::ScopeType::Unknown;
			bool isReserved = false;

			VariableScope(::DLDL::filetemplate::GrammarCPPTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;
			}

			VariableScope(const char* text, ::DLDL::filetemplate::GrammarCPPTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(text), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;
			}

			VariableScope(std::vector<VariableBase*> variable, ::DLDL::filetemplate::GrammarCPPTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(variable), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;
			}
		};

		struct VariableScopes : public VariableBase
		{
			// Default scopes
			VariableBase* default_ = new VariableScope(::DLDL::filetemplate::GrammarCPPTemplate::ScopeType::Default_, true);
			VariableBase* upper_ = new VariableScope(::DLDL::filetemplate::GrammarCPPTemplate::ScopeType::Upper_, true);
			VariableBase* lower_ = new VariableScope(::DLDL::filetemplate::GrammarCPPTemplate::ScopeType::Lower_, true);
			VariableBase* variable_field_ = new VariableScope(::DLDL::filetemplate::GrammarCPPTemplate::ScopeType::Variable_Field_, true);
			VariableBase* variable_field_separator_ = new VariableScope("\n", ::DLDL::filetemplate::GrammarCPPTemplate::ScopeType::Variable_Field_Separator_, true);

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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::file_;
			}

			virtual ~Variable_file_() override = default;

			Variable_file_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::file_;
				*static_cast<VariableBase*>(Content_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("#include \""), GenerateVariable(GrammarCPPTemplate_->language_full_name_slash_->This()), GenerateVariable("/Grammar"), GenerateVariable("."), GenerateVariable("h\"\n#include \""), GenerateVariable(GrammarCPPTemplate_->language_full_name_slash_->This()), GenerateVariable("/Language"), GenerateVariable("."), GenerateVariable("h\"\n"), GenerateVariable(GrammarCPPTemplate_->language_full_name_->This()), GenerateVariable("::Grammar::Grammar("), GenerateVariable(GrammarCPPTemplate_->language_full_name_->This()), GenerateVariable("::Language* language)\n\t\t\t:\t::deamer::language::generator::definition::property::user::Grammar<\n\t\t\t\t\t"), GenerateVariable(GrammarCPPTemplate_->language_full_name_->This()), GenerateVariable("::Language>(language)\n"), GenerateVariable("{"), GenerateVariable("\n"), GenerateVariable("}"), GenerateVariable("\nvoid "), GenerateVariable(GrammarCPPTemplate_->language_full_name_->This()), GenerateVariable("::Grammar::GenerateObjects()\n"), GenerateVariable("{"), GenerateVariable("\n\t// Non-Terminal initialization\n\t"), GenerateVariable(GrammarCPPTemplate_->nonterminal_initialization_->Variable_Field()), GenerateVariable("\n\t// Production-Rule initialization\n\t"), GenerateVariable(GrammarCPPTemplate_->productionrule_initialization_->Variable_Field()), GenerateVariable("\n\t// Add object calls\n\t// AddObject("), GenerateVariable("."), GenerateVariable("."), GenerateVariable("."), GenerateVariable(")\n\t"), GenerateVariable(GrammarCPPTemplate_->nonterminal_add_object_->Variable_Field()), GenerateVariable("\n\t"), GenerateVariable(GrammarCPPTemplate_->productionrule_add_object_->Variable_Field()), GenerateVariable("\n\t// Place higher level operations here"), GenerateVariable("."), GenerateVariable("\n\t// ReplaceObject("), GenerateVariable("."), GenerateVariable("."), GenerateVariable("."), GenerateVariable(", "), GenerateVariable("."), GenerateVariable("."), GenerateVariable("."), GenerateVariable(")\n\t// DeleteObject("), GenerateVariable("."), GenerateVariable("."), GenerateVariable("."), GenerateVariable(", "), GenerateVariable("."), GenerateVariable("."), GenerateVariable("."), GenerateVariable(")\n\t"), GenerateVariable(GrammarCPPTemplate_->high_level_operation_->Variable_Field()), GenerateVariable("\n"), GenerateVariable("}"), GenerateVariable("\n") }));
				Content_->type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;

				*static_cast<VariableBase*>(Class_postfix_) = VariableBase(std::vector<VariableBase*>({  }));
				Class_postfix_->type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;

				*static_cast<VariableBase*>(Extension_) = VariableBase(std::vector<VariableBase*>({  }));
				Extension_->type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;

				*static_cast<VariableBase*>(File_name_) = VariableBase(std::vector<VariableBase*>({  }));
				File_name_->type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;

				*static_cast<VariableBase*>(Namespace_) = VariableBase(std::vector<VariableBase*>({  }));
				Namespace_->type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;

				*static_cast<VariableBase*>(Target_language_) = VariableBase(std::vector<VariableBase*>({  }));
				Target_language_->type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::Scope;


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

		struct Variable_high_level_operation_ : public VariableScopes
		{

			static constexpr auto name = "high_level_operation_";



			Variable_high_level_operation_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::high_level_operation_;
			}

			virtual ~Variable_high_level_operation_() override = default;

			Variable_high_level_operation_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::high_level_operation_;

			}



			Variable_high_level_operation_& operator=(const Variable_high_level_operation_& variable)
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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::language_full_name_;
			}

			virtual ~Variable_language_full_name_() override = default;

			Variable_language_full_name_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::language_full_name_;

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

		struct Variable_language_full_name_slash_ : public VariableScopes
		{

			static constexpr auto name = "language_full_name_slash_";



			Variable_language_full_name_slash_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::language_full_name_slash_;
			}

			virtual ~Variable_language_full_name_slash_() override = default;

			Variable_language_full_name_slash_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::language_full_name_slash_;

			}



			Variable_language_full_name_slash_& operator=(const Variable_language_full_name_slash_& variable)
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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_angle_bracket_;
			}

			virtual ~Variable_left_angle_bracket_() override = default;

			Variable_left_angle_bracket_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_angle_bracket_;

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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_bracket_;
			}

			virtual ~Variable_left_bracket_() override = default;

			Variable_left_bracket_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_bracket_;

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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_curly_bracket_;
			}

			virtual ~Variable_left_curly_bracket_() override = default;

			Variable_left_curly_bracket_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::left_curly_bracket_;

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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_;
			}

			virtual ~Variable_nonterminal_() override = default;

			Variable_nonterminal_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_;

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

		struct Variable_nonterminal_add_object_ : public VariableScopes
		{

			static constexpr auto name = "nonterminal_add_object_";



			Variable_nonterminal_add_object_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_add_object_;
			}

			virtual ~Variable_nonterminal_add_object_() override = default;

			Variable_nonterminal_add_object_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_add_object_;

			}



			Variable_nonterminal_add_object_& operator=(const Variable_nonterminal_add_object_& variable)
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

		struct Variable_nonterminal_initialization_ : public VariableScopes
		{

			static constexpr auto name = "nonterminal_initialization_";



			Variable_nonterminal_initialization_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_initialization_;
			}

			virtual ~Variable_nonterminal_initialization_() override = default;

			Variable_nonterminal_initialization_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::nonterminal_initialization_;

			}



			Variable_nonterminal_initialization_& operator=(const Variable_nonterminal_initialization_& variable)
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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_;
			}

			virtual ~Variable_productionrule_() override = default;

			Variable_productionrule_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_;

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

		struct Variable_productionrule_add_object_ : public VariableScopes
		{

			static constexpr auto name = "productionrule_add_object_";



			Variable_productionrule_add_object_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_add_object_;
			}

			virtual ~Variable_productionrule_add_object_() override = default;

			Variable_productionrule_add_object_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_add_object_;

			}



			Variable_productionrule_add_object_& operator=(const Variable_productionrule_add_object_& variable)
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

		struct Variable_productionrule_initialization_ : public VariableScopes
		{

			static constexpr auto name = "productionrule_initialization_";



			Variable_productionrule_initialization_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_initialization_;
			}

			virtual ~Variable_productionrule_initialization_() override = default;

			Variable_productionrule_initialization_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_initialization_;

			}



			Variable_productionrule_initialization_& operator=(const Variable_productionrule_initialization_& variable)
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

		struct Variable_productionrule_references_ : public VariableScopes
		{

			static constexpr auto name = "productionrule_references_";



			Variable_productionrule_references_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_references_;
			}

			virtual ~Variable_productionrule_references_() override = default;

			Variable_productionrule_references_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::productionrule_references_;

			}



			Variable_productionrule_references_& operator=(const Variable_productionrule_references_& variable)
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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_angle_bracket_;
			}

			virtual ~Variable_right_angle_bracket_() override = default;

			Variable_right_angle_bracket_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_angle_bracket_;

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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_bracket_;
			}

			virtual ~Variable_right_bracket_() override = default;

			Variable_right_bracket_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_bracket_;

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
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_curly_bracket_;
			}

			virtual ~Variable_right_curly_bracket_() override = default;

			Variable_right_curly_bracket_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::right_curly_bracket_;

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

		struct Variable_token_references_ : public VariableScopes
		{

			static constexpr auto name = "token_references_";



			Variable_token_references_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::token_references_;
			}

			virtual ~Variable_token_references_() override = default;

			Variable_token_references_(GrammarCPPTemplate* GrammarCPPTemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::GrammarCPPTemplate::Type::token_references_;

			}



			Variable_token_references_& operator=(const Variable_token_references_& variable)
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
		// e.g. GrammarCPPTemplate.member = "auto-generated";
		Variable_file_* file_ = new Variable_file_();
		Variable_high_level_operation_* high_level_operation_ = new Variable_high_level_operation_();
		Variable_language_full_name_* language_full_name_ = new Variable_language_full_name_();
		Variable_language_full_name_slash_* language_full_name_slash_ = new Variable_language_full_name_slash_();
		VariableScopes* language_full_name_underscore_ = new VariableScopes();
		VariableScopes* header_guard_ = new VariableScopes();
		Variable_left_angle_bracket_* left_angle_bracket_ = new Variable_left_angle_bracket_();
		Variable_left_bracket_* left_bracket_ = new Variable_left_bracket_();
		Variable_left_curly_bracket_* left_curly_bracket_ = new Variable_left_curly_bracket_();
		Variable_nonterminal_* nonterminal_ = new Variable_nonterminal_();
		Variable_nonterminal_add_object_* nonterminal_add_object_ = new Variable_nonterminal_add_object_();
		Variable_nonterminal_initialization_* nonterminal_initialization_ = new Variable_nonterminal_initialization_();
		Variable_productionrule_* productionrule_ = new Variable_productionrule_();
		Variable_productionrule_add_object_* productionrule_add_object_ = new Variable_productionrule_add_object_();
		Variable_productionrule_initialization_* productionrule_initialization_ = new Variable_productionrule_initialization_();
		Variable_productionrule_references_* productionrule_references_ = new Variable_productionrule_references_();
		Variable_right_angle_bracket_* right_angle_bracket_ = new Variable_right_angle_bracket_();
		Variable_right_bracket_* right_bracket_ = new Variable_right_bracket_();
		Variable_right_curly_bracket_* right_curly_bracket_ = new Variable_right_curly_bracket_();
		Variable_token_references_* token_references_ = new Variable_token_references_();


	public:
		GrammarCPPTemplate()
		{
			*file_ = Variable_file_(this, std::vector<VariableBase*>({  }));
			*high_level_operation_ = Variable_high_level_operation_(this, std::vector<VariableBase*>({  }));
			*language_full_name_ = Variable_language_full_name_(this, std::vector<VariableBase*>({  }));
			*language_full_name_slash_ = Variable_language_full_name_slash_(this, std::vector<VariableBase*>({  }));
			*left_angle_bracket_ = Variable_left_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("<") }));
			*left_bracket_ = Variable_left_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("{") }));
			*left_curly_bracket_ = Variable_left_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("(") }));
			*nonterminal_ = Variable_nonterminal_(this, std::vector<VariableBase*>({  }));
			*nonterminal_add_object_ = Variable_nonterminal_add_object_(this, std::vector<VariableBase*>({ GenerateVariable("AddObject("), GenerateVariable(nonterminal_->This()), GenerateVariable(");") }));
			*nonterminal_initialization_ = Variable_nonterminal_initialization_(this, std::vector<VariableBase*>({ GenerateVariable(nonterminal_->This()), GenerateVariable("."), GenerateVariable("Set(::deamer::language::type::definition::object::main::NonTerminal(\""), GenerateVariable(nonterminal_->This()), GenerateVariable("\", "), GenerateVariable("{"), GenerateVariable(" "), GenerateVariable(productionrule_references_->This()), GenerateVariable(" "), GenerateVariable("}"), GenerateVariable("));") }));
			*productionrule_ = Variable_productionrule_(this, std::vector<VariableBase*>({  }));
			*productionrule_add_object_ = Variable_productionrule_add_object_(this, std::vector<VariableBase*>({ GenerateVariable("AddObject("), GenerateVariable(productionrule_->This()), GenerateVariable(");") }));
			*productionrule_initialization_ = Variable_productionrule_initialization_(this, std::vector<VariableBase*>({ GenerateVariable(productionrule_->This()), GenerateVariable("."), GenerateVariable("Set(::deamer::language::type::definition::object::main::ProductionRule("), GenerateVariable(token_references_->This()), GenerateVariable("));") }));
			*productionrule_references_ = Variable_productionrule_references_(this, std::vector<VariableBase*>({  }));
			*right_angle_bracket_ = Variable_right_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(">") }));
			*right_bracket_ = Variable_right_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("}") }));
			*right_curly_bracket_ = Variable_right_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(")") }));
			*token_references_ = Variable_token_references_(this, std::vector<VariableBase*>({  }));


			variables_.emplace_back(file_);
			variables_.emplace_back(high_level_operation_);
			variables_.emplace_back(language_full_name_);
			variables_.emplace_back(language_full_name_slash_);
			variables_.emplace_back(left_angle_bracket_);
			variables_.emplace_back(left_bracket_);
			variables_.emplace_back(left_curly_bracket_);
			variables_.emplace_back(nonterminal_);
			variables_.emplace_back(nonterminal_add_object_);
			variables_.emplace_back(nonterminal_initialization_);
			variables_.emplace_back(productionrule_);
			variables_.emplace_back(productionrule_add_object_);
			variables_.emplace_back(productionrule_initialization_);
			variables_.emplace_back(productionrule_references_);
			variables_.emplace_back(right_angle_bracket_);
			variables_.emplace_back(right_bracket_);
			variables_.emplace_back(right_curly_bracket_);
			variables_.emplace_back(token_references_);

		}

		virtual ~GrammarCPPTemplate()
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

	std::vector<DLDL::filetemplate::GrammarCPPTemplate::VariableBase*> DLDL::filetemplate::GrammarCPPTemplate::variables_to_delete;

}

#endif // DST_GrammarCPPTemplate_cpp
