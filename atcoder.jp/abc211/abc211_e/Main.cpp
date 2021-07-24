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

#include <atcoder/modint>
// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint &v) {
  return os << v.val();
}

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

void YesNo(bool f) {
  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int N, K;

set<uint64_t> used;

vector<pii> used_points(uint64_t f) {
  vector<pii> ret;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((f >> (N * i + j)) & 1ull) { ret.emplace_back(i, j); }
    }
  }
  return ret;
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

vector<uint64_t> res;

void dfs(uint64_t f, int num) {
  used.insert(f);
  if (num == K) {
    res.push_back(f);
    return;
  }
  auto ups = used_points(f);
  for (auto [x, y] : ups) {
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if ((f >> (N * nx + ny)) & 1ull) continue;
      uint64_t nf = f | (1ull << (N * nx + ny));
      if (used.count(nf)) continue;
      dfs(nf, num + 1);
    }
  }
}

void print(uint64_t f) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((f >> (i * N + j)) & 1ull)
        cout << "@";
      else
        cout << ".";
    }
    cout << endl;
  }
}

void solve() {
  cin >> N >> K;
  vector<string> fs(N);
  cin >> fs;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // assert(!used.count(1 << (N * i + j)));
      dfs((1ull << (N * i + j)), 1);
    }
  }

  // for (int f : res) {
  //   dmp(f);
  //   print(f);
  // }

  auto check = [&](uint64_t f) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (((f >> (i * N + j)) & 1ull) && fs[i][j] == '#') return false;
      }
    }
    return true;
  };

  int ans = 0;
  for (uint64_t f : res) {
    if (check(f)) { ans++; }
  }

  cout << ans << endl;

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
