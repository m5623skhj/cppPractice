#include <iostream>
#include <string>

struct Implicit
{
	template<typename T>
	Implicit(T t)
	{
		std::cout << t << std::endl;
	}
};

struct Explicit
{
	template<typename T>
	explicit Explicit(T t)
	{
		std::cout << t << std::endl;
	}
};

struct MyBool
{
	template<typename T>
	explicit(std::is_same<T, bool>::value == false) MyBool(T t)
	{
		std::cout << typeid(t).name() << std::endl;
	}
};

void NeedBool(MyBool b)
{

}

int main()
{
	Implicit im1 = "impl";
	Implicit im2("expl");
	Implicit im3 = 1998;
	Implicit im4(1998);

	std::cout << std::endl;

	// 암묵적 변환 불가
	//Explicit ex1 = "impl";
	Explicit ex2{ "expl" };
	//Explicit ex3 = 1998;
	Explicit ex4{ 1998 };

	std::cout << std::endl;

	MyBool bo1(true);
	MyBool bo2 = false;

	NeedBool(bo1);
	NeedBool(true);
	NeedBool(5);
	NeedBool("true");

	return 0;
}