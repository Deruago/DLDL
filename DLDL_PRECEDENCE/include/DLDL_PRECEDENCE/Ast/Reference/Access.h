#ifndef DLDL_PRECEDENCE_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_PRECEDENCE_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_PRECEDENCE/Ast/Relation/NodeEnumToType.h"
#include "DLDL_PRECEDENCE/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_PRECEDENCE/Ast/Relation/NodeIsInlined.h"

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"
#include "DLDL_PRECEDENCE/Ast/Node/program.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmts.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmt.h"
#include "DLDL_PRECEDENCE/Ast/Node/localized_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/specific_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/terminal_one_or_more.h"
#include "DLDL_PRECEDENCE/Ast/Node/PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Node/NUMBER.h"
#include "DLDL_PRECEDENCE/Ast/Node/TERMINAL.h"
#include "DLDL_PRECEDENCE/Ast/Node/SYMBOLS.h"
#include "DLDL_PRECEDENCE/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_PRECEDENCE { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_PRECEDENCE::ast::Type T>
		void Get(std::vector<const ::DLDL_PRECEDENCE::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_PRECEDENCE::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_PRECEDENCE::ast::relation::NodeIsInlined(static_cast<::DLDL_PRECEDENCE::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_PRECEDENCE::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_PRECEDENCE::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_PRECEDENCE::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::SYMBOLS>;
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts> stmts();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::stmts*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::stmts& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::stmts* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts> stmts();
AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence> specific_precedence();
AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence> localized_precedence();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::localized_precedence*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::localized_precedence*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::localized_precedence& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::localized_precedence* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::localized_precedence*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::localized_precedence*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE> PRECEDENCE();
AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> terminal_one_or_more();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::specific_precedence*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::specific_precedence*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::specific_precedence& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::specific_precedence* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::specific_precedence*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::specific_precedence*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE> PRECEDENCE();
AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> terminal_one_or_more();
AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> terminal_one_or_more();
AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL> TERMINAL();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::TERMINAL*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::TERMINAL*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::TERMINAL& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::TERMINAL* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::TERMINAL*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::TERMINAL*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::SYMBOLS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::SYMBOLS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::SYMBOLS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::SYMBOLS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::SYMBOLS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::SYMBOLS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::SYMBOLS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::SYMBOLS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::SYMBOLS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::SYMBOLS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>(Get<::DLDL_PRECEDENCE::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>(Get<::DLDL_PRECEDENCE::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>(Get<::DLDL_PRECEDENCE::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>::specific_precedence()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>(Get<::DLDL_PRECEDENCE::ast::Type::specific_precedence>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::stmt>::localized_precedence()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>(Get<::DLDL_PRECEDENCE::ast::Type::localized_precedence>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>::PRECEDENCE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>(Get<::DLDL_PRECEDENCE::ast::Type::PRECEDENCE>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::localized_precedence>::terminal_one_or_more()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>(Get<::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>::PRECEDENCE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>(Get<::DLDL_PRECEDENCE::ast::Type::PRECEDENCE>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>::terminal_one_or_more()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>(Get<::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::specific_precedence>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::NUMBER>(Get<::DLDL_PRECEDENCE::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>::terminal_one_or_more()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>(Get<::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more>(ts));
		}

		inline AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL> AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>::TERMINAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_PRECEDENCE::ast::node::TERMINAL>(Get<::DLDL_PRECEDENCE::ast::Type::TERMINAL>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_PRECEDENCE::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_REFERENCE_ACCESSTEMPLATEBASE_H