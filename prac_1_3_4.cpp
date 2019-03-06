#include <iostream>
#include <fstream>
#include <new>
#include <string>

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
	Item pop()
	{
		Item item = first->item;
		first = first->next;
		N--;
		return item;
	}
};

bool Parentheses()
{

	using namespace std;
	string filename;

	cin >> filename;
	ifstream file(filename);
	if (! file.is_open())
	{
		cout << "Error opening file"; exit (1);
	}
	char ch;
	Stack<char> st;
	while(file >> ch)
	{
		if(ch == '(' || ch == '[' ||ch == '{')
			st.push(ch);
		else {
			switch(ch){
			case ')': { if(st.pop() != '(') return false; break; }
			case ']': { if(st.pop() != '[') return false; break; }
			case '}': { if(st.pop() != '{') return false; break; }
			}
		}
	}
	if(!st.isEmpty())
		return false;
	file.close();
	return true;
}
int main()
{
	std::cout << Parentheses();
	return 0;
}
