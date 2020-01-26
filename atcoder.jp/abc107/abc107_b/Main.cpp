#include <bits/stdc++.h>
using namespace std;
int h,w;
int main(){
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin >> s[i];
  vector<bool> vert(h),hori(w);
  for(int i=0;i<h;i++){
    bool f = true;
    for(int j=0;j<w;j++){
      f &= (s[i][j]=='.');
    }
    vert[i] = f;
  }
  for(int j=0;j<w;j++){
    bool f = true;
    for(int i=0;i<h;i++){
      f &= (s[i][j]=='.');
    }
    hori[j] = f;
  }
  for(int i=0;i<h;i++){
    if(vert[i])continue;
    for(int j=0;j<w;j++){
      if(hori[j])continue;
      cout << s[i][j];
    }
    cout << endl;
  }
  return 0;
}