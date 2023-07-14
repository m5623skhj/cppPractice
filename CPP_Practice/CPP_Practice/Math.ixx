// ixx : MSVC �����Ϸ��� ��� ���Ͽ� ����ϴ� Ȯ����
// interface C++ source file

// �Ϲ����� ��� ����
// module -- ���� ��� ����
// #include<���� ���ȭ ���� ���� ���̺귯�� ���>
// export module math -- ��� ����, ��� ���� ����
// import<�鿩�� �ٸ� ����>
// <�������� ���� �����> -- �� ��� �ȿ����� ���̴� �̸�
// export namespace math
// {
//	<������ �����> -- ��� ����ڰ� ���� �� �̸�
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

export namespace math
{
	int add(int fir, int sec);
	int getProduct(const std::vector<int>& vec);
}

/*
// ���� ��� ���
// with MathModule1, 2.ixx

export module math;

export import math.math1;
export import math.math2;
//*/
