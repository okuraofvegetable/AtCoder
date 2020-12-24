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

void solve() {
  int H, W, D;
  cin >> H >> W >> D;
  if (D % 2 == 1) {
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if ((i + j) % 2 == 0)
          cout << 'R';
        else
          cout << 'B';
      }
      cout << endl;
    }
    return;
  }
  auto ans = vect(H, vect(W, 0));
  vector<int> dx = {1, 1, -1, -1};
  vector<int> dy = {-1, 1, 1, -1};
  vector<vector<int>> col(5);
  vector<string> s(5);
  s[1] = "4342";
  s[2] = "3134";
  s[3] = "2421";
  s[4] = "1213";
  for (int c = 1; c <= 4; c++) {
    for (int i = 0; i < s[c].size(); i++) col[c].push_back(s[c][i] - '0');
  }
  queue<tuple<int, int, int>> q;
  set<P> se;
  q.emplace(0, 0, 1);
  q.emplace(0, 1, 1);
  while (!q.empty()) {
    auto [x, y, c] = q.front();
    q.pop();
    bool flag = false;
    for (int i = 0; i < D / 2; i++) {
      for (int j = 0; j < D / 2; j++) {
        int nx = x + dx[0] * i + dx[1] * j;
        int ny = y + dy[0] * i + dy[1] * j;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        flag = true;
        ans[nx][ny] = c;
      }
    }
    if (!flag) continue;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir] * D / 2;
      int ny = y + dy[dir] * D / 2;
      if (se.find(P(nx, ny)) != se.end()) continue;
      se.insert(P(nx, ny));
      q.emplace(nx, ny, col[c][dir]);
    }
  }

  string cs = "RBGY";
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { cout << cs[ans[i][j] - 1]; }
    cout << endl;
  }
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
