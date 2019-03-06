#include <new>
#include <iostream>
#include <memory>

using namespace std;

template<typename Item>
class Stack
{
private:
	class Node {
	public:
		Item item;
		Node *next;
	};
	Node *first;
	int N=0;

public:
	bool isEmpty() { return first == nullptr; }
	int size() { return N; }
	void push(Item item){
		Node *oldfirst = first;
		first = new Node();
		first->item = item;
		first->next = oldfirst;
		N++;
	}
	Item pop() {
		Item item = first->item;
		first = first->next;
		N--;
		return item;
	}

	shared_ptr<Stack<Item>> copy() {
		shared_ptr<Stack<Item>> Sc = make_shared<Stack<Item>>();
		Node * s_node = this->first;
		for(int i = 0; i < this->size(); i++) {
			Sc->push(s_node->item);
			s_node = s_node->next;
		}
		return Sc;
	}
};

int main() {
	Stack<int> a;
	for(int i = 0;i < 5;i++) 
		a.push(2);

	shared_ptr<Stack<int>> b = a.copy();

	for(int i = 0;i < 5;i++) 
		cout << a.pop() << " ";
	cout << endl;

	for(int i = 0;i < 5;i++) 
		cout << b->pop() << " ";
	return 0;
}