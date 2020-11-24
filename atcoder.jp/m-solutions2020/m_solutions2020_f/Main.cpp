#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
  int N;
  cin >> N;

  vector<int> X(N), Y(N);
  vector<char> U(N);
  rep(i, N) cin >> X[i] >> Y[i] >> U[i];

  int ans = INF;

  // v
  // ^
  {
    map<int, vector<pair<int, char>>> m;
    for (int i = 0; i < N; i++) {
      if (U[i] == 'L' || U[i] == 'R') continue;
      m[X[i]].emplace_back(Y[i], U[i]);
    }

    for (auto &[_, vec] : m) {
      sort(all(vec));
      int Ucnt = 0;
      int Umax = -INF;
      for (auto [y, dir] : vec) {
        if (dir == 'U') {
          Ucnt++;
          chmax(Umax, y);
        } else {
          if (Ucnt > 0) chmin(ans, (y - Umax) * 5);
        }
      }
    }
  }

  // ><
  {
    map<int, vector<pair<int, char>>> m;
    for (int i = 0; i < N; i++) {
      if (U[i] == 'D' || U[i] == 'U') continue;
      m[Y[i]].emplace_back(X[i], U[i]);
    }

    for (auto &[_, vec] : m) {
      sort(all(vec));
      int Rcnt = 0;
      int Rmax = -INF;
      for (auto [x, dir] : vec) {
        if (dir == 'R') {
          Rcnt++;
          chmax(Rmax, x);
        } else {
          if (Rcnt > 0) chmin(ans, (x - Rmax) * 5);
        }
      }
    }
  }

  //> v, ^ <
  {
    map<int, vector<pair<int, char>>> m;
    for (int i = 0; i < N; i++) { m[X[i] - Y[i]].emplace_back(X[i], U[i]); }

    for (auto &[_, vec] : m) {
      sort(all(vec));
      int Rmax = -INF, Umax = -INF;
      for (auto [x, dir] : vec) {
        if (dir == 'R') {
          chmax(Rmax, x);
        } else if (dir == 'U') {
          chmax(Umax, x);
        } else if (dir == 'D') {
          if (Rmax > -INF) chmin(ans, (x - Rmax) * 10);
        } else {
          if (Umax > -INF) chmin(ans, (x - Umax) * 10);
        }
      }
    }
  }

  // > ^, v <
  {
    map<int, vector<pair<int, char>>> m;
    for (int i = 0; i < N; i++) { m[X[i] + Y[i]].emplace_back(X[i], U[i]); }

    for (auto &[_, vec] : m) {
      sort(all(vec));
      int Rmax = -INF, Dmax = -INF;
      for (auto [x, dir] : vec) {
        if (dir == 'R') {
          chmax(Rmax, x);
        } else if (dir == 'D') {
          chmax(Dmax, x);
        } else if (dir == 'U') {
          if (Rmax > -INF) chmin(ans, (x - Rmax) * 10);
        } else {
          if (Dmax > -INF) chmin(ans, (x - Dmax) * 10);
        }
      }
    }
  }

  if (ans == INF)
    cout << "SAFE" << endl;
  else
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
