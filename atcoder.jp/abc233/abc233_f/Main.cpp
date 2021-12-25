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

const bool multitest = false;

struct UnionFind {
  vector<int> par, rank, sz;
  UnionFind(int n) {
    par.assign(n, 0);
    rank.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) par[i] = i;
  }
  int find(const int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
      sz[y] += sz[x];
    } else {
      par[y] = x;
      sz[x] += sz[y];
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(const int x, const int y) { return find(x) == find(y); }
  int size(const int x) { return sz[find(x)]; }
  vector<vector<int>> components() {
    int n = par.size();
    vector<vector<int>> cs;
    vector<int> idx(n, -1);
    for (int i = 0; i < n; i++) {
      if (find(i) != i) continue;
      idx[i] = cs.size();
      cs.emplace_back();
    }
    for (int i = 0; i < n; i++) {
      int id = idx[find(i)];
      cs[id].push_back(i);
    }
    return cs;
  }
};

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
  vector<int> par_edge_id;
  vector<int> subtree_size;
  vector<Cost> dist; // distance from root node
  vector<vector<edge<Cost>>> G;
  Tree() {}
  Tree(int V, int r = 0) : V(V), root(r) {
    G.resize(V);
    depth.resize(V, -1);
    par.resize(V);
    par_edge_id.resize(V, -1);
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
      if (u == p) {
        par_edge_id[v] = e.cost;
        continue;
      }
      subtree_size[v] += dfs(u, v, d + 1, c + e.cost);
    }
    return subtree_size[v];
  }
  void dfs() {
    for (int i = 0; i < V; i++) {
      if (depth[i] == -1) dfs(i, -1, 0, Cost(0));
    }
  }

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
  vector<int> get_path(int s, int t) {
    if (s == t) return vector<int>();
    int l = lca(s, t);
    if (l != s && l != t) {
      auto p = get_path(s, l);
      auto q = get_path(l, t);
      p.insert(p.end(), q.begin(), q.end());
      return p;
    } else if (l == s) {
      vector<int> p;
      while (t != s) {
        p.push_back(par_edge_id[t]);
        t = par[t];
      }
      reverse(all(p));
      return p;
    } else {
      vector<int> p;
      while (t != s) {
        p.push_back(par_edge_id[s]);
        s = par[s];
      }
      return p;
    }
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
  vector<int> p(N);
  vector<int> pos(N);
  cin >> p;
  for (int i = 0; i < N; i++) {
    p[i]--;
    pos[p[i]] = i;
  }

  UnionFind uf(N);

  int M;
  cin >> M;
  vector<int> a(M), b(M);
  Tree<int> g(N);
  vector<int> deg(N, 0);
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    if (!uf.same(a[i], b[i])) {
      uf.unite(a[i], b[i]);
      g.add_edge(a[i], b[i], i);
      deg[a[i]]++;
      deg[b[i]]++;
    }
  }
  g.dfs();
  g.construct_dpar();

  auto cmps = uf.components();
  for (const auto &cmp : cmps) {
    vector<int> d;
    for (int c : cmp) { d.push_back(p[c]); }
    sort(all(d));
    // dmp(cmp, d);
    if (cmp != d) {
      cout << -1 << endl;
      return;
    }
  }

  auto apply = [&](int op_id) {
    int s = a[op_id], t = b[op_id];
    swap(pos[p[s]], pos[p[t]]);
    swap(p[s], p[t]);
  };

  vector<int> ans;
  vector<bool> used(N, false);
  for (const auto &cmp : cmps) {
    queue<int> q;
    for (int c : cmp) {
      if (deg[c] == 1) q.push(c);
    }
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      used[c] = true;
      auto path = g.get_path(pos[c], c);
      dmp(path);
      for (int v : path) {
        ans.push_back(v);
        apply(v);
      }
      assert(pos[c] == c);
      for (auto e : g.G[c]) {
        int v = e.to;
        if (used[v]) continue;
        deg[v]--;
        if (deg[v] == 1) { q.push(v); }
      }
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1;
    if (i + 1 < ans.size()) cout << ' ';
  }
  cout << endl;

  return;
}

int main() {
  fastio();
  if (!multitest) {
    solve();
  } else {
    cerr << "[Warning] Multi testcase mode on" << endl;
    int t;
    cin >> t;
    while (t--) solve();
  }
  return 0;
}
