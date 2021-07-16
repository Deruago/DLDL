#ifndef DLDL_AST_REFERENCE_ACCESS_H
#define DLDL_AST_REFERENCE_ACCESS_H

#include "DLDL/Ast/Relation/NodeEnumToType.h"
#include "DLDL/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL/Ast/Relation/NodeIsInlined.h"

#include "DLDL/Ast/Enum/Type.h"
#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"
#include "DLDL/Ast/Node/ANY.h"


#include <vector>
#include <utility>

namespace DLDL { namespace ast { namespace relation { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL::ast::Type T>
		void Get(std::vector<const ::DLDL::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL::ast::relation::NodeIsInlined(static_cast<::DLDL::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL::ast::Type T, typename Q>
		inline std::vector<const ::DLDL::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct Access<::DLDL::ast::node::program>;
	template<>
	struct Access<::DLDL::ast::node::stmts>;
	template<>
	struct Access<::DLDL::ast::node::stmt>;
	template<>
	struct Access<::DLDL::ast::node::ANY>;


	
	template<>
	struct Access<::DLDL::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL::ast::node::program*> ts;

	public:
		Access(std::vector<const ::DLDL::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL::ast::node::program& t) : ts({&t})
		{
		}

		Access(const ::DLDL::ast::node::program* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL::ast::node::program>& operator[](::std::size_t index)
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

		Access<::DLDL::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL::ast::node::stmts> stmts();


		template<typename FunctionType>
		Access<::DLDL::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL::ast::node::stmts*> ts;

	public:
		Access(std::vector<const ::DLDL::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL::ast::node::stmts& t) : ts({&t})
		{
		}

		Access(const ::DLDL::ast::node::stmts* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL::ast::node::stmts>& operator[](::std::size_t index)
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

		Access<::DLDL::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL::ast::node::stmts> stmts();
Access<::DLDL::ast::node::stmt> stmt();


		template<typename FunctionType>
		Access<::DLDL::ast::node::stmts>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL::ast::node::stmt*> ts;

	public:
		Access(std::vector<const ::DLDL::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL::ast::node::stmt& t) : ts({&t})
		{
		}

		Access(const ::DLDL::ast::node::stmt* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL::ast::node::stmt>& operator[](::std::size_t index)
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

		Access<::DLDL::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		Access<::DLDL::ast::node::ANY> ANY();


		template<typename FunctionType>
		Access<::DLDL::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL::ast::node::ANY> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL::ast::node::ANY*> ts;

	public:
		Access(std::vector<const ::DLDL::ast::node::ANY*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL::ast::node::ANY& t) : ts({&t})
		{
		}

		Access(const ::DLDL::ast::node::ANY* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL::ast::node::ANY>& operator[](::std::size_t index)
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

		Access<::DLDL::ast::node::ANY>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL::ast::node::ANY*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL::ast::node::ANY*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		Access<::DLDL::ast::node::ANY>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};


	
		inline Access<::DLDL::ast::node::stmts> Access<::DLDL::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL::ast::node::stmts>(Get<::DLDL::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL::ast::node::stmts> Access<::DLDL::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL::ast::node::stmts>(Get<::DLDL::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL::ast::node::stmt> Access<::DLDL::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL::ast::node::stmt>(Get<::DLDL::ast::Type::stmt>(ts));
		}

		inline Access<::DLDL::ast::node::ANY> Access<::DLDL::ast::node::stmt>::ANY()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL::ast::node::ANY>(Get<::DLDL::ast::Type::ANY>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_AST_REFERENCE_ACCESS_H