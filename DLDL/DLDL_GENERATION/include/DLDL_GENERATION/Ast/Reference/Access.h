#ifndef DLDL_GENERATION_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_GENERATION_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_GENERATION/Ast/Relation/NodeEnumToType.h"
#include "DLDL_GENERATION/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_GENERATION/Ast/Relation/NodeIsInlined.h"

#include "DLDL_GENERATION/Ast/Enum/Type.h"
#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"
#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_GENERATION { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_GENERATION::ast::Type T>
		void Get(std::vector<const ::DLDL_GENERATION::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_GENERATION::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_GENERATION::ast::relation::NodeIsInlined(static_cast<::DLDL_GENERATION::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_GENERATION::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_GENERATION::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_GENERATION::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::type>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::SYMBOLS>;
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts> stmts();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::stmts*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::stmts& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::stmts* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::stmts*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::stmts*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts> stmts();
AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration> generate_declaration();
AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration> integrate_declaration();
AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration> argument_declaration();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::generate_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::generate_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::generate_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::generate_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::generate_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::generate_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE> GENERATE();
AccessTemplateBase<::DLDL_GENERATION::ast::node::type> type();
AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> tool();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::integrate_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::integrate_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::integrate_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::integrate_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::integrate_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::integrate_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> tool();
AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE> INTEGRATE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::argument_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::argument_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::argument_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::argument_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::argument_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::argument_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> tool();
AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data> argument_data();
AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT> ARGUMENT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::type> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::type*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::type*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::type& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::type* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::type>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::type>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::type*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::type*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::type>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::tool*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::tool*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::tool& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::tool* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::tool*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::tool*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::argument_data*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::argument_data*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::argument_data& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::argument_data* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::argument_data*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::argument_data*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data> argument_data();
AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::GENERATE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::GENERATE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::GENERATE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::GENERATE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::GENERATE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::GENERATE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::INTEGRATE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::INTEGRATE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::INTEGRATE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::INTEGRATE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::INTEGRATE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::INTEGRATE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::ARGUMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::ARGUMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::ARGUMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::ARGUMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::ARGUMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::ARGUMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::VALUE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::VALUE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::VALUE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::VALUE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::VALUE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::SYMBOLS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::SYMBOLS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::SYMBOLS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::SYMBOLS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::SYMBOLS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::SYMBOLS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::SYMBOLS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::SYMBOLS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::SYMBOLS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::SYMBOLS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_GENERATION::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts> AccessTemplateBase<::DLDL_GENERATION::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>(Get<::DLDL_GENERATION::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts> AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>(Get<::DLDL_GENERATION::ast::Type::stmts>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt> AccessTemplateBase<::DLDL_GENERATION::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>(Get<::DLDL_GENERATION::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration> AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>::generate_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>(Get<::DLDL_GENERATION::ast::Type::generate_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration> AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>::integrate_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>(Get<::DLDL_GENERATION::ast::Type::integrate_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration> AccessTemplateBase<::DLDL_GENERATION::ast::node::stmt>::argument_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>(Get<::DLDL_GENERATION::ast::Type::argument_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE> AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>::GENERATE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::GENERATE>(Get<::DLDL_GENERATION::ast::Type::GENERATE>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::type> AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>::type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::type>(Get<::DLDL_GENERATION::ast::Type::type>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> AccessTemplateBase<::DLDL_GENERATION::ast::node::generate_declaration>::tool()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>(Get<::DLDL_GENERATION::ast::Type::tool>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>::tool()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>(Get<::DLDL_GENERATION::ast::Type::tool>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE> AccessTemplateBase<::DLDL_GENERATION::ast::node::integrate_declaration>::INTEGRATE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::INTEGRATE>(Get<::DLDL_GENERATION::ast::Type::INTEGRATE>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::tool> AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>::tool()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>(Get<::DLDL_GENERATION::ast::Type::tool>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data> AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>::argument_data()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>(Get<::DLDL_GENERATION::ast::Type::argument_data>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT> AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_declaration>::ARGUMENT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::ARGUMENT>(Get<::DLDL_GENERATION::ast::Type::ARGUMENT>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> AccessTemplateBase<::DLDL_GENERATION::ast::node::type>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>(Get<::DLDL_GENERATION::ast::Type::VALUE>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> AccessTemplateBase<::DLDL_GENERATION::ast::node::tool>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>(Get<::DLDL_GENERATION::ast::Type::VALUE>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data> AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>::argument_data()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>(Get<::DLDL_GENERATION::ast::Type::argument_data>(ts));
		}

		inline AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE> AccessTemplateBase<::DLDL_GENERATION::ast::node::argument_data>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_GENERATION::ast::node::VALUE>(Get<::DLDL_GENERATION::ast::Type::VALUE>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_GENERATION::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_GENERATION_AST_REFERENCE_ACCESSTEMPLATEBASE_H