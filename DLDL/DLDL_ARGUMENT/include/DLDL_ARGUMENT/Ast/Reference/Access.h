#ifndef DLDL_ARGUMENT_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DLDL_ARGUMENT_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "DLDL_ARGUMENT/Ast/Relation/NodeEnumToType.h"
#include "DLDL_ARGUMENT/Ast/Relation/NodeTypeToEnum.h"
#include "DLDL_ARGUMENT/Ast/Relation/NodeIsInlined.h"

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"
#include "DLDL_ARGUMENT/Ast/Node/program.h"
#include "DLDL_ARGUMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/TEXT.h"
#include "DLDL_ARGUMENT/Ast/Node/VARNAME.h"
#include "DLDL_ARGUMENT/Ast/Node/ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace DLDL_ARGUMENT { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::DLDL_ARGUMENT::ast::Type T>
		void Get(std::vector<const ::DLDL_ARGUMENT::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::DLDL_ARGUMENT::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::DLDL_ARGUMENT::ast::relation::NodeIsInlined(static_cast<::DLDL_ARGUMENT::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::DLDL_ARGUMENT::ast::Type T, typename Q>
		inline std::vector<const ::DLDL_ARGUMENT::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::DLDL_ARGUMENT::ast::relation::NodeEnumToType_t<T>*> foundNodes;

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
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::program>;
	template<>
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::MULTI_COMMENT>;
	template<>
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::TEXT>;
	template<>
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::VARNAME>;
	template<>
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ARGUMENT::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ARGUMENT::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::program>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ARGUMENT::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ARGUMENT::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::program>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::MULTI_COMMENT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::MULTI_COMMENT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::MULTI_COMMENT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::MULTI_COMMENT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::TEXT> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ARGUMENT::ast::node::TEXT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ARGUMENT::ast::node::TEXT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::TEXT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::TEXT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::TEXT>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::TEXT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ARGUMENT::ast::node::TEXT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ARGUMENT::ast::node::TEXT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::TEXT>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::VARNAME> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ARGUMENT::ast::node::VARNAME*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ARGUMENT::ast::node::VARNAME*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::VARNAME& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::VARNAME* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::VARNAME>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::VARNAME>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ARGUMENT::ast::node::VARNAME*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ARGUMENT::ast::node::VARNAME*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::VARNAME>& for_all(FunctionType function)
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
	struct AccessTemplateBase<::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS>& operator[](::std::size_t index)
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

		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
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
				std::vector<const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS>& for_all(FunctionType function)
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
			if (node->GetType() == static_cast<::std::size_t>(::DLDL_ARGUMENT::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_REFERENCE_ACCESSTEMPLATEBASE_H