//#include "/stack/stack.h"
//#include <string>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc,char *argv[]){
	/*Question 1
	int num = 0;
	string s;
	while(cin >> s) {
		if(s == "-")
			num--;
		else
			num++;
		if(num < 0){
			cout << "overflow the stack\n";
			return 1;
		}
	}
	cout << num << ": pop successfully" << endl;*/
	/*Question 2*/
	vector<int> min;
	min.push_back(atoi(argv[1]));




	for(int i = 2; i < argc; i++) {
		if(min.back() - 1 == atoi(argv[i]))
			min.pop_back();

		if(min.back() < atoi(argv[i])||(min.back() - 1 == atoi(argv[i]))){
			int j = 1;
			for(; j < i; j++)
				if(atoi(argv[i]) - 1 == atoi(argv[j]))
					break;;
			if(atoi(argv[i]) - 1 != atoi(argv[j]))
				min.push_back(atoi(argv[i]));
		}
		else{
			cout << min.back() << endl;
			cout << "error\n";
			exit(1);
		}
		cout << argv[i] << " ";
	}
	cout << "successful\n";
	return 0;
}