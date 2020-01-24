#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='9')cout << 1;
    else if(s[i]=='1')cout << 9;
    else cout << s[i];
  }
  cout << endl;
  return 0;
}