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

struct edge {
  int to;
  ll A, B;
  edge() {}
  edge(int to, ll A, ll B) : to(to), A(A), B(B) {}
};

void solve() {
  int N, M, S;
  cin >> N >> M >> S;
  chmin(S, N * 51);
  vector<vector<edge>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    g[u].emplace_back(v, a, b);
    g[v].emplace_back(u, a, b);
  }
  vector<int> C(N), D(N);
  for (int i = 0; i < N; i++) cin >> C[i] >> D[i];
  auto encode = [](int v, int d) { return 2600 * v + d; };
  vector<ll> dist(2600 * N, LLINF);
  dist[encode(0, S)] = 0ll;
  MinHeap<pair<ll, int>> q;
  q.push(make_pair(0ll, encode(0, S)));
  while (!q.empty()) {
    auto a = q.top();
    q.pop();
    //     dmp(a.second);
    if (dist[a.second] < a.first) continue;
    int v = a.second / 2600;
    int d = a.second % 2600;
    //     dmp(v);
    //     dmp(d);
    for (auto e : g[v]) {
      if (d >= e.A) {
        int u = encode(e.to, d - e.A);
        if (dist[u] > a.first + e.B) {
          dist[u] = a.first + e.B;
          q.push(make_pair(dist[u], u));
        }
      }
    }
    if (d + C[v] <= 51 * N) {
      int w = encode(v, d + C[v]);
      if (dist[w] > a.first + D[v]) {
        dist[w] = a.first + D[v];
        q.push(make_pair(dist[w], w));
      }
    }
  }
  vector<ll> ans(N, LLINF);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2600; j++) { chmin(ans[i], dist[encode(i, j)]); }
  }
  for (int i = 1; i < ans.size(); i++) cout << ans[i] << endl;
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
