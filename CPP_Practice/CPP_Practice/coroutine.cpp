#include <iostream>
#include <coroutine>
#include <memory>

using namespace std;

template<typename T>
struct MyFuture
{
	MyFuture(shared_ptr<T> ptr) : value(ptr) {}
	~MyFuture() = default;

	// �̰Ÿ� �̷��� �����ؾ߸� �ϴ� ��?
	// ����ü ���̳� �Լ� ���� �����غôµ�, ������ �߻���
	struct promise_type
	{
		MyFuture<T> get_return_object()
		{
			return ptr;
		}

		void return_value(T val)
		{
			*ptr = val;
		}

		suspend_never initial_suspend()
		{
			return {};
		}

		suspend_never final_suspend() noexcept
		{
			return {};
		}

		void unhandled_exception()
		{
			exit(1);
		}

		~promise_type() = default;

		shared_ptr<T> ptr = make_shared<T>();
	};

	T Get()
	{
		return *value;
	}

	shared_ptr<T> value;
};

MyFuture<int> CreateFuture()
{
	co_return 2021;
}

int main()
{
	auto future = CreateFuture();
	cout << future.Get() << endl;

	return 0;
}