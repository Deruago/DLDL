#ifndef DLDL_GENERATION_AST_REFERENCE_ACCESS_H
#define DLDL_GENERATION_AST_REFERENCE_ACCESS_H

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

namespace DLDL_GENERATION { namespace ast { namespace relation { 

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
	struct Access<::DLDL_GENERATION::ast::node::program>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::stmts>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::stmt>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::generate_declaration>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::integrate_declaration>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::argument_declaration>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::type>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::tool>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::argument_data>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::GENERATE>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::INTEGRATE>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::ARGUMENT>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::VALUE>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::SYMBOLS>;
	template<>
	struct Access<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct Access<::DLDL_GENERATION::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::program*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::program& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::program* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::program>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::stmts> stmts();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::stmts> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::stmts*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::stmts*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::stmts& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::stmts* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::stmts>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::stmts>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::stmts> stmts();
Access<::DLDL_GENERATION::ast::node::stmt> stmt();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::stmts>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::stmt*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::stmt& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::stmt* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::stmt>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::generate_declaration> generate_declaration();
Access<::DLDL_GENERATION::ast::node::integrate_declaration> integrate_declaration();
Access<::DLDL_GENERATION::ast::node::argument_declaration> argument_declaration();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::generate_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::generate_declaration*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::generate_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::generate_declaration& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::generate_declaration* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::generate_declaration>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::generate_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::type> type();
Access<::DLDL_GENERATION::ast::node::tool> tool();
Access<::DLDL_GENERATION::ast::node::GENERATE> GENERATE();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::generate_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::integrate_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::integrate_declaration*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::integrate_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::integrate_declaration& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::integrate_declaration* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::integrate_declaration>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::integrate_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::tool> tool();
Access<::DLDL_GENERATION::ast::node::INTEGRATE> INTEGRATE();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::integrate_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::argument_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::argument_declaration*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::argument_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::argument_declaration& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::argument_declaration* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::argument_declaration>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::argument_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::tool> tool();
Access<::DLDL_GENERATION::ast::node::argument_data> argument_data();
Access<::DLDL_GENERATION::ast::node::ARGUMENT> ARGUMENT();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::argument_declaration>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::type> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::type*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::type*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::type& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::type* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::type>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::type>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::type>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::tool> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::tool*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::tool*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::tool& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::tool* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::tool>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::tool>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::tool>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::argument_data> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::argument_data*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::argument_data*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::argument_data& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::argument_data* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::argument_data>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::argument_data>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::argument_data> argument_data();
Access<::DLDL_GENERATION::ast::node::VALUE> VALUE();


		template<typename FunctionType>
		Access<::DLDL_GENERATION::ast::node::argument_data>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::GENERATE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::GENERATE*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::GENERATE*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::GENERATE& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::GENERATE* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::GENERATE>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::GENERATE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::GENERATE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::INTEGRATE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::INTEGRATE*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::INTEGRATE*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::INTEGRATE& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::INTEGRATE* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::INTEGRATE>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::INTEGRATE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::INTEGRATE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::ARGUMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::ARGUMENT*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::ARGUMENT*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::ARGUMENT& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::ARGUMENT* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::ARGUMENT>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::ARGUMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::ARGUMENT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::VALUE*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::VALUE& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::VALUE* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::VALUE>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::VALUE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::SYMBOLS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::SYMBOLS*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::SYMBOLS*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::SYMBOLS& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::SYMBOLS* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::SYMBOLS>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::SYMBOLS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::SYMBOLS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};

	template<>
	struct Access<::DLDL_GENERATION::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS*> ts;

	public:
		Access(std::vector<const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		Access(const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		Access() = default;

	public:
		Access<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		Access<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
		Access<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}
	};


	
		inline Access<::DLDL_GENERATION::ast::node::stmts> Access<::DLDL_GENERATION::ast::node::program>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::stmts>(Get<::DLDL_GENERATION::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::stmts> Access<::DLDL_GENERATION::ast::node::stmts>::stmts()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::stmts>(Get<::DLDL_GENERATION::ast::Type::stmts>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::stmt> Access<::DLDL_GENERATION::ast::node::stmts>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::stmt>(Get<::DLDL_GENERATION::ast::Type::stmt>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::generate_declaration> Access<::DLDL_GENERATION::ast::node::stmt>::generate_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::generate_declaration>(Get<::DLDL_GENERATION::ast::Type::generate_declaration>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::integrate_declaration> Access<::DLDL_GENERATION::ast::node::stmt>::integrate_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::integrate_declaration>(Get<::DLDL_GENERATION::ast::Type::integrate_declaration>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::argument_declaration> Access<::DLDL_GENERATION::ast::node::stmt>::argument_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::argument_declaration>(Get<::DLDL_GENERATION::ast::Type::argument_declaration>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::type> Access<::DLDL_GENERATION::ast::node::generate_declaration>::type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::type>(Get<::DLDL_GENERATION::ast::Type::type>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::tool> Access<::DLDL_GENERATION::ast::node::generate_declaration>::tool()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::tool>(Get<::DLDL_GENERATION::ast::Type::tool>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::GENERATE> Access<::DLDL_GENERATION::ast::node::generate_declaration>::GENERATE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::GENERATE>(Get<::DLDL_GENERATION::ast::Type::GENERATE>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::tool> Access<::DLDL_GENERATION::ast::node::integrate_declaration>::tool()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::tool>(Get<::DLDL_GENERATION::ast::Type::tool>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::INTEGRATE> Access<::DLDL_GENERATION::ast::node::integrate_declaration>::INTEGRATE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::INTEGRATE>(Get<::DLDL_GENERATION::ast::Type::INTEGRATE>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::tool> Access<::DLDL_GENERATION::ast::node::argument_declaration>::tool()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::tool>(Get<::DLDL_GENERATION::ast::Type::tool>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::argument_data> Access<::DLDL_GENERATION::ast::node::argument_declaration>::argument_data()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::argument_data>(Get<::DLDL_GENERATION::ast::Type::argument_data>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::ARGUMENT> Access<::DLDL_GENERATION::ast::node::argument_declaration>::ARGUMENT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::ARGUMENT>(Get<::DLDL_GENERATION::ast::Type::ARGUMENT>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::VALUE> Access<::DLDL_GENERATION::ast::node::type>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::VALUE>(Get<::DLDL_GENERATION::ast::Type::VALUE>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::VALUE> Access<::DLDL_GENERATION::ast::node::tool>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::VALUE>(Get<::DLDL_GENERATION::ast::Type::VALUE>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::argument_data> Access<::DLDL_GENERATION::ast::node::argument_data>::argument_data()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::argument_data>(Get<::DLDL_GENERATION::ast::Type::argument_data>(ts));
		}

		inline Access<::DLDL_GENERATION::ast::node::VALUE> Access<::DLDL_GENERATION::ast::node::argument_data>::VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return Access<::DLDL_GENERATION::ast::node::VALUE>(Get<::DLDL_GENERATION::ast::Type::VALUE>(ts));
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

#endif // DLDL_GENERATION_AST_REFERENCE_ACCESS_H