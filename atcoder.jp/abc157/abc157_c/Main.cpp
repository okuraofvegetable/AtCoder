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
  int N;
  int M;
  cin >> N >> M;
  //   string ans(N, '$');
  //   for (int i = 0; i < M; i++) {
  //     int s, c;
  //     cin >> s >> c;
  //     s--;
  //     if (ans[s] != '$' && ans[s] != (char)('0' + c)) {
  //       cout << -1 << endl;
  //       return;
  //     }
  //     ans[s] = (char)('0' + c);
  //   }
  //   if (ans[0] == '$') ans[0] = '1';
  //   for (int i = 1; i < N; i++) {
  //     if (ans[i] == '$') ans[i] = '0';
  //   }
  //   if (N > 1 && ans[0] == '0') {
  //     cout << -1 << endl;
  //     return;
  //   }
  //   cout << ans << endl;
  vector<int> s(M), c(M);
  for (int i = 0; i < M; i++) {
    cin >> s[i] >> c[i];
    s[i]--;
  }
  for (int i = 0; i < 1000; i++) {
    string a = to_string(i);
    if (a.size() != N) continue;
    bool judge = true;
    for (int j = 0; j < M; j++) {
      if (a[s[j]] != (char)('0' + c[j])) {
        judge = false;
        break;
      }
    }
    if (judge) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
