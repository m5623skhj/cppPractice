template<typename T>
class Node;

template<typename T>
class Tree
{
	friend class temp;
	// Node가 없으면 컴파일 에러가 발생함
	friend class Node<T>;
};

template<typename T>
class _temp
{
	// 클래시 형이 아니라면, 해당 선언을 무시
	friend T;
};

int main()
{


	return 0;
}