template<typename T>
class Node;

template<typename T>
class Tree
{
	friend class temp;
	// Node�� ������ ������ ������ �߻���
	friend class Node<T>;
};

template<typename T>
class _temp
{
	// Ŭ���� ���� �ƴ϶��, �ش� ������ ����
	friend T;
};

int main()
{


	return 0;
}