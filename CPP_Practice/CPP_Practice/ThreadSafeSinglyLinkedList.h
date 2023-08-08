#include <memory>
#include <atomic>

using namespace std;

template<typename T>
class ConcurrentStack
{
private:
	struct Node
	{
		T t;
		shared_ptr<Node> next;
	};

	atomic<shared_ptr<Node>> head;
	ConcurrentStack(ConcurrentStack&) = delete;
	void operator=(ConcurrentStack&) = delete;

public:
	ConcurrentStack() = default;
	~ConcurrentStack() = default;

	class Reference
	{
	private:
		shared_ptr<Node> p;

	public:
		Reference(shared_ptr<Node> in)
			: p(in)
		{
		}

		T& operator*() 
		{ 
			return p->t; 
		}
		T* operator->()
		{
			return &p->t;
		}
	};

	auto find(T t) const
	{
		auto p = head.load();
		while (p && p->t != t)
		{
			p = p->next;
		}

		return Reference(move(p));
	}

	auto front() const
	{
		return Reference(head);
	}

	void push_front(T t)
	{
		auto p = make_shared<Node>();
		p->t = t;
		p->next = head;
		while (!head.compare_exchange_weak(p->next, p))
		{
		}
	}

	void pop_front()
	{
		auto p = head.load();
		while (p && !head.comapare_exchange_weak(p, p->next))
		{
		}
	}
};