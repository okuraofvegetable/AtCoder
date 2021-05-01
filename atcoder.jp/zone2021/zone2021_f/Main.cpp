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

void solve() {
  int N, M;
  cin >> N >> M;
  int n = 0;
  while ((1 << n) < N) n++;
  vector<bool> A(N, true);
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    A[x] = false;
  }

  // const int MX = 20;
  // auto mat = vect(N - 1 - M, vect(MX, 0));

  // auto add_column = [&](ll x) {
  //   for (int i = 0; i < MX; i++) { mat[i].push_back((x >> i) & 1); }
  // };

  // auto get_rank = [&]() -> int {
  //   auto tmp = mat;
  //   if (tmp.empty()) return 0;
  //   int R = tmp.size(), C = tmp[0].size();
  //   int rank = 0;
  //   int r = 0, c = 0;
  //   while (r < R && c < C) {
  //     if (tmp[r][c] == 0) {
  //       int sr = -1;
  //       for (int nr = r + 1; nr < R; nr++) {
  //         if (tmp[nr][c]) {
  //           sr = nr;
  //           break;
  //         }
  //       }
  //       if (sr == -1) {
  //         c++;
  //         continue;
  //       }
  //       for (int i = 0; i < C; i++) swap(tmp[r][i], tmp[sr][i]);
  //     }
  //     for (int i = r + 1; i < R; i++) {
  //       if (tmp[i][c] == 1) {
  //         for (int j = c; j < C; j++) tmp[i][j] = (tmp[r][j] ^ tmp[i][j]);
  //       }
  //     }
  //     r++;
  //     rank++;
  //   }
  //   return rank;
  // };

  // auto dump_mat = [&]() -> void {
  //   for (const auto &row : mat) cerr << row << endl;
  //   cerr << endl;
  // };

  // int idx = 0;
  // for (int i = 1; i < N; i++) {
  //   if (A[i]) {
  //     for (int j = 0; j < MX; j++) { mat[idx][j] = ((i >> j) & 1); }
  //     idx++;
  //   }
  // }

  vector<int> cs;
  vector<int> bs;

  for (int i = 1; i < N; i++) {
    if (A[i]) {
      int x = i;
      for (int b : bs) chmin(x, x ^ b);
      if (x) {
        bs.push_back(x);
        cs.push_back(i);
      }
    }
  }

  if (bs.size() < n) {
    cout << -1 << endl;
    return;
  }

  vector<pii> ans;
  vector<bool> used(N, false);
  function<void(int)> dfs = [&](int v) {
    used[v] = true;
    for (int c : cs) {
      int u = v ^ c;
      if (!used[u]) {
        ans.emplace_back(u, v);
        dfs(u);
      }
    }
  };

  dfs(0);

  for (auto [u, v] : ans) { cout << u << ' ' << v << endl; }
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
