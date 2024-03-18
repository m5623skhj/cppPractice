#include <iostream>
#include <utility>

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

int main()
{
    int x = 5;
    int y = 10;
    Func(10, 20);
    Func(x, y);
    Func(30, std::move(x));
    return 0;
}
