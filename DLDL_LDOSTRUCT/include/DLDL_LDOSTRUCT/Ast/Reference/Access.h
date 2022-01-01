#ifndef DLDL_LDOSTRUCT_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_LDOSTRUCT_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_LDOSTRUCT/Ast/Relation/NodeEnumToType.h"
#include "DLDL_LDOSTRUCT/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_LDOSTRUCT/Ast/Relation/NodeIsInlined.h"

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"
#include "DLDL_LDOSTRUCT/Ast/Node/program.h"
#include "DLDL_LDOSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LDOSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LDOSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LDOSTRUCT/Ast/Node/deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______.h"
#include "DLDL_LDOSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LDOSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LDOSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LDOSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LDOSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LDOSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LDOSTRUCT/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_LDOSTRUCT { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_LDOSTRUCT::ast::Type T>
		void Get(std::vector<const ::DLDL_LDOSTRUCT::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_LDOSTRUCT::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_LDOSTRUCT::ast::relation::NodeIsInlined(static_cast<::DLDL_LDOSTRUCT::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_LDOSTRUCT::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_LDOSTRUCT::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_LDOSTRUCT::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>;
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument> argument();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::argument& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::argument* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON> COLON();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name> argument_name();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block> argument_block();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> VARNAME_EXT();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_name*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_name*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::argument_name& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::argument_name* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_name*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_name*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> VARNAME();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_block*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_block*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::argument_block& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::argument_block* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_block*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::argument_block*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______> deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET> LEFT_ANGLE_BRACKET();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET> RIGHT_ANGLE_BRACKET();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> VARNAME();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> VARNAME_EXT();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE> INDENTED_VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______> deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> VARNAME();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> VARNAME_EXT();
AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE> INDENTED_VALUE();


		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::COLON*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::COLON*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::COLON& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::COLON* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::COLON*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::COLON*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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


	
		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>(Get<::DLDL_LDOSTRUCT::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>(Get<::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>(Get<::DLDL_LDOSTRUCT::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::stmt>::argument()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>(Get<::DLDL_LDOSTRUCT::ast::Type::argument>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>::COLON()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::COLON>(Get<::DLDL_LDOSTRUCT::ast::Type::COLON>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>::argument_name()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name>(Get<::DLDL_LDOSTRUCT::ast::Type::argument_name>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>::argument_block()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>(Get<::DLDL_LDOSTRUCT::ast::Type::argument_block>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument>::VARNAME_EXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>(Get<::DLDL_LDOSTRUCT::ast::Type::VARNAME_EXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_name>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>(Get<::DLDL_LDOSTRUCT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>(Get<::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>::LEFT_ANGLE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET>(Get<::DLDL_LDOSTRUCT::ast::Type::LEFT_ANGLE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>::RIGHT_ANGLE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET>(Get<::DLDL_LDOSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>(Get<::DLDL_LDOSTRUCT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>::VARNAME_EXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>(Get<::DLDL_LDOSTRUCT::ast::Type::VARNAME_EXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::argument_block>::INDENTED_VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>(Get<::DLDL_LDOSTRUCT::ast::Type::INDENTED_VALUE>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>(Get<::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>::VARNAME()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME>(Get<::DLDL_LDOSTRUCT::ast::Type::VARNAME>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>::VARNAME_EXT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>(Get<::DLDL_LDOSTRUCT::ast::Type::VARNAME_EXT>(ts));
		}

		inline AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE> AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>::INDENTED_VALUE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>(Get<::DLDL_LDOSTRUCT::ast::Type::INDENTED_VALUE>(ts));
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_LDOSTRUCT::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_REFERENCE_ACCESSTEMPLATEBASE_H