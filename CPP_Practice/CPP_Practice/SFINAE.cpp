// from https://ko.wikipedia.org/wiki/SFINAE

#include <iostream>
#include <type_traits>

template <typename... Ts>
using void_t = void;

template <typename T, typename = void>
struct has_typedef_foobar : std::false_type {};

template <typename T>
struct has_typedef_foobar<T, void_t<typename T::foobar>> : std::true_type {};

template <typename T>
struct has_typedef_foobar<T, void_t<typename T::temp>> : std::true_type {};

struct foo
{
	using foobar = float;
};

template <typename T>
struct has_member_variable_temp
{
	template <typename U>
	static auto test(int) -> decltype(U::t, std::true_type());

	template <typename>
	static std::false_type test(...);

	using type = decltype(test<T>(0));
	static constexpr bool value = type::value;
};

struct temp
{

};

struct foo2
{
	temp t;
};

struct foo3 : public foo
{

};

int main()
{
	std::cout << std::boolalpha;

	std::cout << has_typedef_foobar<int>::value << std::endl;
	std::cout << has_typedef_foobar<foo>::value << std::endl;
	std::cout << has_typedef_foobar<foo2>::value << std::endl;
	std::cout << has_typedef_foobar<foo3>::value << std::endl;

	std::cout << has_member_variable_temp<foo>::value << std::endl;
	std::cout << has_member_variable_temp<foo2>::value << std::endl;
	std::cout << has_member_variable_temp<foo3>::value << std::endl;
}