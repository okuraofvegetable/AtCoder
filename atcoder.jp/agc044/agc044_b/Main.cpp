// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000               // 2e9
#define LLINF 2000000000000000000ll  // 2e18 (llmax:9e18)
#define fi first
#define sec second
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define dmp(x) cerr << #x << ": " << x << endl;

template <class T>
void chmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, const T &b) {
  if (a < b) a = b;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.fi << ',' << p.sec;
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.fi >> p.sec;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 < vec.size()) os << ' ';
  }
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}
void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

#define endl "\n"

void solve() {
  int N;
  cin >> N;
  vector<int> p(N * N);
  cin >> p;
  vector<vector<int>> dp(N, vector<int>(N, INF));
  vector<vector<int>> used(N, vector<int>(N, true));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      chmin(dp[i][j], i);
      chmin(dp[i][j], j);
      chmin(dp[i][j], N - 1 - i);
      chmin(dp[i][j], N - 1 - j);
      p[i * N + j]--;
    }
  }
  int ans = 0;
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
  for (int i = 0; i < N * N; i++) {
    int x = p[i] / N;
    int y = p[i] % N;
    ans += dp[x][y];
    used[x][y] = false;
    deque<P> q;
    q.push_back(P(x, y));
    while (!q.empty()) {
      P a = q.front();
      q.pop_front();
      int sx = a.first;
      int sy = a.second;
      for (int dir = 0; dir < 4; dir++) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (used[sx][sy]) {
          int val = dp[sx][sy] + 1;
          if (dp[nx][ny] > val) {
            dp[nx][ny] = val;
            q.push_back(P(nx, ny));
          }
        } else {
          int val = dp[sx][sy];
          if (dp[nx][ny] > val) {
            dp[nx][ny] = val;
            q.push_front(P(nx, ny));
          }
        }
      }
    }
  }
  cout << ans << endl;
  return;
}

signed main() {
  fastio();
  solve();
  //   int t;
  //   cin >> t;
  //   while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
