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

template <class T>
struct BIT {
  int N;
  vector<T> bit;
  BIT(int N) : N(N) { bit = vector<T>(N + 1, T(0)); }
  void add(int i, T x) {
    i++;
    while (i <= N) {
      bit[i] += x;
      i += i & -i;
    }
    return;
  }
  T sum(int i) const {
    i++;
    T res = T(0);
    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }
  T sum(int l, int r) const { // [l,r]
    assert(l <= r);
    if (l == 0)
      return sum(r);
    else
      return sum(r) - sum(l - 1);
  }
};

void solve() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  cin >> A >> B;
  vector<int> zip;
  zip.insert(zip.end(), all(A));
  zip.insert(zip.end(), all(B));
  sort(all(zip));
  zip.erase(unique(all(zip)), zip.end());
  vector<pii> ab;
  for (int i = 0; i < N; i++) {
    A[i] = lower_bound(all(zip), A[i]) - zip.begin();
    B[i] = lower_bound(all(zip), B[i]) - zip.begin();
    ab.emplace_back(A[i], B[i]);
  }
  sort(all(ab));
  for (int i = 0; i < N; i++) {
    A[i] = ab[i].first;
    B[i] = ab[i].second;
  }
  dmp(A);
  dmp(B);

  int M = zip.size();
  BIT<int> bit(M + 100);

  int s = 0;
  ll ans = 0ll;
  while (s < N) {
    int t = s;
    unordered_map<int, int> m;
    while (t < N && A[t] == A[s]) {
      ans += bit.sum(B[t], M);
      m[B[t]]++;
      t++;
    }
    for (int i = s; i < t; i++) { bit.add(B[i], 1); }
    dmp(s, t);
    ans += (ll)(t - s) * (ll)(t - s - 1) / 2ll;
    for (auto [k, v] : m) {
      dmp(k, v);
      ans += (ll)v * (ll)(v - 1) / 2ll;
    }

    s = t;
  }
  cout << ans + N << endl;
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
