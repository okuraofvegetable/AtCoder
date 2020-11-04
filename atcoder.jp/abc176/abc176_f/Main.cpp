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

int pts(int a, int b, int c) {
  if (a == b && b == c)
    return 1;
  else
    return 0;
}

void solve() {
  int N;
  cin >> N;
  vector<int> A(3 * N);
  cin >> A;
  for (int i = 0; i < A.size(); i++) A[i]--;
  vector<int> B;
  B.push_back(A[0]);
  B.push_back(A[1]);
  int geta = 0;
  int M = N;
  for (int i = 0; i < N - 1; i++) {
    if (A[3 * i + 2] == A[3 * i + 3] && A[3 * i + 3] == A[3 * i + 4]) {
      geta++;
      M--;
      continue;
    }
    for (int j = 0; j < 3; j++) B.push_back(A[3 * i + 2 + j]);
  }
  B.push_back(A.back());

  auto dp = vect(N, vect(N, -INF));
  dp[B[0]][B[1]] = dp[B[1]][B[0]] = 0;
  int allmax = 0;
  vector<int> rowmax(N, -INF);
  vector<int> colmax(N, -INF);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      chmax(rowmax[i], dp[i][j]);
      chmax(colmax[j], dp[i][j]);
    }
  }

  for (int i = 0; i < M - 1; i++) {
    vector<tuple<int, int, int>> upd;
    vector<int> abc;
    for (int j = 2; j <= 4; j++) abc.push_back(B[3 * i + j]);
    sort(all(abc));
    do {
      int a = abc[0], b = abc[1], c = abc[2];
      for (int j = 0; j < N; j++) {
        upd.emplace_back(j, a, max(rowmax[j], colmax[j]));
        upd.emplace_back(a, j, max(rowmax[j], colmax[j]));
        if (b == c) upd.emplace_back(j, a, max(dp[j][b], dp[b][j]) + 1);
        if (b == c) upd.emplace_back(a, j, max(dp[j][b], dp[b][j]) + 1);
      }
      upd.emplace_back(a, b, dp[c][c] + 1);
      upd.emplace_back(b, a, dp[c][c] + 1);
      upd.emplace_back(a, b, allmax);
      upd.emplace_back(b, a, allmax);
    } while (next_permutation(all(abc)));

    for (auto [x, y, v] : upd) {
      chmax(rowmax[x], v);
      chmax(colmax[y], v);
      chmax(dp[x][y], v);
      chmax(allmax, v);
    }
  }
  cout << max(dp[B.back()][B.back()] + 1, allmax) + geta << endl;
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
