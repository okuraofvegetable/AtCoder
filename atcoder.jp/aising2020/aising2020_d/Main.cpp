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
  is >> p.first >> p.second;
  return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}

// ----------------- Output ------------------

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << ',' << p.second;
  return os;
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
  os << "}";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const multiset<T> &s) {
  os << "{ ";
  for (const T &e : s) os << e << " ";
  os << "}";
  return os;
}

template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
  os << "{ ";
  for (const auto &[key, val] : m) os << "( " << key << " -> " << val << " ) ";
  os << "}";
  return os;
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
  dump_str_rec(oss, forward<T>(args)...);
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

#include <atcoder/modint>

// using mint = atcoder::static_modint<998244353>;

int get_mod(const string &s, int mod) {
  int cur = 0;
  for (int i = 0; i < s.size(); i++) {
    cur *= 2;
    if (s[i] == '1') cur++;
    cur %= mod;
  }
  return cur;
}

vector<int> pow2_mod(int N, int mod) {
  vector<int> b;
  int cur = 1 % mod;
  for (int i = 0; i < N; i++) {
    b.push_back(cur);
    cur = (cur * 2) % mod;
  }
  reverse(all(b));
  return b;
}

void solve() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  int cnt = 0;
  for (char c : s)
    if (c == '1') cnt++;

  int m1 = -1, m2 = -1;
  if (cnt - 1 > 0) m1 = get_mod(s, cnt - 1);
  m2 = get_mod(s, cnt + 1);
  dmp(m1, m2);

  vector<int> g(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    int popcnt = __builtin_popcount(i);
    g[i] = g[i % popcnt] + 1;
  }

  dmp(g);

  vector<int> b1, b2;

  if (cnt - 1 > 0) b1 = pow2_mod(N, cnt - 1);
  b2 = pow2_mod(N, cnt + 1);
  dmp(b1);
  dmp(b2);

  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    if (s[i] == '1') {
      if (cnt - 1 == 0)
        ans[i] = -1;
      else {
        int r = (m1 - b1[i] + cnt - 1) % (cnt - 1);
        ans[i] = g[r];
      }
    } else {
      int r = (m2 + b2[i]) % (cnt + 1);
      ans[i] = g[r];
    }
  }
  for (int i = 0; i < N; i++) cout << ans[i] + 1 << endl;
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
