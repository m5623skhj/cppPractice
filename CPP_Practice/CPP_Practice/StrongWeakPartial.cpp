#include <compare>

struct Strong
{
	std::strong_ordering operator<=>(const Strong&) const = default;
};

struct Weak
{
	std::weak_ordering operator<=>(const Weak&) const = default;
};

struct Partial
{
	std::partial_ordering operator<=>(const Partial&) const = default;
};

struct StrongWeakPartial
{
	Strong s;
	Weak w;
	Partial p;

	auto operator<=>(const StrongWeakPartial&) const = default;
};
