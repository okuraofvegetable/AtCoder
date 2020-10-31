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
  is >> p.first >> p.second;
  return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}

// ----------------- Output ------------------

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << ',' << p.second;
  return os;
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
  os << "}";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const multiset<T> &s) {
  os << "{ ";
  for (const T &e : s) os << e << " ";
  os << "}";
  return os;
}

template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
  os << "{ ";
  for (const auto &[key, val] : m) os << "( " << key << " -> " << val << " ) ";
  os << "}";
  return os;
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
  dump_str_rec(oss, forward<T>(args)...);
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

template <int MOD> // if inv is needed, this shold be prime.
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
mint nCr(int n, int r) {
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

struct UnionFind {
  vector<int> par, rank, sz;
  UnionFind(int n) {
    par.assign(n, 0);
    rank.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) { par[i] = i; }
  }
  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }
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
  bool same(int x, int y) { return find(x) == find(y); }
};

void solve() {
  init(100);
  int N, K;
  cin >> N >> K;
  auto f = vect(N, vect(N, 0));
  cin >> f;
  UnionFind uf1(N), uf2(N);
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      bool flag = true;
      for (int k = 0; k < N; k++) {
        if (f[i][k] + f[j][k] > K) {
          flag = false;
          break;
        }
      }
      if (flag) {
        dmp(i, j);
        uf1.unite(i, j);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      bool flag = true;
      for (int k = 0; k < N; k++) {
        if (f[k][i] + f[k][j] > K) {
          flag = false;
          break;
        }
      }
      if (flag) {
        dmp(i, j);
        uf2.unite(i, j);
      }
    }
  }
  mint ans(1);
  for (int i = 0; i < N; i++) {
    if (uf1.find(i) == i) ans *= fac[uf1.sz[i]];
    if (uf2.find(i) == i) ans *= fac[uf2.sz[i]];
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
