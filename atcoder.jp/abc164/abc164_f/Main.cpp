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

using ull = unsigned long long;

vector<vector<ull>> sub(const vector<ull> &S, const vector<ull> &T,
                        const vector<ull> &U, const vector<ull> &V) {
  int N = S.size();
  auto ret = vect(N, vect(N, 2ull));

  bool onerow = false;
  bool zerorow = false;
  vector<int> row(N, -1);
  for (int i = 0; i < N; i++) {
    if (S[i] == 0 && U[i] == 1) {
      // all - 1
      onerow = true;
      row[i] = 1;
      for (int j = 0; j < N; j++) ret[i][j] = 1ull;
    }
    if (S[i] == 1 && U[i] == 0) {
      // all - 0
      zerorow = true;
      row[i] = 0;
      for (int j = 0; j < N; j++) ret[i][j] = 0ull;
    }
  }
  vector<int> remrow;
  for (int i = 0; i < N; i++)
    if (row[i] == -1) remrow.push_back(i);

  bool onecol = false;
  bool zerocol = false;
  vector<int> col(N, -1);
  for (int i = 0; i < N; i++) {
    if (T[i] == 0 && V[i] == 1) {
      // all - 1
      onecol = true;
      col[i] = 1;
      for (int j = 0; j < N; j++) {
        if (ret[j][i] == 0ull) {
          ret.clear();
          return ret;
        }
        ret[j][i] = 1ull;
      }
    }
    if (T[i] == 1 && V[i] == 0) {
      // all - 0
      zerocol = true;
      col[i] = 0;
      for (int j = 0; j < N; j++) {
        if (ret[j][i] == 1ull) {
          ret.clear();
          return ret;
        }
        ret[j][i] = 0ull;
      }
    }
  }
  vector<int> remcol;
  for (int i = 0; i < N; i++)
    if (col[i] == -1) remcol.push_back(i);

  vector<pair<int, ull>> rowreq;
  for (int i = 0; i < N; i++) {
    if (S[i] == 0 && U[i] == 0) {
      // at least one 0
      if (zerocol) continue;
      rowreq.emplace_back(i, 0ull);
    }
    if (S[i] == 1 && U[i] == 1) {
      // at least one 1
      if (onecol) continue;
      rowreq.emplace_back(i, 1ull);
    }
  }

  vector<pair<int, ull>> colreq;
  for (int i = 0; i < N; i++) {
    if (T[i] == 0 && V[i] == 0) {
      // at least one 0
      if (zerorow) continue;
      colreq.emplace_back(i, 0ull);
    }
    if (T[i] == 1 && V[i] == 1) {
      // at least one 1
      if (onerow) continue;
      colreq.emplace_back(i, 1ull);
    }
  }

  dmp(rowreq);
  dmp(colreq);
  dmp(remrow);
  dmp(remcol);

  if (remrow.empty() || remcol.empty()) {
    if (!rowreq.empty() || !colreq.empty()) ret.clear();
    return ret;
  }

  if (remrow.size() == 1) {
    for (auto [col, v] : colreq) ret[remrow.front()][col] = v;
    if (rowreq.empty()) return ret;
    auto [row, v] = rowreq.front();
    bool ok = false;
    for (int i = 0; i < N; i++) {
      if (ret[row][i] == v || ret[row][i] == 2ull) {
        ret[row][i] = v;
        ok = true;
        break;
      }
    }
    if (!ok) ret.clear();
    return ret;
  }

  if (remcol.size() == 1) {
    for (auto [row, v] : rowreq) ret[row][remcol.front()] = v;
    if (colreq.empty()) return ret;
    auto [col, v] = colreq.front();
    bool ok = false;
    for (int i = 0; i < N; i++) {
      if (ret[i][col] == v || ret[i][col] == 2ull) {
        ret[i][col] = v;
        ok = true;
        break;
      }
    }
    if (!ok) ret.clear();
    return ret;
  }

  assert(remrow.size() >= 2 && remcol.size() >= 2);

  for (auto [row, v] : rowreq) {
    if (row == remrow.front())
      ret[row][remcol[1]] = v;
    else
      ret[row][remcol[0]] = v;
  }

  for (auto [col, v] : colreq) {
    if (col == remcol[1])
      ret[remrow[1]][col] = v;
    else
      ret[remrow[0]][col] = v;
  }

  return ret;
}

void solve() {
  int N;
  cin >> N;
  vector<ull> S(N), T(N), U(N), V(N);
  cin >> S >> T >> U >> V;
  auto ans = vect(N, vect(N, 0ull));
  for (int i = 0; i < 64; i++) {
    vector<ull> u(N), v(N);
    for (int j = 0; j < N; j++) {
      u[j] = ((U[j] >> i) & 1ull);
      v[j] = ((V[j] >> i) & 1ull);
    }
    auto ret = sub(S, T, u, v);
    if (ret.empty()) {
      cout << -1 << endl;
      return;
    }
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (ret[j][k] == 2ull) ret[j][k] = 0ull;
        ans[j][k] |= (ret[j][k] << i);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << ans[i][j];
      if (j + 1 < N)
        cout << ' ';
      else
        cout << endl;
    }
  }
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
