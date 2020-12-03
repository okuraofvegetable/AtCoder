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

// Verify:
// https://atcoder.jp/contests/code-thanks-festival-2017/submissions/18040461

struct PartialPersistentUnionFind {
  const int N;
  int last;
  vector<pair<int, int>> par;
  vector<vector<pair<int, int>>> child;
  vector<vector<pair<int, ll>>> sz;

  PartialPersistentUnionFind(const int N, const vector<ll> &x)
      : N(N), last(numeric_limits<int>::min()), par(N), child(N), sz(N) {
    for (int i = 0; i < N; ++i) {
      par[i] = {numeric_limits<int>::max(), i};
      sz[i].emplace_back(numeric_limits<int>::min(), x[i]);
    }
  }

  int find(int u, const int t) {
    while (par[u].first <= t) u = par[u].second;
    return u;
  }

  bool unite(int u, int v, const int t) {
    assert(last <= t);
    last = t;
    u = find(u, t), v = find(v, t);
    if (u == v) return false;
    if (sz[u].back().first < sz[v].back().first) swap(u, v);
    par[v] = {t, u};
    child[u].emplace_back(t, v);
    sz[u].emplace_back(t, sz[u].back().second + sz[v].back().second);
    return true;
  }

  bool same(const int u, const int v, const int t) {
    return find(u, t) == find(v, t);
  }

  vector<int> component(int u, const int t) {
    u = find(u, t);
    queue<int> q;
    q.push(u);
    vector<int> comp;
    while (!q.empty()) {
      int v = q.front();
      comp.push_back(v);
      q.pop();
      for (int i = 0; i < child[v].size(); i++) {
        if (child[v][i].first > t) break;
        q.push(child[v][i].second);
      }
    }
    return comp;
  }

  ll size(int u, const int t) {
    u = find(u, t);
    int idx = upper_bound(sz[u].begin(), sz[u].end(), make_pair(t, LLINF)) -
              sz[u].begin();
    return sz[u][idx - 1].second;
  }
};

using edge = tuple<ll, int, int>;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<ll> X(N);
  cin >> X;
  vector<edge> es;
  for (int i = 0; i < M; i++) {
    int a, b, y;
    cin >> a >> b >> y;
    a--;
    b--;
    es.emplace_back(y, a, b);
  }
  sort(all(es));
  dmp(es);
  PartialPersistentUnionFind uf(N, X);
  for (int i = 0; i < es.size(); i++) {
    auto [y, a, b] = es[i];
    uf.unite(a, b, i);
  }
  vector<bool> ok(N, false);
  int ans = 0;
  for (int i = M - 1; i >= 0; i--) {
    auto [y, a, b] = es[i];
    if (ok[a] || ok[b]) continue;
    ll sz = uf.size(a, i);
    if (y <= sz) {
      auto comp = uf.component(a, i);
      dmp(comp);
      for (int v : comp) ok[v] = true;
    } else {
      ans++;
    }
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
