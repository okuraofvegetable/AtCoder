#include <bits/stdc++.h>
using namespace std;
int main () {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) ans += s[i] - '0';
    else ans -= s[i] - '0';
  }
  cout << ans << endl;
  return 0;
}