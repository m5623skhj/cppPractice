#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>

/*
	template<typename T>
	concept Recursive = Resucrsive<T*>

	concept는 재귀적으로 정의할 수 없음
*/

template<typename T>
concept Integral = std::is_integral<T>::value;

template <typename T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

template <typename T>
concept UnsignedIntegral = Integral<T> && SignedIntegral<T>;

/*
아래와 같음
// requires constraintExpression;
template<typename T>
concept UnsignedIntegral = Integral<T> &&
	requires(T)
{
	requires !SignedIntegral<T>;
};
*/

template <typename T>
concept Arthmetic = Integral<T> || std::is_floating_point<T>::value;


template<typename T>
concept Addable = requires(T a, T b)
{
	a + b;
};

template <typename>
struct Other;

template<>
struct Other<std::vector<int>> {};

// requires (ParameterList) { requirementSequence }
template<typename T>
concept TypeRequirement = requires
{
	typename T::value_type;
	typename Other<T>;
};

// { expression } (noexcept) (returnType);
template<typename T>
concept Equal = requires(T a, T b)
{
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
};

bool AreEqual(Equal auto a, Equal auto b)
{
	return a == b;
}

// 이 구조체를 이용해서 AreEqual()을 실행시키면 컴파일 에러가 발생!
struct WithoutEqual
{
	bool operator==(const WithoutEqual& other) = delete;
};

template<typename T>
concept Ordering = Equal<T> &&
	requires(T a, T b)
{
	{ a <= b } -> std::convertible_to<bool>;
	{ a < b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;
};

/// template 인수는 적어도 정규 형식이거나 준정규 형식이어야 함
/// 정규 형식
/// 반드시 다음 연산들을 지원해야 함
/// 복사 생성, 배정, 상등 판정, 소멸, 전순서
/// 
/// 준정규 형식
/// 기본 생성자, 복사 생성자, 복사 배정 연산자, 이동 생성자, 이동 배정 연산자, 소멸자
/// 위와 함께 swap()이 유효해야 함

// 준정규 형식
template<typename T>
struct IsSemiRegular :
	std::integral_constant<bool,
	std::is_default_constructible<T>::value&&
	std::is_copy_constructible<T>::value&&
	std::is_copy_assignable<T>::value&&
	std::is_move_constructible<T>::value&&
	std::is_move_assignable<T>::value&&
	std::is_destructible<T>::value&&
	std::is_swappable<T>::value> {};

template<typename T>
concept SemiRegular = IsSemiRegular<T>::value;


