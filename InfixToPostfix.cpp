#include <iostream>
#include <string>
#include <vector>
using namespace std;
class InfixToPostfix
{
private:
	vector<string> result;
	vector<string> ops;
	string exp;
public:
	InfixToPostfix() { 
		while(cin >> exp) {
			result.push_back(exp);
		}
	}
	void solution()	{
		for(auto i = result.begin(); i < result.end(); i++) {
			if(*i == "(")
				ops.push_back(*i);
			else if(*i == "+" || *i == "-" || *i == "*" || *i == "/") {
				while(1) {

					if(ops.empty()) { ops.push_back(*i); break;}
					else if(ops.back() == "(") { ops.push_back(*i); break;}
					else if((*i == "*" || *i == "/") && (ops.back() == "+" || ops.back() == "-")) {
						ops.push_back(*i); break;
					}
					else {
						cout << ops.back() << " ";
						ops.pop_back();
					}
						
				}
			}
			else if(*i == ")") {
				while(ops.back() != "("){
					cout << ops.back() << " ";
					ops.pop_back();
				}
				ops.pop_back();
			}
			else
				cout << *i << " ";
		}
		while(!ops.empty())
		{
			cout << ops.back() << " ";
			ops.pop_back();
		}
	}
};
int main() {
	InfixToPostfix su;
	su.solution();
	return 0;
}