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
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
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
  int N, M;
  cin >> N >> M;

  vector<ll> xs;
  vector<ll> ys;

  vector<ll> a(N), b(N), c(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c[i];
    xs.push_back(a[i]);
    xs.push_back(b[i]);
    ys.push_back(c[i]);
  }

  vector<ll> d(M), e(M), f(M);
  for (int i = 0; i < M; i++) {
    cin >> d[i] >> e[i] >> f[i];
    xs.push_back(d[i]);
    ys.push_back(e[i]);
    ys.push_back(f[i]);
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  sort(all(ys));
  ys.erase(unique(all(ys)), ys.end());

  if (0 < xs.front() || xs.back() < 0 || 0 < ys.front() || ys.back() < 0) {
    cout << "INF" << endl;
    return;
  }

  int H = xs.size() - 1;
  int W = ys.size() - 1;

  auto xid = [&](ll x) { return lower_bound(all(xs), x) - xs.begin(); };
  auto yid = [&](ll y) { return lower_bound(all(ys), y) - ys.begin(); };

  int sx = xid(0) - 1;
  int sy = yid(0) - 1;

  auto R = vect(H, vect(W, false));
  auto L = vect(H, vect(W, false));
  auto U = vect(H, vect(W, false));
  auto D = vect(H, vect(W, false));

  for (int i = 0; i < N; i++) {
    a[i] = xid(a[i]);
    b[i] = xid(b[i]);
    c[i] = yid(c[i]);

    if (c[i] < W) {
      for (int j = a[i]; j < b[i]; j++) D[j][c[i]] = true;
    }
    if (c[i] - 1 >= 0) {
      for (int j = a[i]; j < b[i]; j++) U[j][c[i] - 1] = true;
    }
  }

  for (int i = 0; i < M; i++) {
    d[i] = xid(d[i]);
    e[i] = yid(e[i]);
    f[i] = yid(f[i]);

    if (d[i] < H) {
      for (int j = e[i]; j < f[i]; j++) L[d[i]][j] = true;
    }
    if (d[i] - 1 >= 0) {
      for (int j = e[i]; j < f[i]; j++) R[d[i] - 1][j] = true;
    }
  }

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) { cerr << R[i][j] << ' '; }
  //   cerr << endl;
  // }

  // cerr << endl;

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) { cerr << L[i][j] << ' '; }
  //   cerr << endl;
  // }

  // cerr << endl;

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) { cerr << D[i][j] << ' '; }
  //   cerr << endl;
  // }

  // cerr << endl;

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) { cerr << U[i][j] << ' '; }
  //   cerr << endl;
  // }

  assert(0 <= sx && sx < H && 0 <= sy && sy < W);

  ll ans = 0ll;

  queue<P> q;
  q.push(P(sx, sy));
  auto visited = vect(H, vect(W, false));
  visited[sx][sy] = true;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    ans += (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
    if (!R[x][y]) {
      if (x + 1 >= H) {
        cout << "INF" << endl;
        return;
      }
      if (!visited[x + 1][y]) {
        visited[x + 1][y] = true;
        q.push(P(x + 1, y));
      }
    }
    if (!L[x][y]) {
      if (x - 1 < 0) {
        cout << "INF" << endl;
        return;
      }
      if (!visited[x - 1][y]) {
        visited[x - 1][y] = true;
        q.push(P(x - 1, y));
      }
    }
    if (!U[x][y]) {
      if (y + 1 >= W) {
        cout << "INF" << endl;
        return;
      }
      if (!visited[x][y + 1]) {
        visited[x][y + 1] = true;
        q.push(P(x, y + 1));
      }
    }
    if (!D[x][y]) {
      if (y - 1 < 0) {
        cout << "INF" << endl;
        return;
      }
      if (!visited[x][y - 1]) {
        visited[x][y - 1] = true;
        q.push(P(x, y - 1));
      }
    }
  }

  cout << ans << endl;
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
