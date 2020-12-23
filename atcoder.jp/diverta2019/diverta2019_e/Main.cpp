#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

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

constexpr int MOD = 1e9 + 7;
// constexpr int MOD = 998244353;
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

template <class D, class O>
struct LazySegmentTree {
  using DMerger = function<D(D, D)>;
  using OMerger = function<O(O, O)>;
  using Applier = function<D(D, O, int)>;

  int length;
  D d_unit;
  O o_unit;

  vector<D> seg;
  vector<O> lazy;

  DMerger dm;
  OMerger om;
  Applier app;

  void lazy_evaluate(int k, int len) {
    if (lazy[k] == o_unit) return;
    if (len > 1) {
      lazy[2 * k + 1] = om(lazy[2 * k + 1], lazy[k]);
      lazy[2 * k + 2] = om(lazy[2 * k + 2], lazy[k]);
    }
    seg[k] = app(seg[k], lazy[k], len);
    lazy[k] = o_unit;
  }
  void update(int a, int b, int k, int l, int r, O x) {
    lazy_evaluate(k, r - l);
    if (r <= a || b <= l)
      return;
    else if (a <= l && r <= b) {
      lazy[k] = om(lazy[k], x);
      lazy_evaluate(k, r - l);
    } else {
      update(a, b, k * 2 + 1, l, (l + r) / 2, x);
      update(a, b, k * 2 + 2, (l + r) / 2, r, x);
      seg[k] = dm(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  void update(int a, int b, O x) { update(a, b, 0, 0, length, x); }
  D query(int a, int b, int k, int l, int r) {
    lazy_evaluate(k, r - l);
    if (r <= a || b <= l)
      return d_unit;
    else if (a <= l && r <= b)
      return seg[k];
    else {
      D lch = query(a, b, k * 2 + 1, l, (l + r) / 2);
      D rch = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return dm(lch, rch);
    }
  }
  D query(int a, int b) { return query(a, b, 0, 0, length); }
  LazySegmentTree(int n, D d_unit, O o_unit, DMerger dm, OMerger om,
                  Applier app)
      : length(1), d_unit(d_unit), o_unit(o_unit), dm(dm), om(om), app(app) {
    while (length < n) { length <<= 1; }
    seg.assign(length * 2, d_unit);
    lazy.assign(length * 2, o_unit);
  }
  LazySegmentTree(vector<D> vec, D d_unit, O o_unit, DMerger dm, OMerger om,
                  Applier app)
      : length(1), d_unit(d_unit), o_unit(o_unit), dm(dm), om(om), app(app) {
    while (length < vec.size()) { length <<= 1; }
    seg.assign(length * 2, d_unit);
    lazy.assign(length * 2, o_unit);
    for (int i = 0; i < vec.size(); i++) seg[length - 1 + i] = vec[i];
    for (int i = length - 2; i >= 0; i--)
      seg[i] = dm(seg[i * 2 + 1], seg[i * 2 + 2]);
  }
};

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A;

  for (int i = 0; i + 1 < N; i++) A[i + 1] ^= A[i];
  int z = 0;
  for (int i = 0; i < N; i++)
    if (A[i] == 0) z++;
  mint ans(0);
  if (A[N - 1] == 0) ans += mint(2).pow(z - 1);

  LazySegmentTree<mint, mint> seg((1 << 20), mint(0), mint(0),
                                  [](mint a, mint b) { return a + b; },
                                  [](mint a, mint b) { return a + b; },
                                  [](mint a, mint b, int) { return a + b; });
  vector<mint> B(1 << 20, mint(1)), C(1 << 20, mint(0));
  for (int i = 0; i < N; i++) {
    if (A[i] == 0) {
      if (i == N - 1) { ans += accumulate(all(C), mint(0)); }
      seg.update(1, (1 << 20), mint(1));
    } else {
      mint a = seg.query(A[i], A[i] + 1);
      seg.update(A[i], A[i] + 1, -a);
      B[A[i]] += C[A[i]] * a;
      C[A[i]] += B[A[i]];
      if (i == N - 1) ans += B[A[i]];
    }
  }
  cout << ans << endl;
  return;
}

int main() {
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
