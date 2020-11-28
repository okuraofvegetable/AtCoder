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

using D = tuple<P, P, P>;
using T = tuple<int, int, int>;

int dist(P a, P b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

bool check(const P &a, const P &b, const P &c) {
  int ab = dist(a, b);
  int bc = dist(b, c);
  int ca = dist(c, a);
  int cnt = 0;
  if (ab == 1) cnt++;
  if (bc == 1) cnt++;
  if (ca == 1) cnt++;
  if (cnt < 2) return false;
  if (a.first == b.first && b.first == c.first) return false;
  if (a.second == b.second && b.second == c.second) return false;
  return true;
}

T toState(P a, P b, P c) {
  if (dist(a, b) == 2)
    swap(a, c);
  else if (dist(a, c) == 2)
    swap(a, b);
  if (a.second != b.second) swap(b, c);
  auto [x, y] = a;
  if (b.first - a.first == 1) {
    if (c.second - a.second == 1)
      return T(x, y, 0);
    else
      return T(x, y, 1);
  } else {
    if (c.second - a.second == -1)
      return T(x, y, 2);
    else
      return T(x, y, 3);
  }
}

D toPoints(T s) {
  auto [x, y, dir] = s;
  if (dir == 0) return D(P(x, y), P(x + 1, y), P(x, y + 1));
  if (dir == 1) return D(P(x, y), P(x + 1, y), P(x, y - 1));
  if (dir == 2) return D(P(x, y), P(x - 1, y), P(x, y - 1));
  if (dir == 3) return D(P(x, y), P(x - 1, y), P(x, y + 1));
  assert(false);
}

map<T, int> precalc(int sx, int sy, int sdir, int limit) {
  map<T, int> m;
  queue<T> q;
  m[T(sx, sy, sdir)] = 0;
  q.emplace(sx, sy, sdir);

  while (!q.empty()) {
    T cur = q.front();
    int d = m[cur];
    q.pop();
    if (d > limit) continue;
    auto [a, b, c] = toPoints(cur);
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        P na = P(a.first + i, a.second + j);
        P nb = P(b.first + i, b.second + j);
        P nc = P(c.first + i, c.second + j);
        if (check(na, b, c)) {
          auto state = toState(na, b, c);
          if (m.find(state) == m.end()) {
            m[state] = d + 1;
            q.push(state);
          }
        }
        if (check(a, nb, c)) {
          auto state = toState(a, nb, c);
          if (m.find(state) == m.end()) {
            m[state] = d + 1;
            q.push(state);
          }
        }
        if (check(a, b, nc)) {
          auto state = toState(a, b, nc);
          if (m.find(state) == m.end()) {
            m[state] = d + 1;
            q.push(state);
          }
        }
      }
    }
  }

  // for (auto [s, d] : m) {
  //   auto [x, y, dir] = s;
  //   dmp(x, y, dir, d);
  // }
  return m;
}

void solve(map<T, int> &m) {
  P a, b, c;
  cin >> a >> b >> c;
  T s = toState(a, b, c);
  auto [x, y, dir] = s;
  if (m.find(s) != m.end()) {
    cout << m[s] << endl;
    return;
  }
  auto mp = precalc(x, y, dir, 4);
  int ans = numeric_limits<int>::max();
  for (auto [from, sd] : m) {
    auto [sx, sy, sdir] = from;
    for (auto [to, td] : mp) {
      auto [tx, ty, tdir] = to;
      if (sdir != tdir) continue;
      int dx = tx - sx;
      int dy = ty - sy;
      int ax = abs(dx);
      int ay = abs(dy);
      if (dx > 0)
        dx = 1;
      else if (dx < 0)
        dx = -1;
      if (dy > 0)
        dy = 1;
      else if (dy < 0)
        dy = -1;
      int penalty = 0;
      if ((sdir == 0 || sdir == 2) && dx * dy > 0) penalty = 1;
      if ((sdir == 1 || sdir == 3) && dx * dy < 0) penalty = 1;
      chmin(ans, max(ax, ay) * 2 + sd + td + penalty);
    }
  }
  cout << ans << endl;
  return;
}

int main() {
  fastio();
  auto m = precalc(0, 0, 0, 10);
  int t;
  cin >> t;
  while (t--) solve(m);

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
