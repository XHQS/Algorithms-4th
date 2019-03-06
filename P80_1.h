/*P80 Dijkstra 的双栈算术表达式求值算法
**逻辑：
将操作数压入操作数栈；
将运算符压入运算符栈；
忽略左括号；
再遇到右括号时，弹出一个运算符，弹出所需数量的操作数，并将运算符和操作数的运算结果压入操作数栈
**
**
*/
#include <string>
using std::string;
class Calculation
{
public:
	Calculation();
	~Calculation();
	void start();
};