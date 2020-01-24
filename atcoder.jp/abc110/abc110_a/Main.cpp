#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int d = max(a,max(b,c));
  cout << d*10+a+b+c-d << endl;
  return 0;
}