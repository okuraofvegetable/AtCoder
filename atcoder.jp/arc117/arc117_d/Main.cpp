#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define drep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)

#define popcount __builtin_popcount
#define next __next
#define prev __prev

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

// ------------------ ACL --------------------

// #include <atcoder/modint>
// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// using mint = atcoder::static_modint<MOD>;
// ostream &operator<<(ostream &os, const mint &v) {
//   return os << v.val();
// }

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

template <class Cost = int>
struct edge {
  int from, to;
  Cost cost;
  edge() {}
  edge(int f, int t, Cost cost) : from(f), to(t), cost(cost) {}
};

template <class Cost = int>
struct Tree {
  int V;
  int LOG_V;
  int root;
  vector<int> depth;
  vector<vector<int>> dpar;
  vector<int> par;
  vector<int> subtree_size;
  vector<Cost> dist; // distance from root node
  vector<vector<edge<Cost>>> G;
  Tree() {}
  Tree(int V, int r = 0) : V(V), root(r) {
    G.resize(V);
    depth.resize(V);
    par.resize(V);
    dist.resize(V);
    subtree_size.resize(V);
  }
  void add_edge(int u, int v, Cost c = Cost(0)) {
    G[u].emplace_back(u, v, c);
    G[v].emplace_back(v, u, c);
  }
  int dfs(int v, int p, int d, Cost c) {
    depth[v] = d;
    par[v] = p;
    subtree_size[v] = 1;
    dist[v] = c;
    for (auto e : G[v]) {
      int u = e.to;
      if (u == p) continue;
      subtree_size[v] += dfs(u, v, d + 1, c + e.cost);
    }
    return subtree_size[v];
  }
  void dfs() { dfs(root, -1, 0, Cost(0)); }

  void construct_dpar() {
    LOG_V = 1;
    while ((1 << LOG_V) <= V) LOG_V++;
    dpar.resize(LOG_V);
    for (int i = 0; i < LOG_V; i++) dpar[i].resize(V, -1);
    for (int i = 0; i < V; i++) dpar[0][i] = par[i];
    for (int i = 1; i < LOG_V; i++) {
      for (int j = 0; j < V; j++) {
        if (dpar[i - 1][j] == -1)
          dpar[i][j] = -1;
        else
          dpar[i][j] = dpar[i - 1][dpar[i - 1][j]];
      }
    }
    return;
  }
  int kth_parent(int v, int k) {
    int res = v;
    for (int i = 0; i < LOG_V; i++) {
      if (k & (1 << i)) res = dpar[i][res];
      if (res == -1) return -1;
    }
    return res;
  }
  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    v = kth_parent(v, depth[v] - depth[u]);
    if (u == v) return v;
    for (int i = LOG_V - 1; i >= 0; i--) {
      if (dpar[i][u] != dpar[i][v]) {
        u = dpar[i][u];
        v = dpar[i][v];
      }
    }
    return par[v];
  }
  Cost distance(int u, int v) {
    int l = lca(u, v);
    return dist[u] + dist[v] - dist[l] - dist[l];
  }
  int size() { return V; }
  void dump_tree() {
    for (int i = 0; i < V; i++) {
      printf("id: %d, par %d, depth %d\n", i, par[i], depth[i]);
    }
    return;
  }
};

void solve() {
  int N;
  cin >> N;
  Tree<int> T(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    T.add_edge(a, b);
  }

  function<pii(int, int)> rec = [&](int v, int p) {
    pair<int, int> r(0, v);
    for (auto e : T.G[v]) {
      if (e.to == p) continue;
      pair<int, int> t = rec(e.to, v);
      t.first++;
      chmax(r, t);
    }
    return r;
  };

  pii r = rec(0, -1);
  pii t = rec(r.second, -1);

  int A = r.second, B = t.second;
  dmp(A, B);

  T.root = A;
  T.dfs();
  T.construct_dpar();

  vector<ll> ans(N, -1ll);

  function<ll(int, int, ll)> dfs = [&](int v, int p, ll dist) {
    ans[v] = dist;
    int last = -1;
    for (auto e : T.G[v]) {
      if (e.to == p) continue;
      if (T.lca(e.to, B) == e.to) {
        last = e.to;
        continue;
      }
      dist = dfs(e.to, v, dist + 1);
    }
    if (last != -1) { dist = dfs(last, v, dist + 1); }
    return dist + 1;
  };

  dfs(A, -1, 1ll);

  for (int i = 0; i < N; i++) {
    cout << ans[i];
    if (i + 1 < N)
      cout << ' ';
    else
      cout << endl;
  }

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
