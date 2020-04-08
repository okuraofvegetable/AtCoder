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

struct UnionFind {
  vector<int> par, rank, sz;
  UnionFind(int n) {
    par.assign(n, 0);
    rank.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) { par[i] = i; }
  }
  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
      sz[y] += sz[x];
    } else {
      par[y] = x;
      sz[x] += sz[y];
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
};

#define endl "\n"

void solve() {
  int N, K, L;
  cin >> N >> K >> L;
  UnionFind uf1(N), uf2(N);
  for (int i = 0; i < K; i++) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    uf1.unite(p, q);
  }
  for (int i = 0; i < L; i++) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    uf2.unite(p, q);
  }
  map<P, int> m;
  for (int i = 0; i < N; i++) {
    int a = uf1.find(i);
    int b = uf2.find(i);
    m[P(a, b)]++;
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    int a = uf1.find(i);
    int b = uf2.find(i);
    ans[i] = m[P(a, b)];
  }
  cout << ans << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
