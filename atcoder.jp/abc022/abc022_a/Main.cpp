#include <iostream>
using namespace std;
int main(){
  int n,s,t,w;
  cin >> n >> s >> t >> w;
  int ans = 0;
  for(int i=0;i<n;i++){
    int a = 0;
    if(i>0)cin >> a;
    w+=a;
    if(s<=w&&w<=t)ans++;
  }
  cout << ans << endl;
  return 0;
}