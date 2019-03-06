#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
using namespace std;

class EvalutatePostfix{
private:
	vector<int> val;
public:
	EvalutatePostfix() {}
	void Solution() {
		string s;
		while(cin >> s) {
			if(s != "+" && s != "-" && s != "*" && s != "/") {
				//const char* c = s;
				val.push_back(stoi(s));
			}
			else {
				int a,b;
				a = val.back();
				val.pop_back();
				b = val.back();
				val.pop_back();
				if(s == "+")
					val.push_back(a + b);
				else if(s == "-")
					val.push_back(b - a);
				else if(s == "*")
					val.push_back(a * b);
				else if(s == "/")
					val.push_back(b / a);
			}
		}
		cout << endl << val.back() << endl;;
	}
};

int main(){
	EvalutatePostfix a;
	a.Solution();
	return 0;
}