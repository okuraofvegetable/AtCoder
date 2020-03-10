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

void solve() {
  int N, Y;
  cin >> N >> Y;
  Y /= 1000;
  vector<vector<bool>> dp = vect(N + 1, vect(Y + 1, false));
  vector<vector<int>> prev = vect(N + 1, vect(Y + 1, INF));
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < Y; j++) {
      if (!dp[i][j]) continue;
      dp[i + 1][j + 1] = true;
      prev[i + 1][j + 1] = j;
      if (j + 5 <= Y) {
        dp[i + 1][j + 5] = true;
        prev[i + 1][j + 5] = j;
      }
      if (j + 10 <= Y) {
        dp[i + 1][j + 10] = true;
        prev[i + 1][j + 10] = j;
      }
    }
  }
  if (!dp[N][Y]) {
    cout << "-1 -1 -1" << endl;
    return;
  }
  int now = Y;
  vector<int> ans(20, 0);
  for (int i = 0; i < N; i++) {
    int nxt = prev[N - i][now];
    ans[now - nxt]++;
    now = nxt;
  }
  cout << ans[10] << ' ' << ans[5] << ' ' << ans[1] << endl;
  return;
}

signed main() {
  fastio();
  solve();
  //   int t;
  //   cin >> t;
  //   while (t--) solve();
  return 0;
}
