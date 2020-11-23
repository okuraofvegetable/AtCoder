#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
using P = pair<int, ll>;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<P>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    ll s;
    cin >> u >> v >> s;
    u--;
    v--;
    g[u].emplace_back(v, s);
    g[v].emplace_back(u, s);
  }
  vector<int> depth(N, -1);
  vector<ll> A(N);
  // depth : even -> x + A[i]
  //       : odd  -> -x + A[i]
  bool fail = false;
  ll L = 1, R = LLINF;
  vector<ll> sol;
  function<void(int, int, ll)> dfs = [&](int v, int d, ll a) {
    depth[v] = d;
    A[v] = a;
    if (d % 2 == 0)
      chmax(L, -A[v] + 1);
    else
      chmin(R, A[v] - 1);
    for (auto [u, c] : g[v]) {
      if (depth[u] != -1) {
        int diff = abs(depth[v] - depth[u]);
        if (diff % 2 == 1) {
          if (A[u] + A[v] != c) { fail = true; }
        } else {
          if ((c - A[u] - A[v]) % 2 == 1) { fail = true; }
          ll fix = (c - A[u] - A[v]) / 2;
          if (d % 2 == 1) fix *= -1;
          sol.push_back(fix);
        }
      } else {
        dfs(u, d + 1, c - A[v]);
      }
    }
  };
  dfs(0, 0, 0ll);
  if (!sol.empty()) {
    if (sol.front() < L || sol.front() > R) fail = true;
    for (int i = 1; i < sol.size(); i++)
      if (sol[i] != sol.front()) fail = true;
  }
  dmp(A);
  dmp(sol, fail);
  dmp(L, R);
  if (fail) {
    cout << 0 << endl;
    return;
  }
  if (!sol.empty()) {
    cout << 1 << endl;
    return;
  }
  cout << max(0ll, R - L + 1) << endl;
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
