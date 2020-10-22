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
  int N, Q;
  cin >> N >> Q;
  vector<int> c(N);
  vector<vector<int>> idx(N + 1);
  atcoder::fenwick_tree<int> bit(N + 1);

  for (int i = 0; i < N; i++) {
    cin >> c[i];
    idx[c[i]].push_back(i);
  }

  vector<Query> qs;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    qs.emplace_back(l, r, i);
  }
  sort(all(qs));

  vector<int> ans(Q);

  for (int i = 0; i < qs.size(); i++) {
    if (i == 0 || qs[i].l < qs[i - 1].l) {
      int nl = (i == 0) ? N : qs[i - 1].l;
      for (int j = nl - 1; j >= qs[i].l; j--) {
        auto next = upper_bound(all(idx[c[j]]), j);
        if (next != idx[c[j]].end()) bit.add(*next, -1);
        bit.add(j, 1);
      }
    }
    ans[qs[i].id] = bit.sum(qs[i].l, qs[i].r);
  }

  for (int i = 0; i < Q; i++) cout << ans[i] << endl;

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
