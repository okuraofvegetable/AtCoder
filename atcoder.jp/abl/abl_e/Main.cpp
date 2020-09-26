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

#include <atcoder/modint>

using mint = atcoder::static_modint<998244353>;

void solve() {
  using Data = pair<mint, mint>;
  int N, Q;
  cin >> N >> Q;
  vector<Data> vec(N);
  for (int i = 0; i < N; i++) {
    mint pow10 = mint(10).pow(N - 1 - i);
    vec[i] = Data(pow10, pow10);
  }
  auto dm = [](Data a, Data b) {
    return Data(a.first + b.first, a.second + b.second);
  };
  auto om = [](int a, int b) {
    if (b == -1) return a;
    return b;
  };
  auto app = [](Data dat, int lz, int) {
    if (lz == -1) return dat;
    return Data(dat.first, dat.first * lz);
  };
  LazySegmentTree<Data, int> seg(vec, Data(mint(0), mint(0)), -1, dm, om, app);
  for (int i = 0; i < Q; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    l--;
    seg.update(l, r, d);
    cout << seg.query(0, N).second.val() << endl;
  }
  return;
}

signed main() {
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
