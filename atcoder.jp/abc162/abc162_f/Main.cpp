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

ll solve_even(vector<ll> &A) {
  int N = A.size();
  vector<ll> o(N, 0ll), e(N, 0ll);
  for (int i = 0; i < N; i++) {
    if (i % 2 == 1)
      o[i] = A[i];
    else
      e[i] = A[i];
  }
  RangeSum<ll> odd(o), even(e);
  vector<ll> sum(2, 0ll);
  for (int i = 0; i < N; i++) { sum[i % 2] += A[i]; }
  ll ans = max(sum[0], sum[1]);
  ll s = sum[0];
  for (int i = N - 1; i >= 1; i -= 2) {
    s += A[i];
    s -= A[i - 1];
    chmax(ans, s);
  }
  return ans;
}

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  cin >> A;
  //   function<void(int, ll, bool, vector<int>)> dfs = [&](int i, ll sum, bool
  //   use,
  //                                                        vector<int> vec) {
  //     if (i == N) {
  //       if (vec.size() < N / 2) return;
  //       dmp(sum);
  //       dmp(vec);
  //       return;
  //     }
  //     if (use)
  //       dfs(i + 1, sum, false, vec);
  //     else {
  //       dfs(i + 1, sum, false, vec);
  //       vec.push_back(i);
  //       sum += A[i];
  //       dfs(i + 1, sum, true, vec);
  //     }
  //   };
  //   dfs(0, 0ll, false, vector<int>());
  vector<ll> o(N, 0ll), e(N, 0ll);
  for (int i = 0; i < N; i++) {
    if (i % 2 == 1)
      o[i] = A[i];
    else
      e[i] = A[i];
  }
  RangeSum<ll> odd(o), even(e);
  if (N % 2 == 0) {
    cout << solve_even(A) << endl;
  } else {
    vector<ll> f(N), b(N);
    f[1] = max(A[0], A[1]);
    for (int i = 3; i < N; i += 2) {
      f[i] = f[i - 2] + A[i];
      chmax(f[i], even.sum(0, i));
    }
    b[N - 2] = max(A[N - 1], A[N - 2]);
    for (int i = N - 4; i >= 0; i -= 2) {
      b[i] = b[i + 2] + A[i];
      chmax(b[i], even.sum(i, N - 1));
    }
    ll ans = odd.sum(1, N - 1);
    for (int i = 1; i < N; i += 2) {
      chmax(ans, max(odd.sum(0, i - 1) + even.sum(i + 1, N - 1),
                     even.sum(0, i - 1) + odd.sum(i + 1, N - 1)));
    }
    for (int i = 0; i < N; i += 2) {
      ll res = 0ll;
      if (i > 0) res += f[i - 1];
      if (i + 1 < N) res += b[i + 1];
      chmax(ans, res);
    }
    cout << ans << endl;
  }
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
