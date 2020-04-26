// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")
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

template <class T>
vector<T> divisor(T n) {
  vector<T> ret;
  for (T i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return ret;
}

void solve() {
  int N;
  cin >> N;
  vector<int> c(N);
  for (int i = 0; i < N; i++) {
    cin >> c[i];
    c[i]--;
  }
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> nxt(N, 0);
  vector<int> subtree_size(N, 0);
  vector<ll> ans(N, (ll)N * (ll)(N - 1) / 2ll + (ll)N);
  function<void(int, int)> dfs = [&](int v, int p) {
    subtree_size[v] = 1;
    int pre = nxt[c[v]];
    for (auto u : g[v]) {
      if (u == p) continue;
      nxt[c[v]] = 0;
      dfs(u, v);
      //       dmp(v);
      //       dmp(u);
      //       dmp(nxt);
      ll a = subtree_size[u] - nxt[c[v]];
      ans[c[v]] -= a * (a - 1ll) / 2ll + a;
      subtree_size[v] += subtree_size[u];
    }
    nxt[c[v]] = pre + subtree_size[v];
  };
  dfs(0, -1);
  //   dmp(ans);
  //   dmp(nxt);
  for (int i = 0; i < N; i++) {
    ll a = N - nxt[i];
    ans[i] -= a * (a - 1ll) / 2ll + a;
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return;
}

signed main() {
  fastio();
  solve();
  //   int t;
  //   cin >> t;
  //   while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
