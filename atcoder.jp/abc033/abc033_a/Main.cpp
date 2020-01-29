#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(s[i]!=s[0]){
      cout << "DIFFERENT" << endl;
      return 0;
    }
  }
  cout << "SAME" << endl;
  return 0;
}