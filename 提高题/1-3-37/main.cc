#include <iostream>
#include <stdlib.h>
#include "queue.h"
int main(int argc,char *argv[]){
	Queue<int> order,buff;
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	for(int i = 0; i < N; i++)
		order.enqueue(i);
	while(!order.Earn()) {
		for(int i = 1; i < M ; i++) {
			buff.enqueue(order.dequeue());
		}
		std::cout << order.dequeue() << " ";
		while(!buff.isEmpty())
			order.enqueue(buff.dequeue());
	}
	std::cout << order.dequeue() << " ";
	std::cout << "\nover\n";
	return 0;
}
