#ifndef __KRAM_JSON_COMMOM_H__
#define __KRAM_JSON_COMMOM_H__

#include <type_traits>
#include <exception>
#include <algorithm>
#include <iostream>
#include <concepts>
#include <cstdint>
#include <utility>
#include <string>
#include <vector>
#include <map>


namespace kram
{
	typedef std::uint8_t UInt8;
	typedef std::uint16_t UInt16;
	typedef std::uint32_t UInt32;
	typedef std::uint64_t UInt64;

	typedef std::int8_t Int8;
	typedef std::int16_t Int16;
	typedef std::int32_t Int32;
	typedef std::int64_t Int64;

	using std::size_t;
}

namespace kram
{
	class JsonException : public std::exception
	{
		JsonException(const char* msg);
		JsonException(const std::string& msg);
	};
}

namespace kram::utils
{
	template<typename _Ty, typename... _Args>
	inline _Ty& reconstruct(_Ty& object, _Args&&... args)
	{
		new (&object) _Ty(std::forward<_Args>(args)...);
		return object;
	}

	template<typename _Ty>
	inline _Ty& destruct(_Ty& object)
	{
		object.~_Ty();
		return object;
	}
}

#endif //__KRAM_JSON_COMMOM_H__
