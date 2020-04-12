// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC target( \
//     "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
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

LazySegmentTree<ll, ll> RangeAddRangeMax(int len) {
  auto dm = [](ll a, ll b) { return max(a, b); };
  auto om = [](ll a, ll b) { return a + b; };
  auto app = [](ll dat, ll lz, int len) { return dat + lz; };
  return LazySegmentTree<ll, ll>(len, 0ll, 0ll, dm, om, app);
}

#define endl "\n"

void solve() {
  int N;
  cin >> N;
  vector<int> C(N);
  cin >> C;
  double ans = 0.0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (i != j && C[i] % C[j] == 0) cnt++;
    }
    int a = (cnt + 2) / 2;
    double res = (double)a / (double)(cnt + 1);
    ans += res;
  }
  cout << ans << endl;
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
