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
  int N;
  cin >> N;
  vector<int> used(2 * N + 1, false);
  vector<int> to(2 * N + 1, -2);
  vector<int> from(2 * N + 1, -2);
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (A != -1) {
      if (used[A]) {
        cout << "No" << endl;
        return;
      }
      used[A] = true;
    }
    if (B != -1) {
      if (used[B]) {
        cout << "No" << endl;
        return;
      }
      used[B] = true;
    }
    if (A != -1 && B != -1 && A >= B) {
      cout << "No" << endl;
      return;
    }
    if (A != -1) to[A] = B;
    if (B != -1) from[B] = A;
  }

  // check [l,r]
  auto check = [&](int l, int r) {
    assert((r - l + 1) % 2 == 0);
    int h = (r - l + 1) / 2;
    assert(h > 0);
    for (int i = 0; i < h; i++) {
      // l + i -> l + i + h
      if (to[l + i] >= 0 && to[l + i] != l + i + h) return false;
      if (from[l + h + i] >= 0 && from[l + h + i] != l + i) return false;
      if (from[l + i] != -2) return false;
      if (to[l + h + i] != -2) return false;
      if (used[l + i] && used[l + h + i]) {
        if (to[l + i] != l + i + h) return false;
        if (from[l + h + i] != l + i) return false;
      }
    }
    return true;
  };

  vector<bool> dp(2 * N + 1, false);
  dp[0] = true;
  for (int i = 2; i <= 2 * N; i += 2) {
    for (int j = 2; j <= i; j += 2) {
      if (!dp[i - j]) continue;
      if (check(i - j + 1, i)) {
        dp[i] = true;
        break;
      }
    }
  }
  if (dp[2 * N])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
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
