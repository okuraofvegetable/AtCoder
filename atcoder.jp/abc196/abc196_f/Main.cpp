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

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

#include <atcoder/convolution>
#include <atcoder/modint>

template <class T>
vector<ll> wildcard_matching(const T &s, const T &p, int w = -1) {
  static constexpr int mod = 1811939329;
  using mint = atcoder::static_modint<mod>;

  const int n = s.size();
  const int m = p.size();

#ifdef LOCAL
  assert(1 <= n);
  assert(m <= n);
  const int mx = std::max(*std::max_element(p.begin(), p.end()),
                          *std::max_element(s.begin(), s.end()));
  // maximum squared diff
  assert(ll(mx) * mx * m < mod);
#endif

  vector<mint> diff(n - m + 1, mint(0));

  auto add_term = [&](const auto f, const auto g) {
    vector<mint> x(n), y(m);
    for (int i = 0; i < n; i++) x[i] = f((int)s[i]);
    for (int i = 0; i < m; i++) y[i] = g((int)p[m - 1 - i]);
    const auto z = atcoder::convolution(x, y);
    for (int i = 0; i < n - m + 1; i++) diff[i] += z[m - 1 + i];
  };

  // Calculate sum of (p_i != w) * (t_{i+j} != w) * (p_i - t_{i+j})^2
  add_term([&](const int v) -> ll { return ll(v != w) * v * v; },
           [&](const int v) -> ll { return ll(v != w); });
  add_term([&](const int v) -> ll { return ll(v != w) * (-2) * v; },
           [&](const int v) -> ll { return ll(v != w) * v; });
  add_term([&](const int v) -> ll { return ll(v != w); },
           [&](const int v) -> ll { return ll(v != w) * v * v; });

  // p matches t[j..] <=> diff[j] = 0
  vector<ll> res(n - m + 1);
  for (int i = 0; i < n - m + 1; i++) res[i] = (diff[i].val());
  return res;
}

void solve() {
  string S, T;
  cin >> S >> T;
  auto diff = wildcard_matching(S, T, '?');
  ll ans = LLINF;
  for (int i = 0; i <= S.size() - T.size(); i++) { chmin(ans, diff[i]); }
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
