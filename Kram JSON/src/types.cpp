#include "types.h"


namespace kram::json
{
	Value& Value::_construct(Type type)
	{
		_destruct();
		_type = type;

		switch (type)
		{
			case Type::String:
				utils::reconstruct(_string);
				break;

			case Type::Array:
				utils::reconstruct(_array);
				break;

			case Type::Object:
				utils::reconstruct(_object);
				break;
		}

		return *this;
	}
	Value& Value::_destruct()
	{
		switch (_type)
		{
			case Type::String:
				utils::destruct(_string);
				break;

			case Type::Array:
				utils::destruct(_array);
				break;

			case Type::Object:
				utils::destruct(_object);
				break;
		}
		_type = Type::Null;

		return *this;
	}
	Value& Value::_copy(const Value& value)
	{
		_construct(value._type);
		switch (_type)
		{
			case Type::Integer:
				_integer = value._integer;
				break;

			case Type::Real:
				_real = value._real;
				break;

			case Type::String:
				_string = value._string;
				break;

			case Type::Array:
				_array = value._array;
				break;

			case Type::Object:
				_object = value._object;
				break;
		}

		return *this;
	}

	Value& Value::_move(Value&& value) noexcept
	{
		_construct(value._type);
		switch (_type)
		{
			case Type::Integer:
				_integer = std::move(value._integer);
				break;

			case Type::Real:
				_real = std::move(value._real);
				break;

			case Type::String:
				_string = std::move(value._string);
				break;

			case Type::Array:
				_array = std::move(value._array);
				break;

			case Type::Object:
				_object = std::move(value._object);
				break;
		}

		return *this;
	}

	Value::Value(Type type) :
		Value{}
	{
		_construct(type);
	}

	Value::~Value() { _destruct(); }

	Value::Value(const Value& value) :
		Value{}
	{
		_copy(value);
	}
	Value::Value(Value&& value) noexcept :
		Value{}
	{
		_move(std::move(value));
	}

	Value& Value::operator= (const Value& right) { return _copy(right); }
	Value& Value:: operator= (Value&& right) noexcept { return _move(std::move(right)); }
}
