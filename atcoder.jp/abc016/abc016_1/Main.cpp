#include <iostream> 
#include <string>
int main(){
  int a,b;
  std::cin >> a >> b;
  std::cout << (std::string)((a%b==0)?"YES":"NO") << std::endl;
  return 0;
}