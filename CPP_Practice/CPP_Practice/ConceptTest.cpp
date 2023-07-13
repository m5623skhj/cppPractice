#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>

/*
	template<typename T>
	concept Recursive = Resucrsive<T*>

	concept�� ��������� ������ �� ����
*/

template<typename T>
concept Integral = std::is_integral<T>::value;

template <typename T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

template <typename T>
concept UnsignedIntegral = Integral<T> && SignedIntegral<T>;

/*
�Ʒ��� ����
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

// �� ����ü�� �̿��ؼ� AreEqual()�� �����Ű�� ������ ������ �߻�!
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

/// template �μ��� ��� ���� �����̰ų� ������ �����̾�� ��
/// ���� ����
/// �ݵ�� ���� ������� �����ؾ� ��
/// ���� ����, ����, ��� ����, �Ҹ�, ������
/// 
/// ������ ����
/// �⺻ ������, ���� ������, ���� ���� ������, �̵� ������, �̵� ���� ������, �Ҹ���
/// ���� �Բ� swap()�� ��ȿ�ؾ� ��

// ������ ����
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


