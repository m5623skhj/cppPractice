#include <iostream>
#include <utility>
#include <type_traits>

void Func_Result(int&& _)
{
    std::cout << "r" << std::endl;
}

void Func_Result(int& _)
{
    std::cout << "l" << std::endl;
}

template<typename T>
void CallFuncResult(T&& arg)
{
    Func_Result(std::forward<T>(arg));
}

template<typename T, typename... Args>
void CallFuncResult(T&& arg, Args&&... args)
{
    Func_Result(std::forward<T>(arg));
    CallFuncResult(std::forward<Args>(args)...);
}

template<typename... Args>
void Func(Args&&... args)
{
    CallFuncResult(std::forward<Args>(args)...);
}

template <typename T>
concept IsConstLValue = std::is_lvalue_reference_v<T> && std::is_const_v<std::remove_reference_t<T>>;

template <typename... Args>
requires(IsConstLValue<Args> && ...)
void OverloadTestFunc(Args const&... args)
{
    std::cout << "Func(lvalue const Arg&... args) called" << std::endl;
}

template <typename... Args>
void OverloadTestFunc(Args&&... args)
{
    std::cout << "Func(Arg&&... args) called" << std::endl;
}

int main()
{
    int x = 5;
    int y = 10;
    Func(10, 20);
    Func(x, y);
    Func(30, std::move(x));

    const int constItem1 = 0;
    const int constItem2 = 1;
    int item1 = 0;
    int item2 = 0;

    // OverloadTestFunc(constItem1);를 주석처리하고
    // OverloadTestFunc<const int&>(constItem1);만 호출하면
    // Func(lvalue const Arg&... args) called가 출력되는데
    // 주석을 해제하면 
    // 둘 다 Func(Arg&&... args) called가 출력됨
    // 함수 호출 모호성 때문인거 같음
    OverloadTestFunc(constItem1);
    OverloadTestFunc(constItem1, constItem2);

    OverloadTestFunc(1, 2);
    OverloadTestFunc(item1);
    OverloadTestFunc(item1, item2);

    std::cout << std::endl << std::endl;

    return 0;
}