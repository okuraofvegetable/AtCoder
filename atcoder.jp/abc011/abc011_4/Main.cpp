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

void solve() {

  int N, D;
  cin >> N >> D;
  int X, Y;
  cin >> X >> Y;

  if (X % D != 0 || Y % D != 0) {
    cout << 0 << endl;
    return;
  }
  X /= D;
  Y /= D;
  if (abs(X) + abs(Y) > N || (abs(X) + abs(Y)) % 2 != N % 2) {
    cout << 0 << endl;
    return;
  }

  // nCr[i][j] = (i choose j) / (2 ^ i)
  auto nCr = vect(N + 1, vect(N + 1, 0.0));
  nCr[0][0] = 1.0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j > 0)
        nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) / 2.0;
      else
        nCr[i][j] = nCr[i - 1][j] / 2.0;
    }
  }

  double ans = 0.0;
  for (int i = 0; i <= N; i++) {
    if (i % 2 != abs(X) % 2) continue;
    if ((N - i) % 2 != abs(Y) % 2) continue;
    if (i < abs(X) || (N - i) < abs(Y)) continue;
    int a1 = (i + X) / 2;
    // int a2 = (i - X) / 2;
    int b1 = (N - i + Y) / 2;
    // int b2 = (N - i - Y) / 2;
    ans += nCr[N][i] * nCr[i][a1] * nCr[N - i][b1];
  }
  cout << ans << endl;
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
