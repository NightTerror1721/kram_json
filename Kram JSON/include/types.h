#ifndef __KRAM_JSON_TYPES_H__
#define __KRAM_JSON_TYPES_H__

#include "common.h"

namespace kram::json
{
	enum class Type
	{
		Null,
		Integer,
		Real,
		String,
		Array,
		Object
	};

	class Value
	{
	private:
		Type _type;

		union
		{
			Int64 _integer;
			double _real;
			std::string _string;
			std::vector<Value> _array;
			std::map<std::string, Value> _object;

			UInt8 _data[
				std::max(sizeof(_object),
					std::max(sizeof(_array), 
						std::max(sizeof(_string), 
							std::max(sizeof(_integer), sizeof(_real))
						)
					)
				)
			];
		};

	public:
		constexpr Value() :
			_type{ Type::Null },
			_data{}
		{}

		explicit Value(Type type);

		~Value();

		Value(const Value& value);
		Value(Value&& value) noexcept;
		
		Value& operator= (const Value& right);
		Value& operator= (Value&& right) noexcept;


	private:
		Value& _construct(Type type);
		Value& _destruct();
		Value& _copy(const Value& value);
		Value& _move(Value&& value) noexcept;
	};
}

#endif //__KRAM_JSON_TYPES__H__
