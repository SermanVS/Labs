#include <string>
#include <iostream>
#include "PQueue.h"
using namespace std;

int main()
{
	PQueue pq;
	pq.add("Kek", 5);
	pq.add("Lol", 6);
	pq.add("Wow", 3);
	pq.add("Jesus", 10);
	pq.print();
	system("pause");
	return 0;
}