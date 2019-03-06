/*
使用下压堆栈实现链表
含有操作：
1. first
2. isEmpty()
3. push()
4. pop()
5. size()
*/
template <typename Item>
class Node
{
public:
	Node(Item &a):item(a),next(nullptr){}
	Node(Node &n):item(n.item),next(nullptr){}
	Node():item(NULL),next(nullptr){}
	Item item;
	Node *next;
};


template <typename Item>
class List
{

public:
	Node<Item> * begin();
	int size()const;
	bool push(Node<Item> &n);
	bool pop();
	bool isEmpty() const;
	List();
	~List();
private:
	Node<Item> *first;
	Node<Item> *end;
	int length;


};
