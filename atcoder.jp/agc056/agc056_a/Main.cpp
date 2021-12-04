#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define drep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)

#define popcount __builtin_popcount
#define next __next
#define prev __prev

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

// ------------------ ACL --------------------

// #include <atcoder/modint>
// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// using mint = atcoder::static_modint<MOD>;
// ostream &operator<<(ostream &os, const mint &v) {
//   return os << v.val();
// }

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool found;

vector<vector<vector<int>>> sol(12);

void get(int n, vector<int> &cur, vector<int> &colsum) {
  if (found) return;
  if (cur.size() == n) {
    auto used = vect(n, vect(n, false));
    int cmp = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (((cur[i] >> j) & 1) && !used[i][j]) {
          cmp++;
          queue<pii> q;
          q.emplace(i, j);
          while (!q.empty()) {
            auto [x, y] = q.front();
            used[x][y] = true;
            q.pop();
            for (int d = 0; d < 4; d++) {
              int ni = x + dx[d], nj = y + dy[d];
              if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
              if (((cur[ni] >> nj) & 1) && !used[ni][nj]) q.emplace(ni, nj);
            }
          }
        }
      }
    }
    if (cmp == n) {
      sol[n] = vect(n, vect(n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { sol[n][i][j] = ((cur[i] >> j) & 1); }
      }
      found = true;
    }
    return;
  }
  for (int i = 0; i < (1 << n); i++) {
    if (popcount(i) != 3) continue;
    bool valid = true;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        colsum[j]++;
        if (colsum[j] > 3) valid = false;
      }
    }
    cur.push_back(i);
    if (valid) { get(n, cur, colsum); }
    if (found) return;
    cur.pop_back();
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) { colsum[j]--; }
    }
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 6; i < 12; i++) {
    auto colsum = vect(i, 0);
    auto cur = vect(0, 0);
    found = false;
    get(i, cur, colsum);
  }

  auto ans = vect(n, vect(n, 0));

  int K = n / 6 - 1;
  int r = n % 6 + 6;
  assert(6 * K + r == n);

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 6; k++) { ans[6 * i + j][6 * i + k] = sol[6][j][k]; }
    }
  }
  for (int j = 0; j < r; j++) {
    for (int k = 0; k < r; k++) { ans[6 * K + j][6 * K + k] = sol[r][j][k]; }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == 1)
        cout << '#';
      else
        cout << '.';
    }
    cout << endl;
  }

  return;
}

int main() {
  fastio();
  if (!multitest) {
    solve();
  } else {
    cerr << "[Warning] Multi testcase mode on" << endl;
    int t;
    cin >> t;
    while (t--) solve();
  }
  return 0;
}
