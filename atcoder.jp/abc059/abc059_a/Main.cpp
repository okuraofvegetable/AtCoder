#include <iostream>
#include <string>
using namespace std;
int main(){
  string a[3];
  for(int i=0;i<3;i++)cin >> a[i];
  for(int i=0;i<3;i++)cout << (char)(a[i][0]-'a'+'A');
  cout << endl;
  return 0;
}