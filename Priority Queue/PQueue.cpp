#include "PQueue.h"
#include <iostream>
using namespace std;

PQueue::PQueue()
{
	first = last = nullptr;
}
PQueue::~PQueue()
{
	while (!isEmpty()) pop();
}
bool PQueue::isEmpty() const
{
	return first == nullptr;
}
void PQueue::add(string n, int p)
{
	Link* tmp = new Link;
	tmp->task.name = n;
	tmp->task.priority = p;
	if (isEmpty() == true)
	{
		first = last = tmp;
		tmp->next = tmp->prev = nullptr;
	}
	else
	{
		Link* cur = first;
		while (cur != nullptr && cur->task.priority > tmp->task.priority)
		{
			cur = cur->next;
		}
		if (cur == nullptr)
		{
			last->next = tmp;
			tmp->prev = last;
			tmp->next = nullptr;
			last = tmp;
		}
		else if (cur->prev == nullptr)
		{
			cur->prev = tmp;
			tmp->next = cur;
			tmp->prev = nullptr;
			first = tmp;
		}
		else
		{
			cur->prev->next = tmp;
			tmp->next = cur;
			tmp->prev = cur->prev;
			cur->prev = tmp;
		}
	}
}
Task PQueue::front() const
{
	if (isEmpty()) return Task("", -1);
	else return first->task;
}
void PQueue::pop()
{
	if (!isEmpty())
	{
		first = first->next;
		if (first == nullptr)
		{
			delete last;
			last = nullptr;
		}
		else
		{
			delete first->prev;
			first->prev = nullptr;
		}
	}
}
PQueue::PQueue(const PQueue& pq)
{
	first = last = nullptr;
	for (Link* cur = pq.first; cur != nullptr; cur = cur->next)
	{
		add(cur->task.name, cur->task.priority);
	}
}
void PQueue::print()
{
	if (!isEmpty())
	{
		for (Link* cur = first; cur != nullptr; cur = cur->next)
		{
			cout << cur->task.name << " with the priority of " << cur->task.priority << endl;
		}
	}
	else cout << "empty" << endl;
}