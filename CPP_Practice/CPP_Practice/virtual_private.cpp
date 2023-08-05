#include <iostream>

using namespace std;

class Parent
{
public:
	Parent() = default;
	virtual ~Parent() = default;

	void CallFunc()
	{
		func();
	}

private:
	virtual void func()
	{
		cout << "parent" << endl;
	}
};

class Child : public Parent
{
public:
	Child() = default;
	virtual ~Child() = default;

private:
	virtual void func()
	{
		cout << "child" << endl;
	}
};

int main()
{
	Child* child = new Child();
	Parent* child2 = child;

	child2->CallFunc();
	child->CallFunc();

	Parent* parent = new Parent();
	parent->CallFunc();

	return 0;
}