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

// #include <atcoder/modint>
// using mint = atcoder::static_modint<1000000007>;

template <class Cost>
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

template <class Cost>
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

  // verified
  // https://atcoder.jp/contests/dwacon6th-final-open/submissions/10023433
  vector<Cost> dijkstra(int s) {
    assert(0 <= s && s < G.size());
    vector<Cost> dist;
    dist.assign(G.size(), numeric_limits<Cost>::max());
    dist[s] = Cost(0);
    MinHeap<pair<Cost, int>> q;
    q.push(make_pair(Cost(0), s));
    while (!q.empty()) {
      auto a = q.top();
      q.pop();
      int v = a.second;
      if (dist[v] < a.first) continue;
      for (auto e : G[v]) {
        if (dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          q.push(make_pair(dist[e.to], e.to));
        }
      }
    }
    return dist;
  }

  // for debug
  friend ostream &operator<<(ostream &os, const Graph &g) {
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
  int N, a;
  cin >> N >> a;
  a--;
  Graph<int> G(N);
  string k;
  cin >> k;
  vector<int> b(N);
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    b[i]--;
    G.add_edge(i, b[i]);
  }
  if (k.size() <= 6) {
    int K = stoi(k);
    int ans = a;
    for (int i = 0; i < K; i++) ans = b[ans];
    cout << ans + 1 << endl;
    return;
  }
  SCC<Graph<int>> scc(G);
  auto &cs = scc.cmp;
  vector<int> loop(N, 0);
  int loop_len = -1;
  for (const auto &c : cs) {
    if (c.size() <= 1) continue;
    for (int v : c) { loop[v] = c.size(); }
  }
  int cur = a;
  int step = 0;
  while (!loop[cur]) {
    cur = b[cur];
    step++;
  }
  loop_len = loop[cur];
  // dmp(loop_len);
  // dmp(step);
  // dmp(cur);
  int K = 0;
  for (int i = 0; i < k.size(); i++) {
    int d = k[i] - '0';
    K = (K * 10 + d) % loop_len;
  }
  // dmp(K);
  K = (K - (step % loop_len) + loop_len) % loop_len;
  for (int i = 0; i < K; i++) cur = b[cur];
  cout << cur + 1 << endl;
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
