#ifndef DLDL_IDENTITY_AST_REFERENCE_ACCESS_H
#define DLDL_IDENTITY_AST_REFERENCE_ACCESS_H

#include "DLDL_IDENTITY/Ast/Relation/NodeEnumToType.h"
#include "DLDL_IDENTITY/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_IDENTITY/Ast/Relation/NodeIsInlined.h"

#include "DLDL_IDENTITY/Ast/Enum/Type.h"
#include "DLDL_IDENTITY/Ast/Node/program.h"
#include "DLDL_IDENTITY/Ast/Node/stmts.h"
#include "DLDL_IDENTITY/Ast/Node/stmt.h"
#include "DLDL_IDENTITY/Ast/Node/name_declaration.h"
#include "DLDL_IDENTITY/Ast/Node/NAME.h"
#include "DLDL_IDENTITY/Ast/Node/VALUE.h"
#include "DLDL_IDENTITY/Ast/Node/SYMBOLS.h"
#include "DLDL_IDENTITY/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_IDENTITY { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_IDENTITY::ast::Type T>
		void Get(std::vector<const ::DLDL_IDENTITY::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_IDENTITY::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_IDENTITY::ast::relation::NodeIsInlined(static_cast<::DLDL_IDENTITY::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_IDENTITY::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_IDENTITY::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_IDENTITY::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct Access<::DLDL_IDENTITY::ast::node::program>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::stmts>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::stmt>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::name_declaration>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::NAME>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::VALUE>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::SYMBOLS>;
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct Access<::DLDL_IDENTITY::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::program*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::program& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::program* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::program>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_IDENTITY::ast::node::stmts> stmts();


		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::stmts*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::stmts& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::stmts* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::stmts>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_IDENTITY::ast::node::stmts> stmts();
Access<::DLDL_IDENTITY::ast::node::stmt> stmt();


		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::stmts>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::stmt*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::stmt& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::stmt* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::stmt>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_IDENTITY::ast::node::name_declaration> name_declaration();


		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::name_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::name_declaration*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::name_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::name_declaration& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::name_declaration* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::name_declaration>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::name_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::name_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::name_declaration*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL_IDENTITY::ast::node::NAME> NAME();
Access<::DLDL_IDENTITY::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::name_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::NAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::NAME*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::NAME*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::NAME& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::NAME* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::NAME>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::NAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::NAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::NAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::NAME>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::VALUE*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::VALUE& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::VALUE* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::VALUE>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::VALUE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::VALUE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::VALUE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::SYMBOLS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::SYMBOLS*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::SYMBOLS*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::SYMBOLS& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::SYMBOLS* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::SYMBOLS>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::SYMBOLS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::SYMBOLS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::SYMBOLS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::SYMBOLS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_IDENTITY::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS*> ts;

	public:
		Access(std::vector<const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		Access(const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_IDENTITY::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		Access<::DLDL_IDENTITY::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL_IDENTITY::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};


	
		inline Access<::DLDL_IDENTITY::ast::node::stmts> Access<::DLDL_IDENTITY::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_IDENTITY::ast::node::stmts>(Get<::DLDL_IDENTITY::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL_IDENTITY::ast::node::stmts> Access<::DLDL_IDENTITY::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_IDENTITY::ast::node::stmts>(Get<::DLDL_IDENTITY::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL_IDENTITY::ast::node::stmt> Access<::DLDL_IDENTITY::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_IDENTITY::ast::node::stmt>(Get<::DLDL_IDENTITY::ast::Type::stmt>(ts));
		}

		inline Access<::DLDL_IDENTITY::ast::node::name_declaration> Access<::DLDL_IDENTITY::ast::node::stmt>::name_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_IDENTITY::ast::node::name_declaration>(Get<::DLDL_IDENTITY::ast::Type::name_declaration>(ts));
		}

		inline Access<::DLDL_IDENTITY::ast::node::NAME> Access<::DLDL_IDENTITY::ast::node::name_declaration>::NAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_IDENTITY::ast::node::NAME>(Get<::DLDL_IDENTITY::ast::Type::NAME>(ts));
		}

		inline Access<::DLDL_IDENTITY::ast::node::VALUE> Access<::DLDL_IDENTITY::ast::node::name_declaration>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_IDENTITY::ast::node::VALUE>(Get<::DLDL_IDENTITY::ast::Type::VALUE>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_IDENTITY::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_REFERENCE_ACCESS_H