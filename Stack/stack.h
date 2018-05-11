#include <iostream>
using namespace std;

class Stack
{
private:
	int* data;
	int size;
	int top;
public:
	Stack(int = 10);
	Stack(const Stack&);
	~Stack();
	void push(int); //insert
	void pop(); //delete
	int front(); //access to top element
	bool isEmpty();
	bool isFull();
	void print();
	void resize();
}; 
