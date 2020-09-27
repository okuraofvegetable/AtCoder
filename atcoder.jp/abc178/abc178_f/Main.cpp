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
  vector<int> A(N), B(N);
  cin >> A;
  cin >> B;
  vector<int> cnt(200100);
  vector<int> cntA(200100);
  vector<int> cntB(200100);
  vector<vector<int>> idxA(200100);
  set<P> sA, sB;
  for (int i = 0; i < N; i++) {
    cnt[A[i]]++;
    cnt[B[i]]++;
    cntA[A[i]]++;
    cntB[B[i]]++;
    idxA[A[i]].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    sA.insert(P(cnt[A[i]], A[i]));
    sB.insert(P(cnt[B[i]], B[i]));
    if (cnt[A[i]] > N || cnt[B[i]] > N) {
      cout << "No" << endl;
      return;
    }
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    P cA = *sA.rbegin();
    sA.erase((++sA.rbegin()).base());
    {
      auto it = sB.find(cA);
      if (it != sB.end()) {
        sB.erase(it);
        sB.insert(P(cA.first - 1, cA.second));
      }
    }
    cA.first--;
    cntA[cA.second]--;
    if (cntA[cA.second] > 0) sA.insert(cA);

    auto it = sB.rbegin();
    if (it->second == cA.second) it++;
    P cB = *it;
    sB.erase((++it).base());
    {
      auto it = sA.find(cB);
      if (it != sA.end()) {
        sA.erase(it);
        sA.insert(P(cB.first - 1, cB.second));
      }
    }
    cB.first--;
    cntB[cB.second]--;
    if (cntB[cB.second] > 0) sB.insert(cB);

    ans[idxA[cA.second][cntA[cA.second]]] = cB.second;
  }
  cout << "Yes" << endl;
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
