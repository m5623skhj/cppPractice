#include "Headers.h"
#include <coroutine>
#include <vector>

template<typename T>
struct Generator
{
	struct promise_type;
	using handleType = coroutine_handle<promise_type>;

	Generator(handleType handle)
		: coro(handle)
	{
	}

	~Generator()
	{
		if (coro != nullptr)
		{
			coro.destroy();
		}
	}

	Generator(const Generator&)=delete;
	Generator& operator = (const Generator&) = delete;
	Generator(Generator&& other)
		: coro(other.coro)
	{
		other.coro = nullptr;
	}

	Generator& operator=(Generator&& other)
	{
		coro = other.coro;
		other.coro = nullptr;
		return *this;
	}

	T getNextValue()
	{
		coro.resume();
		return coro.promise().current_value;
	}

	struct promise_type
	{
		promise_type()
		{
		}

		~promise_type()
		{
		}

		suspend_always initial_suspend()
		{
			return {};
		}

		suspend_always final_suspend() noexcept
		{
			return {};
		}

		auto get_return_object()
		{
			return Generator{ handleType::from_promise(*this) };
		}

		suspend_always yield_value(int value)
		{
			current_value = value;
			return {};
		}

		void return_void() {}
		void unhandled_exception()
		{
			exit(1);
		}

		T current_value;
	};

	handleType coro;
};

template<typename T>
Generator<typename T::value_type> GetNext(T cont)
{
	for (auto c : cont)
	{
		co_yield c;
	}
}

int main()
{
	string helloWorld = "Hello world";
	auto generator = GetNext(helloWorld);
	for (int i = 0; i < helloWorld.size(); ++i)
	{
		cout << generator.getNextValue() << " ";
	}
	cout << endl;

	auto generator2 = GetNext(helloWorld);
	for (int i = 0; i < 5; ++i)
	{
		cout << generator2.getNextValue() << " ";
	}
	cout << endl;

	vector vec{ 1, 2, 3, 4, 5 };
	auto generator3 = GetNext(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << generator3.getNextValue() << " ";
	}
	cout << endl;

	return 0;
}