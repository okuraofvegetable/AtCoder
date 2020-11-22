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

void solve() {
  int H, W;
  cin >> H >> W;
  vector<string> f(H);
  cin >> f;
  vector<vector<P>> alpha(26);
  int sx, sy, gx, gy;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (islower(f[i][j])) { alpha[f[i][j] - 'a'].emplace_back(i, j); }
      if (f[i][j] == 'S') sx = i, sy = j;
      if (f[i][j] == 'G') gx = i, gy = j;
    }
  }
  vector<bool> used(26, false);
  auto dist = vect(H, vect(W, INF));
  queue<P> q;
  dist[sx][sy] = 0;
  q.emplace(sx, sy);
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
  while (!q.empty()) {
    P a = q.front();
    q.pop();
    int x = a.first;
    int y = a.second;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (f[nx][ny] == '#') continue;
      if (dist[nx][ny] != INF) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.emplace(nx, ny);
    }
    if (islower(f[x][y]) && !used[f[x][y] - 'a']) {
      int c = f[x][y] - 'a';
      used[c] = true;
      for (auto [nx, ny] : alpha[c]) {
        if (dist[nx][ny] == INF) {
          dist[nx][ny] = dist[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    }
  }
  if (dist[gx][gy] == INF)
    cout << -1 << endl;
  else
    cout << dist[gx][gy] << endl;
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
