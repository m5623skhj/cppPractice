#include <iostream>
#include <typeinfo>

using namespace std;

class base
{
public:
	virtual void T() { cout << "A" << endl; }
};

class drived_1 : public base
{
public:
};

class drived_2 : public base
{
public:
};

int main()
{
	base* b = new base();
	base* d1 = new drived_1();
	base* d2 = new drived_2();

	cout << "test 1 cast : ";
	// base의 T()를 지우면 base가 다형 형식이 아니므로 캐스팅이 불가능
	// dynamic_cast는 RTTI 정보가 필요한데, RTTI는 가상함수가 정의될 때 해당 정보가 추가됨
	// 따라서, 가상함수가 없으므로 정상적으로 dynamic_cast를 수행할 수 없음
	if (auto test1 = dynamic_cast<drived_1*>(d1))
	{
		cout << "success " << typeid(test1).name() << " " << typeid(*test1).name() << endl;
	}
	else
	{
		cout << "failed" << endl;
	}

	cout << "test 2 cast : ";
	if (auto test2 = dynamic_cast<drived_2*>(d2))
	{
		cout << "success " << typeid(test2).name() << " " << typeid(*test2).name() << endl;
	}
	else
	{
		cout << "failed" << endl;
	}

	return 0;
}