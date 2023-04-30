#ifndef DLDL_FILETEMPLATE_ARGUMENTCPPTEMPLATE_h
#define DLDL_FILETEMPLATE_ARGUMENTCPPTEMPLATE_h

#include <variant>
#include <vector>
#include <string>

namespace DLDL::filetemplate
{

	/*!	\class ArgumentCPPTemplate
	 *
	 *	\brief Generates code for "ArgumentCPPTemplate"
	 *
	 *	\details This is generated by DST.
	 *	For more information visit: https://github.com/Deruago/DeamerStringTemplate
	 */
	class ArgumentCPPTemplate
	{
	public:
		enum class Type
{
Unknown,
Scope,

// User defined types
add_unknown_reference_,
file_,
language_full_name_,
language_full_name_slash_,
language_full_name_underscore_,
left_angle_bracket_,
left_bracket_,
left_curly_bracket_,
right_angle_bracket_,
right_bracket_,
right_curly_bracket_,
unknown_reference_,
unknown_reference_implementation_,


};


		enum class ScopeType
{
Unknown,

// Default
Default_,
Upper_,
Lower_,

Snake_,
Slash_,
BackSlash_,
Colon_,
DoubleColon_,

Variable_Field_,
Variable_Field_Separator_,
Function_Field_,
Function_Field_Separator_,


};


		static constexpr const char* ConvertEnumToName(::DLDL::filetemplate::ArgumentCPPTemplate::Type enumerationValue)
{
	switch(enumerationValue)
	{
	case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Unknown: {
		return "Unknown";}

	case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope: {
		return "Scope";}

	case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::add_unknown_reference_:
{
	return "add_unknown_reference";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::file_:
{
	return "file";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_:
{
	return "language_full_name";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_slash_:
{
	return "language_full_name_slash";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_underscore_:
{
	return "language_full_name_underscore";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_angle_bracket_:
{
	return "left_angle_bracket";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_bracket_:
{
	return "left_bracket";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_curly_bracket_:
{
	return "left_curly_bracket";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_angle_bracket_:
{
	return "right_angle_bracket";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_bracket_:
{
	return "right_bracket";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_curly_bracket_:
{
	return "right_curly_bracket";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::unknown_reference_:
{
	return "unknown_reference";
}

case ::DLDL::filetemplate::ArgumentCPPTemplate::Type::unknown_reference_implementation_:
{
	return "unknown_reference_implementation";
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

			::DLDL::filetemplate::ArgumentCPPTemplate::Type type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Unknown;

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

			virtual std::string GetValue()
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
			::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType scope_type = ::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Unknown;
			bool isReserved = false;

			VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;
			}

			VariableScope(const char* text, ::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(text), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;
			}

			VariableScope(std::vector<VariableBase*> variable, ::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(variable), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;
			}
		};
		
		struct Variable_ReservedScope_Upper : public VariableScope
		{
			VariableBase* base;
			Variable_ReservedScope_Upper(VariableBase* base_)
			: VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Upper_, true),
			  base(base_)
			{
			}
			
			virtual std::string GetValue() override
			{
				std::string upperVariant;
				std::string currentValue = base->GetValue();

				for (const auto character : currentValue)
				{
					upperVariant += std::toupper(character);
				}

				return upperVariant;
			}
		};
		
		struct Variable_ReservedScope_Lower : public VariableScope
		{
			VariableBase* base;
			Variable_ReservedScope_Lower(VariableBase* base_)
			: VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Lower_, true),
			  base(base_)
			{
			}
			
			virtual std::string GetValue() override
			{
				std::string lowerVariant;
				std::string currentValue = base->GetValue();

				for (const auto character : currentValue)
				{
					lowerVariant += std::tolower(character);
				}

				return lowerVariant;
			}
		};
		
		struct Variable_ReservedScope_Snake : public VariableScope
		{
			VariableBase* base;
			Variable_ReservedScope_Snake(VariableBase* base_)
			: VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Snake_, true),
			  base(base_)
			{
			}
			
			virtual std::string GetValue() override
			{
				std::string snakeVariant;
				std::string currentValue = base->GetValue();
				
				bool lastWasNonAlpha = true;
				for (const auto character : currentValue)
				{
					if (std::isalpha(character))
					{
						snakeVariant += character;
						lastWasNonAlpha = false;
					}
					else
					{
						if (lastWasNonAlpha)
						{
							continue;
						}
						
						snakeVariant += '_';
						lastWasNonAlpha = true;
					}
				}
				
				// If it contains text
				// remove the tail
				if (!snakeVariant.empty() && lastWasNonAlpha)
				{
					snakeVariant.pop_back();
				}

				return snakeVariant;
			}
		};
		
		struct Variable_ReservedScope_Slash : public VariableScope
		{
			VariableBase* base;
			Variable_ReservedScope_Slash(VariableBase* base_)
			: VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Slash_, true),
			  base(base_)
			{
			}
			
			virtual std::string GetValue() override
			{
				std::string slashVariant;
				std::string currentValue = base->GetValue();
				
				bool lastWasNonAlpha = true;
				for (const auto character : currentValue)
				{
					if (std::isalpha(character))
					{
						slashVariant += character;
						lastWasNonAlpha = false;
					}
					else
					{
						if (lastWasNonAlpha)
						{
							continue;
						}
						
						slashVariant += '/';
						lastWasNonAlpha = true;
					}
				}
				
				// If it contains text
				// remove the tail
				if (!slashVariant.empty() && lastWasNonAlpha)
				{
					slashVariant.pop_back();
				}

				return slashVariant;
			}
		};
		
		struct Variable_ReservedScope_DoubleColon : public VariableScope
		{
			VariableBase* base;
			Variable_ReservedScope_DoubleColon(VariableBase* base_)
			: VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::DoubleColon_, true),
			  base(base_)
			{
			}
			
			virtual std::string GetValue() override
			{
				std::string doubleColonVariant;
				std::string currentValue = base->GetValue();
				
				bool lastWasNonAlpha = true;
				for (const auto character : currentValue)
				{
					if (std::isalpha(character))
					{
						doubleColonVariant += character;
						lastWasNonAlpha = false;
					}
					else
					{
						if (lastWasNonAlpha)
						{
							continue;
						}
						
						doubleColonVariant += "::";
						lastWasNonAlpha = true;
					}
				}
				
				// If it contains text
				// remove the tail
				if (!doubleColonVariant.empty() && lastWasNonAlpha)
				{
					doubleColonVariant.pop_back();
					doubleColonVariant.pop_back();
				}

				return doubleColonVariant;
			}
		};

		struct VariableScopes : public VariableBase
		{
			// Default scopes
			VariableBase* default_ = new VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Default_, true);
			VariableBase* upper_ = new Variable_ReservedScope_Upper(this);
			VariableBase* lower_ = new Variable_ReservedScope_Lower(this);
			
			VariableBase* snake_ = new Variable_ReservedScope_Snake(this);
			VariableBase* slash_ = new Variable_ReservedScope_Slash(this);
			VariableBase* double_colon_ = new Variable_ReservedScope_DoubleColon(this);
			
			VariableBase* variable_field_ = new VariableScope(::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Variable_Field_, true);
			VariableBase* variable_field_separator_ = new VariableScope("\n", ::DLDL::filetemplate::ArgumentCPPTemplate::ScopeType::Variable_Field_Separator_, true);

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
				return upper_;
			}

			VariableBase* Lower()
			{
				return lower_;
			}

			VariableBase* Underscore()
			{
				return snake_;
			}

			VariableBase* Snake()
			{
				return snake_;
			}

			VariableBase* Slash()
			{
				return slash_;
			}

			VariableBase* DoubleColon()
			{
				return double_colon_;
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
		
struct Variable_add_unknown_reference_ : public VariableScopes
{

static constexpr auto name = "add_unknown_reference_";



Variable_add_unknown_reference_() : VariableScopes()
{
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::add_unknown_reference_;
}

virtual ~Variable_add_unknown_reference_() override = default;

Variable_add_unknown_reference_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::add_unknown_reference_;

}



Variable_add_unknown_reference_& operator=(const Variable_add_unknown_reference_& variable)
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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::file_;
}

virtual ~Variable_file_() override = default;

Variable_file_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::file_;
*static_cast<VariableBase*>(Content_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("#include \""), GenerateVariable(argumentcpptemplate_->language_full_name_slash_->This()), GenerateVariable("/Argument"), GenerateVariable("."), GenerateVariable("h\"\n#include \""), GenerateVariable(argumentcpptemplate_->language_full_name_slash_->This()), GenerateVariable("/Language"), GenerateVariable("."), GenerateVariable("h\"\n\n"), GenerateVariable(argumentcpptemplate_->language_full_name_->This()), GenerateVariable("::Argument::Argument("), GenerateVariable(argumentcpptemplate_->language_full_name_->This()), GenerateVariable("::Language* language)\n\t\t\t:\t::deamer::language::generator::definition::property::user::Argument<\n\t\t\t\t\t"), GenerateVariable(argumentcpptemplate_->language_full_name_->This()), GenerateVariable("::Language>(language)\n"), GenerateVariable("{"), GenerateVariable("\n"), GenerateVariable("}"), GenerateVariable("\n\nvoid "), GenerateVariable(argumentcpptemplate_->language_full_name_->This()), GenerateVariable("::Argument::GenerateObjects()\n"), GenerateVariable("{"), GenerateVariable("\n\t// Unknown References\n\t"), GenerateVariable(argumentcpptemplate_->unknown_reference_implementation_->Variable_Field()), GenerateVariable("\n\n\t// Unknown References\n\t"), GenerateVariable(argumentcpptemplate_->add_unknown_reference_->Variable_Field()), GenerateVariable("\n"), GenerateVariable("}") }));
Content_->type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;

*static_cast<VariableBase*>(Class_postfix_) = VariableBase(std::vector<VariableBase*>({  }));
Class_postfix_->type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;

*static_cast<VariableBase*>(Extension_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("h") }));
Extension_->type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;

*static_cast<VariableBase*>(File_name_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("ArgumentCPP") }));
File_name_->type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;

*static_cast<VariableBase*>(Namespace_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("DLDL::filetemplate") }));
Namespace_->type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;

*static_cast<VariableBase*>(Target_language_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("C++") }));
Target_language_->type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::Scope;


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

struct Variable_language_full_name_ : public VariableScopes
{

static constexpr auto name = "language_full_name_";



Variable_language_full_name_() : VariableScopes()
{
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_;
}

virtual ~Variable_language_full_name_() override = default;

Variable_language_full_name_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_;

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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_slash_;
}

virtual ~Variable_language_full_name_slash_() override = default;

Variable_language_full_name_slash_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_slash_;

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

struct Variable_language_full_name_underscore_ : public VariableScopes
{

static constexpr auto name = "language_full_name_underscore_";



Variable_language_full_name_underscore_() : VariableScopes()
{
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_underscore_;
}

virtual ~Variable_language_full_name_underscore_() override = default;

Variable_language_full_name_underscore_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::language_full_name_underscore_;

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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_angle_bracket_;
}

virtual ~Variable_left_angle_bracket_() override = default;

Variable_left_angle_bracket_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_angle_bracket_;

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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_bracket_;
}

virtual ~Variable_left_bracket_() override = default;

Variable_left_bracket_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_bracket_;

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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_curly_bracket_;
}

virtual ~Variable_left_curly_bracket_() override = default;

Variable_left_curly_bracket_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::left_curly_bracket_;

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

struct Variable_right_angle_bracket_ : public VariableScopes
{

static constexpr auto name = "right_angle_bracket_";



Variable_right_angle_bracket_() : VariableScopes()
{
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_angle_bracket_;
}

virtual ~Variable_right_angle_bracket_() override = default;

Variable_right_angle_bracket_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_angle_bracket_;

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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_bracket_;
}

virtual ~Variable_right_bracket_() override = default;

Variable_right_bracket_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_bracket_;

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
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_curly_bracket_;
}

virtual ~Variable_right_curly_bracket_() override = default;

Variable_right_curly_bracket_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::right_curly_bracket_;

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

struct Variable_unknown_reference_ : public VariableScopes
{

static constexpr auto name = "unknown_reference_";



Variable_unknown_reference_() : VariableScopes()
{
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::unknown_reference_;
}

virtual ~Variable_unknown_reference_() override = default;

Variable_unknown_reference_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::unknown_reference_;

}



Variable_unknown_reference_& operator=(const Variable_unknown_reference_& variable)
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

struct Variable_unknown_reference_implementation_ : public VariableScopes
{

static constexpr auto name = "unknown_reference_implementation_";



Variable_unknown_reference_implementation_() : VariableScopes()
{
	type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::unknown_reference_implementation_;
}

virtual ~Variable_unknown_reference_implementation_() override = default;

Variable_unknown_reference_implementation_(ArgumentCPPTemplate* argumentcpptemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::ArgumentCPPTemplate::Type::unknown_reference_implementation_;

}



Variable_unknown_reference_implementation_& operator=(const Variable_unknown_reference_implementation_& variable)
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
		// e.g. ArgumentCPPTemplate.member = "auto-generated";
		Variable_add_unknown_reference_* add_unknown_reference_ = new Variable_add_unknown_reference_();
Variable_file_* file_ = new Variable_file_();
Variable_language_full_name_* language_full_name_ = new Variable_language_full_name_();
Variable_language_full_name_slash_* language_full_name_slash_ = new Variable_language_full_name_slash_();
Variable_language_full_name_underscore_* language_full_name_underscore_ = new Variable_language_full_name_underscore_();
Variable_left_angle_bracket_* left_angle_bracket_ = new Variable_left_angle_bracket_();
Variable_left_bracket_* left_bracket_ = new Variable_left_bracket_();
Variable_left_curly_bracket_* left_curly_bracket_ = new Variable_left_curly_bracket_();
Variable_right_angle_bracket_* right_angle_bracket_ = new Variable_right_angle_bracket_();
Variable_right_bracket_* right_bracket_ = new Variable_right_bracket_();
Variable_right_curly_bracket_* right_curly_bracket_ = new Variable_right_curly_bracket_();
Variable_unknown_reference_* unknown_reference_ = new Variable_unknown_reference_();
Variable_unknown_reference_implementation_* unknown_reference_implementation_ = new Variable_unknown_reference_implementation_();


	public:
		ArgumentCPPTemplate()
		{
			*add_unknown_reference_ = Variable_add_unknown_reference_(this, std::vector<VariableBase*>({  }));
*file_ = Variable_file_(this, std::vector<VariableBase*>({  }));
*language_full_name_ = Variable_language_full_name_(this, std::vector<VariableBase*>({  }));
*language_full_name_slash_ = Variable_language_full_name_slash_(this, std::vector<VariableBase*>({  }));
*language_full_name_underscore_ = Variable_language_full_name_underscore_(this, std::vector<VariableBase*>({  }));
*left_angle_bracket_ = Variable_left_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("<") }));
*left_bracket_ = Variable_left_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("{") }));
*left_curly_bracket_ = Variable_left_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("(") }));
*right_angle_bracket_ = Variable_right_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(">") }));
*right_bracket_ = Variable_right_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("}") }));
*right_curly_bracket_ = Variable_right_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(")") }));
*unknown_reference_ = Variable_unknown_reference_(this, std::vector<VariableBase*>({  }));
*unknown_reference_implementation_ = Variable_unknown_reference_implementation_(this, std::vector<VariableBase*>({ GenerateVariable(unknown_reference_->This()), GenerateVariable("."), GenerateVariable("Set(::deamer::language::type::definition::object::special::Uninitialized<::deamer::language::type::definition::object::main::NonTerminal>(\"NonTerminal\", \""), GenerateVariable(unknown_reference_->This()), GenerateVariable("\", \"Unknown reference to (most likely) a NonTerminal!\"));") }));


			variables_.emplace_back(add_unknown_reference_);
variables_.emplace_back(file_);
variables_.emplace_back(language_full_name_);
variables_.emplace_back(language_full_name_slash_);
variables_.emplace_back(language_full_name_underscore_);
variables_.emplace_back(left_angle_bracket_);
variables_.emplace_back(left_bracket_);
variables_.emplace_back(left_curly_bracket_);
variables_.emplace_back(right_angle_bracket_);
variables_.emplace_back(right_bracket_);
variables_.emplace_back(right_curly_bracket_);
variables_.emplace_back(unknown_reference_);
variables_.emplace_back(unknown_reference_implementation_);

		}

		virtual ~ArgumentCPPTemplate()
		{
			for(auto* variable : variables_to_delete)
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
}

#endif // DLDL_FILETEMPLATE_ARGUMENTCPPTEMPLATE_h
