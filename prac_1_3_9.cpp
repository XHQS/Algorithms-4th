#include <vector>
#include <string>
#include <iostream>

using std::vector,std::string,std::cin;

class Solution
{
	
private:
	vector<string> A;
	int num = 0;
public:
	//constructor
	Solution() {}
	//destructor
	~Solution() {}
	//functions
	void push(string s) { A.push_back(s); }
	//string pop() { return A.pop_back(); }
	bool isEmpty() { return num; }
	void input() {
		string num;
		while(cin >> num) {
				A.push_back(num);
		}
	}
	void print_vec(const std::vector<string>& vec)
	{
	    for (auto x: vec) {
	         std::cout << ' ' << x;
	    }
	    std::cout << '\n';
	}
	void prac_1_3_9() {
		int key1 = 0;
		input();
		for(std::vector<std::string>::iterator i = A.end()-1;i >= A.begin() ;i--) {
			if(*i == ")")
				key1++;
			else if(*i == "+" || *i == "-" || *i == "*" || *i == "/") {
				--i;
				if(*i != ")" && key1 > 0) {
					
					--key1;
					i = A.insert(i,"(");
				}
			}
		}
		print_vec(A);

	}

};

int main(){
	Solution su;
	su.prac_1_3_9();
	return 0;
}
