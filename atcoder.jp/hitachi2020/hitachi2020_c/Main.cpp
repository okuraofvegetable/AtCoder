#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
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
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> ans(N);
  vector<int> vs, us;
  function<void(int, int, int)> dfs = [&](int v, int p, int d) {
    if (d % 2 == 0) {
      vs.push_back(v);
    } else {
      us.push_back(v);
    }
    for (auto u : G[v]) {
      if (u == p) continue;
      dfs(u, v, d + 1);
    }
    return;
  };
  dfs(0, -1, 0);
  vector<int> num[3];
  for (int i = 1; i <= N; i++) { num[i % 3].push_back(i); }
  if (us.size() <= N / 3) {  // zenbu mod 0
    for (int i = 0; i < us.size(); i++) ans[us[i]] = num[0][i];
    vector<int> rem;
    for (int i = us.size(); i < num[0].size(); i++) rem.push_back(num[0][i]);
    for (int i = 0; i < num[1].size(); i++) rem.push_back(num[1][i]);
    for (int i = 0; i < num[2].size(); i++) rem.push_back(num[2][i]);
    assert(vs.size() == rem.size());
    for (int i = 0; i < vs.size(); i++) ans[vs[i]] = rem[i];
  } else if (vs.size() <= N / 3) {
    for (int i = 0; i < vs.size(); i++) ans[vs[i]] = num[0][i];
    vector<int> rem;
    for (int i = vs.size(); i < num[0].size(); i++) rem.push_back(num[0][i]);
    for (int i = 0; i < num[1].size(); i++) rem.push_back(num[1][i]);
    for (int i = 0; i < num[2].size(); i++) rem.push_back(num[2][i]);
    assert(us.size() == rem.size());
    for (int i = 0; i < us.size(); i++) ans[us[i]] = rem[i];
  } else {
    for (int i = 0; i < num[1].size(); i++) ans[vs[i]] = num[1][i];
    for (int i = 0; i < num[2].size(); i++) ans[us[i]] = num[2][i];
    int idx = 0;
    for (int i = num[1].size(); i < vs.size(); i++) ans[vs[i]] = num[0][idx++];
    for (int i = num[2].size(); i < us.size(); i++) ans[us[i]] = num[0][idx++];
    assert(idx == num[0].size());
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
