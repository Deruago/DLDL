#ifndef DLDL_LPDDEF_EF_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_LPDDEF_EF_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_LPDDEF_EF/Ast/Relation/NodeEnumToType.h"
#include "DLDL_LPDDEF_EF/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_LPDDEF_EF/Ast/Relation/NodeIsInlined.h"

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF_EF/Ast/Node/program.h"
#include "DLDL_LPDDEF_EF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_EF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_EF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant_specific_number.h"
#include "DLDL_LPDDEF_EF/Ast/Node/value.h"
#include "DLDL_LPDDEF_EF/Ast/Node/enum_name.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_EF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_EF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_LPDDEF_EF { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_LPDDEF_EF::ast::Type T>
		void Get(std::vector<const ::DLDL_LPDDEF_EF::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_LPDDEF_EF::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_LPDDEF_EF::ast::relation::NodeIsInlined(static_cast<::DLDL_LPDDEF_EF::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_LPDDEF_EF::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_LPDDEF_EF::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_LPDDEF_EF::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COLON>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::SEMICOLON>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line> comment_line();
AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant> standard_variant();
AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number> standard_variant_specific_number();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::comment_line*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::comment_line*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::comment_line& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::comment_line* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::comment_line*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::comment_line*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT> COMMENT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::standard_variant& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::standard_variant* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name> enum_name();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value> value();
AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name> enum_name();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::enum_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::enum_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::enum_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::enum_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::enum_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::enum_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::COLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::COLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::COLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::COLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::COLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::COLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::SEMICOLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::SEMICOLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::SEMICOLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::SEMICOLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>(Get<::DLDL_LPDDEF_EF::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>(Get<::DLDL_LPDDEF_EF::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>::comment_line()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line>(Get<::DLDL_LPDDEF_EF::ast::Type::comment_line>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>::standard_variant()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant>(Get<::DLDL_LPDDEF_EF::ast::Type::standard_variant>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::stmt>::standard_variant_specific_number()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>(Get<::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::comment_line>::COMMENT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::COMMENT>(Get<::DLDL_LPDDEF_EF::ast::Type::COMMENT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant>::enum_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>(Get<::DLDL_LPDDEF_EF::ast::Type::enum_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value>(Get<::DLDL_LPDDEF_EF::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>::enum_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>(Get<::DLDL_LPDDEF_EF::ast::Type::enum_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::value>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::NUMBER>(Get<::DLDL_LPDDEF_EF::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::enum_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF_EF::ast::node::VARNAME>(Get<::DLDL_LPDDEF_EF::ast::Type::VARNAME>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_LPDDEF_EF::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_REFERENCE_ACCESSTEMPLATEBASE_H