#include <iostream>
#include <coroutine>
#include <memory>

using namespace std;

template<typename T>
struct MyFuture
{
	MyFuture(shared_ptr<T> ptr) : value(ptr) {}
	~MyFuture() = default;

	// 이거를 이렇게 정의해야만 하는 듯?
	// 구조체 명이나 함수 명을 변경해봤는데, 에러가 발생함
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