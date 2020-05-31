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
  using P = pair<ll, ll>;
  vector<P> A(N);
  cin >> A;
  for (int i = 0; i < N; i++) {
    A[i].first *= 2;
    A[i].second *= 2;
  }
  auto check = [&](ll x) {
    ll mx = 0, cnt = 0, mi = LLINF;
    for (int i = 0; i < N; i++) {
      if (A[i].second < x) {
        chmax(mx, A[i].second);
        cnt++;
      } else {
        chmin(mi, A[i].second);
      }
    }
    if (N % 2 == 1) {
      if (cnt > N / 2)
        return false;
      else
        return true;
    } else {
      if (cnt == N / 2) {
        return (mx + mi) >= 2 * x;
      } else
        return cnt < N / 2;
    }
  };
  // x ika ni naru?
  auto check2 = [&](ll x) {
    ll mx = 0, cnt = 0, mi = LLINF;
    for (int i = 0; i < N; i++) {
      if (A[i].first > x) {
        chmin(mi, A[i].first);
        cnt++;
      } else {
        chmax(mx, A[i].first);
      }
    }
    if (N % 2 == 1) {
      if (cnt > N / 2)
        return false;
      else
        return true;
    } else {
      if (cnt == N / 2) {
        return (mx + mi) <= 2 * x;
      } else
        return cnt < N / 2;
    }
  };
  ll low, high;
  {
    ll l = 0, r = LLINF;
    while (r - l > 1ll) {
      ll mid = (l + r) / 2ll;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    // cout << l << endl;
    high = l;
  }
  {
    ll l = 0, r = LLINF;
    while (r - l > 1ll) {
      ll mid = (l + r) / 2ll;
      if (check2(mid))
        r = mid;
      else
        l = mid;
    }
    // cout << r << endl;
    low = r;
  }
  if (N % 2 == 1) {
    cout << (high - low) / 2 + 1 << endl;
  } else
    cout << high - low + 1 << endl;
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
