
#include <iostream>
#include <new>
#include <string>
#include "prac_1_3_31.hpp"

using namespace std;

int main()
{
	DoubleNode<int> k;
	k.insert_begin(12);
	k.insert_begin(0);
	k.insert_end(13);
	k.insert_end(50);
	k.insert_prev((k.first)->next, 9);
	k.insert_prev((k.first)->next, 8);
	k.insert_next((k.end)->prev, 15);
	k.insert_next((k.end)->prev, 16);
	k.remove_begin();
	k.remove_begin();
	k.remove_end();
	k.remove_end();
	k.remove_node(k.first->next);
		k.remove_begin();
	k.remove_begin();
	k.remove_end();
	k.remove_end();
	for(auto *i = k.first; i != nullptr; i = i->next)
		cout << i->item << " ";

	return 0;
}