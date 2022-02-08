#ifndef DLDL_LPDDEF_DF_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_LPDDEF_DF_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_LPDDEF_DF/Ast/Relation/NodeEnumToType.h"
#include "DLDL_LPDDEF_DF/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_LPDDEF_DF/Ast/Relation/NodeIsInlined.h"

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_LPDDEF_DF { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_LPDDEF_DF::ast::Type T>
		void Get(std::vector<const ::DLDL_LPDDEF_DF::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_LPDDEF_DF::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_LPDDEF_DF::ast::relation::NodeIsInlined(static_cast<::DLDL_LPDDEF_DF::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_LPDDEF_DF::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_LPDDEF_DF::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_LPDDEF_DF::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::SEMICOLON>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant> vector_variant();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line> comment_line();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant> optional_variant();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant> standard_variant();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::comment_line*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::comment_line*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::comment_line& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::comment_line* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::comment_line*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::comment_line*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT> COMMENT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::vector_variant*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::vector_variant*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::vector_variant& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::vector_variant* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::vector_variant*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::vector_variant*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB> LAB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> value_part();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> var_type();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> var_name();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB> RAB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB> LSB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB> RSB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR> VECTOR();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::optional_variant*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::optional_variant*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::optional_variant& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::optional_variant* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::optional_variant*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::optional_variant*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB> LAB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> value_part();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> var_type();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> var_name();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB> RAB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB> LSB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB> RSB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL> OPTIONAL();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_part*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_part*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::value_part& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::value_part* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_part*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_part*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value> value();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ> EQ();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::standard_variant*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::standard_variant*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::standard_variant& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::standard_variant* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::standard_variant*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::standard_variant*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> value_part();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> var_type();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> var_name();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> value_type();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_type*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_type*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::value_type& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::value_type* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_type*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::value_type*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> value_type();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__> deamerreserved_arrow__value_type__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> deamerreserved_star__COMMA__value_type__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> COLON();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB> LB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB> RB();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> COMMA();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME> DEAMER_VARNAME();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> VARNAME();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER> NUMBER();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING> STRING();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> value_type();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> deamerreserved_star__COMMA__value_type__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> COMMA();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> value_type();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> deamerreserved_star__COMMA__value_type__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> COMMA();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_type*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_type*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::var_type& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::var_type* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_type*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_type*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__> deamerreserved_arrow__VARNAME__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> deamerreserved_star__COLON__VARNAME__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> COLON();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME> DEAMER_VARNAME();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> deamerreserved_star__COLON__VARNAME__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> COLON();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> deamerreserved_star__COLON__VARNAME__();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> COLON();
AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::var_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::var_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::var_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::LAB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::LAB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::LAB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::LAB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::LAB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::LAB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::RAB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::RAB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::RAB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::RAB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::RAB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::RAB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::LSB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::LSB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::LSB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::LSB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::LSB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::LSB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::RSB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::RSB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::RSB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::RSB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::RSB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::RSB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::EQ*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::EQ*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::EQ& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::EQ* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::EQ*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::EQ*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::COLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::COLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::COLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::COLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::COLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::COLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::LB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::LB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::LB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::LB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::LB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::LB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::RB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::RB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::RB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::RB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::RB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::RB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMA*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMA*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::COMMA& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::COMMA* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMA*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMA*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::VECTOR*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::VECTOR*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::VECTOR& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::VECTOR* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::VECTOR*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::VECTOR*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::STRING*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::STRING*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::STRING& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::STRING* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::STRING*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::STRING*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::SEMICOLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::SEMICOLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::SEMICOLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::SEMICOLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>(Get<::DLDL_LPDDEF_DF::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>(Get<::DLDL_LPDDEF_DF::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>::vector_variant()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>(Get<::DLDL_LPDDEF_DF::ast::Type::vector_variant>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>::comment_line()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line>(Get<::DLDL_LPDDEF_DF::ast::Type::comment_line>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>::optional_variant()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>(Get<::DLDL_LPDDEF_DF::ast::Type::optional_variant>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::stmt>::standard_variant()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>(Get<::DLDL_LPDDEF_DF::ast::Type::standard_variant>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::comment_line>::COMMENT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMENT>(Get<::DLDL_LPDDEF_DF::ast::Type::COMMENT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::LAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB>(Get<::DLDL_LPDDEF_DF::ast::Type::LAB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::value_part()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>(Get<::DLDL_LPDDEF_DF::ast::Type::value_part>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::var_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>(Get<::DLDL_LPDDEF_DF::ast::Type::var_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::var_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>(Get<::DLDL_LPDDEF_DF::ast::Type::var_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::RAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB>(Get<::DLDL_LPDDEF_DF::ast::Type::RAB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::LSB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB>(Get<::DLDL_LPDDEF_DF::ast::Type::LSB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::RSB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB>(Get<::DLDL_LPDDEF_DF::ast::Type::RSB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::vector_variant>::VECTOR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VECTOR>(Get<::DLDL_LPDDEF_DF::ast::Type::VECTOR>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::LAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LAB>(Get<::DLDL_LPDDEF_DF::ast::Type::LAB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::value_part()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>(Get<::DLDL_LPDDEF_DF::ast::Type::value_part>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::var_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>(Get<::DLDL_LPDDEF_DF::ast::Type::var_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::var_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>(Get<::DLDL_LPDDEF_DF::ast::Type::var_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::RAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RAB>(Get<::DLDL_LPDDEF_DF::ast::Type::RAB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::LSB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LSB>(Get<::DLDL_LPDDEF_DF::ast::Type::LSB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::RSB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RSB>(Get<::DLDL_LPDDEF_DF::ast::Type::RSB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::optional_variant>::OPTIONAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::OPTIONAL>(Get<::DLDL_LPDDEF_DF::ast::Type::OPTIONAL>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value>(Get<::DLDL_LPDDEF_DF::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>::EQ()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::EQ>(Get<::DLDL_LPDDEF_DF::ast::Type::EQ>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>::value_part()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_part>(Get<::DLDL_LPDDEF_DF::ast::Type::value_part>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>::var_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>(Get<::DLDL_LPDDEF_DF::ast::Type::var_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::standard_variant>::var_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>(Get<::DLDL_LPDDEF_DF::ast::Type::var_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value>::value_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>(Get<::DLDL_LPDDEF_DF::ast::Type::value_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::value_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>(Get<::DLDL_LPDDEF_DF::ast::Type::value_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::deamerreserved_arrow__value_type__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::deamerreserved_star__COMMA__value_type__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>(Get<::DLDL_LPDDEF_DF::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::LB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::LB>(Get<::DLDL_LPDDEF_DF::ast::Type::LB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::RB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::RB>(Get<::DLDL_LPDDEF_DF::ast::Type::RB>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::COMMA()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>(Get<::DLDL_LPDDEF_DF::ast::Type::COMMA>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::DEAMER_VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::NUMBER>(Get<::DLDL_LPDDEF_DF::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>::STRING()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::STRING>(Get<::DLDL_LPDDEF_DF::ast::Type::STRING>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>::value_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>(Get<::DLDL_LPDDEF_DF::ast::Type::value_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>::deamerreserved_star__COMMA__value_type__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>::COMMA()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>(Get<::DLDL_LPDDEF_DF::ast::Type::COMMA>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>::value_type()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::value_type>(Get<::DLDL_LPDDEF_DF::ast::Type::value_type>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>::deamerreserved_star__COMMA__value_type__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>::COMMA()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COMMA>(Get<::DLDL_LPDDEF_DF::ast::Type::COMMA>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>::deamerreserved_arrow__VARNAME__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>::deamerreserved_star__COLON__VARNAME__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>(Get<::DLDL_LPDDEF_DF::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>::DEAMER_VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_type>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>::deamerreserved_star__COLON__VARNAME__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>(Get<::DLDL_LPDDEF_DF::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>::deamerreserved_star__COLON__VARNAME__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>(Get<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::COLON>(Get<::DLDL_LPDDEF_DF::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::var_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_DF::ast::node::VARNAME>(Get<::DLDL_LPDDEF_DF::ast::Type::VARNAME>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_LPDDEF_DF::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_REFERENCE_ACCESSTEMPLATEBASE_H