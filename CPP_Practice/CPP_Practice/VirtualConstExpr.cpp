#include <iostream>

using namespace std;

class Base
{
public:
	virtual constexpr int Func() { return 100; }
	virtual constexpr int Func2() { return test + 100; }
	virtual constexpr int Func3(int t) { return t + 100; }
	virtual constexpr int Func4(int t) { return t + test + 100; }
	virtual constexpr int Func5(int t) 
	{
		test = t + 100;
		return test;
	}
	virtual constexpr void Func6(int& t)
	{
		t = test + 100;
	}
	virtual constexpr int Func7(int t)
	{
		test = t + val;
		return test;
	}

protected:
	int test = 10;
	int val = 10000;
};

class Drived : public Base
{
public:
	virtual constexpr int Func() override { return 200; }
	virtual constexpr int Func2() override { return test + 200; }
	virtual constexpr int Func3 (int t) override { return t + 200; }
	virtual constexpr int Func4 (int t) override { return t + test + 100; }
	virtual constexpr int Func5 (int t) override
	{
		test = t + 200;
		return test;
	}
	virtual constexpr void Func6(int& t) override
	{
		t = test + 200;
	}
	virtual constexpr int Func7(int t) override
	{
		val = 20000;
		test = t + my_t;

		test += 200000;

		return test;
	}

private:
	int my_t = 200000;
};

int main()
{
	Base base;
	Drived drived, drived2;
	Base* drivedPtr = &drived2;

	int t = 1;

	cout << base.Func() << " " << drived.Func() << " " << drivedPtr->Func() << endl;
	cout << base.Func2() << " " << drived.Func2() << " " << drivedPtr->Func2() << endl;
	cout << base.Func3(t) << " " << drived.Func3(t) << " " << drivedPtr->Func3(t) << endl;
	cout << base.Func4(t) << " " << drived.Func4(t) << " " << drivedPtr->Func4(t) << endl;
	cout << base.Func5(t) << " " << drived.Func5(t) << " " << drivedPtr->Func5(t) << endl;

	int t1, t2, t3;
	base.Func6(t1);
	drived.Func6(t2);
	drivedPtr->Func6(t3);
	cout << t1 << " " << t2 << " " << t3 << endl;

	t1 = base.Func7(t);
	cout << t1 << " ";
	t2 = drived.Func7(t);
	cout << t2 << " ";
	t3 = drivedPtr->Func7(t);
	cout << t3 << endl;

	return 0;
}