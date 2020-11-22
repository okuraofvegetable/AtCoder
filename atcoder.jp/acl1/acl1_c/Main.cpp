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

#include <atcoder/mincostflow>

void solve() {
  int N, M;
  cin >> N >> M;
  vector<string> f(N);
  cin >> f;
  int s = N * M, t = N * M + 1;
  int S = N * M + 2, T = N * M + 3;
  atcoder::mcf_graph<int, int> g(T + 1);
  auto encode = [&](int i, int j) { return i * M + j; };

  int C = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (f[i][j] == 'o') C++;

  g.add_edge(S, s, C, 0);
  g.add_edge(t, T, C, 0);

  int F = C;
  int geta = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (f[i][j] == '#') continue;
      int u = encode(i, j);
      g.add_edge(u, t, 1, 0);
      if (f[i][j] == 'o') g.add_edge(s, u, 1, 0);
      if (i + 1 < N && f[i + 1][j] != '#') {
        int v = encode(i + 1, j);
        geta -= C;
        F += C;
        g.add_edge(v, u, C, 1);
        g.add_edge(S, v, C, 0);
        g.add_edge(u, T, C, 0);
      }
      if (j + 1 < M && f[i][j + 1] != '#') {
        int v = encode(i, j + 1);
        geta -= C;
        F += C;
        g.add_edge(v, u, C, 1);
        g.add_edge(S, v, C, 0);
        g.add_edge(u, T, C, 0);
      }
    }
  }
  auto res = g.flow(S, T, F);
  dmp(res, geta);
  cout << -res.second - geta << endl;
  assert(res.first == F);
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
