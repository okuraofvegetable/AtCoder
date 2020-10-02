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

template <class D>
struct SegmentTree {
  using DMerger = function<D(D, D)>;
  int length;
  vector<D> seg;
  const D d_unit;
  const DMerger dm;

  SegmentTree() {}
  SegmentTree(int n, const DMerger dm, const D &d_unit)
      : dm(dm), d_unit(d_unit) {
    length = 1;
    while (length < n) length <<= 1;
    seg.assign(2 * length, d_unit);
  }
  SegmentTree(vector<D> vec, const DMerger dm, const D &d_unit)
      : dm(dm), d_unit(d_unit) {
    length = 1;
    while (length < vec.size()) length <<= 1;
    seg.assign(2 * length, d_unit);
    for (int i = 0; i < vec.size(); i++) seg[length - 1 + i] = vec[i];
    for (int i = length - 2; i >= 0; i--)
      seg[i] = dm(seg[i * 2 + 1], seg[i * 2 + 2]);
  }

  void update(int k, D x) {
    k += length - 1;
    seg[k] = x;
    while (k) {
      k = (k - 1) / 2;
      seg[k] = dm(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }

  D query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return d_unit;
    } else if (a <= l && r <= b) {
      return seg[k];
    } else {
      D lch = query(a, b, k * 2 + 1, l, (l + r) / 2);
      D rch = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return dm(lch, rch);
    }
  }
  D query(int a, int b) { return query(a, b, 0, 0, length); }
  D get_point(int x) { return seg[length - 1 + x]; }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> f(N + 1);
  for (int i = 1; i <= N; i++) { cin >> f[i]; }
  auto dm = [](mint a, mint b) { return a + b; };
  SegmentTree<mint> seg(N + 1, dm, mint(0));
  vector<int> last(M + 1, 0);
  multiset<int> ms;
  int l = 1;
  seg.update(0, mint(1));
  for (int i = 1; i <= N; i++) {
    while (ms.find(f[i]) != ms.end()) { ms.erase(ms.find(f[l++])); }
    mint s = seg.query(l - 1, i);
    seg.update(i, s);
    ms.insert(f[i]);
  }
  cout << seg.get_point(N) << endl;
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
