#include <new>
#include <iostream>
using namespace std;

template<typename Item>
class Solution{
private:
	int n = 0;
	int max = 3;
	Item* ar =  new Item[max];
public:
	~Solution() {
		delete [] ar;
	}
	void enqueue(Item data) {
		if(n >= max) {
			max += 10;
			Item* ar2 =  new Item[max];
			for(int i = 0; i < max - 10; i++) {
				ar2[i] = ar[i];
			}
			delete [] ar;
			ar = ar2;
		}
		ar[n] = data;
		n++;//increase the number of member
	}
	Item dequeue() {
		if(!this->isEmpty())
			return ar[--n];
		return 0;
	}
	bool isEmpty(){
		if(n == 0)
			return true;
		return false;
	}
	int size() {
		return max;
	}
};

int main() {
	Solution<int> A;
	for(int i = 0; i < 10; i++)
		A.enqueue(5);
	for(int i = 0; i < A.size(); i++)
		cout << A.dequeue() << " ";
	return 0;
}