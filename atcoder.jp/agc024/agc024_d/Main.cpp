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

template <class TupleTy, size_t... I>
void dump_tuple(ostream &os, const TupleTy t, std::index_sequence<I...>) {
  (..., (os << (I == 0 ? "" : ",") << std::get<I>(t)));
}

template <class... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
  os << "(";
  dump_tuple(os, t, std::make_index_sequence<sizeof...(Args)>());
  return os << ")";
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
  vector<vector<int>> g(N);

  auto dist = vector(N, vector(N, INF / 2));
  for (int i = 0; i < N; i++) dist[i][i] = 0;

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    dist[a][b] = dist[b][a] = 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  function<P(int, int)> dfs = [&](int v, int p) {
    P res(0, v);
    for (int u : g[v]) {
      if (u == p) continue;
      auto c = dfs(u, v);
      c.first++;
      chmax(res, c);
    }
    return res;
  };

  // calculate diameter
  auto [_, v] = dfs(0, -1);
  auto [d, u] = dfs(v, -1);

  vector<ll> max_branch(N, 1);
  int max_depth = 0;

  function<void(int, int, int)> ffs = [&](int v, int p, int d) -> void {
    ll branch = 0;
    for (int u : g[v]) {
      if (u == p) continue;
      branch++;
      ffs(u, v, d + 1);
    }
    chmax(max_branch[d], branch);
    chmax(max_depth, d);
    return;
  };

  ll ans = numeric_limits<ll>::max();

  auto refl = [&](int c1, int c2) {
    max_branch.assign(N, 1);
    max_depth = 0;
    ffs(c1, c2, 0);
    ffs(c2, c1, 0);

    if (max_depth > d / 2) return;

    ll res = 2ll;
    bool overflow = false;
    for (int i = 0; i < N; i++) {
      if (ans / res < max_branch[i]) {
        overflow = true;
        break;
      }
      res *= max_branch[i];
    }
    if (!overflow) chmin(ans, res);
    return;
  };

  auto point_sym = [&](int center) {
    max_branch.assign(N, 1);
    max_branch[0] = g[center].size();
    max_depth = 0;
    for (int v : g[center]) ffs(v, center, 1);

    if (max_depth > d / 2) return;

    ll res = 1ll;
    bool overflow = false;
    for (int i = 0; i < N; i++) {
      if (ans / res < max_branch[i]) {
        overflow = true;
        break;
      }
      res *= max_branch[i];
    }
    if (!overflow) chmin(ans, res);
    return;
  };

  for (int i = 0; i < N; i++) point_sym(i);
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (dist[i][j] == 1) refl(i, j);
    }
  }

  cout << d / 2 + 1 << ' ' << ans << endl;

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
