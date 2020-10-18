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
  int N, L;
  cin >> N >> L;
  vector<int> a(N + 2), b(N + 2);
  a[0] = 0;
  a[N + 1] = L + 1;
  b[0] = 0;
  b[N + 1] = L + 1;
  for (int i = 1; i <= N; i++) { cin >> a[i]; }
  for (int i = 1; i <= N; i++) { cin >> b[i]; }

  for (int i = 0; i < a.size(); i++) {
    a[i] -= i;
    b[i] -= i;
  }
  // dmp(a);
  // dmp(b);

  vector<int> target(N + 2, -1);
  for (int i = 1; i <= N; i++) {
    auto it = lower_bound(all(a), b[i]);
    if (it == a.end() || *it != b[i]) {
      cout << -1 << endl;
      return;
    }
    int l = it - a.begin();
    int r = upper_bound(all(a), b[i]) - a.begin() - 1;
    if (l <= i && i <= r)
      target[i] = i;
    else if (r < i)
      target[i] = r;
    else {
      assert(i < l);
      target[i] = l;
    }
  }

  ll ans = 0ll;

  int mi = INF;
  for (int i = N; i >= 1; i--) {
    if (target[i] >= i) continue;
    if (mi == a[target[i]]) continue;
    ans += i - target[i];
    chmin(mi, a[target[i]]);
  }

  int mx = -INF;
  for (int i = 1; i <= N; i++) {
    if (target[i] <= i) continue;
    if (mx == a[target[i]]) continue;
    ans += target[i] - i;
    chmax(mx, a[target[i]]);
  }

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
