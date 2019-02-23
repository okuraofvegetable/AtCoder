#include <iostream>
#include <set>
using namespace std;
int main(){
  int a;
  cin >> a;
  set<int> s;
  for(int i=1;;i++){
    if(s.find(a)!=s.end()){
      cout << i << endl;
      return 0;
    }
    s.insert(a);
    if(a&1)a=a*3+1;
    else a=a/2;
  }
  return 0;
}