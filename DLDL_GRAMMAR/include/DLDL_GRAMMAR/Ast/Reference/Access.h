#ifndef DLDL_GRAMMAR_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_GRAMMAR_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_GRAMMAR/Ast/Relation/NodeEnumToType.h"
#include "DLDL_GRAMMAR/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_GRAMMAR/Ast/Relation/NodeIsInlined.h"

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"
#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_GRAMMAR { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_GRAMMAR::ast::Type T>
		void Get(std::vector<const ::DLDL_GRAMMAR::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_GRAMMAR::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_GRAMMAR::ast::relation::NodeIsInlined(static_cast<::DLDL_GRAMMAR::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_GRAMMAR::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_GRAMMAR::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_GRAMMAR::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE>;
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts> stmts();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::stmts*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::stmts& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::stmts* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts> stmts();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration> abstraction_declaration();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition> definition();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::abstraction_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::abstraction_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction> abstraction();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL> NONTERMINAL();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION> START_ABSTRACTION();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION> GROUP_ABSTRACTION();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION> INLINE_ABSTRACTION();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION> INLINE_GROUP_ABSTRACTION();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION> UNKNOWN_ABSTRACTION();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::definition*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::definition*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::definition& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::definition* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::definition*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::definition*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction> abstraction();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules> production_rules();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL> NONTERMINAL();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::production_rules*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::production_rules*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::production_rules& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::production_rules* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::production_rules*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::production_rules*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules> production_rules();
AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE> PRODUCTION_RULE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::NONTERMINAL*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::NONTERMINAL*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::NONTERMINAL& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::NONTERMINAL* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::NONTERMINAL*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::NONTERMINAL*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>(Get<::DLDL_GRAMMAR::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>(Get<::DLDL_GRAMMAR::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>(Get<::DLDL_GRAMMAR::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>::abstraction_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>(Get<::DLDL_GRAMMAR::ast::Type::abstraction_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::stmt>::definition()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>(Get<::DLDL_GRAMMAR::ast::Type::definition>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>::abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>(Get<::DLDL_GRAMMAR::ast::Type::abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction_declaration>::NONTERMINAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL>(Get<::DLDL_GRAMMAR::ast::Type::NONTERMINAL>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>::START_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION>(Get<::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>::GROUP_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION>(Get<::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>::INLINE_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION>(Get<::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>::INLINE_GROUP_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION>(Get<::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>::UNKNOWN_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION>(Get<::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>::abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::abstraction>(Get<::DLDL_GRAMMAR::ast::Type::abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>::production_rules()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>(Get<::DLDL_GRAMMAR::ast::Type::production_rules>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::definition>::NONTERMINAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::NONTERMINAL>(Get<::DLDL_GRAMMAR::ast::Type::NONTERMINAL>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>::production_rules()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>(Get<::DLDL_GRAMMAR::ast::Type::production_rules>(ts));
		}

		inline AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE> AccessTemplateBase<::DLDL_GRAMMAR::ast::node::production_rules>::PRODUCTION_RULE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE>(Get<::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_GRAMMAR::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_REFERENCE_ACCESSTEMPLATEBASE_H