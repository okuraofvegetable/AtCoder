#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000               // 2e9
#define LLINF 2000000000000000000ll  // 2e18 (llmax:9e18)
#define fi first
#define sec second
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define dmp(x) cerr << #x << ": " << x << endl;

template <class T>
void chmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, const T &b) {
  if (a < b) a = b;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.fi << ',' << p.sec;
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.fi >> p.sec;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 < vec.size()) os << ' ';
  }
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}
void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

#define endl "\n"

void solve() {
  int N, K, C;
  cin >> N >> K >> C;
  string s;
  cin >> s;
  vector<int> mx(N, 0);
  {
    vector<int> nxt(N);
    vector<int> idx;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'o') idx.push_back(i);
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'x') {
        nxt[i] = -2;
        continue;
      }
      int k = upper_bound(all(idx), i + C) - idx.begin();
      if (k == idx.size())
        nxt[i] = -1;
      else
        nxt[i] = idx[k];
    }
    // dmp(nxt);
    mx[0] = (s[0] == 'o') ? 1 : 0;
    for (int i = 0; i < N; i++) {
      if (i + 1 < N) chmax(mx[i + 1], mx[i]);
      if (nxt[i] >= 0) chmax(mx[nxt[i]], mx[i] + 1);
    }
    // dmp(mx);
    for (int i = 0; i < N; i++) {
      if (s[i] == 'x') { continue; }
      if (i > 0 && mx[i - 1] == mx[i]) continue;
    }
  }

  vector<int> mx2(N, 0);
  {
    vector<int> nxt(N);
    vector<int> idx;
    reverse(all(s));
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'o') idx.push_back(i);
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'x') {
        nxt[i] = -2;
        continue;
      }
      int k = upper_bound(all(idx), i + C) - idx.begin();
      if (k == idx.size())
        nxt[i] = -1;
      else
        nxt[i] = idx[k];
    }
    // dmp(nxt);
    for (int i = 0; i < N; i++) mx2[i] = (s[i] == 'o') ? 1 : 0;
    for (int i = 0; i < N; i++) {
      if (i + 1 < N) chmax(mx2[i + 1], mx2[i]);
      if (nxt[i] >= 0) chmax(mx2[nxt[i]], mx2[i] + 1);
    }
    // dmp(mx2);
    reverse(all(s));
    reverse(all(mx2));
  }
  dmp(mx);
  dmp(mx2);
  for (int i = 0; i < N; i++) {
    if (s[i] == 'x') { continue; }
    if (i > 0 && mx[i - 1] == mx[i]) continue;
    if (i + 1 < N && mx2[i + 1] == mx2[i]) continue;
    if (K - mx2[i] + 1 == mx[i] && mx[i] <= K) cout << i + 1 << endl;
  }
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
