#include <utility>
#include <functional>

template<typename Iter, typename Callable, typename... Args>
void foreach(Iter cur, Iter end, Callable op, Args const&... args)
{
	while (cur != end)
	{
		std::invoke(op, args..., *cur);
		++cur;
	}
}