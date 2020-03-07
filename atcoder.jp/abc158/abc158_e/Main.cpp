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

void solve() {
  int N, P;
  cin >> N >> P;
  string s;
  cin >> s;
  vector<ll> dp(P, 0ll);
  vector<int> ten(N);
  ten[0] = 1;
  for (int i = 1; i < N; i++) ten[i] = (ten[i - 1] * 10) % P;
  int start = 0;
  ll ans = 0ll;
  if (P == 2) {
    for (int i = 0; i < s.size(); i++) {
      int d = (int)(s[i] - '0');
      if (d % 2 == 0) ans += i + 1;
    }
    cout << ans << endl;
    return;
  }
  if (P == 5) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0' || s[i] == '5') ans += i + 1;
    }
    cout << ans << endl;
    return;
  }
  reverse(all(s));
  for (int i = 0; i < s.size(); i++) {
    int digit = (int)(s[i] - '0');
    int d = (digit * ten[i]) % P;
    start = ((start - d) % P + P) % P;
    dp[(start + d) % P]++;
    ans += dp[start];
    // dmp(dp);
    // dmp(start);
    // dmp(ans);
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
