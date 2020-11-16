#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

#ifndef LOCAL
#define dmp(...) ;
#else
#define dmp(...)                                                               \
  cerr << "[ " << #__VA_ARGS__ << " ] : " << dump_str(__VA_ARGS__) << endl
#endif

// ---------------- Utility ------------------

template <class T>
bool chmin(T &a, const T &b) {
  if (a <= b) return false;
  a = b;
  return true;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a >= b) return false;
  a = b;
  return true;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

// ----------------- Input -------------------

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}

template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}

// ----------------- Output ------------------

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ',' << p.second;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const T &e : v) os << e << " ";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const deque<T> &d) {
  for (const T &e : d) os << e << " ";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{ ";
  for (const T &e : s) os << e << " ";
  return os << "}";
}

template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
  os << "{ ";
  for (const auto &[key, val] : m) os << "( " << key << " -> " << val << " ) ";
  return os << "}";
}

void dump_str_rec(ostringstream &) {}

template <class Head, class... Tail>
void dump_str_rec(ostringstream &oss, Head &&head, Tail &&... tail) {
  oss << ", " << head;
  dump_str_rec(oss, forward<Tail>(tail)...);
}

template <class T, class... U>
string dump_str(T &&arg, U &&... args) {
  ostringstream oss;
  oss << arg;
  dump_str_rec(oss, forward<U>(args)...);
  return oss.str();
}

// --------------- Fast I/O ------------------

void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

// ------------ End of template --------------

#define endl "\n"

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  cin >> A;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto dp = vect(N, vect(N, LLINF));
  auto ep = vect(N, vect(N, LLINF));
  auto sz = vect(N, 0);
  function<void(int, int)> rec = [&](int v, int p) {
    sz[v] = 1;
    dp[v][0] = A[v];
    if (A[v] > 0) ep[v][0] = A[v];
    for (int u : g[v]) {
      if (u == p) continue;
      rec(u, v);
      auto tdp = dp[v];
      auto edp = ep[v];
      for (int i = 0; i < sz[v]; i++) { dp[v][i] = ep[v][i] = LLINF; }
      for (int i = 0; i < sz[v]; i++) {
        for (int j = 0; j < sz[u]; j++) {
          // v-uを切らない
          chmin(dp[v][i + j], tdp[i] + dp[u][j]);
          chmin(ep[v][i + j], edp[i] + ep[u][j]);
          // v-uを切る
          if (dp[u][j] < 0) {
            chmin(dp[v][i + j + 1], tdp[i]);
            chmin(ep[v][i + j + 1], edp[i]);
          }
          if (ep[u][j] < LLINF) {
            chmin(dp[v][i + j + 1], tdp[i]);
            chmin(ep[v][i + j + 1], edp[i]);
          }
        }
      }
      sz[v] += sz[u];
    }
    return;
  };
  rec(0, -1);
  int ans = INF;
  for (int i = 0; i < N; i++) {
    if (dp[0][i] < 0) chmin(ans, i);
    if (ep[0][i] < LLINF) chmin(ans, i);
  }
  cout << ans << endl;
  return;
}

int main() {
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
