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

#include <atcoder/modint>
// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint &v) {
  return os << v.val();
}

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

template <class Cost = int>
struct edge {
  int from, to;
  Cost cost;
  edge() {}
  edge(int from, int to, Cost cost) : from(from), to(to), cost(cost) {}

  // for debug
  friend ostream &operator<<(ostream &os, const edge &e) {
    os << e.from << " -> " << e.to << " : " << e.cost << ", ";
    return os;
  }
};

template <class Cost = int>
struct Graph {
  int V;
  vector<vector<edge<Cost>>> G;
  Graph() {}
  Graph(int V) : V(V) { G.resize(V); }
  void add_edge(int a, int b, Cost cost = Cost(0)) {
    G[a].push_back(edge<Cost>(a, b, cost));
  }
  void add_edge_undirected(int a, int b, Cost cost = Cost(0)) {
    G[a].push_back(edge<Cost>(a, b, cost));
    G[b].push_back(edge<Cost>(b, a, cost));
  }
  size_t size() const { return G.size(); }
  const vector<edge<Cost>> &operator[](int id) const { return G[id]; }

  // for debug
  friend ostream &operator<<(ostream &os, const Graph g) {
    for (int i = 0; i < g.size(); i++) {
      os << g[i];
      if (i + 1 < g.size()) os << endl;
    }
    return os;
  }
};

// verified https://judge.yosupo.jp/submission/3440
template <class Graph>
struct SCC {
  Graph G, rG; // Graph and reverse Graph
  vector<bool> used;
  vector<int> vs;
  vector<int> cmp_id;      // component id
  vector<vector<int>> cmp; // components
  explicit SCC(const Graph G) : G(G) {
    rG = Graph(G.size());
    used.resize(G.size(), false);
    cmp_id.resize(G.size(), -1);
    for (int i = 0; i < G.size(); i++) {
      for (auto e : G[i]) { rG.add_edge(e.to, e.from, e.cost); }
    }
    for (int i = 0; i < G.size(); i++) {
      if (!used[i]) dfs(i);
    }
    used.assign(G.size(), false);
    reverse(vs.begin(), vs.end());
    int id = 0;
    for (int i = 0; i < vs.size(); i++) {
      if (!used[vs[i]]) {
        cmp.push_back(vector<int>());
        rdfs(vs[i], id++);
      }
    }
  }
  void dfs(int s) {
    used[s] = true;
    for (const auto &e : G[s]) {
      if (!used[e.to]) dfs(e.to);
    }
    vs.push_back(s);
  }
  void rdfs(int s, int k) {
    used[s] = true;
    cmp_id[s] = k;
    cmp[k].push_back(s);
    for (const auto &e : rG[s]) {
      if (!used[e.to]) rdfs(e.to, k);
    }
  }
};

void solve() {
  int N;
  cin >> N;
  vector<string> s(N);
  cin >> s;
  vector<string> zip;
  for (int i = 0; i < N; i++) {
    zip.push_back(s[i].substr(0, 3));
    zip.push_back(s[i].substr(s[i].size() - 3));
  }
  sort(all(zip));
  zip.erase(unique(all(zip)), zip.end());
  vector<int> from(N), to(N);
  Graph g(zip.size());
  for (int i = 0; i < N; i++) {
    from[i] = lower_bound(all(zip), s[i].substr(0, 3)) - zip.begin();
    to[i] = lower_bound(all(zip), s[i].substr(s[i].size() - 3)) - zip.begin();
    g.add_edge(from[i], to[i]);
  }

  SCC scc(g);
  int M = scc.cmp.size();
  vector<int> state(zip.size(), 2);

  for (int i = M - 1; i >= 0; i--) {
    queue<int> q;
    for (int v : scc.cmp[i]) q.push(v);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      bool all_win = true;
      bool exist_lose = false;
      for (auto e : g[v]) {
        if (state[e.to] == 0) exist_lose = true;
        if (state[e.to] != 1) all_win = false;
      }
      assert(!(all_win && exist_lose));
      if (all_win) state[v] = 0;
      if (exist_lose) state[v] = 1;
      if (all_win || exist_lose) {
        for (auto e : scc.rG[v]) {
          if (state[e.to] == 2) q.push(e.to);
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (state[to[i]] == 0) cout << "Takahashi" << endl;
    if (state[to[i]] == 1) cout << "Aoki" << endl;
    if (state[to[i]] == 2) cout << "Draw" << endl;
  }
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
