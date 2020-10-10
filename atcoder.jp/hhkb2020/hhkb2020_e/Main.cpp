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
#define eps 1e-9
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
  int H, W;
  cin >> H >> W;
  vector<string> f(H);
  cin >> f;
  auto R = vect(H, vect(W, 0));
  auto L = vect(H, vect(W, 0));
  auto D = vect(H, vect(W, 0));
  auto U = vect(H, vect(W, 0));
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (f[i][j] == '.') {
        L[i][j] = 1;
        if (j > 0) L[i][j] += L[i][j - 1];
        cnt++;
      }
      // cout << L[i][j] << ' ';
    }
    // cout << endl;
  }
  for (int i = 0; i < H; i++) {
    for (int j = W - 1; j >= 0; j--) {
      if (f[i][j] == '.') {
        R[i][j] = 1;
        if (j + 1 < W) R[i][j] += R[i][j + 1];
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = W - 1; j >= 0; j--) {
      if (f[i][j] == '.') {
        U[i][j] = 1;
        if (i > 0) U[i][j] += U[i - 1][j];
      }
    }
  }
  for (int i = H - 1; i >= 0; i--) {
    for (int j = W - 1; j >= 0; j--) {
      if (f[i][j] == '.') {
        D[i][j] = 1;
        if (i + 1 < H) D[i][j] += D[i + 1][j];
      }
    }
  }
  mint ans(0);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (f[i][j] == '#') continue;
      int k = L[i][j] + R[i][j] + D[i][j] + U[i][j] - 3;
      ans += (mint::raw(2).pow(k) - mint::raw(1)) * mint::raw(2).pow(cnt - k);
    }
  }

  cout << ans.val() << endl;

  return;
}

signed main() {
  fastio();
  solve();
  // int t;
  // cin >> t;
  // while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
