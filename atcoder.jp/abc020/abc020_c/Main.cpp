// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")
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
  int H, W;
  ll T;
  cin >> H >> W >> T;
  ll l = 1, r = INF;
  vector<string> f(H);
  cin >> f;
  P start, end;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (f[i][j] == 'S') start = P(i, j);
      if (f[i][j] == 'G') end = P(i, j);
    }
  }
  vector<int> dx({0, 1, 0, -1});
  vector<int> dy({1, 0, -1, 0});
  auto check = [&](ll X) {
    MinHeap<pair<ll, P>> q;
    auto dist = vect(H, vect(W, LLINF));
    q.push(make_pair(0ll, start));
    dist[start.first][start.second] = 0ll;
    while (!q.empty()) {
      auto a = q.top();
      q.pop();
      const ll &d = a.first;
      const int &x = a.second.first;
      const int &y = a.second.second;
      if (dist[x][y] < d) continue;
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        ll cost = (f[nx][ny] == '#') ? X : 1ll;
        if (dist[nx][ny] > d + cost) {
          dist[nx][ny] = d + cost;
          q.push(make_pair(d + cost, P(nx, ny)));
        }
      }
    }
    ll res = dist[end.first][end.second];
    return res <= T;
  };
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return;
}

signed main() {
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
