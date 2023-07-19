#include <iostream>
#include <string>
#include <vector>

int main()
{
	// std::vector �ڵ� ����
	for (auto vec = std::vector{ 1, 2, 3 }; const auto& v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	using namespace std::string_literals;

	// ���ڿ� ���� s ���̸� �ش� ���ڿ��� std::string ��ü�� ��������
	for (auto str = "hello world"s; auto c : str)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	return 0;
}