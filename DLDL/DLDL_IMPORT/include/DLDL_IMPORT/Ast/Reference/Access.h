#ifndef DLDL_IMPORT_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_IMPORT_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_IMPORT/Ast/Relation/NodeEnumToType.h"
#include "DLDL_IMPORT/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_IMPORT/Ast/Relation/NodeIsInlined.h"

#include "DLDL_IMPORT/Ast/Enum/Type.h"
#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"
#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_IMPORT { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_IMPORT::ast::Type T>
		void Get(std::vector<const ::DLDL_IMPORT::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_IMPORT::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_IMPORT::ast::relation::NodeIsInlined(static_cast<::DLDL_IMPORT::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_IMPORT::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_IMPORT::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_IMPORT::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::value>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::SINGLE_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::MULTI_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration> import_declaration();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::import_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::import_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::import_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::import_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__> deamerreserved_arrow__import_context__();
AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> deamerreserved_long_40();
AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> deamerreserved_long_43();
AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization> specialization();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> import_abstraction();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> import_context();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name> import_rule_name();
AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS> LEFT_PARANTHESIS();
AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS> RIGHT_PARANTHESIS();
AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> deamerreserved_long_40();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> import_context();
AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_40*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_40*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_long_40& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_long_40* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_40*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_40*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> deamerreserved_long_40();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> import_context();
AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_43*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_43*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_long_43& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_long_43* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_43*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_long_43*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> deamerreserved_long_43();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> import_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::specialization*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::specialization*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::specialization& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::specialization* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::specialization*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::specialization*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE> IMPORT_FILE();
AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE> IMPORT_MODULE();
AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT> IMPORT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::import_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::import_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::import_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::import_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::value> value();
AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction> abstraction();
AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON> COLON();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::value> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::value>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> deamerreserved_long_43();
AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> import_abstraction();
AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__> deamerreserved_optional__VARNAME__();
AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT> TEXT();
AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::value>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::import_context*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::import_context*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_context& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_context* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::import_context*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::import_context*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::import_rule_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::import_rule_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_rule_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::import_rule_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::import_rule_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::import_rule_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::SINGLE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::SINGLE_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::SINGLE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::SINGLE_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::MULTI_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::MULTI_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::MULTI_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::MULTI_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::MULTI_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::MULTI_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::MULTI_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::MULTI_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::MULTI_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::MULTI_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::COLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::COLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::COLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::COLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::COLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::COLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::DOT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::DOT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::DOT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::DOT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::DOT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::DOT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_FILE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_FILE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::IMPORT_FILE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::IMPORT_FILE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_FILE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_FILE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_MODULE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_MODULE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::IMPORT_MODULE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::IMPORT_MODULE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_MODULE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::IMPORT_MODULE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::IMPORT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::IMPORT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::IMPORT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::IMPORT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::IMPORT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::IMPORT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::TEXT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::TEXT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::TEXT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::TEXT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::TEXT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::TEXT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_IMPORT::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_IMPORT::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_IMPORT::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_IMPORT::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_IMPORT::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt> AccessTemplateBase<::DLDL_IMPORT::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>(Get<::DLDL_IMPORT::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>(Get<::DLDL_IMPORT::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration> AccessTemplateBase<::DLDL_IMPORT::ast::node::stmt>::import_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>(Get<::DLDL_IMPORT::ast::Type::import_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::deamerreserved_arrow__import_context__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::deamerreserved_long_40()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_long_40>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::deamerreserved_long_43()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_long_43>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::specialization()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>(Get<::DLDL_IMPORT::ast::Type::specialization>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::import_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>(Get<::DLDL_IMPORT::ast::Type::import_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::import_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>(Get<::DLDL_IMPORT::ast::Type::import_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::import_rule_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name>(Get<::DLDL_IMPORT::ast::Type::import_rule_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::LEFT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS>(Get<::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::RIGHT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS>(Get<::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_declaration>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>(Get<::DLDL_IMPORT::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>::deamerreserved_long_40()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_long_40>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>::import_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>(Get<::DLDL_IMPORT::ast::Type::import_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>(Get<::DLDL_IMPORT::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>::deamerreserved_long_40()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_long_40>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>::import_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>(Get<::DLDL_IMPORT::ast::Type::import_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_40>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::DOT>(Get<::DLDL_IMPORT::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>::deamerreserved_long_43()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_long_43>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>::import_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>(Get<::DLDL_IMPORT::ast::Type::import_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE> AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>::IMPORT_FILE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_FILE>(Get<::DLDL_IMPORT::ast::Type::IMPORT_FILE>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE> AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>::IMPORT_MODULE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT_MODULE>(Get<::DLDL_IMPORT::ast::Type::IMPORT_MODULE>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT> AccessTemplateBase<::DLDL_IMPORT::ast::node::specialization>::IMPORT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::IMPORT>(Get<::DLDL_IMPORT::ast::Type::IMPORT>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::value> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::value>(Get<::DLDL_IMPORT::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>::abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction>(Get<::DLDL_IMPORT::ast::Type::abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::COLON>(Get<::DLDL_IMPORT::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::deamerreserved_long_43()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_long_43>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_long_43>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::import_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::import_abstraction>(Get<::DLDL_IMPORT::ast::Type::import_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::deamerreserved_optional__VARNAME__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>(Get<::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::TEXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::TEXT>(Get<::DLDL_IMPORT::ast::Type::TEXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> AccessTemplateBase<::DLDL_IMPORT::ast::node::value>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>(Get<::DLDL_IMPORT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> AccessTemplateBase<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>(Get<::DLDL_IMPORT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> AccessTemplateBase<::DLDL_IMPORT::ast::node::abstraction>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>(Get<::DLDL_IMPORT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_context>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>(Get<::DLDL_IMPORT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME> AccessTemplateBase<::DLDL_IMPORT::ast::node::import_rule_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_IMPORT::ast::node::VARNAME>(Get<::DLDL_IMPORT::ast::Type::VARNAME>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_IMPORT::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_IMPORT_AST_REFERENCE_ACCESSTEMPLATEBASE_H