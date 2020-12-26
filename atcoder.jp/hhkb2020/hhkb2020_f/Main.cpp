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

constexpr int MOD = 1e9 + 7;
// constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

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

// Do not cast FPS* to vector*!
template <class T>
struct FormalPowerSeries : public std::vector<T> {
  using std::vector<T>::vector;
  using std::vector<T>::operator=;
  using F = FormalPowerSeries;

  F operator-() const {
    F f(*this);
    for (auto &x : f) x = -x;
    return f;
  }

  F &operator+=(const F &g) {
    int n = this->size();
    int m = g.size();
    this->resize(max(n, m));
    for (int i = 0; i < m; i++) (*this)[i] += g[i];
    return *this;
  }

  F &operator-=(const F &g) {
    int n = this->size();
    int m = g.size();
    this->resize(max(n, m));
    for (int i = 0; i < m; i++) (*this)[i] -= g[i];
    return *this;
  }

  F &operator+=(const T &c) {
    (*this)[0] += c;
    return *this;
  }

  F &operator-=(const T &c) {
    (*this)[0] -= c;
    return *this;
  }

  F &operator*=(const T &c) {
    for (auto &x : *this) x *= c;
    return *this;
  }

  F &operator/=(const T &c) {
    for (auto &x : *this) x /= c;
    return *this;
  }

  F &operator*=(const vector<pair<int, T>> &g) {
#ifdef LOCAL
    assert(!g.empty());
    assert(std::is_sorted(g.begin(), g.end()));
#endif
    this->resize(this->size() + g.back().first);
    int n = this->size();
    for (int i = n - 1; i >= 0; i--) {
      T res(0);
      for (const auto &[d, c] : g) {
        if (i - d < 0) break;
        res += (*this)[i - d] * c;
      }
      (*this)[i] = res;
    }
    return *this;
  }

  F &operator*(const vector<pair<int, T>> &g) { return F(*this) *= g; }

  pair<F, F> div(const vector<pair<int, T>> &g) {
#ifdef LOCAL
    assert(!g.empty());
    assert(std::is_sorted(g.begin(), g.end()));
#endif
    F f(*this);
    int n = f.size();
    int max_deg = g.back().first;
    T max_deg_coeff = g.back().second;
    F quo(max(1, n - max_deg), T(0));
    for (int i = n - 1; i >= max_deg; i--) {
      T q = f[i] / max_deg_coeff;
      int k = i - max_deg;
      quo[k] = q;
      for (const auto &[d, c] : g) f[d + k] -= c * q;
      f.pop_back();
    }
    return {quo, f};
  }

  F &operator/(const vector<pair<int, T>> &g) const { return div(g).first; }
  F &operator%(const vector<pair<int, T>> &g) const { return div(g).second; }

  F &operator/=(const vector<pair<int, T>> &g) { return *this = div(g).first; }
  F &operator%=(const vector<pair<int, T>> &g) { return *this = div(g).second; }

  T eval(const T &a) const {
    T b(1), res(0);
    for (auto x : *this) {
      res += x * b;
      b *= a;
    }
    return res;
  }

  F integral() {
    F f(1, T(0));
    for (int i = 0; i < this->size(); i++) {
      f.push_back((*this)[i] / T(i + 1));
    }
    return f;
  }

  T integral(T a, T b) {
    F f = integral();
    return f.eval(b) - f.eval(a);
  }
};

template <class T>
using fps = FormalPowerSeries<T>;
template <class T>
using sfps = vector<pair<int, T>>;

void solve() {
  int N;
  cin >> N;
  vector<int> L(N), R(N);
  vector<int> xs;
  xs.push_back(0);
  int maxR = -1, maxL = -1;
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    chmax(maxR, R[i]);
    chmax(maxL, L[i]);
    xs.push_back(L[i]);
    xs.push_back(R[i]);
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  mint ans(0);
  for (int i = 0; i + 1 < xs.size(); i++) {
    int x = xs[i], y = xs[i + 1];
    if (x < maxL) continue;
    fps<mint> f(1, mint(1));
    for (int j = 0; j < N; j++) {
      sfps<mint> g;
      mint w(R[j] - L[j]);
      if (y <= R[j]) {
        g.emplace_back(0, mint(-L[j]) / w);
        g.emplace_back(1, w.inv());
      }
      if (!g.empty()) { f *= g; }
    }
    ans += f.integral(x, y);
  }

  ans = mint(maxR) - ans;
  ans *= fac[N + 1];
  for (int i = 0; i < N; i++) { ans *= mint(R[i] - L[i]); }
  cout << ans << endl;
  return;
}

int main() {
  fastio();
  init(2000);
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
