#ifndef DLDL_ASSOCIATIVITY_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_ASSOCIATIVITY_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_ASSOCIATIVITY/Ast/Relation/NodeEnumToType.h"
#include "DLDL_ASSOCIATIVITY/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_ASSOCIATIVITY/Ast/Relation/NodeIsInlined.h"

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/program.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmts.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmt.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/ASSOCIATIVITY.h"


#include <vector>
#include <utility>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_ASSOCIATIVITY::ast::Type T>
		void Get(std::vector<const ::DLDL_ASSOCIATIVITY::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_ASSOCIATIVITY::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_ASSOCIATIVITY::ast::relation::NodeIsInlined(static_cast<::DLDL_ASSOCIATIVITY::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_ASSOCIATIVITY::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_ASSOCIATIVITY::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_ASSOCIATIVITY::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>;
	template<>
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY>;


	
	template<>
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts> stmts();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmts*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::stmts& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::stmts* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts> stmts();
AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY> ASSOCIATIVITY();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts> AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>(Get<::DLDL_ASSOCIATIVITY::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts> AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>(Get<::DLDL_ASSOCIATIVITY::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt> AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt>(Get<::DLDL_ASSOCIATIVITY::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY> AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::stmt>::ASSOCIATIVITY()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY>(Get<::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_ASSOCIATIVITY::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_REFERENCE_ACCESSTEMPLATEBASE_H