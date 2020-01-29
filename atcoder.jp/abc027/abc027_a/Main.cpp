#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> v(3);
  map<int,int> m;
  for(int i=0;i<3;i++){
    cin >> v[i];
    m[v[i]]++;
  }    
  for(int i=0;i<3;i++){
    if(m[v[i]]%2==1){
      cout << v[i] << endl;
      return 0;
}      
  }    
  return 0;
}