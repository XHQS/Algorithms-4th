#include <iostream>
#include <new>
#include <string>

using namespace std;

template<typename Item>
class prac_1_3_29{
private:
	class Node{
	public:
		Item item;
		Node *next = nullptr;
		Node(Item a):item(a){}
		Node(Item a,Node *b):item(a),next(b) {}
	};
	int N = 0;
public:
	Node *first = nullptr;
	Node *end = nullptr;

	void enqueue(Item item){
		if(first == nullptr) { //one element
			first = new Node(item);
			end = first;
			first->next = end;
			N = 1;
		}
		else if(first->next == first) {
			first = new Node(item);
			first->next = end;
			end->next = first;
			N = 2;
		}
		else {
			first = new Node(item,first);
			end->next = first;
			N++;
		}
	}
	Item dequeue() {
		Item re;
		if(end == nullptr){ // list is empty
			cout << "cannot delete NULL list\n";
			exit(1);
		}
		else if(end->next == end) { //list has only one element
			re = end->item;
			delete end;
			first = end = nullptr;
			N = 0;
		}
		else {
			re = end->item;
			auto k = first;
			while(k->next != end)
				k = k->next;
			k->next = first;
			delete end;
			end = k;
			N--;
		}
		return re;
	}

};

int main() {
	prac_1_3_29<int> solution;
	for(int i = 0; i < 5; i++)
		solution.enqueue(i);

	auto k = solution.first;
	for(int i = 0; i < 5; i++){
		cout << k->item << " ";
		k=k->next;
	}
	cout << endl;
	for(int i = 0; i < 5; i++)
		cout << solution.dequeue() << " ";
	return 0;
}