#ifndef DLDL_LEXER_AST_REFERENCE_ACCESS_H
#define DLDL_LEXER_AST_REFERENCE_ACCESS_H

#include "DLDL_LEXER/Ast/Relation/NodeEnumToType.h"
#include "DLDL_LEXER/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_LEXER/Ast/Relation/NodeIsInlined.h"

#include "DLDL_LEXER/Ast/Enum/Type.h"
#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"


#include <vector>
#include <utility>

namespace DLDL_LEXER { namespace ast { namespace relation { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_LEXER::ast::Type T>
		void Get(std::vector<const ::DLDL_LEXER::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_LEXER::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_LEXER::ast::relation::NodeIsInlined(static_cast<::DLDL_LEXER::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_LEXER::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_LEXER::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_LEXER::ast::relation::NodeEnumToType_t<T>*> foundNodes;

			for (const auto* const currentNode : currentNodes)
			{
				AccessBase::Get<T>(foundNodes, currentNode);
			}

			return foundNodes;
		}
	};

	/*!	\class Access
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 */
	template<typename T>
	struct Access : public AccessBase
	{
		Access() = delete;
		~Access() = delete;
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::program>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::stmts>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::stmt>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::tokendeclaration>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::abstraction>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::TERMINAL>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::REGEX>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::ESCAPE_CHARS>;
	template<>
	struct Access<::DLDL_LEXER::ast::node::COMMENT>;


	
	template<>
	struct Access<::DLDL_LEXER::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::program*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::program& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::program* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::program>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_LEXER::ast::node::stmts> stmts();


		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::stmts*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::stmts& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::stmts* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::stmts>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_LEXER::ast::node::stmts> stmts();
Access<::DLDL_LEXER::ast::node::stmt> stmt();


		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::stmts>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::stmt*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::stmt& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::stmt* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::stmt>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_LEXER::ast::node::tokendeclaration> tokendeclaration();


		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::tokendeclaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::tokendeclaration*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::tokendeclaration*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::tokendeclaration& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::tokendeclaration* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::tokendeclaration>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::tokendeclaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::tokendeclaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::tokendeclaration*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_LEXER::ast::node::abstraction> abstraction();
Access<::DLDL_LEXER::ast::node::TERMINAL> TERMINAL();
Access<::DLDL_LEXER::ast::node::REGEX> REGEX();


		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::tokendeclaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::abstraction*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::abstraction& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::abstraction* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::abstraction>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::abstraction*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION> DELETE_ABSTRACTION();
Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION> IGNORE_ABSTRACTION();
Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION> NOVALUE_ABSTRACTION();
Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION> CRASH_ABSTRACTION();
Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION> STANDARD_ABSTRACTION();
Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION> UNKNOWN_ABSTRACTION();


		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::abstraction>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::TERMINAL> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::TERMINAL*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::TERMINAL*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::TERMINAL& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::TERMINAL* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::TERMINAL>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::TERMINAL>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::TERMINAL*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::TERMINAL*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::TERMINAL>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::REGEX> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::REGEX*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::REGEX*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::REGEX& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::REGEX* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::REGEX>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::REGEX>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::REGEX*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::REGEX*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::REGEX>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::ESCAPE_CHARS*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_LEXER::ast::node::COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LEXER::ast::node::COMMENT*> ts;

	public:
		Access(std::vector<const ::DLDL_LEXER::ast::node::COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_LEXER::ast::node::COMMENT& t) : ts({&t})
		{
		}

		Access(const ::DLDL_LEXER::ast::node::COMMENT* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_LEXER::ast::node::COMMENT>& operator[](::std::size_t index)
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

		Access<::DLDL_LEXER::ast::node::COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LEXER::ast::node::COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LEXER::ast::node::COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_LEXER::ast::node::COMMENT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};


	
		inline Access<::DLDL_LEXER::ast::node::stmts> Access<::DLDL_LEXER::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::stmts>(Get<::DLDL_LEXER::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::stmts> Access<::DLDL_LEXER::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::stmts>(Get<::DLDL_LEXER::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::stmt> Access<::DLDL_LEXER::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::stmt>(Get<::DLDL_LEXER::ast::Type::stmt>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::tokendeclaration> Access<::DLDL_LEXER::ast::node::stmt>::tokendeclaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::tokendeclaration>(Get<::DLDL_LEXER::ast::Type::tokendeclaration>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::abstraction> Access<::DLDL_LEXER::ast::node::tokendeclaration>::abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::abstraction>(Get<::DLDL_LEXER::ast::Type::abstraction>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::TERMINAL> Access<::DLDL_LEXER::ast::node::tokendeclaration>::TERMINAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::TERMINAL>(Get<::DLDL_LEXER::ast::Type::TERMINAL>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::REGEX> Access<::DLDL_LEXER::ast::node::tokendeclaration>::REGEX()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::REGEX>(Get<::DLDL_LEXER::ast::Type::REGEX>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION> Access<::DLDL_LEXER::ast::node::abstraction>::DELETE_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION>(Get<::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION> Access<::DLDL_LEXER::ast::node::abstraction>::IGNORE_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION>(Get<::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION> Access<::DLDL_LEXER::ast::node::abstraction>::NOVALUE_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION>(Get<::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION> Access<::DLDL_LEXER::ast::node::abstraction>::CRASH_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION>(Get<::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION> Access<::DLDL_LEXER::ast::node::abstraction>::STANDARD_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION>(Get<::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION>(ts));
		}

		inline Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION> Access<::DLDL_LEXER::ast::node::abstraction>::UNKNOWN_ABSTRACTION()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION>(Get<::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_LEXER::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_LEXER_AST_REFERENCE_ACCESS_H