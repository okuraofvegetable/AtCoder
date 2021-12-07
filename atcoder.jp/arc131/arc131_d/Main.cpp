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

void solve() {
  ll N, M, D;
  cin >> N >> M >> D;
  vector<ll> r(M + 1);
  cin >> r;
  vector<ll> s(M);
  cin >> s;

  vector<tuple<ll, ll, ll>> rs;
  for (int i = M; i > 1; i--) rs.emplace_back(-r[i], -r[i - 1], s[i - 1]);
  rs.emplace_back(-r[1], r[1] + 1, s[0]);
  for (int i = 1; i < M; i++) rs.emplace_back(r[i] + 1, r[i + 1] + 1, s[i]);

  ll x = -((N * D + 1) / 2ll);

  vector<ll> cnt(D + 1, 0ll);
  for (auto [L, R, p] : rs) {
    dmp(L, R, p);
    vector<pair<ll, ll>> es;

    // 初期値
    es.emplace_back(0, min(N, (max(0ll, (R - x)) + D - 1) / D) * p -
                           min(N, (max(0ll, (L - x)) + D - 1) / D) * p);
    // Lの変化点
    ll lc = ((L - x) % D + D) % D;
    es.emplace_back(lc, min(N, (max(0ll, (R - x - lc)) + D - 1) / D) * p -
                            min(N, (max(0ll, (L - x - lc)) + D - 1) / D) * p);
    // Rの変化点
    ll rc = ((R - x) % D + D) % D;
    es.emplace_back(rc, min(N, (max(0ll, (R - x - rc)) + D - 1) / D) * p -
                            min(N, (max(0ll, (L - x - rc)) + D - 1) / D) * p);
    // 念の為
    es.emplace_back(D, min(N, (max(0ll, (R - x - D)) + D - 1) / D) * p -
                           min(N, (max(0ll, (L - x - D)) + D - 1) / D) * p);
    sort(all(es));
    for (int i = 0; i < es.size(); i++) {
      auto [pos, val] = es[i];
      if (i > 0 && es[i - 1].first == pos) {
        assert(es[i - 1].second == val);
        continue;
      }
      if (i > 0)
        cnt[pos] += val - es[i - 1].second;
      else
        cnt[pos] += val;
    }
  }

  for (int i = 1; i <= D; i++) { cnt[i] += cnt[i - 1]; }

  cout << *max_element(all(cnt)) << endl;

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
