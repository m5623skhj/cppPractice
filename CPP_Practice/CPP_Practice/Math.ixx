// ixx : MSVC 컴파일러가 모듈 파일에 사용하는 확장자
// interface C++ source file

// 일반적인 모듈 구조
// module -- 전역 모듈 조각
// #include<아직 모듈화 되지 않은 라이브러리 헤더>
// export module math -- 모듈 선언, 모듈 범위 시작
// import<들여올 다른 모듈들>
// <내보내지 않을 선언들> -- 이 모듈 안에서만 보이는 이름
// export namespace math
// {
//	<내보낼 선언들> -- 모듈 사용자가 보게 될 이름
// }


module;

#include <vector>

export module math;

//export int add(int fir, int sec)
//{
//	return fir + sec;
//}
//
//export int getProduct(const std::vector<int>& vec)
//{
//	return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
//}

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

export namespace math
{
	int add(int fir, int sec);
	int getProduct(const std::vector<int>& vec);
}

/*
// 하위 모듈 사용
// with MathModule1, 2.ixx

export module math;

export import math.math1;
export import math.math2;
//*/
