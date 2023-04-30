#ifndef DLDL_OOPSYNTAX_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_OOPSYNTAX_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_OOPSYNTAX/Ast/Relation/NodeEnumToType.h"
#include "DLDL_OOPSYNTAX/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_OOPSYNTAX/Ast/Relation/NodeIsInlined.h"

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/program.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/stmt.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_69.h"
#include "DLDL_OOPSYNTAX/Ast/Node/production_rule_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/numbered_pr_convert.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_72.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_arrow__property__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_76.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_arrow__terminal_name__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_long_80.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_any_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/embedded_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/oop_type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/extended_property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/extended_terminal_access.h"
#include "DLDL_OOPSYNTAX/Ast/Node/terminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ARROW.h"
#include "DLDL_OOPSYNTAX/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/DOT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/EQ.h"
#include "DLDL_OOPSYNTAX/Ast/Node/STAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/VARNAME.h"
#include "DLDL_OOPSYNTAX/Ast/Node/NUMBER.h"
#include "DLDL_OOPSYNTAX/Ast/Node/COMMENT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ESCAPE_CHAR.h"


#include <vector>
#include <utility>

namespace DLDL_OOPSYNTAX { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_OOPSYNTAX::ast::Type T>
		void Get(std::vector<const ::DLDL_OOPSYNTAX::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_OOPSYNTAX::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_OOPSYNTAX::ast::relation::NodeIsInlined(static_cast<::DLDL_OOPSYNTAX::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_OOPSYNTAX::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_OOPSYNTAX::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_OOPSYNTAX::ast::relation::NodeEnumToType_t<T>*> foundNodes;

			for (const auto* const currentNode : currentNodes)
			{
				AccessBase::Get<T>(foundNodes, currentNode);
			}

			return foundNodes;
		}
	};

	/*!	\class AccessTemplateBase
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 *
	 *	\details This class contains the type dependent implementation of Access<T>.
	 *	Refrain from using this class, as there is no backwards compatibility
	 *	guarantee of this implementation class,
	 *	Use Access<T> instead, this is backwards compatible and offers different benefits.
	 *
	 *	\see Access
	 */
	template<typename T>
	struct AccessTemplateBase : public AccessBase
	{
		AccessTemplateBase() = delete;
		~AccessTemplateBase() = delete;
	};

	/*! \class Access
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 *
	 *	\details Type dispatcher for logic.
	 *
	 *	\see AccessTemplateBase
	 */
	template<typename T>
	struct Access : public AccessTemplateBase<T>
	{
		Access(std::vector<const T*> ts_) : AccessTemplateBase<T>(ts_)
		{
		}

		Access(const T& t) : AccessTemplateBase<T>(t)
		{
		}

		Access(const T* t) : AccessTemplateBase<T>(t)
		{
		}

		Access(const AccessTemplateBase<T>& rhs) : AccessTemplateBase<T>(rhs)
		{
		}

		Access() = default;
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR>;


	
	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt> stmt();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt> stmt();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion> nonterminal_conversion();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> ARROW();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> production_rule_conversion();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> deamerreserved_long_69();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name> nonterminal_name();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> oop_type();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> LEFT_BRACKET();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> RIGHT_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> production_rule_conversion();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> deamerreserved_long_69();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert> numbered_pr_convert();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> ARROW();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72> deamerreserved_long_72();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment> property_assignment();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> LEFT_BRACKET();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> RIGHT_BRACKET();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72> deamerreserved_long_72();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment> property_assignment();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::property_assignment*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::property_assignment*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::property_assignment& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::property_assignment* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::property_assignment*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::property_assignment*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment> direct_any_property_assignment();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment> embedded_assignment();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment> direct_property_assignment();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> deamerreserved_long_76();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__> deamerreserved_arrow__terminal_name__();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> deamerreserved_long_80();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__> deamerreserved_arrow__property__();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> oop_type();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> extended_property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> extended_terminal_access();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> terminal_name();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ> EQ();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> deamerreserved_long_76();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> extended_property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> deamerreserved_long_76();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> extended_property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> deamerreserved_long_80();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> extended_terminal_access();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> terminal_name();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> deamerreserved_long_80();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> extended_terminal_access();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> deamerreserved_long_76();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__> deamerreserved_arrow__terminal_name__();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> deamerreserved_long_80();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__> deamerreserved_arrow__property__();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> extended_property();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> extended_terminal_access();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> terminal_name();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ> EQ();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR> STAR();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> ARROW();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> production_rule_conversion();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> deamerreserved_long_69();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name> nonterminal_name();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> oop_type();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> LEFT_BRACKET();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> RIGHT_BRACKET();
AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::oop_type*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::oop_type*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::oop_type& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::oop_type* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::oop_type*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::oop_type*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::property*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::property*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::property& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::property* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::property*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::property*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_property*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_property*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::extended_property& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::extended_property* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_property*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_property*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_terminal_access*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_terminal_access*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::extended_terminal_access& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::extended_terminal_access* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_terminal_access*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::extended_terminal_access*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::terminal_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::terminal_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::terminal_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::terminal_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::terminal_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::terminal_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::ARROW*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::ARROW*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::ARROW& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::ARROW* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::ARROW*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::ARROW*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::DOT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::DOT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::DOT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::DOT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::DOT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::DOT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::EQ*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::EQ*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::EQ& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::EQ* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::EQ*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::EQ*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::STAR*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::STAR*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::STAR& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::STAR* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::STAR*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::STAR*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::COMMENT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::COMMENT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};


	
		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>(Get<::DLDL_OOPSYNTAX::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>(Get<::DLDL_OOPSYNTAX::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::stmt>::nonterminal_conversion()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>(Get<::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::ARROW()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>(Get<::DLDL_OOPSYNTAX::ast::Type::ARROW>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::production_rule_conversion()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>(Get<::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::deamerreserved_long_69()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::nonterminal_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>(Get<::DLDL_OOPSYNTAX::ast::Type::nonterminal_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::oop_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>(Get<::DLDL_OOPSYNTAX::ast::Type::oop_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::LEFT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>(Get<::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>::RIGHT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>(Get<::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>::production_rule_conversion()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>(Get<::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>::deamerreserved_long_69()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>::numbered_pr_convert()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>(Get<::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>::ARROW()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>(Get<::DLDL_OOPSYNTAX::ast::Type::ARROW>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>::deamerreserved_long_72()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>::property_assignment()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>(Get<::DLDL_OOPSYNTAX::ast::Type::property_assignment>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>::LEFT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>(Get<::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>::RIGHT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>(Get<::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::NUMBER>(Get<::DLDL_OOPSYNTAX::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>::deamerreserved_long_72()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_72>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_72>::property_assignment()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>(Get<::DLDL_OOPSYNTAX::ast::Type::property_assignment>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>::direct_any_property_assignment()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>(Get<::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>::embedded_assignment()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>(Get<::DLDL_OOPSYNTAX::ast::Type::embedded_assignment>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property_assignment>::direct_property_assignment()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>(Get<::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::deamerreserved_long_76()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::deamerreserved_arrow__terminal_name__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__terminal_name__>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::deamerreserved_long_80()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::deamerreserved_arrow__property__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__property__>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::oop_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>(Get<::DLDL_OOPSYNTAX::ast::Type::oop_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>(Get<::DLDL_OOPSYNTAX::ast::Type::property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::extended_property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::extended_terminal_access()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::terminal_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>(Get<::DLDL_OOPSYNTAX::ast::Type::terminal_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>::EQ()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ>(Get<::DLDL_OOPSYNTAX::ast::Type::EQ>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>::deamerreserved_long_76()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>::property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>(Get<::DLDL_OOPSYNTAX::ast::Type::property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>::extended_property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>::deamerreserved_long_76()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>::extended_property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>::deamerreserved_long_80()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>::extended_terminal_access()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>::terminal_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>(Get<::DLDL_OOPSYNTAX::ast::Type::terminal_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>::deamerreserved_long_80()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>::extended_terminal_access()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::deamerreserved_long_76()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_76>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_76>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::deamerreserved_arrow__terminal_name__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__terminal_name__>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__terminal_name__>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::deamerreserved_long_80()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_80>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_80>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::deamerreserved_arrow__property__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_arrow__property__>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_arrow__property__>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>(Get<::DLDL_OOPSYNTAX::ast::Type::property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::extended_property()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_property>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::extended_terminal_access()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>(Get<::DLDL_OOPSYNTAX::ast::Type::extended_terminal_access>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::terminal_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>(Get<::DLDL_OOPSYNTAX::ast::Type::terminal_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::EQ()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::EQ>(Get<::DLDL_OOPSYNTAX::ast::Type::EQ>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::STAR>(Get<::DLDL_OOPSYNTAX::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::ARROW()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::ARROW>(Get<::DLDL_OOPSYNTAX::ast::Type::ARROW>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::production_rule_conversion()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>(Get<::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::deamerreserved_long_69()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::deamerreserved_long_69>(Get<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_long_69>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::nonterminal_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>(Get<::DLDL_OOPSYNTAX::ast::Type::nonterminal_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::oop_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>(Get<::DLDL_OOPSYNTAX::ast::Type::oop_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::LEFT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>(Get<::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::RIGHT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>(Get<::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::DOT>(Get<::DLDL_OOPSYNTAX::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>(Get<::DLDL_OOPSYNTAX::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::oop_type>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>(Get<::DLDL_OOPSYNTAX::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::property>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>(Get<::DLDL_OOPSYNTAX::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_property>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>(Get<::DLDL_OOPSYNTAX::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::extended_terminal_access>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>(Get<::DLDL_OOPSYNTAX::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME> AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::terminal_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_OOPSYNTAX::ast::node::VARNAME>(Get<::DLDL_OOPSYNTAX::ast::Type::VARNAME>(ts));
		}


	/*!	\class Access_if
	 *
	 *	\brief Accesses the node if it is of the given type.
	 *
	 *	\note A lambda has to be supplied as second argument with paramater: "Access<T>".
	 */
	template<typename T>
	struct Access_if
	{
		const ::deamer::external::cpp::ast::Node* node;

		template<typename FunctionType>
		Access_if(const ::deamer::external::cpp::ast::Node* node_, FunctionType function) : node(node_)
		{
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_OOPSYNTAX::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_REFERENCE_ACCESSTEMPLATEBASE_H