#ifndef PRAC_1_3_31_H_
#define PRAC_1_3_31_H_
/* 
** 实现一个嵌套类DoubleNode用来构造双向链表，
** 其中每个节点都含有一个指向前驱元素的引用和一项指向后续元素的引用。
** 
** 方法：表头插入、表尾插入、表头删除、表尾删除、
** 指定节点前插入、指定节点后插入、指定节点删除
*/
template<typename Item>
class DoubleNode{
private:
	class Node{
	public:
		Item item;
		Node *prev;
		Node *next;
		Node():prev(nullptr),next(nullptr) {}
		Node(Item a):item(a),prev(nullptr),next(nullptr) {}
	};
public:
	
	Node *first;
	Node *end;
	void insert_begin(Item);
	void insert_end(Item);
	bool remove_begin();
	bool remove_end();
	void insert_prev(Node *,Item);
	void insert_next(Node *,Item);
	bool remove_node(Node *);

	DoubleNode():first(nullptr),end(nullptr) {}
};

#endif