#pragma once
#include <string>
using namespace std;

struct Task
{
	string name;
	int priority;
	Task(string n = "", int p = -1) : name(n), priority(p) {}
};
class PQueue
{
	struct Link
	{
		Task task;
		Link* next;
		Link* prev;
	};
	Link* first;
	
public:
	Link* last;
	PQueue();
	~PQueue();
	PQueue(const PQueue&);
	Task front() const;
	void add(string n, int p);
	bool isEmpty() const;
	void pop();
	void print();
};