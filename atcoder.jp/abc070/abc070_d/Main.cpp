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

template <int MOD>  // if inv is needed, this shold be prime.
struct ModInt {
  ll val;
  ModInt() : val(0ll) {}
  ModInt(const ll &v) : val(((v % MOD) + MOD) % MOD) {}
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return !(*this == x); }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return !(*this < x); }
  bool operator<=(const ModInt &x) const { return !(*this > x); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt inv() const { return this->pow(MOD - 2); }
  ModInt &operator+=(const ModInt &x) {
    if ((val += x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &x) {
    if ((val += MOD - x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &x) {
    (val *= x.val) %= MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &x) { return *this *= x.inv(); };
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend istream &operator>>(istream &i, ModInt &x) {
    ll v;
    i >> v;
    x = v;
    return i;
  }
  friend ostream &operator<<(ostream &o, const ModInt &x) {
    o << x.val;
    return o;
  }
  ModInt pow(ll x) const {
    auto res = ModInt(1ll);
    auto b = *this;
    while (x) {
      if (x & 1) res *= b;
      x >>= 1;
      b *= b;
    }
    return res;
  }
};

template <int MOD>
ModInt<MOD> pow(ModInt<MOD> a, ll x) {
  ModInt<MOD> res = ModInt<MOD>(1ll);
  while (x) {
    if (x & 1) res *= a;
    x >>= 1;
    a *= a;
  }
  return res;
}

// constexpr int MOD = 1e9 + 7;
constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

vector<mint> inv, fac, facinv;
// notice: 0C0 = 1
ModInt<MOD> nCr(int n, int r) {
  assert(!(n < r));
  assert(!(n < 0 || r < 0));
  return fac[n] * facinv[r] * facinv[n - r];
}

void init(int SIZE) {
  fac.resize(SIZE + 1);
  inv.resize(SIZE + 1);
  facinv.resize(SIZE + 1);
  fac[0] = inv[1] = facinv[0] = mint(1ll);
  for (int i = 1; i <= SIZE; i++) fac[i] = fac[i - 1] * mint(i);
  for (int i = 2; i <= SIZE; i++)
    inv[i] = mint(0ll) - mint(MOD / i) * inv[MOD % i];
  for (int i = 1; i <= SIZE; i++) facinv[i] = facinv[i - 1] * inv[i];
  return;
}

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
  vector<Cost> dist;  // distance from root node
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
    G[u].pb(edge<Cost>(u, v, c));
    G[v].pb(edge<Cost>(v, u, c));
  }
  int dfs(int v, int p, int d, Cost c) {
    depth[v] = d;
    par[v] = p;
    subtree_size[v] = 1;
    dist[v] = c;
    bool is_centroid = true;
    for (auto e : G[v]) {
      int u = e.to;
      if (u == p) continue;
      subtree_size[v] += dfs(u, v, d + 1, c + e.cost);
    }
    return subtree_size[v];
  }
  void dfs() { dfs(root, -1, 0, Cost(0)); }

  // require : call dfs
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
  // requirement : call construct_dpar
  int kth_parent(int v, int k) {
    int res = v;
    for (int i = 0; i < LOG_V; i++) {
      if (k & (1 << i)) res = dpar[i][res];
      if (res == -1) return -1;
    }
    return res;
  }
  // requirement : call construct_dpar
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
  // requirement : call construct_dpar
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
  Tree<ll> T(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    T.add_edge(a, b, c);
  }
  T.dfs();
  T.construct_dpar();
  int Q, K;
  cin >> Q >> K;
  K--;
  for (int q = 0; q < Q; q++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << T.distance(x, K) + T.distance(K, y) << endl;
  }
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
