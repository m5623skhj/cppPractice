// ixx : MSVC �����Ϸ��� ��� ���Ͽ� ����ϴ� Ȯ����
// interface C++ source file

module;

#include <numeric>
#include <vector>

export module math;

export int add(int fir, int sec)
{
	return fir + sec;
}

export int getProduct(const std::vector<int>& vec)
{
	return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}

// ��� ���� ��������
// export int mult(int fir, int sec);
// export void doTheMath();

// �׷� ��������
// export
// {
// 	int mult(int fir, int sec);
// 	void doTheMath();
// }

// namespace ��������
// export namespace math
// {
// 	int mult(int fir, int sec);
// 	void doTheMath();
// }