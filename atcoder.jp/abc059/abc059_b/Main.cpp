#include <iostream>
#include <string>
using namespace std;
int main(){
  string a,b;
  cin >> a;
  cin >> b;
  if(a.size()>b.size()){
    cout << "GREATER" << endl;
  }else if(b.size()>a.size()){
    cout << "LESS" << endl;
  }else{
    if(a<b)cout << "LESS" << endl;
    else if(a>b)cout << "GREATER" << endl;
    else cout << "EQUAL" << endl;
  }
  return 0;
}