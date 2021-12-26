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
  int n, d;
  cin >> n >> d;
  vector<int> a(n), rev(n, -1);
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      a[i]--;
      rev[a[i]] = i;
    }
  }

  dmp(a);
  dmp(rev);

  int m = (1 << d);

  auto rem_max = [&](int mask) { return (mask >> (d - 1)) & 1; };
  auto ok = [&](int x, int y) {
    if (a[x] != -1 && a[x] != y) return false;
    if (rev[y] != -1 && rev[y] != x) return false;
    return true;
  };

  auto dp = vect(n + 1, vect(m, vect(m, mint(0))));
  dp[0][0][0] = mint(1);

  dmp(ok(0, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        if (dp[i][j][k] == mint(0)) continue;
        // i <-> i
        {
          if (!rem_max(j) && !rem_max(k) && ok(i, i)) {
            dp[i + 1][j << 1][k << 1] += dp[i][j][k];
          }
        }
        // i <-> (i未満)
        // (iより大) <-> i
        {
          for (int l = 0; l < d; l++) {
            if (!((k >> l) & 1)) continue;
            int nk = k ^ (1 << l);
            if (!rem_max(j) && !rem_max(nk) && ok(i, i - 1 - l)) {
              dp[i + 1][j << 1][(nk << 1) | 1] += dp[i][j][k];
            }
          }
        }
        // i <-> (iより大)
        // (i未満) <-> i
        {
          for (int l = 0; l < d; l++) {
            if (!((j >> l) & 1)) continue;
            int nj = j ^ (1 << l);
            if (!rem_max(nj) && !rem_max(k) && ok(i - 1 - l, i)) {
              dp[i + 1][(nj << 1) | 1][k << 1] += dp[i][j][k];
            }
          }
        }
        // (i未満) <-> i
        // i <-> (i未満)
        {
          for (int l = 0; l < d; l++) {
            if (!((j >> l) & 1)) continue;
            for (int o = 0; o < d; o++) {
              if (!((k >> o) & 1)) continue;
              int nj = j ^ (1 << l);
              int nk = k ^ (1 << o);
              if (!rem_max(nj) && !rem_max(nk) && ok(i, i - 1 - o) &&
                  ok(i - 1 - l, i)) {
                dp[i + 1][nj << 1][nk << 1] += dp[i][j][k];
              }
            }
          }
        }
        // (iより大) <-> i
        // i <-> (iより大)
        {
          if (!rem_max(j) && !rem_max(k)) {
            dp[i + 1][(j << 1) | 1][(k << 1) | 1] += dp[i][j][k];
          }
        }
      }
    }
  }

  cout << dp[n][0][0] << endl;

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
