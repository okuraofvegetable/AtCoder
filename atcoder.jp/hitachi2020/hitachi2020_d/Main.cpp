#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
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
  ll T;
  cin >> N >> T;
  vector<ll> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    b[i] += a[i] + 1;
    a[i] += 1;
  }
  vector<P> ls;
  vector<ll> add;
  for (int i = 0; i < N; i++) {
    if (a[i] == 1)
      add.push_back(b[i]);
    else
      ls.emplace_back(a[i], b[i]);
  }
  sort(all(add));
  for (int i = 1; i < add.size(); i++) add[i] += add[i - 1];
  sort(all(ls), [](const P &a, const P &b) {
    return (1 - a.first) * b.second < (1 - b.first) * a.second;
  });
  dmp(add);
  dmp(ls);
  int M = ls.size();
  vector<vector<ll>> dp = vect(M + 1, vect(40, LLINF));
  dp[0][0] = 0ll;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 40; j++) {
      if (dp[i][j] == LLINF) continue;
      chmin(dp[i + 1][j], dp[i][j]);
      if (dp[i][j] < T / ls[i].first + 5)
        chmin(dp[i + 1][j + 1], ls[i].first * dp[i][j] + ls[i].second);
    }
  }
  int ans = 0;
  for (int i = 0; i < 40; i++) {
    if (dp[M][i] > T) continue;
    chmax(ans, i + (int)(upper_bound(all(add), T - dp[M][i]) - add.begin()));
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
