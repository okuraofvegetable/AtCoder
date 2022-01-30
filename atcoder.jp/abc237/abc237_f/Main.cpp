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
ostream &operator<<(ostream &os, const mint &v) {
  return os << v.val();
}

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

void solve() {
  int N, M;
  cin >> N >> M;

  int p = (M + 1) * (M + 1) * (M + 1);
  dmp(p);

  auto decode = [&](int s) {
    vector<int> res;
    for (int i = 0; i < 3; i++) {
      res.push_back(s % (M + 1));
      s /= (M + 1);
    }
    return res;
  };

  auto encode = [&](const vector<int> &res) {
    int s = 0;
    for (int i = 2; i >= 0; i--) {
      s *= (M + 1);
      s += res[i];
    }
    return s;
  };

  for (int i = 0; i < p; i++) {
    auto d = decode(i);
    dmp(i, d, encode(d));
    assert(encode(d) == i);
  }

  auto to = vect(p, vect(M, -1));
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < M; j++) {
      auto dp = decode(i);
      if (dp[0] > dp[1] || dp[1] > dp[2]) continue;
      dmp(dp, j);
      if (lower_bound(all(dp), j) == dp.end()) continue;
      *lower_bound(all(dp), j) = j;
      dmp(dp);
      to[i][j] = encode(dp);
    }
  }

  auto dp = vect(N + 1, vect(p, mint(0)));
  vector<int> init;
  for (int i = 0; i < 3; i++) init.push_back(M);
  dmp(encode(init));

  dp[0][encode(init)] = mint(1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < M; k++) {
        if (to[j][k] != -1) {
          // dmp(p, to[j][k]);
          dp[i + 1][to[j][k]] += dp[i][j];
        }
      }
    }
  }

  mint ans(0);
  for (int i = 0; i < p; i++) {
    auto res = decode(i);
    if (res.back() < M) ans += dp[N][i];
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
