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
  int L;
  cin >> L;
  vector<ll> A(L);
  cin >> A;
  auto dp = vect(L + 1, vect(5, LLINF));
  dp[0][0] = 0ll;
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < 5; j++) {
      if (dp[i][j] == LLINF) continue;
      ll Even = (A[i] == 0) ? 2 : (A[i] % 2);
      ll Odd = (A[i] % 2 == 1) ? 0 : 1;
      if (j == 0) {
        chmin(dp[i + 1][0], dp[i][0] + A[i]);
        chmin(dp[i + 1][1], dp[i][0] + Even);
        chmin(dp[i + 1][2], dp[i][0] + Odd);
        chmin(dp[i + 1][3], dp[i][0] + Even);
        chmin(dp[i + 1][4], dp[i][0] + A[i]);
      }
      if (j == 1) {
        chmin(dp[i + 1][1], dp[i][1] + Even);
        chmin(dp[i + 1][2], dp[i][1] + Odd);
        chmin(dp[i + 1][3], dp[i][1] + Even);
        chmin(dp[i + 1][4], dp[i][1] + A[i]);
      }
      if (j == 2) {
        chmin(dp[i + 1][2], dp[i][2] + Odd);
        chmin(dp[i + 1][3], dp[i][2] + Even);
        chmin(dp[i + 1][4], dp[i][2] + A[i]);
      }
      if (j == 3) {
        chmin(dp[i + 1][3], dp[i][3] + Even);
        chmin(dp[i + 1][4], dp[i][3] + A[i]);
      }
      if (j == 4) { chmin(dp[i + 1][4], dp[i][4] + A[i]); }
    }
    dmp(i + 1, dp[i + 1]);
  }
  ll ans = LLINF;
  for (int i = 0; i < 5; i++) chmin(ans, dp[L][i]);
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
