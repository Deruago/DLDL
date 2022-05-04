#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Relation/NodeEnumToType.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Relation/NodeIsInlined.h"

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ENDING_USELESS_SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type T>
		void Get(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeIsInlined(static_cast<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> stmts();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt> stmt();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> stmts();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group> nested_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group> optional_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group> zero_or_more_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group> one_or_more_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group> or_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group> min_max_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group> extension_group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS> MINUS();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> stmts();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS> LEFT_PARANTHESIS();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS> RIGHT_PARANTHESIS();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> stmts();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK> QUESTION_MARK();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR> STAR();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS> PLUS();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH> VERTICAL_SLASH();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET> LEFT_BRACKET();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET> RIGHT_BRACKET();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR> STAR();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS> PLUS();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> group();
AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW> ARROW();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::nested_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::optional_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::zero_or_more_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::one_or_more_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::or_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::min_max_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::extension_group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::MINUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>::LEFT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>::RIGHT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>::QUESTION_MARK()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>::PLUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>::VERTICAL_SLASH()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>::LEFT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>::RIGHT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>::PLUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW> AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>::ARROW()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW>(Get<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_REFERENCE_ACCESSTEMPLATEBASE_H