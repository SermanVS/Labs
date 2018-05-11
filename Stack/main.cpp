#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	Stack st(10);
	st.push(15);
	st.push(10);
	st.push(11);
	st.push(1);
	st.print();
	cin.get();
	return 0;
}