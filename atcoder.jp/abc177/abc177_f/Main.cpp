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
  int H, W;
  cin >> H >> W;
  vector<int> A(H), B(H);
  for (int i = 0; i < H; i++) { cin >> A[i] >> B[i]; }
  set<P> s;
  multiset<int> ms;
  for (int i = 1; i <= W; i++) {
    s.insert(P(i, i));
    ms.insert(0);
  }
  auto erase_one = [&](int v) {
    auto it = ms.find(v);
    assert(it != ms.end());
    ms.erase(it);
    return;
  };
  for (int i = 0; i < H; i++) {
    auto it = s.lower_bound(P(A[i], -1));
    int mx = -1;
    while (it != s.end() && it->first <= B[i]) {
      erase_one(it->first - it->second);
      chmax(mx, it->second);
      it = s.erase(it);
    }
    if (mx >= 0) {
      s.insert(P(B[i] + 1, mx));
      if (B[i] + 1 <= W) ms.insert(B[i] + 1 - mx);
    }
    // for (auto x : s) cout << x << " ,";
    // cout << endl;
    // for (auto x : ms) cout << x << " ,";
    // cout << endl;
    if (ms.empty() || *ms.begin() > W)
      cout << -1 << endl;
    else {
      int ans = i + 1 + *ms.begin();
      cout << ans << endl;
    }
  }
  return;
}

signed main() {
  fastio();
  solve();
  // int t;
  // cin >> t;
  // while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
