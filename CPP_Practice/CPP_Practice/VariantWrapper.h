#include <variant>
#include <string>

class VariantWrapper
{
	std::variant<bool, char, int, double, float, std::string> myVariant;
};

