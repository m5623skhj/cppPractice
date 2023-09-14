#include <string>

template<typename T>
class Cont
{
private:
	T* element;

public:
	// 아래의 template 선언이 없으면, 컴파일이 실패함
	// 따라서, foo()를 템플릿 멤버 함수로 선언하여 foo()가 인스턴스화될 때 까지 
	// is_move_constructible의 평가를 미루어서 컴파일이 정상적으로 작동하게 할 수 있다.
	template<typename D = T>
	typename std::conditional<std::is_move_constructible<D>::value, T&&, T&>::type foo();
};

struct Node
{
	std::string value;
	Cont<Node> next;
};

int main()
{
	Node n;

	return 0;
}