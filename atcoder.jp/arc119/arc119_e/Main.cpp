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
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}

ll longest_overlap(vector<pair<ll, ll>> &segs) {
  if (segs.empty()) return 0ll;

  sort(all(segs), comp);
  ll max_overlap = 0ll;
  auto L = segs[0];
  for (int i = 1; i < segs.size(); i++) {
    chmax(max_overlap, min(L.second, segs[i].second) - segs[i].first);
    if (segs[i].second > L.second) L = segs[i];
  }
  return max_overlap;
}

void solve() {
  int N;
  cin >> N;
  vector<ll> a(N);
  cin >> a;
  ll base = 0ll;
  for (int i = 1; i < N; i++) { base += abs(a[i] - a[i - 1]); }
  ll ans = base;
  for (int i = 1; i + 1 < N; i++) {
    chmin(ans, base - abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[0]));
  }
  for (int i = 1; i + 1 < N; i++) {
    chmin(ans, base - abs(a[i] - a[i - 1]) + abs(a[i - 1] - a[N - 1]));
  }
  vector<pair<ll, ll>> S, T;
  for (int i = 0; i + 1 < N; i++) {
    if (a[i] <= a[i + 1])
      S.emplace_back(a[i], a[i + 1]);
    else
      T.emplace_back(a[i + 1], a[i]);
  }

  ll max_overlap = 0;

  dmp(S);
  dmp(T);
  dmp(longest_overlap(S), longest_overlap(T));

  chmax(max_overlap, longest_overlap(S));
  chmax(max_overlap, longest_overlap(T));

  chmin(ans, base - 2 * max_overlap);

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
