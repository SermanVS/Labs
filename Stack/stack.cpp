#include <iostream>
#include "stack.h"
using namespace std;



Stack::Stack(int s)
{
	if (s <= 0 || s > 1000000)
	{
		throw 1; // 1 - undefined or wrong size;
	}
	size = 0;
	size += s;
	data = new int[size];
	top = 0;
}
Stack::Stack(const Stack& s)
{
	size = s.size;
	top = s.top;
	data = new int[size];
	for (int i = 0; i < top; i++)
	{
		data[i] = s.data[i];
	}
}
Stack::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}
void Stack::resize()
{
	int nsize = 2 * size;
	int* ndata = new int[nsize];
	for (int i = 0; i < size; i++)
	{
		ndata[i] = data[i];
	}
	delete[] data;
	data = ndata;
	size = nsize;
}
bool Stack::isEmpty()
{
	return top == 0;
}
bool Stack::isFull()
{
	return top == size;
}
void Stack::push(int val)
{
	if (isFull()) resize();
	data[++top] = val;
}
void Stack::pop()
{
	if (isEmpty()) throw 3; // 3 - stack is empty
	top--;
}
int Stack::front()
{
	if (isEmpty()) throw 3;
	return data[top - 1];
}
void Stack::print()
{
	for (int i = top; i > 0; i--)
	{
		cout << data[i] << " " << endl;
	}
}