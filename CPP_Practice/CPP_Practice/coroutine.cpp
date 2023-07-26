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

template<typename T>
struct Generator
{
	struct promise_type;
	using handle_type = coroutine_handle<promise_type>;

	Generator(handle_type handle) : coro(handle) // 3
	{

	}
	handle_type coro;

	~Generator()
	{
		if (coro)
		{
			coro.destroy();
		}
	}

	Generator(const Generator&) = delete;
	Generator& operator=(const Generator&) = delete;
	Generator(Generator&& other) noexcept : coro(other.coro)
	{
		other.coro = nullptr;
	}
	Generator& operator=(Generator&& other) noexcept
	{
		coro = other.coro;
		other.coro = nullptr;

		return *this;
	}

	T GetValue()
	{
		return coro.promise().current_value;
	}

	bool Next() // 5
	{
		coro.resume();
		return not coro.done();
	}

	struct promise_type
	{
		promise_type() = default; // 1
		~promise_type() = default;

		auto initial_suspend()
		{
			return suspend_always{}; // 4
		}
		auto final_suspend() noexcept
		{
			return suspend_always{};
		}
		auto get_return_object() // 2
		{
			return Generator{ handle_type::from_promise(*this) };
		}
		auto return_void()
		{
			return suspend_never{};
		}
		auto yield_value(const T value) // 6
		{
			current_value = value;
			return suspend_always{};
		}
		void unhandled_exception()
		{
			exit(1);
		}

		T current_value;
	};
};

Generator<int> GetNext(int start = 0, int step = 1)
{
	auto value = start;
	while (true)
	{
		co_yield value;
		value += step;
	}
}

int main()
{
	auto future = CreateFuture();
	cout << future.Get() << endl;

	auto gen = GetNext();
	for (int i = 0; i <= 10; ++i)
	{
		gen.Next();
		cout << gen.GetValue() << " ";
	}

	cout << endl;

	auto gen2 = GetNext(100, -10);
	for (int i = 0; i <= 20; ++i)
	{
		gen2.Next();
		cout << gen2.GetValue() << " ";
	}

	return 0;
}