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
	// 컴파일 에러
	// Multi<int>가 여러개 있어서 T가 어떤 타입으로 연역해야 하는지 모호함
	//Apply(&Multi<int>, 3);
}
