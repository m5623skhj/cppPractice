// ixx : MSVC 컴파일러가 모듈 파일에 사용하는 확장자
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

// 모듈 개별 내보내기
// export int mult(int fir, int sec);
// export void doTheMath();

// 그룹 내보내기
// export
// {
// 	int mult(int fir, int sec);
// 	void doTheMath();
// }

// namespace 내보내기
// export namespace math
// {
// 	int mult(int fir, int sec);
// 	void doTheMath();
// }