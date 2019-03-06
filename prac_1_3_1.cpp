/*
** 为FixedCapacityStackOfStrings添加一个方法isFull()
*/
#include <iostream>
#include <string>

template<typename Item>
class FixedCapacityStack
{
private:
	int N = 0;
	int length = 0;
	Item * a;
public:
	FixedCapacityStack(int cap):length(cap)
	{ a = new Item [cap]; }
	bool isEmpty() { return N == 0; }
	bool isFull() { return N == length;}
	int size() { return N; }
	void push(Item item) { a[N++] = item; }
	Item pop() { return a[--N]; }
};

int main()
{
	using namespace std;
	FixedCapacityStack<std::string> a(2);
	FixedCapacityStack<int> b(1);
	cout << a.isFull() << endl;
	a.push("1");
	cout << a.isFull() << endl;
	cout << a.isEmpty() << endl;
	a.push("2");
	cout << a.isEmpty() << endl;
	return 0;
}
