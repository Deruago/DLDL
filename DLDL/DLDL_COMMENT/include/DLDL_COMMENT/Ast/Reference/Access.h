#ifndef DLDL_COMMENT_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_COMMENT_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_COMMENT/Ast/Relation/NodeEnumToType.h"
#include "DLDL_COMMENT/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_COMMENT/Ast/Relation/NodeIsInlined.h"

#include "DLDL_COMMENT/Ast/Enum/Type.h"
#include "DLDL_COMMENT/Ast/Node/program.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_COMMENT/Ast/Node/stmt.h"
#include "DLDL_COMMENT/Ast/Node/comment_value_declaration.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_3.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_6.h"
#include "DLDL_COMMENT/Ast/Node/comment_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/end_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_sequence.h"
#include "DLDL_COMMENT/Ast/Node/end_sequence.h"
#include "DLDL_COMMENT/Ast/Node/sequence.h"
#include "DLDL_COMMENT/Ast/Node/syntactic_reference.h"
#include "DLDL_COMMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/COMMENT_VALUE.h"
#include "DLDL_COMMENT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/START.h"
#include "DLDL_COMMENT/Ast/Node/END.h"
#include "DLDL_COMMENT/Ast/Node/TEXT.h"
#include "DLDL_COMMENT/Ast/Node/VARNAME.h"
#include "DLDL_COMMENT/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_COMMENT { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_COMMENT::ast::Type T>
		void Get(std::vector<const ::DLDL_COMMENT::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_COMMENT::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_COMMENT::ast::relation::NodeIsInlined(static_cast<::DLDL_COMMENT::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_COMMENT::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_COMMENT::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_COMMENT::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::SINGLE_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::MULTI_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::START>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::END>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration> comment_value_declaration();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::comment_value_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::comment_value_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::comment_value_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::comment_value_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::comment_value_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::comment_value_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> deamerreserved_long_3();
AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6> deamerreserved_long_6();
AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> comment_abstraction();
AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference> syntactic_reference();
AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE> COMMENT_VALUE();
AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_3*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_3*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::deamerreserved_long_3& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::deamerreserved_long_3* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_3*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_3*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> deamerreserved_long_3();
AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> comment_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_6*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_6*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::deamerreserved_long_6& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::deamerreserved_long_6* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_6*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::deamerreserved_long_6*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> deamerreserved_long_3();
AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> comment_abstraction();
AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::comment_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::comment_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::comment_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::comment_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::comment_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::comment_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction> start_abstraction();
AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction> end_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::start_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::start_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::start_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::start_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::start_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::start_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence> start_sequence();
AccessTemplateBase<::DLDL_COMMENT::ast::node::START> START();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::end_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::end_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::end_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::end_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::end_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::end_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence> end_sequence();
AccessTemplateBase<::DLDL_COMMENT::ast::node::END> END();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::start_sequence*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::start_sequence*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::start_sequence& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::start_sequence* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::start_sequence*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::start_sequence*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence> sequence();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::end_sequence*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::end_sequence*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::end_sequence& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::end_sequence* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::end_sequence*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::end_sequence*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence> sequence();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::sequence*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::sequence*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::sequence& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::sequence* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::sequence*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::sequence*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT> TEXT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::syntactic_reference*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::syntactic_reference*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::syntactic_reference& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::syntactic_reference* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::syntactic_reference*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::syntactic_reference*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::SINGLE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::SINGLE_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::SINGLE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::SINGLE_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::MULTI_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::MULTI_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::MULTI_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::MULTI_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::MULTI_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::MULTI_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::MULTI_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::MULTI_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::MULTI_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::MULTI_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::COMMENT_VALUE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::COMMENT_VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::COMMENT_VALUE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::COMMENT_VALUE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::COMMENT_VALUE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::COMMENT_VALUE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::START> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::START*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::START*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::START& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::START* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::START>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::START>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::START*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::START*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::START>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::END> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::END*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::END*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::END& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::END* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::END>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::END>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::END*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::END*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::END>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::TEXT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::TEXT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::TEXT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::TEXT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::TEXT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::TEXT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_COMMENT::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_COMMENT::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_COMMENT::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_COMMENT::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_COMMENT::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt> AccessTemplateBase<::DLDL_COMMENT::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>(Get<::DLDL_COMMENT::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>(Get<::DLDL_COMMENT::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration> AccessTemplateBase<::DLDL_COMMENT::ast::node::stmt>::comment_value_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>(Get<::DLDL_COMMENT::ast::Type::comment_value_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::deamerreserved_long_3()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>(Get<::DLDL_COMMENT::ast::Type::deamerreserved_long_3>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::deamerreserved_long_6()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>(Get<::DLDL_COMMENT::ast::Type::deamerreserved_long_6>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::comment_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>(Get<::DLDL_COMMENT::ast::Type::comment_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::syntactic_reference()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference>(Get<::DLDL_COMMENT::ast::Type::syntactic_reference>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::COMMENT_VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::COMMENT_VALUE>(Get<::DLDL_COMMENT::ast::Type::COMMENT_VALUE>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_value_declaration>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>::deamerreserved_long_3()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>(Get<::DLDL_COMMENT::ast::Type::deamerreserved_long_3>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>::comment_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>(Get<::DLDL_COMMENT::ast::Type::comment_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>::deamerreserved_long_3()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_3>(Get<::DLDL_COMMENT::ast::Type::deamerreserved_long_3>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>::comment_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>(Get<::DLDL_COMMENT::ast::Type::comment_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_COMMENT::ast::node::deamerreserved_long_6>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>::start_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>(Get<::DLDL_COMMENT::ast::Type::start_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction> AccessTemplateBase<::DLDL_COMMENT::ast::node::comment_abstraction>::end_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>(Get<::DLDL_COMMENT::ast::Type::end_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence> AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>::start_sequence()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence>(Get<::DLDL_COMMENT::ast::Type::start_sequence>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::START> AccessTemplateBase<::DLDL_COMMENT::ast::node::start_abstraction>::START()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::START>(Get<::DLDL_COMMENT::ast::Type::START>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence> AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>::end_sequence()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence>(Get<::DLDL_COMMENT::ast::Type::end_sequence>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::END> AccessTemplateBase<::DLDL_COMMENT::ast::node::end_abstraction>::END()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::END>(Get<::DLDL_COMMENT::ast::Type::END>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence> AccessTemplateBase<::DLDL_COMMENT::ast::node::start_sequence>::sequence()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>(Get<::DLDL_COMMENT::ast::Type::sequence>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence> AccessTemplateBase<::DLDL_COMMENT::ast::node::end_sequence>::sequence()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>(Get<::DLDL_COMMENT::ast::Type::sequence>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT> AccessTemplateBase<::DLDL_COMMENT::ast::node::sequence>::TEXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::TEXT>(Get<::DLDL_COMMENT::ast::Type::TEXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME> AccessTemplateBase<::DLDL_COMMENT::ast::node::syntactic_reference>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_COMMENT::ast::node::VARNAME>(Get<::DLDL_COMMENT::ast::Type::VARNAME>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_COMMENT::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_COMMENT_AST_REFERENCE_ACCESSTEMPLATEBASE_H