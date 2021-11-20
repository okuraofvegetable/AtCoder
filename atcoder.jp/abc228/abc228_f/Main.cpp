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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using mint = atcoder::static_modint<MOD>;
using mint2 = atcoder::static_modint<MOD - 1>;
ostream &operator<<(ostream &os, const mint &v) {
  return os << v.val();
}

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

// D requires operator +,-
template <class D>
struct RangeSum2D {
  vector<vector<D>> f;
  vector<vector<D>> rui;
  bool flag;
  RangeSum2D() { flag = false; }
  RangeSum2D(int H, int W) {
    flag = false;
    f.resize(H);
    for (int i = 0; i < H; i++) f[i].resize(W);
  }
  void set(int x, int y, D v) {
    assert(x < f.size() && y < f[0].size());
    assert(!flag);
    f[x][y] = v;
  }
  void calc() {
    rui = f;
    for (int i = 0; i < f.size(); i++) {
      for (int j = 1; j < f[0].size(); j++) { rui[i][j] += rui[i][j - 1]; }
    }
    for (int i = 1; i < f.size(); i++) {
      for (int j = 0; j < f[0].size(); j++) { rui[i][j] += rui[i - 1][j]; }
    }
    flag = true;
  }
  D get(int a, int b, int c, int d) {
    assert(a >= 0 && a < f.size());
    assert(b >= 0 && b < f[0].size());
    assert(c >= 0 && c < f.size());
    assert(d >= 0 && d < f[0].size());
    assert(a <= c && b <= d);
    assert(flag);
    D res = rui[c][d];
    if (a > 0) res -= rui[a - 1][d];
    if (b > 0) res -= rui[c][b - 1];
    if (a > 0 && b > 0) res += rui[a - 1][b - 1];
    return res;
  }
};

ll func(ll a, ll b) {
  return max(a, b);
}

ll e = -LLINF;

const int SIZE = 1 << 10;
struct segtree {
  ll seg[SIZE * 2];
  void update(int k) {
    while (k > 0) {
      k = (k - 1) / 2;
      seg[k] = func(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  ll query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l)
      return e;
    else if (a <= l && r <= b)
      return seg[k];
    else
      return func(query(a, b, k * 2 + 1, l, (l + r) / 2),
                  query(a, b, k * 2 + 2, (l + r) / 2, r));
  }
};

segtree Segtree[SIZE * 2];
void Update(int kx, int ky, ll x) {
  kx += SIZE - 1;
  ky += SIZE - 1;
  Segtree[kx].seg[ky] = x;
  while (1) {
    Segtree[kx].update(ky);
    if (kx == 0) break;
    kx = (kx - 1) / 2;
    Segtree[kx].seg[ky] =
        func(Segtree[kx * 2 + 1].seg[ky], Segtree[kx * 2 + 2].seg[ky]);
  }
  return;
}
// note:row row column column
ll Query(int a, int b, int c, int d, int k, int l, int r) {
  if (r <= a || b <= l)
    return e;
  else if (a <= l && r <= b)
    return Segtree[k].query(c, d, 0, 0, SIZE);
  else
    return func(Query(a, b, c, d, k * 2 + 1, l, (l + r) / 2),
                Query(a, b, c, d, k * 2 + 2, (l + r) / 2, r));
}

void solve() {
  int H, W, h1, w1, h2, w2;
  cin >> H >> W >> h1 >> w1 >> h2 >> w2;

  int h = min(h1, h2), w = min(w1, w2);

  auto A = vect(H, vect(W, 0ll));
  cin >> A;

  RangeSum2D<ll> rs(H, W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { rs.set(i, j, A[i][j]); }
  }
  rs.calc();

  auto sub = vect(H - h + 1, vect(W - w + 1, 0ll));
  for (int i = 0; i <= H - h; i++) {
    for (int j = 0; j <= W - w; j++) {
      // sub[i][j] = rs.get(i, j, i + h - 1, j + w - 1);
      Update(i, j, rs.get(i, j, i + h - 1, j + w - 1));
    }
  }
  // SparseTable2D<ll> submax(sub);

  ll ans = 0ll;
  for (int i = 0; i <= H - h1; i++) {
    for (int j = 0; j <= W - w1; j++) {
      ll base = rs.get(i, j, i + h1 - 1, j + w1 - 1);
      base -= Query(i, i + h1 - h + 1, j, j + w1 - w + 1, 0, 0, SIZE);
      chmax(ans, base);
    }
  }
  cout << ans << endl;
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
