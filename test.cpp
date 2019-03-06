#include <iostream>
#include <vector>
 
void print_vec(const std::vector<int>& vec)
{
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}
 
int main ()
{
    std::vector<int> vec(3,100);
    print_vec(vec);
 
    auto it = vec.rbegin()+1;
    it = vec.insert(it, 200);
    print_vec(vec);
 
   return 0;
}