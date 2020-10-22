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
#define eps 1e-4
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

const int B = 700;

struct Query {
  int l, r, id;
  Query() {}
  Query(int l, int r, int id) : l(l), r(r), id(id) {}
  bool operator<(const Query &a) const { return l > a.l; }
};

#include <atcoder/fenwicktree>

void solve() {
  int W, H;
  cin >> W >> H;
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  vector<int> xs, ys;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    xs.push_back(X[i]);
    ys.push_back(Y[i]);
  }

  xs.push_back(1);
  xs.push_back(W);

  ys.push_back(1);
  ys.push_back(H);

  sort(all(xs));
  sort(all(ys));
  xs.erase(unique(all(xs)), xs.end());
  ys.erase(unique(all(ys)), ys.end());

  vector<int> x = X, y = Y;
  for (int &v : x) v = lower_bound(all(xs), v) - xs.begin();
  for (int &v : y) v = lower_bound(all(ys), v) - ys.begin();

  // dmp(xs);
  // dmp(x);
  // dmp(X);

  // dmp(ys);
  // dmp(y);
  // dmp(Y);

  vector<int> xL(xs.size()), xR(xs.size());
  vector<int> yL(ys.size()), yR(ys.size());
  for (int i = 0; i < xs.size(); i++) {
    xL[i] = (i == 0) ? 1 : xs[i - 1] + 1;
    xR[i] = (i + 1 == xs.size()) ? W : xs[i + 1] - 1;
  }
  for (int i = 0; i < ys.size(); i++) {
    yL[i] = (i == 0) ? 1 : ys[i - 1] + 1;
    yR[i] = (i + 1 == ys.size()) ? H : ys[i + 1] - 1;
  }

  auto dp =
      vect(xs.size(), vect(xs.size(), vect(ys.size(), vect(ys.size(), -1ll))));

  auto rec = [&](auto &&f, int xl, int xr, int yl, int yr) -> ll {
    if (xl >= xs.size() || xr < 0 || yl >= ys.size() || yr < 0) return 0ll;
    if (xl > xr || yl > yr) return 0ll;
    if (dp[xl][xr][yl][yr] != -1ll) return dp[xl][xr][yl][yr];
    ll res = 0ll;
    ll xw = xR[xr] - xL[xl] + 1;
    ll yw = yR[yr] - yL[yl] + 1;
    for (int i = 0; i < N; i++) {
      if (X[i] < xs[xl] || X[i] > xs[xr] || Y[i] < ys[yl] || Y[i] > ys[yr])
        continue;
      chmax(res, xw + yw - 1 + f(f, xl, x[i] - 1, yl, y[i] - 1) +
                     f(f, xl, x[i] - 1, y[i] + 1, yr) +
                     f(f, x[i] + 1, xr, yl, y[i] - 1) +
                     f(f, x[i] + 1, xr, y[i] + 1, yr));
    }
    // cerr << xl << ' ' << xr << ' ' << yl << ' ' << yr << " : " << res <<
    // endl;
    return dp[xl][xr][yl][yr] = res;
  };

  cout << rec(rec, 0, xs.size() - 1, 0, ys.size() - 1) << endl;

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
