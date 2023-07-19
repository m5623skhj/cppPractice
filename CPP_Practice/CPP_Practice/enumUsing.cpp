#include <iostream>
#include <string_view>

using namespace std;

enum class Color
{
	RED,
	GREEN,
	BLUE
};

string_view ToString(Color color)
{
	switch (color)
	{
	// 지역 범위 using 열거형
	using enum Color;
	case RED:
		return "red";
	case GREEN:
		return "green";
	case BLUE:
		return "blue";
	}

	return "invalid";
}

int main()
{
	cout << "red : " << ToString(Color::RED) << endl;

	return 0;
}