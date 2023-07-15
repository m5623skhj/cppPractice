#include <compare>
#include <iostream>

struct MyInt
{
	int value;
	explicit MyInt(int val) : value{ val } {}
	auto operator<=>(const MyInt& rhs) const
	{
		return value <=> rhs.value;
	}
};

struct MyDouble
{
	double value;
	explicit constexpr MyDouble(double val) : value{ val } {}
	auto operator<=>(const MyDouble&) const = default;
};

template<typename T>
constexpr bool isLessThen(const T& lhs, const T& rhs)
{
	return lhs < rhs;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 1;
	int d = -1;

	auto bRet = a <=> b;
	auto cRet = a <=> c;
	auto dRet = a <=> d;

	bRet.equal;
	cRet.less;
	dRet.greater;

	if (bRet == 0)
	{
		std::cout << " a = b " << std::endl;
	}
	if (cRet < 0)
	{
		std::cout << " a < c " << std::endl;
	}
	if (dRet > 0)
	{
		std::cout << " a > d " << std::endl;
	}
}