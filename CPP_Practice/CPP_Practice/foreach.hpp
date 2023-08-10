template<typename Iter, typename Callable>
void foreach(Iter cur, Iter end, Callable op)
{
	while (cur != end)
	{
		op(*cur);
		++cur;
	}
}