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

template <class T>
struct RangeSum {
  vector<T> vec;
  RangeSum() {}
  RangeSum(vector<T> elems) : vec(elems) {
    for (int i = 1; i < vec.size(); i++) { vec[i] += vec[i - 1]; }
  }
  T sum(int l, int r) {
    if (l > r) return T(0);
    if (l == 0)
      return vec[r];
    else
      return vec[r] - vec[l - 1];
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<ll> w(N);
  auto cost = vect(N, vect(N, -LLINF));
  cin >> w;
  ll mxw = *max_element(all(w));
  vector<pair<ll, ll>> bs(M);
  ll minv = LLINF;
  for (int i = 0; i < M; i++) {
    cin >> bs[i].first >> bs[i].second;
    chmin(minv, bs[i].second);
  }
  sort(all(bs));
  for (int i = M - 2; i >= 0; i--) chmin(bs[i].second, bs[i + 1].second);
  set<pair<int, int>> s;
  for (int i = 0; i < M; i++) {
    s.insert(pair<int, int>(bs[i].second, bs[i].first));
  }
  s.insert(pair<int, int>(0, 0));

  if (minv < mxw) {
    cout << -1 << endl;
    return;
  }

  ll ans = LLINF;
  vector<int> perm;
  for (int i = 0; i < N; i++) perm.push_back(i);
  do {
    vector<ll> W(N);
    for (int i = 0; i < N; i++) W[i] = w[perm[i]];
    RangeSum<ll> rs(W);
    vector<ll> dp(N, 0);
    for (int i = 1; i < N; i++) {
      chmax(dp[i], dp[i - 1]);
      for (int j = 0; j < i; j++) {
        ll wsum = rs.sum(j, i);
        auto it = s.lower_bound(pair<int, int>(wsum, -1));
        it--;
        chmax(dp[i], dp[j] + it->second);
      }
    }
    chmin(ans, dp[N - 1]);
  } while (next_permutation(all(perm)));
  cout << ans << endl;
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
