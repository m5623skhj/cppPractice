#include "Headers.h"
#include <coroutine>

template<typename T>
struct MyFuture
{
	shared_ptr<T> value;
	MyFuture(shared_ptr<T> p) :
		value(p)
	{
		cout << " MyFuture::MyFuture" << endl;
	}

	~MyFuture()
	{
		cout << " MyFuture::~MyFuture" << endl;
	}

	T get()
	{
		cout << " MyFuture::get" << endl;
		return *value;
	}

	struct promise_type
	{
		shared_ptr<T> ptr = make_shared<T>();
		promise_type()
		{
			cout << " promise_type::promise_type" << endl;
		}

		~promise_type()
		{
			cout << " promise_type::~promise_type" << endl;
		}

		MyFuture<T> get_return_object()
		{
			cout << " promise_type::get_return_object" << endl;
			return ptr;
		}

		void return_value(T v)
		{
			cout << " promise_type::return_value" << endl;
		}

		suspend_never initial_suspend()
		{
			cout << " promise_type::initial_suspend" << endl;
			return {};
		}

		suspend_never final_suspend() noexcept
		{
			cout << " promise_type::final_suspend" << endl;
			return {};
		}

		void unhandled_exception()
		{
			exit(1);
		}
	};
};

MyFuture<int> CreateFuture()
{
	cout << "CreateFuture" << endl;
	co_return 2021;
}

int main()
{
	auto future = CreateFuture();
	auto res = future.get();

	cout << "res : " << res << endl;
}