/* 
** 实现一个嵌套类DoubleNode用来构造双向链表，
** 其中每个节点都含有一个指向前驱元素的引用和一项指向后续元素的引用。
** 
** 方法：表头插入、表尾插入、表头删除、表尾删除、
** 指定节点前插入、指定节点后插入、指定节点删除
*/
#include "prac_1_3_31.hpp"
#include <iostream>

template<typename Item>
void DoubleNode<Item>::insert_begin(Item item) {
	Node *in = new Node(item);
	if(this->first == nullptr)
		end = first = in;
	else{
		in->next = first;
		first = in;
	}
}

template<typename Item>
void DoubleNode<Item>::insert_end(Item item) {
	Node *in = new Node(item);
	if(this->end == nullptr)
		end = first = in;
	else {
		end->next = in;
		end = in;
	}
}

template<typename Item>
bool DoubleNode<Item>::remove_begin() {
	if(first == nullptr) {
		std::cout << "cannot remove the NULL list";
		return 0;
	}
	else if(first->next == nullptr) {
		delete first;
		first = end = nullptr;
	}
	else {
		auto k = first->next;
		delete first;
		first = k;
	}
	return 1;
}

template<typename Item>
bool DoubleNode<Item>::remove_end() {
	if(end == nullptr) {
		std::cout << "cannot remove the NULL list";
		return 0;
	}
	else if(end->prev == nullptr) {
		delete end;
		first = end = nullptr;
	}
	else {
		auto k = end->prev;
		delete end;
		end = k;
	}
	return 1;
}

template<typename Item>
void DoubleNode<Item>::insert_prev(Node *node,Item item) {
	Node *in = new Node(item);
	in->next = node;
	if(node == nullptr)
		node = in;
	else if(node->prev == nullptr) {
		node->prev = in;
		first = in;
	}
	else {
		auto k = node->prev;
		node->prev = in;
		k->next = in;
		in->prev = k;
	}
}

template<typename Item>
void DoubleNode<Item>::insert_next(Node *node,Item item) {
	Node *in = new Node(item);
	in->prev = node;

	if(node == nullptr)
		node = in;
	else if(node->next == nullptr) {
		node->next = in;
		end = in;
	}
	else {
		auto k = node->next;
		node->next = in;
		k->prev = in;
		in->next = k;
	}
}

template<typename Item>
bool DoubleNode<Item>::remove_node(Node *node){
	auto pre = node->prev;
	auto nex = node->next;
	if(pre == nullptr)
		return remove_begin();
	else if(nex == nullptr)
		return remove_end();
	else {
		pre->next = nex;
		nex->prev = pre;
		delete node;
	}
	return 1;
}