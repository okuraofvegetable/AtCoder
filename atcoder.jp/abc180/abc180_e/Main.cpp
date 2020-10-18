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

struct city {
  ll x, y, z;
  city() {}
  city(ll x, ll y, ll z) : x(x), y(y), z(z) {}
  ll dist(city &a) { return abs(x - a.x) + abs(y - a.y) + max(0ll, a.z - z); }
};

void solve() {
  int N;
  cin >> N;
  vector<city> cs(N);
  for (int i = 0; i < N; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    cs[i] = city(a, b, c);
  }
  auto dp = vect(N, vect(1 << N, -1ll));
  dp[0][1] = 0ll;
  // for (int S = 0; S < (1 << N); S++) {
  //   for (int v = 0; v < N; v++) {
  //     if (dp[v][S] == LLINF) continue;
  //     for (int u = 0; u < N; u++) {
  //       if ((S >> u) & 1) continue;
  //       chmin(dp[u][S | (1 << u)], dp[v][S] + cs[v].dist(cs[u]));
  //     }
  //   }
  // }
  function<ll(int, int)> rec = [&](int v, int S) {
    if (dp[v][S] != -1ll) return dp[v][S];
    dp[v][S] = LLINF;
    for (int i = 0; i < N; i++) {
      if (i == v) continue;
      if ((S >> i) & 1) {
        chmin(dp[v][S], rec(i, (S ^ (1 << v))) + cs[i].dist(cs[v]));
      }
    }
    return dp[v][S];
  };
  ll ans = LLINF;
  // dmp(dp);
  for (int i = 0; i < N; i++) {
    chmin(ans, rec(i, (1 << N) - 1) + cs[i].dist(cs[0]));
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
