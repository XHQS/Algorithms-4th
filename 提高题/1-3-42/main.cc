#include "stack/stack.h"
#include <iostream>
//#include <new>
int main() {
	Stack<int> s;
	for(int i = 0; i < 5; i++)
		s.push(i);
	//s.pop();
	Stack<int> t(s);
	for(int i = 0; i < 6; i++)
		std::cout<< t.pop() << " ";
	return 0;
}
