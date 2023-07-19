#include <iostream>
#include <string>
#include <vector>

int main()
{
	// std::vector 자동 연역
	for (auto vec = std::vector{ 1, 2, 3 }; const auto& v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	using namespace std::string_literals;

	// 문자열 옆에 s 붙이면 해당 문자열을 std::string 객체로 생성해줌
	for (auto str = "hello world"s; auto c : str)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	return 0;
}