template<typename T, typename U>
void Apply(T func, U x)
{
	func(x);
}

template<typename T> void Single(T)
{

}

template<typename T> void Multi(T)
{

}

template<typename T> void Multi(T*)
{

}

int main()
{
	Apply(&Single<int>, 3);
	// ������ ����
	// Multi<int>�� ������ �־ T�� � Ÿ������ �����ؾ� �ϴ��� ��ȣ��
	//Apply(&Multi<int>, 3);
}
