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

// ax + by = gcd(a, b)
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  if (b != 0) {
    T g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  } else {
    x = 1;
    y = 0;
    return a;
  }
}

vector<pair<ll, ll>> factorize(ll x) {
  ll tmp = x;
  vector<pair<ll, ll>> ret;
  for (ll i = 2ll; i * i <= x; i++) {
    ll mul = 1ll;
    while (tmp % i == 0ll) {
      tmp /= i;
      mul *= i;
    }
    if (mul > 1ll) ret.emplace_back(i, mul);
  }
  if (tmp != 1ll) ret.emplace_back(tmp, tmp);
  return ret;
}

void solve() {
  ll N;
  cin >> N;
  auto fac = factorize(2 * N);
  int M = fac.size();
  ll ans = LLINF;
  for (int i = 0; i < (1 << M); i++) {
    ll mul = 1ll;
    for (int j = 0; j < M; j++) {
      if ((i >> j) & 1) mul *= fac[j].second;
    }
    ll a, b;
    ll p = mul, q = 2 * N / mul;
    extgcd(p, q, a, b);
    if (a >= 0ll) {
      ll d = ((a / q) + 1);
      a -= d * q;
      b += d * p;
    }
    if (b <= 0ll) {
      ll d = ((-b) / p + 1);
      a -= d * q;
      b += d * p;
    }
    ll d1 = (b - 1) / p;
    ll d2 = (-1 - a) / q;
    ll d = min(d1, d2);
    a -= d * q;
    b += d * p;
    assert(a <= -1);
    assert(b >= 1);
    chmin(ans, p * (-a));
    dmp(p, q, a, b);
  }
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
