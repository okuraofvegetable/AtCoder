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

#include <atcoder/modint>

using mint = atcoder::static_modint<1000000007>;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A;
  vector<vector<int>> zipped;
  auto dfs = [&](auto &&f, int mx, vector<int> &vec) {
    if (vec.size() == N) {
      for (int i = 0; i <= mx; i++) {
        bool flag = false;
        for (int v : vec) {
          if (v == i) {
            flag = true;
            break;
          }
        }
        if (!flag) return;
      }
      zipped.push_back(vec);
      return;
    }
    for (int i = 0; i < N; i++) {
      vec.push_back(i);
      f(f, max(mx, i), vec);
      vec.pop_back();
    }
    return;
  };
  vector<int> v;
  dfs(dfs, -1, v);

  mint sum(0);

  auto calc_LIS = [&](vector<int> &zip) {
    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
        if (zip[j] < zip[i]) chmax(dp[i], dp[j] + 1);
      }
    }
    return *max_element(all(dp));
  };

  auto nCk = [](int n, int k) {
    assert(k > 0);
    assert(n >= 0);
    if (n == 0 || n < k) return mint::raw(0);
    mint res(1);
    for (int i = 0; i < k; i++) {
      res *= mint::raw(n - i);
      res /= mint::raw(i + 1);
    }
    return res;
  };

  auto subsolve = [&](vector<int> &zip) {
    // dmp(zip);
    int M = *max_element(all(zip)) + 1;
    vector<int> X(M + 1, INF);
    X[0] = 0;
    for (int i = 0; i < N; i++) chmin(X[zip[i] + 1], A[i]);
    for (int i = M - 1; i >= 0; i--) chmin(X[i], X[i + 1] - 1);
    if (X[0] != 0) return;
    auto dp = vect(M + 1, vect(M + 1, mint(0)));
    auto dpsum = vect(M + 1, vect(M + 1, mint(0)));
    dp[0][0] = mint::raw(1);
    for (int i = 1; i <= M; i++) {
      for (int j = 0; j <= M; j++) { dpsum[i - 1][j] = dp[i - 1][j]; }
      for (int j = 1; j <= M; j++) { dpsum[i - 1][j] += dpsum[i - 1][j - 1]; }
      for (int j = 1; j <= i; j++) {
        for (int k = j - 1; k < i; k++) {
          dp[i][j] += dpsum[k][j - 1] * nCk(X[j] - X[j - 1], i - k);
        }
      }
    }
    mint ans(0);
    for (int i = 0; i <= M; i++) { ans += dp[M][i]; }
    sum += ans * calc_LIS(zip);
    // dmp(calc_LIS(zip));
    // dmp(X);
    // for (int i = 0; i <= M; i++) {
    //   for (int j = 0; j <= M; j++) { cout << dp[i][j].val() << ' '; }
    //   cout << endl;
    // }
    // dmp(ans.val());
    // cerr << endl;
  };

  for (auto &zip : zipped) subsolve(zip);

  mint prod(1);
  for (int a : A) prod *= mint::raw(a);

  cout << (sum / prod).val() << endl;

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
