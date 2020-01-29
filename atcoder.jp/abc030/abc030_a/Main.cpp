#include <iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> b >> a >> d >> c;
  if(a*d>b*c)cout << "TAKAHASHI" << endl;
  else if(a*d==b*c)cout << "DRAW" << endl;
  else cout << "AOKI" << endl;
  return 0;
}