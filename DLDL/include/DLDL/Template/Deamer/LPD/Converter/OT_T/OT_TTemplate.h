#ifndef DLDL_FILETEMPLATE_LPD_CONVERTER_OT_TTEMPLATE_h
#define DLDL_FILETEMPLATE_LPD_CONVERTER_OT_TTEMPLATE_h

#include <variant>
#include <vector>
#include <string>

namespace DLDL::filetemplate::lpd::converter
{

	/*!	\class OT_TTemplate
	 *
	 *	\brief Generates code for "OT_TTemplate"
	 *
	 *	\details This is generated by DST.
	 *	For more information visit: https://github.com/Deruago/DeamerStringTemplate
	 */
	class OT_TTemplate
	{
	public:
		enum class Type
{
Unknown,
Scope,

// User defined types
explicit_lpd_namespace_,
explicit_lpd_namespace_dispatch_,
file_,
ldo_implementation_,
ldo_include_,
ldo_name_,
left_angle_bracket_,
left_bracket_,
left_curly_bracket_,
loc_impl_,
loc_main_,
loc_tool_,
location_,
lpd_name_,
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


		static constexpr const char* ConvertEnumToName(::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type enumerationValue)
{
	switch(enumerationValue)
	{
	case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::explicit_lpd_namespace_:
{
	return "explicit_lpd_namespace";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::explicit_lpd_namespace_dispatch_:
{
	return "explicit_lpd_namespace_dispatch";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::file_:
{
	return "file";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_implementation_:
{
	return "ldo_implementation";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_include_:
{
	return "ldo_include";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_name_:
{
	return "ldo_name";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_angle_bracket_:
{
	return "left_angle_bracket";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_bracket_:
{
	return "left_bracket";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_curly_bracket_:
{
	return "left_curly_bracket";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_impl_:
{
	return "loc_impl";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_main_:
{
	return "loc_main";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_tool_:
{
	return "loc_tool";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::location_:
{
	return "location";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::lpd_name_:
{
	return "lpd_name";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_angle_bracket_:
{
	return "right_angle_bracket";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_bracket_:
{
	return "right_bracket";
}

case ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_curly_bracket_:
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

			::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Unknown;

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
			::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType scope_type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Unknown;
			bool isReserved = false;

			VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;
			}

			VariableScope(const char* text, ::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(text), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;
			}

			VariableScope(std::vector<VariableBase*> variable, ::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType scope_type_, bool isReserved_ = false) : VariableBase(variable), scope_type(scope_type_), isReserved(isReserved_)
			{
				type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;
			}
		};
		
		struct Variable_ReservedScope_Upper : public VariableScope
		{
			VariableBase* base;
			Variable_ReservedScope_Upper(VariableBase* base_)
			: VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Upper_, true),
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
			: VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Lower_, true),
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
			: VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Snake_, true),
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
			: VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Slash_, true),
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
			: VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::DoubleColon_, true),
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
			VariableBase* default_ = new VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Default_, true);
			VariableBase* upper_ = new Variable_ReservedScope_Upper(this);
			VariableBase* lower_ = new Variable_ReservedScope_Lower(this);
			
			VariableBase* snake_ = new Variable_ReservedScope_Snake(this);
			VariableBase* slash_ = new Variable_ReservedScope_Slash(this);
			VariableBase* double_colon_ = new Variable_ReservedScope_DoubleColon(this);
			
			VariableBase* variable_field_ = new VariableScope(::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Variable_Field_, true);
			VariableBase* variable_field_separator_ = new VariableScope("\n", ::DLDL::filetemplate::lpd::converter::OT_TTemplate::ScopeType::Variable_Field_Separator_, true);

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
		
struct Variable_explicit_lpd_namespace_ : public VariableScopes
{

static constexpr auto name = "explicit_lpd_namespace_";



Variable_explicit_lpd_namespace_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::explicit_lpd_namespace_;
}

virtual ~Variable_explicit_lpd_namespace_() override = default;

Variable_explicit_lpd_namespace_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::explicit_lpd_namespace_;

}



Variable_explicit_lpd_namespace_& operator=(const Variable_explicit_lpd_namespace_& variable)
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

struct Variable_explicit_lpd_namespace_dispatch_ : public VariableScopes
{

static constexpr auto name = "explicit_lpd_namespace_dispatch_";



Variable_explicit_lpd_namespace_dispatch_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::explicit_lpd_namespace_dispatch_;
}

virtual ~Variable_explicit_lpd_namespace_dispatch_() override = default;

Variable_explicit_lpd_namespace_dispatch_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::explicit_lpd_namespace_dispatch_;

}



Variable_explicit_lpd_namespace_dispatch_& operator=(const Variable_explicit_lpd_namespace_dispatch_& variable)
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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::file_;
}

virtual ~Variable_file_() override = default;

Variable_file_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::file_;
*static_cast<VariableBase*>(Content_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("/*\n * This program is free software; you can redistribute it and/or\n * modify it under the terms of the GNU General Public License\n * as published by the Free Software Foundation; either version 3\n * of the License, or (at your option) any later version"), GenerateVariable("."), GenerateVariable("\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE"), GenerateVariable("."), GenerateVariable("  See the\n * GNU General Public License for more details"), GenerateVariable("."), GenerateVariable("\n *\n * You should have received a copy of the GNU General Public License\n * along with this program; if not, write to the Free Software Foundation,\n * Inc"), GenerateVariable("."), GenerateVariable(", 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA"), GenerateVariable("."), GenerateVariable("\n */\n/*\n * Part of the DeamerProject"), GenerateVariable("."), GenerateVariable("\n * For more information go to: https://github"), GenerateVariable("."), GenerateVariable("com/Deruago/theDeamerProject\n */\n\n#ifndef DEAMER_LANGUAGE_CONVERTOR_DEFINITION_OBJECTENUMTOTYPE_H\n#define DEAMER_LANGUAGE_CONVERTOR_DEFINITION_OBJECTENUMTOTYPE_H\n\n"), GenerateVariable(ot_ttemplate_->ldo_include_->Variable_Field()), GenerateVariable("\n#include \"Deamer/Language/Type/Definition/Object/Type"), GenerateVariable("."), GenerateVariable("h\"\n\nnamespace deamer::language::convertor::definition\n"), GenerateVariable("{"), GenerateVariable("\n\t/*! "), GenerateVariable("\\"), GenerateVariable("class ObjectEnumToType\n\t *\n\t *\t"), GenerateVariable("\\"), GenerateVariable("brief This class is used to convert object enum types into typenames\n\t *\n\t *\t"), GenerateVariable("\\"), GenerateVariable("tparam T The enum value that needs to be converted to a typename\n\t *\n\t *\t"), GenerateVariable("\\"), GenerateVariable("see deamer::language::convertor::definition::ObjectTypeToEnum\n\t */\n\ttemplate<type::definition::object::Type T>\n\tclass ObjectEnumToType\n\t"), GenerateVariable("{"), GenerateVariable("\n\tpublic:\n\t\tconstexpr static auto value = type::definition::object::Type::Unknown;\n\t\tusing type = void;\n\t"), GenerateVariable("}"), GenerateVariable(";\n\n"), GenerateVariable(ot_ttemplate_->ldo_implementation_->Variable_Field()), GenerateVariable("\n\n\ttemplate<type::definition::object::Type T>\n\tusing ObjectEnumToType_t = typename ObjectEnumToType<T>::type;\n"), GenerateVariable("}"), GenerateVariable("\n\n#endif // DEAMER_LANGUAGE_CONVERTOR_DEFINITION_OBJECTENUMTOTYPE_H") }));
Content_->type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;

*static_cast<VariableBase*>(Class_postfix_) = VariableBase(std::vector<VariableBase*>({  }));
Class_postfix_->type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;

*static_cast<VariableBase*>(Extension_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("h") }));
Extension_->type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;

*static_cast<VariableBase*>(File_name_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("OT_T") }));
File_name_->type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;

*static_cast<VariableBase*>(Namespace_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("DLDL::filetemplate::lpd::converter") }));
Namespace_->type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;

*static_cast<VariableBase*>(Target_language_) = VariableBase(std::vector<VariableBase*>({ GenerateVariable("C++") }));
Target_language_->type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::Scope;


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

struct Variable_ldo_implementation_ : public VariableScopes
{

static constexpr auto name = "ldo_implementation_";



Variable_ldo_implementation_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_implementation_;
}

virtual ~Variable_ldo_implementation_() override = default;

Variable_ldo_implementation_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_implementation_;

}



Variable_ldo_implementation_& operator=(const Variable_ldo_implementation_& variable)
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

struct Variable_ldo_include_ : public VariableScopes
{

static constexpr auto name = "ldo_include_";



Variable_ldo_include_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_include_;
}

virtual ~Variable_ldo_include_() override = default;

Variable_ldo_include_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_include_;

}



Variable_ldo_include_& operator=(const Variable_ldo_include_& variable)
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

struct Variable_ldo_name_ : public VariableScopes
{

static constexpr auto name = "ldo_name_";



Variable_ldo_name_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_name_;
}

virtual ~Variable_ldo_name_() override = default;

Variable_ldo_name_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::ldo_name_;

}



Variable_ldo_name_& operator=(const Variable_ldo_name_& variable)
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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_angle_bracket_;
}

virtual ~Variable_left_angle_bracket_() override = default;

Variable_left_angle_bracket_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_angle_bracket_;

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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_bracket_;
}

virtual ~Variable_left_bracket_() override = default;

Variable_left_bracket_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_bracket_;

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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_curly_bracket_;
}

virtual ~Variable_left_curly_bracket_() override = default;

Variable_left_curly_bracket_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::left_curly_bracket_;

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

struct Variable_loc_impl_ : public VariableScopes
{

static constexpr auto name = "loc_impl_";



Variable_loc_impl_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_impl_;
}

virtual ~Variable_loc_impl_() override = default;

Variable_loc_impl_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_impl_;

}



Variable_loc_impl_& operator=(const Variable_loc_impl_& variable)
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

struct Variable_loc_main_ : public VariableScopes
{

static constexpr auto name = "loc_main_";



Variable_loc_main_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_main_;
}

virtual ~Variable_loc_main_() override = default;

Variable_loc_main_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_main_;

}



Variable_loc_main_& operator=(const Variable_loc_main_& variable)
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

struct Variable_loc_tool_ : public VariableScopes
{

static constexpr auto name = "loc_tool_";



Variable_loc_tool_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_tool_;
}

virtual ~Variable_loc_tool_() override = default;

Variable_loc_tool_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::loc_tool_;

}



Variable_loc_tool_& operator=(const Variable_loc_tool_& variable)
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

struct Variable_location_ : public VariableScopes
{

static constexpr auto name = "location_";



Variable_location_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::location_;
}

virtual ~Variable_location_() override = default;

Variable_location_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::location_;

}



Variable_location_& operator=(const Variable_location_& variable)
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

struct Variable_lpd_name_ : public VariableScopes
{

static constexpr auto name = "lpd_name_";



Variable_lpd_name_() : VariableScopes()
{
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::lpd_name_;
}

virtual ~Variable_lpd_name_() override = default;

Variable_lpd_name_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::lpd_name_;

}



Variable_lpd_name_& operator=(const Variable_lpd_name_& variable)
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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_angle_bracket_;
}

virtual ~Variable_right_angle_bracket_() override = default;

Variable_right_angle_bracket_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_angle_bracket_;

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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_bracket_;
}

virtual ~Variable_right_bracket_() override = default;

Variable_right_bracket_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_bracket_;

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
	type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_curly_bracket_;
}

virtual ~Variable_right_curly_bracket_() override = default;

Variable_right_curly_bracket_(OT_TTemplate* ot_ttemplate_, const std::vector<VariableBase*>& variables) : VariableScopes(variables)
{
type = ::DLDL::filetemplate::lpd::converter::OT_TTemplate::Type::right_curly_bracket_;

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
		// e.g. OT_TTemplate.member = "auto-generated";
		Variable_explicit_lpd_namespace_* explicit_lpd_namespace_ = new Variable_explicit_lpd_namespace_();
Variable_explicit_lpd_namespace_dispatch_* explicit_lpd_namespace_dispatch_ = new Variable_explicit_lpd_namespace_dispatch_();
Variable_file_* file_ = new Variable_file_();
Variable_ldo_implementation_* ldo_implementation_ = new Variable_ldo_implementation_();
Variable_ldo_include_* ldo_include_ = new Variable_ldo_include_();
Variable_ldo_name_* ldo_name_ = new Variable_ldo_name_();
Variable_left_angle_bracket_* left_angle_bracket_ = new Variable_left_angle_bracket_();
Variable_left_bracket_* left_bracket_ = new Variable_left_bracket_();
Variable_left_curly_bracket_* left_curly_bracket_ = new Variable_left_curly_bracket_();
Variable_loc_impl_* loc_impl_ = new Variable_loc_impl_();
Variable_loc_main_* loc_main_ = new Variable_loc_main_();
Variable_loc_tool_* loc_tool_ = new Variable_loc_tool_();
Variable_location_* location_ = new Variable_location_();
Variable_lpd_name_* lpd_name_ = new Variable_lpd_name_();
Variable_right_angle_bracket_* right_angle_bracket_ = new Variable_right_angle_bracket_();
Variable_right_bracket_* right_bracket_ = new Variable_right_bracket_();
Variable_right_curly_bracket_* right_curly_bracket_ = new Variable_right_curly_bracket_();


	public:
		OT_TTemplate()
		{
			*explicit_lpd_namespace_ = Variable_explicit_lpd_namespace_(this, std::vector<VariableBase*>({ GenerateVariable(explicit_lpd_namespace_dispatch_->This()) }));
*explicit_lpd_namespace_dispatch_ = Variable_explicit_lpd_namespace_dispatch_(this, std::vector<VariableBase*>({ GenerateVariable("::"), GenerateVariable(lpd_name_->Lower()) }));
*file_ = Variable_file_(this, std::vector<VariableBase*>({  }));
*ldo_implementation_ = Variable_ldo_implementation_(this, std::vector<VariableBase*>({ GenerateVariable("\n\t/*!\n\t *\t"), GenerateVariable("\\"), GenerateVariable("see deamer::language::convertor::definition::ObjectEnumToType\n\t */\n\ttemplate<>\n\tclass ObjectEnumToType<type::definition::object::Type::"), GenerateVariable(ldo_name_->This()), GenerateVariable(">\n\t"), GenerateVariable("{"), GenerateVariable("\n\tpublic:\n\t\tconstexpr static auto value = type::definition::object::Type::"), GenerateVariable(ldo_name_->This()), GenerateVariable(";\n\t\tusing type = type::definition::object::"), GenerateVariable(location_->This()), GenerateVariable(explicit_lpd_namespace_->This()), GenerateVariable("::"), GenerateVariable(ldo_name_->This()), GenerateVariable(";\n\t"), GenerateVariable("}"), GenerateVariable(";\n") }));
*ldo_include_ = Variable_ldo_include_(this, std::vector<VariableBase*>({ GenerateVariable("#include \"Deamer/Language/Type/Definition/Object/"), GenerateVariable(loc_impl_->This()), GenerateVariable("/"), GenerateVariable(lpd_name_->This()), GenerateVariable("/"), GenerateVariable(ldo_name_->This()), GenerateVariable("."), GenerateVariable("h\"") }));
*ldo_name_ = Variable_ldo_name_(this, std::vector<VariableBase*>({  }));
*left_angle_bracket_ = Variable_left_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("<") }));
*left_bracket_ = Variable_left_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("{") }));
*left_curly_bracket_ = Variable_left_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("(") }));
*loc_impl_ = Variable_loc_impl_(this, std::vector<VariableBase*>({ GenerateVariable(loc_main_->This()) }));
*loc_main_ = Variable_loc_main_(this, std::vector<VariableBase*>({ GenerateVariable("Main") }));
*loc_tool_ = Variable_loc_tool_(this, std::vector<VariableBase*>({ GenerateVariable("Tool") }));
*location_ = Variable_location_(this, std::vector<VariableBase*>({ GenerateVariable(loc_impl_->Lower()) }));
*lpd_name_ = Variable_lpd_name_(this, std::vector<VariableBase*>({  }));
*right_angle_bracket_ = Variable_right_angle_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(">") }));
*right_bracket_ = Variable_right_bracket_(this, std::vector<VariableBase*>({ GenerateVariable("}") }));
*right_curly_bracket_ = Variable_right_curly_bracket_(this, std::vector<VariableBase*>({ GenerateVariable(")") }));


			variables_.emplace_back(explicit_lpd_namespace_);
variables_.emplace_back(explicit_lpd_namespace_dispatch_);
variables_.emplace_back(file_);
variables_.emplace_back(ldo_implementation_);
variables_.emplace_back(ldo_include_);
variables_.emplace_back(ldo_name_);
variables_.emplace_back(left_angle_bracket_);
variables_.emplace_back(left_bracket_);
variables_.emplace_back(left_curly_bracket_);
variables_.emplace_back(loc_impl_);
variables_.emplace_back(loc_main_);
variables_.emplace_back(loc_tool_);
variables_.emplace_back(location_);
variables_.emplace_back(lpd_name_);
variables_.emplace_back(right_angle_bracket_);
variables_.emplace_back(right_bracket_);
variables_.emplace_back(right_curly_bracket_);

		}

		virtual ~OT_TTemplate()
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

#endif // DLDL_FILETEMPLATE_LPD_CONVERTER_OT_TTEMPLATE_h
