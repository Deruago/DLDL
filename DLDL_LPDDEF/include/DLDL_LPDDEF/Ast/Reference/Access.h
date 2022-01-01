#ifndef DLDL_LPDDEF_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_LPDDEF_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_LPDDEF/Ast/Relation/NodeEnumToType.h"
#include "DLDL_LPDDEF/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_LPDDEF/Ast/Relation/NodeIsInlined.h"

#include "DLDL_LPDDEF/Ast/Enum/Type.h"
#include "DLDL_LPDDEF/Ast/Node/program.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF/Ast/Node/argument.h"
#include "DLDL_LPDDEF/Ast/Node/argument_name.h"
#include "DLDL_LPDDEF/Ast/Node/argument_block.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/argument_stmt.h"
#include "DLDL_LPDDEF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LPDDEF/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDDEF/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_LPDDEF { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_LPDDEF::ast::Type T>
		void Get(std::vector<const ::DLDL_LPDDEF::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_LPDDEF::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_LPDDEF::ast::relation::NodeIsInlined(static_cast<::DLDL_LPDDEF::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_LPDDEF::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_LPDDEF::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_LPDDEF::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE>;
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument> argument();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::argument*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::argument*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::argument*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::argument*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON> COLON();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name> argument_name();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block> argument_block();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT> VARNAME_EXT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::argument_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::argument_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::argument_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::argument_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::argument_block*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::argument_block*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument_block& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument_block* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::argument_block*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::argument_block*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__> deamerreserved_star__argument_stmt__();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt> argument_stmt();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET> LEFT_ANGLE_BRACKET();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET> RIGHT_ANGLE_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__> deamerreserved_star__argument_stmt__();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt> argument_stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::argument_stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::argument_stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument_stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::argument_stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::argument_stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::argument_stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME> VARNAME();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT> VARNAME_EXT();
AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE> INDENTED_VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::COLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::COLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::COLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::COLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::COLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::COLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME_EXT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME_EXT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::VARNAME_EXT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::VARNAME_EXT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME_EXT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::VARNAME_EXT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::INDENTED_VALUE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::INDENTED_VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::INDENTED_VALUE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::INDENTED_VALUE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::INDENTED_VALUE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::INDENTED_VALUE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LPDDEF::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LPDDEF::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LPDDEF::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LPDDEF::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt> AccessTemplateBase<::DLDL_LPDDEF::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>(Get<::DLDL_LPDDEF::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt> AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>(Get<::DLDL_LPDDEF::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument> AccessTemplateBase<::DLDL_LPDDEF::ast::node::stmt>::argument()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>(Get<::DLDL_LPDDEF::ast::Type::argument>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::COLON>(Get<::DLDL_LPDDEF::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>::argument_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name>(Get<::DLDL_LPDDEF::ast::Type::argument_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>::argument_block()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>(Get<::DLDL_LPDDEF::ast::Type::argument_block>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument>::VARNAME_EXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT>(Get<::DLDL_LPDDEF::ast::Type::VARNAME_EXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME>(Get<::DLDL_LPDDEF::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>::deamerreserved_star__argument_stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>(Get<::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>::argument_stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>(Get<::DLDL_LPDDEF::ast::Type::argument_stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>::LEFT_ANGLE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET>(Get<::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_block>::RIGHT_ANGLE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET>(Get<::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__> AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>::deamerreserved_star__argument_stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>(Get<::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt> AccessTemplateBase<::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__>::argument_stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>(Get<::DLDL_LPDDEF::ast::Type::argument_stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME>(Get<::DLDL_LPDDEF::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>::VARNAME_EXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::VARNAME_EXT>(Get<::DLDL_LPDDEF::ast::Type::VARNAME_EXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE> AccessTemplateBase<::DLDL_LPDDEF::ast::node::argument_stmt>::INDENTED_VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LPDDEF::ast::node::INDENTED_VALUE>(Get<::DLDL_LPDDEF::ast::Type::INDENTED_VALUE>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_LPDDEF::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_REFERENCE_ACCESSTEMPLATEBASE_H