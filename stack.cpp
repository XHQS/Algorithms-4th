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
	int N;

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
};