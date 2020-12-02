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
  \ cerr << "[ " << #__VA_ARGS__ << " ] : " << dump_str(__VA_ARGS__) << endl
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
  vector<ll> V(N), W(N);
  for (int i = 0; i < N; i++) { cin >> V[i] >> W[i]; }

  constexpr int H = 10;
  constexpr int MX = 100000;
  vector<int> depth(N, 0);
  auto dp = vect(1024, vect(MX + 1, 0ll));
  vector<vector<pair<ll, ll>>> brute(1024);

  if (W[0] <= MX) chmax(dp[0][W[0]], V[0]);
  for (int i = 0; i < MX; i++) chmax(dp[0][i + 1], dp[0][i]);

  for (int i = 1; i < N; i++) {
    int par = (i - 1) / 2;
    depth[i] = depth[par] + 1;
    if (depth[i] < H) {
      for (int j = 0; j <= MX; j++) {
        if (j + W[i] <= MX) chmax(dp[i][j + W[i]], dp[par][j] + V[i]);
        chmax(dp[i][j], dp[par][j]);
      }
      for (int j = 0; j < MX; j++) chmax(dp[i][j + 1], dp[i][j]);
    }
  }

  auto query = [&](int v, ll L) -> ll {
    deque<int> deq;
    deq.push_front(v);
    while (v > 0) {
      v = (v - 1) / 2;
      deq.push_front(v);
    }
    if (deq.size() <= H) return dp[deq.back()][L];

    ll ans = 0;
    int R = deq.size() - H;
    for (int i = 0; i < (1 << R); i++) {
      ll sumV = 0ll, sumW = 0ll;
      for (int j = 0; j < R; j++) {
        if (sumW > L) break;
        if ((i >> j) & 1) sumV += V[deq[H + j]], sumW += W[deq[H + j]];
      }
      if (sumW > L) continue;
      chmax(ans, dp[deq[H - 1]][L - sumW] + sumV);
    }
    return ans;
  };

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int v;
    ll L;
    cin >> v >> L;
    v--;
    cout << query(v, L) << endl;
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
