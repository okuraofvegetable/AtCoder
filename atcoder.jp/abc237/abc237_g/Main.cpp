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

// #include <atcoder/modint>
// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// using mint = atcoder::static_modint<MOD>;
// ostream &operator<<(ostream &os, const mint &v) {
//   return os << v.val();
// }

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

template <class D>
struct SegmentTreeBeats {
  using DMerger = function<D(D, D)>;
  vector<D> seg;
  int length;
  DMerger dm;
  D d_unit;
  SegmentTreeBeats(const vector<D> &vec, DMerger dm, D d_unit = D())
      : length(1), dm(dm) {
    while (length < vec.size()) length <<= 1;
    seg.assign(length * 2, d_unit);
    for (int i = 0; i < vec.size(); i++) { seg[i + length - 1] = vec[i]; }
    for (int i = length - 2; i >= 0; i--) {
      seg[i] = dm(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
  }
  template <class F, class... Args>
  void update(int a, int b, int k, int l, int r, F break_or_puttag,
              Args... args) {
    if (r <= a || b <= l) return;
    if (a <= l && r <= b && (seg[k].*break_or_puttag)(args...)) return;
    seg[k].pushdown(seg[k * 2 + 1], seg[k * 2 + 2]);
    update(a, b, k * 2 + 1, l, (l + r) / 2, break_or_puttag, args...);
    update(a, b, k * 2 + 2, (l + r) / 2, r, break_or_puttag, args...);
    seg[k] = dm(seg[k * 2 + 1], seg[k * 2 + 2]);
  }
  template <class F, class... Args>
  void update(int a, int b, F break_or_puttag, Args... args) {
    update(a, b, 0, 0, length, break_or_puttag, args...);
  }
  template <class Getter, class QMerger, class Q>
  Q query(int a, int b, int k, int l, int r, Getter getter, QMerger qm,
          Q q_unit) {
    if (r <= a || b <= l) return q_unit;
    if (a <= l && r <= b) return (seg[k].*getter)();
    seg[k].pushdown(seg[k * 2 + 1], seg[k * 2 + 2]);
    Q lch = query(a, b, k * 2 + 1, l, (l + r) / 2, getter, qm, q_unit);
    Q rch = query(a, b, k * 2 + 2, (l + r) / 2, r, getter, qm, q_unit);
    return qm(lch, rch);
  }
  template <class Getter, class QMerger, class Q>
  Q query(int a, int b, Getter getter, QMerger qm, Q q_unit) {
    return query(a, b, 0, 0, length, getter, qm, q_unit);
  }
};

// requirements :
//
// static Data merge(Data l,Data r)
//
// void pushdown(Data& l,Data& r) (push down tag)
//
// for each update query :
// bool break_or_puttag_[QUERY] (TAGTYPE tag)
//   if puttag condition is satisfied, update data and put tag
//   return : if break condition or puttag condition is satisfied, return true,
//   otherwise return false

struct Data {
  ll tag, num, sum, mx, mi, second_mx, second_mi, mx_num, mi_num;
  Data(ll v = 0ll)
      : tag(0ll), num(1ll), sum(v), mx(v), mi(v), second_mx(-LLINF),
        second_mi(LLINF), mx_num(1), mi_num(1) {}
  static Data merge(Data l, Data r) {
    Data ret;
    ret.tag = 0;
    ret.sum = l.sum + r.sum;
    ret.num = l.num + r.num;

    if (l.mx < r.mx) {
      ret.mx = r.mx;
      ret.mx_num = r.mx_num;
      ret.second_mx = max(l.mx, r.second_mx);
    } else if (l.mx > r.mx) {
      ret.mx = l.mx;
      ret.mx_num = l.mx_num;
      ret.second_mx = max(l.second_mx, r.mx);
    } else {
      ret.mx = l.mx;
      ret.mx_num = l.mx_num + r.mx_num;
      ret.second_mx = max(l.second_mx, r.second_mx);
    }

    if (l.mi < r.mi) {
      ret.mi = l.mi;
      ret.mi_num = l.mi_num;
      ret.second_mi = min(l.second_mi, r.mi);
    } else if (l.mi > r.mi) {
      ret.mi = r.mi;
      ret.mi_num = r.mi_num;
      ret.second_mi = min(l.mi, r.second_mi);
    } else {
      ret.mi = l.mi;
      ret.mi_num = l.mi_num + r.mi_num;
      ret.second_mi = min(l.second_mi, r.second_mi);
    }
    return ret;
  }
  bool add(ll x) {
    sum += num * x;
    mx += x;
    if (second_mx != -LLINF) second_mx += x;
    mi += x;
    if (second_mi != LLINF) second_mi += x;
    tag += x;
    return true;
  }
  void pushdown(Data &l, Data &r) {
    l.add(tag);
    r.add(tag);
    tag = 0ll;
    l.chmin_query(mx);
    r.chmin_query(mx);
    l.chmax_query(mi);
    r.chmax_query(mi);
  }
  bool chmax_query(ll x) {
    if (mi >= x) return true;
    if (second_mi > x) {
      if (second_mi == LLINF) { // 1 value only
        mx = x;
      } else if (second_mi == mx) { // 2 value only
        second_mx = x;
      }
      sum += (x - mi) * mi_num;
      mi = x;
      return true;
    }
    return false;
  }
  bool chmin_query(ll x) {
    if (mx <= x) return true;
    if (second_mx < x) {
      if (second_mx == -LLINF) { // 1 value only
        mi = x;
      } else if (second_mi == mx) { // 2 value only
        second_mi = x;
      }
      sum -= (mx - x) * mx_num;
      mx = x;
      return true;
    }
    return false;
  }
  ll get_sum() { return sum; }
  ll get_min() { return mi; }
  ll get_max() { return mx; }
};

void yosupo_RangeChminChmaxAddRangeSum() {
  int n, q;
  cin >> n >> q;
  vector<Data> vec;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    vec.emplace_back(a);
  }
  SegmentTreeBeats<Data> seg(vec, Data::merge);
  for (int i = 0; i < q; i++) {
    int type, l, r;
    ll b;
    cin >> type;
    if (type == 0) {
      cin >> l >> r >> b;
      seg.update(l, r, &Data::chmin_query, b);
    }
    if (type == 1) {
      cin >> l >> r >> b;
      seg.update(l, r, &Data::chmax_query, b);
    }
    if (type == 2) {
      cin >> l >> r >> b;
      seg.update(l, r, &Data::add, b);
    }
    if (type == 3) {
      cin >> l >> r;
      cout << seg.query(
                  l, r, &Data::get_sum, [](ll x, ll y) { return x + y; }, 0ll)
           << endl;
    }
    /*
    for(int j=0;j<seg.seg.size();j++){
      cout << "id : " << j << endl;
      cout << " mx : " << seg.seg[j].mx;
      cout << " second_mx : " << seg.seg[j].second_mx;
      cout << " mx_num : " << seg.seg[j].mx_num;
      cout << " mi : " << seg.seg[j].mi;
      cout << " second_mi : " << seg.seg[j].second_mi;
      cout << " mi_num : " << seg.seg[j].mi_num;
      cout << " sum : " << seg.seg[j].sum;
      cout << " num : " << seg.seg[j].num;
      cout << " tag : " << seg.seg[j].tag;
      cout << endl;
    }
    */
  }
}

void solve() {
  int N, Q, X;
  cin >> N >> Q >> X;
  vector<int> P(N);
  cin >> P;
  int pos = -1;
  vector<Data> small, large;
  for (int i = 0; i < N; i++) {
    if (P[i] < X) {
      small.emplace_back(1);
      large.emplace_back(0);
    } else if (P[i] == X) {
      pos = i;
      small.emplace_back(0);
      large.emplace_back(0);
    } else {
      small.emplace_back(0);
      large.emplace_back(1);
    }
  }

  SegmentTreeBeats<Data> seg_small(small, Data::merge);
  SegmentTreeBeats<Data> seg_large(large, Data::merge);

  for (int i = 0; i < Q; i++) {
    int c, l, r;
    cin >> c >> l >> r;
    l--;
    int num_small = seg_small.query(
        l, r, &Data::get_sum, [](ll x, ll y) { return x + y; }, 0ll);
    int num_large = seg_large.query(
        l, r, &Data::get_sum, [](ll x, ll y) { return x + y; }, 0ll);
    int num_X = ((l <= pos && pos < r) ? 1 : 0);
    seg_small.update(l, r, &Data::chmin_query, 0);
    seg_large.update(l, r, &Data::chmin_query, 0);
    if (c == 1) {
      int small_l = l, small_r = l + num_small;
      if (num_X > 0) pos = small_r;
      int large_l = small_r + num_X, large_r = r;
      seg_small.update(small_l, small_r, &Data::add, 1);
      seg_large.update(large_l, large_r, &Data::add, 1);
    } else {
      int large_l = l, large_r = l + num_large;
      if (num_X > 0) pos = large_r;
      int small_l = large_r + num_X, small_r = r;
      seg_small.update(small_l, small_r, &Data::add, 1);
      seg_large.update(large_l, large_r, &Data::add, 1);
    }
  }

  cout << pos + 1 << endl;

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
