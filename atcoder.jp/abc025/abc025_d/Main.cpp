// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-4
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
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

#include <atcoder/modint>

using mint = atcoder::static_modint<1000000007>;

void solve() {
  vector<vector<int>> f = vect(5, vect(5, 0));
  cin >> f;
  vector<int> pos(26, -1);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (f[i][j] != 0) pos[f[i][j]] = 5 * i + j;
    }
  }
  auto dp = vect(1 << 25, mint::raw(0));
  auto calc = vect(1 << 25, false);
  calc[0] = true;
  dp[0] = mint::raw(1);

  auto get_bit = [](int mask, int x, int y) -> int {
    int p = 5 * x + y;
    if ((mask >> p) & 1)
      return 1;
    else
      return 0;
  };

  auto judge = [&](int S, int p) {
    int x = p / 5;
    int y = p % 5;

    bool ok_x = false;
    if ((x - 1 < 0 || x + 1 >= 5))
      ok_x = true;
    else if ((get_bit(S, x - 1, y) ^ get_bit(S, x + 1, y)) != 1)
      ok_x = true;

    bool ok_y = false;
    if ((y - 1 < 0 || y + 1 >= 5))
      ok_y = true;
    else if ((get_bit(S, x, y - 1) ^ get_bit(S, x, y + 1)) != 1)
      ok_y = true;

    return ok_x && ok_y;
  };

  auto rec = [&](auto &&f, int S) -> mint {
    if (calc[S]) return dp[S];
    calc[S] = true;
    int num = __builtin_popcount(S);
    if (pos[num] != -1) {
      if (!((S >> pos[num]) & 1)) return dp[S];
      int T = S ^ (1 << pos[num]);
      if (judge(T, pos[num])) dp[S] += f(f, T);
    } else {
      for (int i = 0; i < 25; i++) {
        if (!((S >> i) & 1)) continue;
        int T = S ^ (1 << i);
        if (judge(T, i)) dp[S] += f(f, T);
      }
    }
    return dp[S];
  };
  cout << rec(rec, (1 << 25) - 1).val() << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
