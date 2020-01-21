#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int s = a+b+c;
  if(s==a*2||s==b*2||s==c*2)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}