#ifndef DLDL_VALUE_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_VALUE_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_VALUE/Ast/Relation/NodeEnumToType.h"
#include "DLDL_VALUE/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_VALUE/Ast/Relation/NodeIsInlined.h"

#include "DLDL_VALUE/Ast/Enum/Type.h"
#include "DLDL_VALUE/Ast/Node/program.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_VALUE/Ast/Node/stmt.h"
#include "DLDL_VALUE/Ast/Node/value_charactersitic_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_82.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_85.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_88.h"
#include "DLDL_VALUE/Ast/Node/value_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_91.h"
#include "DLDL_VALUE/Ast/Node/value_characteristic_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_declaration_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_abstraction.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__value_abstraction__.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_96.h"
#include "DLDL_VALUE/Ast/Node/value.h"
#include "DLDL_VALUE/Ast/Node/syntactic_context.h"
#include "DLDL_VALUE/Ast/Node/abstraction_name.h"
#include "DLDL_VALUE/Ast/Node/value_rule_name.h"
#include "DLDL_VALUE/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/DOT.h"
#include "DLDL_VALUE/Ast/Node/VALUE_CHARACTERISTIC.h"
#include "DLDL_VALUE/Ast/Node/VALUE_RULE.h"
#include "DLDL_VALUE/Ast/Node/NUMBER.h"
#include "DLDL_VALUE/Ast/Node/TEXT.h"
#include "DLDL_VALUE/Ast/Node/VARNAME.h"
#include "DLDL_VALUE/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_VALUE { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_VALUE::ast::Type T>
		void Get(std::vector<const ::DLDL_VALUE::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_VALUE::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_VALUE::ast::relation::NodeIsInlined(static_cast<::DLDL_VALUE::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_VALUE::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_VALUE::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_VALUE::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::SINGLE_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::MULTI_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_VALUE::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_VALUE::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration> value_charactersitic_declaration();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration> value_declaration();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value_charactersitic_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value_charactersitic_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_charactersitic_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_charactersitic_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value_charactersitic_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value_charactersitic_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82> deamerreserved_long_82();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> deamerreserved_long_85();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88> deamerreserved_long_88();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction> value_characteristic_abstraction();
AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> syntactic_context();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name> value_rule_name();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> LEFT_PARANTHESIS();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> RIGHT_PARANTHESIS();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> DOT();
AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC> VALUE_CHARACTERISTIC();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_82*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_82*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_82& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_82* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_82*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_82*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> deamerreserved_long_85();
AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> syntactic_context();
AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_85*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_85*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_85& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_85* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_85*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_85*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> deamerreserved_long_85();
AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> syntactic_context();
AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> DOT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_88*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_88*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_88& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_88* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_88*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_88*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88> deamerreserved_long_88();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction> value_characteristic_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value_declaration*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value_declaration*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_declaration& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_declaration* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value_declaration*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value_declaration*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82> deamerreserved_long_82();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> deamerreserved_long_85();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91> deamerreserved_long_91();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction> value_declaration_abstraction();
AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> syntactic_context();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name> value_rule_name();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> LEFT_PARANTHESIS();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> RIGHT_PARANTHESIS();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> DOT();
AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE> VALUE_RULE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_91*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_91*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_91& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_91* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_91*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_91*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91> deamerreserved_long_91();
AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction> value_declaration_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value_characteristic_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value_characteristic_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_characteristic_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_characteristic_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value_characteristic_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value_characteristic_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> value_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value_declaration_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value_declaration_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_declaration_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_declaration_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value_declaration_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value_declaration_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> value_abstraction();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value_abstraction*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value_abstraction*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_abstraction& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_abstraction* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value_abstraction*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value_abstraction*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> value_abstraction();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> deamerreserved_star__value_abstraction__();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96> deamerreserved_long_96();
AccessTemplateBase<::DLDL_VALUE::ast::node::value> value();
AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name> abstraction_name();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> LEFT_PARANTHESIS();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> RIGHT_PARANTHESIS();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> value_abstraction();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> deamerreserved_star__value_abstraction__();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_96*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_96*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_96& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::deamerreserved_long_96* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_96*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::deamerreserved_long_96*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> value_abstraction();
AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> deamerreserved_star__value_abstraction__();
AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER> NUMBER();
AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT> TEXT();
AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::syntactic_context*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::syntactic_context*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::syntactic_context& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::syntactic_context* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::syntactic_context*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::syntactic_context*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::abstraction_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::abstraction_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::abstraction_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::abstraction_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::abstraction_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::abstraction_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::value_rule_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::value_rule_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_rule_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::value_rule_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::value_rule_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::value_rule_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::SINGLE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::SINGLE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::SINGLE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::SINGLE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::SINGLE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::SINGLE_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::SINGLE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::SINGLE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::SINGLE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::SINGLE_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::MULTI_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::MULTI_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::MULTI_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::MULTI_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::MULTI_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::MULTI_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::MULTI_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::MULTI_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::MULTI_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::MULTI_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::LEFT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::LEFT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::LEFT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::LEFT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::LEFT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::LEFT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::RIGHT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::RIGHT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::RIGHT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::RIGHT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::RIGHT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::RIGHT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::DOT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::DOT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::DOT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::DOT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::DOT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::DOT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::VALUE_RULE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::VALUE_RULE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::VALUE_RULE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::VALUE_RULE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::VALUE_RULE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::VALUE_RULE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::TEXT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::TEXT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::TEXT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::TEXT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::TEXT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::TEXT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_VALUE::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_VALUE::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_VALUE::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_VALUE::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_VALUE::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_VALUE::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_VALUE::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_VALUE::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_VALUE::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_VALUE::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::stmt> AccessTemplateBase<::DLDL_VALUE::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>(Get<::DLDL_VALUE::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::stmt> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>(Get<::DLDL_VALUE::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration> AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>::value_charactersitic_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>(Get<::DLDL_VALUE::ast::Type::value_charactersitic_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration> AccessTemplateBase<::DLDL_VALUE::ast::node::stmt>::value_declaration()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>(Get<::DLDL_VALUE::ast::Type::value_declaration>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::deamerreserved_long_82()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_82>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::deamerreserved_long_85()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_85>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::deamerreserved_long_88()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_88>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::value_characteristic_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>(Get<::DLDL_VALUE::ast::Type::value_characteristic_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::syntactic_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>(Get<::DLDL_VALUE::ast::Type::syntactic_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::value_rule_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>(Get<::DLDL_VALUE::ast::Type::value_rule_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::LEFT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>(Get<::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::RIGHT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>(Get<::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>(Get<::DLDL_VALUE::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC> AccessTemplateBase<::DLDL_VALUE::ast::node::value_charactersitic_declaration>::VALUE_CHARACTERISTIC()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC>(Get<::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>::deamerreserved_long_85()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_85>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>::syntactic_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>(Get<::DLDL_VALUE::ast::Type::syntactic_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>(Get<::DLDL_VALUE::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>::deamerreserved_long_85()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_85>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>::syntactic_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>(Get<::DLDL_VALUE::ast::Type::syntactic_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>(Get<::DLDL_VALUE::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>::deamerreserved_long_88()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_88>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_88>::value_characteristic_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>(Get<::DLDL_VALUE::ast::Type::value_characteristic_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::deamerreserved_long_82()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_82>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_82>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::deamerreserved_long_85()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_85>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_85>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::deamerreserved_long_91()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_91>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::value_declaration_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>(Get<::DLDL_VALUE::ast::Type::value_declaration_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::syntactic_context()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>(Get<::DLDL_VALUE::ast::Type::syntactic_context>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::value_rule_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>(Get<::DLDL_VALUE::ast::Type::value_rule_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::LEFT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>(Get<::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::RIGHT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>(Get<::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::DOT> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::DOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::DOT>(Get<::DLDL_VALUE::ast::Type::DOT>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration>::VALUE_RULE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::VALUE_RULE>(Get<::DLDL_VALUE::ast::Type::VALUE_RULE>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>::deamerreserved_long_91()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_91>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_91>::value_declaration_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>(Get<::DLDL_VALUE::ast::Type::value_declaration_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::value_characteristic_abstraction>::value_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>(Get<::DLDL_VALUE::ast::Type::value_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::value_declaration_abstraction>::value_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>(Get<::DLDL_VALUE::ast::Type::value_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::value_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>(Get<::DLDL_VALUE::ast::Type::value_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::deamerreserved_star__value_abstraction__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>(Get<::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::deamerreserved_long_96()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>(Get<::DLDL_VALUE::ast::Type::deamerreserved_long_96>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::value()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value>(Get<::DLDL_VALUE::ast::Type::value>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::abstraction_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name>(Get<::DLDL_VALUE::ast::Type::abstraction_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::LEFT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>(Get<::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::RIGHT_PARANTHESIS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>(Get<::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>::value_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>(Get<::DLDL_VALUE::ast::Type::value_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>::deamerreserved_star__value_abstraction__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>(Get<::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>::value_abstraction()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::value_abstraction>(Get<::DLDL_VALUE::ast::Type::value_abstraction>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>::deamerreserved_star__value_abstraction__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>(Get<::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::DLDL_VALUE::ast::node::deamerreserved_long_96>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>(Get<::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER> AccessTemplateBase<::DLDL_VALUE::ast::node::value>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::NUMBER>(Get<::DLDL_VALUE::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT> AccessTemplateBase<::DLDL_VALUE::ast::node::value>::TEXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::TEXT>(Get<::DLDL_VALUE::ast::Type::TEXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> AccessTemplateBase<::DLDL_VALUE::ast::node::value>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>(Get<::DLDL_VALUE::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> AccessTemplateBase<::DLDL_VALUE::ast::node::syntactic_context>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>(Get<::DLDL_VALUE::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> AccessTemplateBase<::DLDL_VALUE::ast::node::abstraction_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>(Get<::DLDL_VALUE::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME> AccessTemplateBase<::DLDL_VALUE::ast::node::value_rule_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_VALUE::ast::node::VARNAME>(Get<::DLDL_VALUE::ast::Type::VARNAME>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_VALUE::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_VALUE_AST_REFERENCE_ACCESSTEMPLATEBASE_H