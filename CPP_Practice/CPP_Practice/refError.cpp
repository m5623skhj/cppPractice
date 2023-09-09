template<typename T, T Z = T{} >
class RefMem
{
public:
	RefMem() : zero{ Z }
	{

	}

private:
	T zero;
};

int null = 0;

int main()
{
	RefMem<int> rm1, rm2;
	rm1 = rm2;

	//RefMem<int&> rm3;
	//RefMem<int&, 0> rm4;

	extern int null;
	RefMem<int&, null> rm5, rm6;
	//rm5 = rm6;
}