#include <string>

template<typename... Mixin>
class Point : public Mixin...
{
	double x;
	double y;
	double z;

public:
	Point(Mixin... mixin) : Mixin(mixin)...
	{
	}

	template<typename Visitor>
	void VisitMixin(Visitor visitor)
	{
		visitor(static_cast<Mixin&>(*this)...);
	}
};

struct Color 
{
	char red;
	char green;
	char blue;
};

struct Label
{
	std::string name;
};

// Color, Label 둘 다 상속받아짐
Point<Color, Label> point({ 1, 2, 3 }, {"my name"});

int main()
{

	return 0;
}