#include <string>

template<typename T>
class Cont
{
private:
	T* element;

public:
	// �Ʒ��� template ������ ������, �������� ������
	// ����, foo()�� ���ø� ��� �Լ��� �����Ͽ� foo()�� �ν��Ͻ�ȭ�� �� ���� 
	// is_move_constructible�� �򰡸� �̷� �������� ���������� �۵��ϰ� �� �� �ִ�.
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