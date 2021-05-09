#ifndef DST_CMAKELISTSTEMPLATE_txt
#define DST_CMAKELISTSTEMPLATE_txt

#include <variant>
#include <vector>
#include <string>

namespace DLDL::filetemplate
{

	/*!	\class CMakeListsTemplate
	 *
	 *	\brief Generates code for "CMakeListsTemplate"
	 *
	 *	\details This is generated by DST.
	 *	For more information visit: https://github.com/Deruago/DeamerStringTemplate
	 */
	class CMakeListsTemplate
	{
	public:
		enum class Type
		{
			Unknown,
			Scope,

			// User defined types
			file_,
			language_generation_target_,
			language_static_library_target_,
			languages_,
			languages_comma_,
			left_angle_bracket_,
			left_bracket_,
			left_curly_bracket_,
			project_name_,
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


		static constexpr const char* ConvertEnumToName(::DLDL::filetemplate::CMakeListsTemplate::Type enumerationValue)
		{
			switch (enumerationValue)
			{
			case ::DLDL::filetemplate::CMakeListsTemplate::Type::file_:
			{
				return "file";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::language_generation_target_:
			{
				return "language_generation_target";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::language_static_library_target_:
			{
				return "language_static_library_target";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::languages_:
			{
				return "languages";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::languages_comma_:
			{
				return "languages_comma";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::left_angle_bracket_:
			{
				return "left_angle_bracket";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::left_bracket_:
			{
				return "left_bracket";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::left_curly_bracket_:
			{
				return "left_curly_bracket";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::project_name_:
			{
				return "project_name";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::right_angle_bracket_:
			{
				return "right_angle_bracket";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::right_bracket_:
			{
				return "right_bracket";
			}

			case ::DLDL::filetemplate::CMakeListsTemplate::Type::right_curly_bracket_:
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

			::DLDL::filetemplate::CMakeListsTemplate::Type type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Unknown;

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
			::DLDL::filetemplate::CMakeListsTemplate::ScopeType scope_type = ::DLDL::filetemplate::CMakeListsTemplate::ScopeType::Unknown;
			bool isReserved = false;

			VariableScope(::DLDL::filetemplate::CMakeListsTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;
			}

			VariableScope(const char* text, ::DLDL::filetemplate::CMakeListsTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(text), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;
			}

			VariableScope(std::vector<VariableBase*> variable, ::DLDL::filetemplate::CMakeListsTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(variable), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;
			}
		};

		struct VariableScopes : public VariableBase
		{
			// Default scopes
			VariableBase* default_ = new VariableScope(::DLDL::filetemplate::CMakeListsTemplate::ScopeType::Default_, true);
			VariableBase* upper_ = new VariableScope(::DLDL::filetemplate::CMakeListsTemplate::ScopeType::Upper_, true);
			VariableBase* lower_ = new VariableScope(::DLDL::filetemplate::CMakeListsTemplate::ScopeType::Lower_, true);
			VariableBase* variable_field_ = new VariableScope(::DLDL::filetemplate::CMakeListsTemplate::ScopeType::Variable_Field_, true);
			VariableBase* variable_field_separator_ = new VariableScope("\n", ::DLDL::filetemplate::CMakeListsTemplate::ScopeType::Variable_Field_Separator_, true);

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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::file_;
			}

			virtual ~Variable_file_() override = default;

			Variable_file_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::file_;
				*static_cast<VariableBase*>(Content_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("cmake_minimum_required(VERSION 3"), GenerateVariable("."), GenerateVariable("16)\nproject("), GenerateVariable(cmakeliststemplate_->project_name_->This()), GenerateVariable("\n                      DESCRIPTION \"Compiler/Ecosystem generator for language(s): "), GenerateVariable(cmakeliststemplate_->languages_comma_->This()), GenerateVariable("."), GenerateVariable(" This CompilerGenerator project uses Deamer CC for the generation, and DLDL to generate the definitions"), GenerateVariable("."), GenerateVariable("\"\n                      LANGUAGES CXX)\nfind_package(Deamer REQUIRED)\nfile(GLOB_RECURSE SOURCE_LIST \"$"), GenerateVariable(cmakeliststemplate_->left_bracket_->This()), GenerateVariable(cmakeliststemplate_->project_name_->This()), GenerateVariable("_SOURCE_DIR"), GenerateVariable("}"), GenerateVariable("/lib/*"), GenerateVariable("."), GenerateVariable("cpp\")\nadd_library("), GenerateVariable(cmakeliststemplate_->language_static_library_target_->This()), GenerateVariable(" STATIC $"), GenerateVariable("{"), GenerateVariable("SOURCE_LIST"), GenerateVariable("}"), GenerateVariable(")\ntarget_include_directories("), GenerateVariable(cmakeliststemplate_->language_static_library_target_->This()), GenerateVariable(" PUBLIC \"$"), GenerateVariable(cmakeliststemplate_->left_bracket_->This()), GenerateVariable(cmakeliststemplate_->project_name_->This()), GenerateVariable("_SOURCE_DIR"), GenerateVariable("}"), GenerateVariable("/include\")\ntarget_link_libraries("), GenerateVariable(cmakeliststemplate_->language_static_library_target_->This()), GenerateVariable(" PUBLIC Deamer)\ntarget_compile_features("), GenerateVariable(cmakeliststemplate_->language_static_library_target_->This()), GenerateVariable(" PUBLIC cxx_std_17)\nset_target_properties("), GenerateVariable(cmakeliststemplate_->language_static_library_target_->This()), GenerateVariable(" PROPERTIES LINKER_LANGUAGE CXX)\nadd_executable("), GenerateVariable(cmakeliststemplate_->language_generation_target_->This()), GenerateVariable(" \"$"), GenerateVariable(cmakeliststemplate_->left_bracket_->This()), GenerateVariable(cmakeliststemplate_->project_name_->This()), GenerateVariable("_SOURCE_DIR"), GenerateVariable("}"), GenerateVariable("/main"), GenerateVariable("."), GenerateVariable("cpp\")\ntarget_link_libraries("), GenerateVariable(cmakeliststemplate_->language_generation_target_->This()), GenerateVariable(" PUBLIC "), GenerateVariable(cmakeliststemplate_->language_static_library_target_->This()), GenerateVariable(")\n") }));
				Content_->type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;

				*static_cast<VariableBase*>(Class_postfix_) = VariableBase(std::vector<VariableBase*>({  }));
				Class_postfix_->type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;

				*static_cast<VariableBase*>(Extension_) = VariableBase(std::vector<VariableBase*>({  }));
				Extension_->type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;

				*static_cast<VariableBase*>(File_name_) = VariableBase(std::vector<VariableBase*>({  }));
				File_name_->type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;

				*static_cast<VariableBase*>(Namespace_) = VariableBase(std::vector<VariableBase*>({  }));
				Namespace_->type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;

				*static_cast<VariableBase*>(Target_language_) = VariableBase(std::vector<VariableBase*>({  }));
				Target_language_->type = ::DLDL::filetemplate::CMakeListsTemplate::Type::Scope;


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

		struct Variable_language_generation_target_ : public VariableScopes
		{

			static constexpr auto name = "language_generation_target_";



			Variable_language_generation_target_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::language_generation_target_;
			}

			virtual ~Variable_language_generation_target_() override = default;

			Variable_language_generation_target_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::language_generation_target_;

			}



			Variable_language_generation_target_& operator=(const Variable_language_generation_target_& variable)
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

		struct Variable_language_static_library_target_ : public VariableScopes
		{

			static constexpr auto name = "language_static_library_target_";



			Variable_language_static_library_target_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::language_static_library_target_;
			}

			virtual ~Variable_language_static_library_target_() override = default;

			Variable_language_static_library_target_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::language_static_library_target_;

			}



			Variable_language_static_library_target_& operator=(const Variable_language_static_library_target_& variable)
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

		struct Variable_languages_ : public VariableScopes
		{

			static constexpr auto name = "languages_";



			Variable_languages_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::languages_;
			}

			virtual ~Variable_languages_() override = default;

			Variable_languages_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::languages_;

			}



			Variable_languages_& operator=(const Variable_languages_& variable)
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

		struct Variable_languages_comma_ : public VariableScopes
		{

			static constexpr auto name = "languages_comma_";



			Variable_languages_comma_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::languages_comma_;
			}

			virtual ~Variable_languages_comma_() override = default;

			Variable_languages_comma_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::languages_comma_;

			}



			Variable_languages_comma_& operator=(const Variable_languages_comma_& variable)
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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::left_angle_bracket_;
			}

			virtual ~Variable_left_angle_bracket_() override = default;

			Variable_left_angle_bracket_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::left_angle_bracket_;

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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::left_bracket_;
			}

			virtual ~Variable_left_bracket_() override = default;

			Variable_left_bracket_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::left_bracket_;

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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::left_curly_bracket_;
			}

			virtual ~Variable_left_curly_bracket_() override = default;

			Variable_left_curly_bracket_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::left_curly_bracket_;

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

		struct Variable_project_name_ : public VariableScopes
		{

			static constexpr auto name = "project_name_";



			Variable_project_name_() : VariableScopes()
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::project_name_;
			}

			virtual ~Variable_project_name_() override = default;

			Variable_project_name_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::project_name_;

			}



			Variable_project_name_& operator=(const Variable_project_name_& variable)
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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::right_angle_bracket_;
			}

			virtual ~Variable_right_angle_bracket_() override = default;

			Variable_right_angle_bracket_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::right_angle_bracket_;

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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::right_bracket_;
			}

			virtual ~Variable_right_bracket_() override = default;

			Variable_right_bracket_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::right_bracket_;

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
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::right_curly_bracket_;
			}

			virtual ~Variable_right_curly_bracket_() override = default;

			Variable_right_curly_bracket_(CMakeListsTemplate* cmakeliststemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
			{
				type = ::DLDL::filetemplate::CMakeListsTemplate::Type::right_curly_bracket_;

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
		inline static std::vector<VariableBase*> variables_to_delete = std::vector<VariableBase*>();

	public:
		std::vector<VariableBase*> variables_;

	public:
		// Members that one can directly access.
		// e.g. CMakeListsTemplate.member = "auto-generated";
		Variable_file_* file_ = new Variable_file_();
		Variable_language_generation_target_* language_generation_target_ = new Variable_language_generation_target_();
		Variable_language_static_library_target_* language_static_library_target_ = new Variable_language_static_library_target_();
		Variable_languages_* languages_ = new Variable_languages_();
		Variable_languages_comma_* languages_comma_ = new Variable_languages_comma_();
		Variable_left_angle_bracket_* left_angle_bracket_ = new Variable_left_angle_bracket_();
		Variable_left_bracket_* left_bracket_ = new Variable_left_bracket_();
		Variable_left_curly_bracket_* left_curly_bracket_ = new Variable_left_curly_bracket_();
		Variable_project_name_* project_name_ = new Variable_project_name_();
		Variable_right_angle_bracket_* right_angle_bracket_ = new Variable_right_angle_bracket_();
		Variable_right_bracket_* right_bracket_ = new Variable_right_bracket_();
		Variable_right_curly_bracket_* right_curly_bracket_ = new Variable_right_curly_bracket_();


	public:
		CMakeListsTemplate()
		{
			*file_ = Variable_file_(this, std::vector<VariableBase*>({  }));
			*language_generation_target_ = Variable_language_generation_target_(this, std::vector<VariableBase*>({ GenerateVariable(languages_->This()), GenerateVariable("_CompilerGenerator_Main") }));
			*language_static_library_target_ = Variable_language_static_library_target_(this, std::vector<VariableBase*>({ GenerateVariable(languages_->This()), GenerateVariable("_CompilerGenerator_static_library") }));
			*languages_ = Variable_languages_(this, std::vector<VariableBase*>({  }));
			*languages_comma_ = Variable_languages_comma_(this, std::vector<VariableBase*>({  }));
			*left_angle_bracket_ = Variable_left_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("<") }));
			*left_bracket_ = Variable_left_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("{") }));
			*left_curly_bracket_ = Variable_left_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("(") }));
			*project_name_ = Variable_project_name_(this, std::vector<VariableBase*>({ GenerateVariable(languages_->This()), GenerateVariable("_CompilerGenerator") }));
			*right_angle_bracket_ = Variable_right_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(">") }));
			*right_bracket_ = Variable_right_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("}") }));
			*right_curly_bracket_ = Variable_right_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(")") }));


			variables_.emplace_back(file_);
			variables_.emplace_back(language_generation_target_);
			variables_.emplace_back(language_static_library_target_);
			variables_.emplace_back(languages_);
			variables_.emplace_back(languages_comma_);
			variables_.emplace_back(left_angle_bracket_);
			variables_.emplace_back(left_bracket_);
			variables_.emplace_back(left_curly_bracket_);
			variables_.emplace_back(project_name_);
			variables_.emplace_back(right_angle_bracket_);
			variables_.emplace_back(right_bracket_);
			variables_.emplace_back(right_curly_bracket_);

		}

		virtual ~CMakeListsTemplate()
		{
			for (auto* variable : variables_to_delete)
			{
				delete variable;
			}
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
}

#endif // DST_CMAKELISTSTEMPLATE_txt
