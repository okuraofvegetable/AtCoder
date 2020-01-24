#include <iostream>
using namespace std;
void rotate(int& x,int& y){
  swap(x,y);
  x *= -1;
}
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int x = c-a, y = d-b;
  rotate(x,y);
  cerr << x << ' ' << y << endl;
  c += x;
  d += y;
  cout << c << ' ' << d << ' ';
  rotate(x,y);
  c += x;
  d += y;
  cout << c << ' ' << d << endl;
  return 0;
}