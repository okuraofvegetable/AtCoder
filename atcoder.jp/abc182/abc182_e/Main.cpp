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

set<P> r[2000], c[2000];

void solve() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    r[A[i]].emplace(B[i], 1);
    c[B[i]].emplace(A[i], 1);
  }
  auto m = vect(H, vect(W, false));
  vector<int> C(M), D(M);
  for (int i = 0; i < M; i++) {
    cin >> C[i] >> D[i];
    C[i]--;
    D[i]--;
    r[C[i]].emplace(D[i], 0);
    c[D[i]].emplace(C[i], 0);
    m[C[i]][D[i]] = true;
  }
  auto check_row = [&](int x, int y) -> bool {
    if (r[x].size() == 0) return false;
    auto it = r[x].lower_bound(P(y, 0));
    if (it != r[x].end() && it->second == 1) return true;
    if (it != r[x].begin()) {
      it--;
      if (it->second == 1) return true;
    }
    return false;
  };
  auto check_col = [&](int x, int y) -> bool {
    if (c[y].size() == 0) return false;
    auto it = c[y].lower_bound(P(x, 0));
    if (it != c[y].end() && it->second == 1) return true;
    if (it != c[y].begin()) {
      it--;
      if (it->second == 1) return true;
    }
    return false;
  };
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (m[i][j]) continue;
      if (check_row(i, j) || check_col(i, j)) { ans++; }
    }
  }
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
