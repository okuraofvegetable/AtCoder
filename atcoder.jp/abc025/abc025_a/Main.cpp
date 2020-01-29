#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n;
  cin >> s;
  cin >> n;
  vector<string> vec;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      string t;
      t += s[i];
      t += s[j];
      vec.push_back(t);
    }
  }
  sort(vec.begin(),vec.end());
  cout << vec[n-1] << endl;
  return 0;
}