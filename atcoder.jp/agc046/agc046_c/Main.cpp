#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

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
template <int MOD> // if inv is needed, this shold be prime.
struct ModInt {
  ll val;
  ModInt() : val(0ll) {}
  ModInt(const ll &v) : val(((v % MOD) + MOD) % MOD) {}
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return !(*this == x); }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return !(*this < x); }
  bool operator<=(const ModInt &x) const { return !(*this > x); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt inv() const { return this->pow(MOD - 2); }
  ModInt &operator+=(const ModInt &x) {
    if ((val += x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &x) {
    if ((val += MOD - x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &x) {
    (val *= x.val) %= MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &x) { return *this *= x.inv(); };
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend istream &operator>>(istream &i, ModInt &x) {
    ll v;
    i >> v;
    x = v;
    return i;
  }
  friend ostream &operator<<(ostream &o, const ModInt &x) {
    o << x.val;
    return o;
  }
  ModInt pow(ll x) const {
    auto res = ModInt(1ll);
    auto b = *this;
    while (x) {
      if (x & 1) res *= b;
      x >>= 1;
      b *= b;
    }
    return res;
  }
};

template <int MOD>
ModInt<MOD> pow(ModInt<MOD> a, ll x) {
  ModInt<MOD> res = ModInt<MOD>(1ll);
  while (x) {
    if (x & 1) res *= a;
    x >>= 1;
    a *= a;
  }
  return res;
}

// constexpr int MOD = 1e9 + 7;
constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

void solve() {
  string S;
  int K;
  cin >> S >> K;

  int N = S.size();
  vector<int> cnt(N, 0);
  int z = 0;
  int M = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '0')
      z++;
    else
      cnt[z]++, M++;
  }
  auto rui = cnt;
  for (int i = 1; i < N; i++) rui[i] += rui[i - 1];
  dmp(cnt, rui);

  auto dp = vect(N + 1, vect(M + 1, vect(M + 1, mint(0))));
  dp[0][0][0] = mint(1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= M; j++) {
      int need = max(0, rui[i] - j);
      for (int k = 0; k <= M; k++) {
        for (int v = need; v + j <= M; v++) {
          int nk = k + max(0, v - cnt[i]);
          if (nk <= M) dp[i + 1][v + j][nk] += dp[i][j][k];
        }
      }
    }
  }

  mint ans(0);
  for (int i = 0; i <= min(K, M); i++) ans += dp[N][M][i];
  cout << ans << endl;

  return;
}

int main() {
  fastio();
  solve();
  // int t;
  // cin >> t;
  // while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
