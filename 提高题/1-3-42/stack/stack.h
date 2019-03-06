#ifndef STACK_H_
#define STACK_H_
#include <vector>
#include <iostream>

using namespace std;

template<typename Item>
class Stack
{
private:
	class Node {
	public:
		Item item;
		Node *next = nullptr;
	};
	Node *first = nullptr;
	int N = 0;

public:
	Stack(Stack<Item> &cs) {
		vector<Item> a(cs.N);
		for(int i = 0; i < a.size(); i++)
			a[i] = cs.pop();
		for(int i = a.size() - 1; i >= 0; i--){
			push(a[i]);
			cs.push(a[i]);
		}
	}
	Stack(){}
	~Stack(){
		while(!isEmpty())
			pop();
	}

	bool isEmpty() { return N == 0; }
	int size() { return N; }
	void push(Item item){
		Node *oldfirst = first;
		first = new Node();
		first->item = item;
		first->next = oldfirst;
		N++;
	}
	Item pop() {
		if(isEmpty()){
			std::cout << "cannot delete the empty stack";
			exit(1);
		}
		Item item = first->item;
		auto k = first->next;
		delete first;
		first = k;
		N--;
		return item;
	}
};
#endif
