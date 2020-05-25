// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000               // 2e9
#define LLINF 2000000000000000000ll  // 2e18 (llmax:9e18)
#define fi first
#define sec second
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define dmp(x) cerr << #x << ": " << x << endl;

template <class T>
void chmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, const T &b) {
  if (a < b) a = b;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.fi << ',' << p.sec;
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.fi >> p.sec;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 < vec.size()) os << ' ';
  }
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}
void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

#define endl "\n"

template <int MOD>  // if inv is needed, this shold be prime.
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

constexpr int MOD = 1e9 + 7;
// constexpr int MOD = 998244353;
// using mint = ModInt<MOD>;
using mint = ll;

vector<mint> inv, fac, facinv;
// notice: 0C0 = 1
mint nCr(int n, int r) {
  assert(!(n < r));
  assert(!(n < 0 || r < 0));
  return fac[n] * facinv[r] * facinv[n - r];
}

void init(int SIZE) {
  fac.resize(SIZE + 1);
  inv.resize(SIZE + 1);
  facinv.resize(SIZE + 1);
  fac[0] = inv[1] = facinv[0] = mint(1ll);
  for (int i = 1; i <= SIZE; i++) fac[i] = fac[i - 1] * mint(i);
  for (int i = 2; i <= SIZE; i++)
    inv[i] = mint(0ll) - mint(MOD / i) * inv[MOD % i];
  for (int i = 1; i <= SIZE; i++) facinv[i] = facinv[i - 1] * inv[i];
  return;
}

vector<int> g[5000];
mint dp[5000][5001][2];
mint tmp[5000][5001][2];
mint subtree_size[5000];
mint num[5001];

void dfs(int v, int p) {
  vector<int> childs;
  subtree_size[v] = 1;
  for (int u : g[v]) {
    if (u == p) continue;
    childs.push_back(u);
    dfs(u, v);
    subtree_size[v] += subtree_size[u];
  }
  for (int i = 0; i <= childs.size(); i++) {
    for (int j = 0; j <= subtree_size[v]; j++) {
      for (int k = 0; k < 2; k++) { tmp[i][j][k] = mint(0); }
    }
  }
  tmp[0][1][0] = mint(1);
  int sum_size = 1;
  for (int i = 0; i < childs.size(); i++) {
    for (int j = 0; j <= sum_size; j++) {
      for (int jb = 0; jb < 2; jb++) {
        for (int k = 0; k <= subtree_size[childs[i]]; k++) {
          for (int kb = 0; kb < 2; kb++) {
            tmp[i + 1][j][(jb + kb + 1) % 2] +=
                ((tmp[i][j][jb] * dp[childs[i]][k][kb]) % MOD * num[k]) % MOD;
            tmp[i + 1][j][(jb + kb + 1) % 2] %= MOD;
            tmp[i + 1][j + k][(jb + kb) % 2] +=
                tmp[i][j][jb] * dp[childs[i]][k][kb] % MOD;
            tmp[i + 1][j + k][(jb + kb) % 2] %= MOD;
          }
        }
      }
    }
    sum_size += subtree_size[childs[i]];
  }
  for (int j = 0; j <= subtree_size[v]; j++) {
    for (int k = 0; k < 2; k++) { dp[v][j][k] = tmp[childs.size()][j][k]; }
  }
}

void solve() {
  int N;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  //   auto dp = vect(N, vect(N + 1, vect(2, mint(0))));
  //   auto tmp = vect(N, vect(N + 1, vect(2, mint(0))));
  //   auto subtree_size = vect(N, 1);
  //   auto num = vect(N + 1, mint(0));
  memset(dp, 0, sizeof(dp));
  memset(tmp, 0, sizeof(tmp));
  memset(subtree_size, 0, sizeof(subtree_size));
  memset(num, 0, sizeof(num));
  num[0] = mint(1);
  for (int i = 2; i <= N; i++) num[i] = (num[i - 2] * mint(i - 1)) % MOD;
  dfs(0, -1);
  //   for (int i = 0; i < N; i++) {
  //     for (int j = 0; j <= N; j++) {
  //       for (int k = 0; k < 2; k++) {
  //         cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
  //       }
  //     }
  //   }
  mint ans(0);
  for (int i = 1; i <= N; i++) {
    ans += dp[0][i][0] * num[i] % MOD;
    ans %= MOD;
    ans -= dp[0][i][1] * num[i] % MOD;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return;
}

signed main() {
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
