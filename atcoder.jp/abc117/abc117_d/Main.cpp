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
  int N;
  cin >> N;
  ll K;
  cin >> K;
  vector<ll> A(N);
  cin >> A;
  auto dp = vect(61, vect(2, -LLINF));
  vector<ll> cnt(60, 0ll);
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < N; j++) {
      if ((A[j] >> i) & 1) cnt[i]++;
    }
  }
  dp[0][1] = 0ll;
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < 2; j++) {
      if (dp[i][j] == -LLINF) continue;
      ll bit = (1LL << (59 - i));
      // use 0
      if (j == 1 && (bit & K) == 0) {
        chmax(dp[i + 1][1], dp[i][j] + bit * cnt[59 - i]);
      } else {
        chmax(dp[i + 1][0], dp[i][j] + bit * cnt[59 - i]);
      }
      // use 1
      if (j == 1 && (bit & K) == 0) continue;
      if (j == 1) {
        chmax(dp[i + 1][1], dp[i][j] + bit * ((ll)N - cnt[59 - i]));
      } else {
        chmax(dp[i + 1][0], dp[i][j] + bit * ((ll)N - cnt[59 - i]));
      }
    }
  }
  cout << max(dp[60][0], dp[60][1]) << endl;
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
