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

// verified
// https://atcoder.jp/contests/dwacon6th-final-open/submissions/10023433
template <class Cost>
vector<Cost> dijkstra(Graph<Cost> &g, int s) {
  assert(0 <= s && s < g.size());
  vector<Cost> dist;
  dist.assign(g.size(), numeric_limits<Cost>::max());
  dist[s] = Cost(0);
  MinHeap<pair<Cost, int>> q;
  q.push(make_pair(Cost(0), s));
  while (!q.empty()) {
    auto a = q.top();
    q.pop();
    int v = a.second;
    if (dist[v] < a.first) continue;
    for (auto e : g[v]) {
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        q.push(make_pair(dist[e.to], e.to));
      }
    }
  }
  return dist;
}

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  a--;
  b--;
  Graph<int> g(200);
  for (int i = 0; i < 100; i++) { g.add_edge_undirected(i, i + 100, x); }
  for (int i = 0; i < 99; i++) g.add_edge_undirected(i + 1, i + 100, x);
  for (int i = 0; i < 99; i++) {
    g.add_edge_undirected(i, i + 1, y);
    g.add_edge_undirected(i + 100, i + 1 + 100, y);
  }
  auto dist = dijkstra(g, a);
  cout << dist[100 + b] << endl;
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
