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
using pii = pair<ll, ll>;

void solve() {

  ll xoff = 0, yoff = 0;
  int swapped = 0;
  int xsign = 1, ysign = 1;

  auto Swap = [&]() {
    swap(xoff, yoff);
    swap(xsign, ysign);
    swapped ^= 1;
  };

  auto apply = [&](pii p) {
    auto [x, y] = p;
    if (swapped) swap(x, y);
    return pii(xsign * x + xoff, ysign * y + yoff);
  };

  int N;
  cin >> N;

  vector<pii> ps(N);
  cin >> ps;

  int M;
  cin >> M;
  vector<pii> ops(M);
  for (int i = 0; i < M; i++) {
    cin >> ops[i].first;
    if (ops[i].first > 2) cin >> ops[i].second;
  }

  int Q;
  cin >> Q;
  vector<tuple<int, int, int>> qs;
  for (int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    b--;
    qs.emplace_back(a, b, i);
  }
  sort(all(qs));

  int pos = 0;
  vector<pii> ans(Q);
  for (int i = 0; i <= M; i++) {
    while (pos < Q && get<0>(qs[pos]) == i) {
      auto [a, b, id] = qs[pos];
      ans[id] = apply(ps[b]);
      pos++;
    }
    if (i == M) break;
    auto [type, p] = ops[i];
    if (type == 1) {
      Swap();
      ysign *= -1;
      yoff *= -1;
    }
    if (type == 2) {
      Swap();
      xsign *= -1;
      xoff *= -1;
    }
    if (type == 3) {
      xsign *= -1;
      xoff *= -1;
      xoff += 2 * p;
    }
    if (type == 4) {
      ysign *= -1;
      yoff *= -1;
      yoff += 2 * p;
    }
  }

  for (int i = 0; i < Q; i++)
    cout << ans[i].first << ' ' << ans[i].second << endl;

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
