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
	// base�� T()�� ����� base�� ���� ������ �ƴϹǷ� ĳ������ �Ұ���
	// dynamic_cast�� RTTI ������ �ʿ��ѵ�, RTTI�� �����Լ��� ���ǵ� �� �ش� ������ �߰���
	// ����, �����Լ��� �����Ƿ� ���������� dynamic_cast�� ������ �� ����
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