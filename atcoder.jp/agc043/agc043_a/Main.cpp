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
  int h, w;
  cin >> h >> w;
  vector<string> f(h);
  cin >> f;
  vector<vector<int>> dp = vect(h, vect(w, INF));
  dp[0][0] = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j - 1 >= 0) {
        if (f[i][j - 1] == f[i][j])
          chmin(dp[i][j], dp[i][j - 1]);
        else
          chmin(dp[i][j], dp[i][j - 1] + 1);
      }
      if (i - 1 >= 0) {
        if (f[i][j] == f[i - 1][j])
          chmin(dp[i][j], dp[i - 1][j]);
        else
          chmin(dp[i][j], dp[i - 1][j] + 1);
      }
    }
  }
  // dmp(dp);
  int base = 0;
  if (f[0][0] == '#') base++;
  if (f[h - 1][w - 1] == '#') base++;
  cout << (dp[h - 1][w - 1] + base) / 2 << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
