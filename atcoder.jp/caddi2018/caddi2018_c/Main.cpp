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

// a * 4^p <= b * 4^q
bool comp(ll a, int p, ll b, int q) {
  int r = min(p, q);
  p -= r;
  q -= r;
  if (p == 0) {
    int x = 0;
    while (a > b) {
      x++;
      b *= 4;
    }
    return q >= x;
  } else {
    int x = 0;
    while (a * 4 <= b) {
      x++;
      a *= 4;
    }
    return p <= x;
  }
}

vector<ll> calc(const vector<ll> &A) {
  int N = A.size();
  vector<ll> V(N + 1, 0);
  vector<int> p(N), r(N);
  for (int i = 0; i < N; i++) p[i] = 0, r[i] = i;
  for (int i = N - 1; i >= 0; i--) {
    V[i] = V[i + 1];
    int cur = i;
    while (cur + 1 < N && !comp(A[cur], p[cur], A[cur + 1], p[cur + 1])) {
      r[i] = r[cur + 1];
      int x = 1;
      while (!comp(A[cur], p[cur], A[cur + 1], p[cur + 1] + x)) x++;
      V[i] += (ll)(r[cur + 1] - cur) * x;
      p[cur + 1] += x;
      if (cur + 1 < r[cur + 1]) p[r[cur + 1]] += x;
      cur = r[cur + 1];
    }
  }
  return V;
}

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  cin >> A;
  auto R = calc(A);
  reverse(all(A));
  auto L = calc(A);
  reverse(all(L));
  dmp(R);
  dmp(L);
  ll ans = LLINF;
  for (int i = 0; i <= N; i++) chmin(ans, 2 * (L[i] + R[i]) + i);
  cout << ans << endl;
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
