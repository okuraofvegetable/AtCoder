#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

int sub(vector<int> &xc, vector<int> &yc) {
  int N = xc.size();
  int xall = 0, yall = 0;
  rep(i, N) {
    if (yc[i] == N) yall++;
    if (xc[i] == N) xall++;
  }
  int ans = INF;
  rep(i, N) {
    int getall = N - xc[i] + N - yall + (yc[i] > 0 ? 0 : 1);
    chmin(ans, getall);
  }
  // dmp(xc, yc, ans);
  return ans;
}

void solve() {
  int N;
  cin >> N;
  vector<string> a(N);
  cin >> a;

  vector<int> xc(N, 0), yc(N, 0);
  rep(i, N) rep(j, N) if (a[i][j] == '#') xc[i]++, yc[j]++;

  int b = 0, w = 0;
  rep(i, N) rep(j, N) {
    if (a[i][j] == '.') w++;
    if (a[i][j] == '#') b++;
  }
  if (w == 0) {
    cout << 0 << endl;
    return;
  }
  if (b == 0) {
    cout << -1 << endl;
    return;
  }

  int ans = sub(xc, yc);

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     // a[i][.] -> a[.][j]
  //     {
  //       auto px = xc, py = yc;
  //       rep(k, N) if (a[i][k] == '#') xc[i]--, yc[k]--;
  //       rep(k, N) if (a[k][j] == '#') xc[i]++, yc[k]++;
  //       chmin(ans, sub(xc, yc) + 1);
  //       // dmp(i, j, ans);
  //       xc = px;
  //       yc = py;
  //     }
  //   }
  // }

  cout << ((ans == INF) ? -1 : ans) << endl;

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
