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

vector<int> fac;

int nCr(int n, int r) {
  return ((fac[n] - fac[r] - fac[n - r]) > 0) ? 0 : 1;
}

int f(vector<int> a) {
  for (int i = 0; i < a.size(); i++) a[i] %= 2;
  int m = a.size() - 1;
  int res = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 1) { res += nCr(m, i); }
  }
  return res % 2;
}

void solve() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  vector<int> a;
  for (int i = 0; i < N - 1; i++) {
    a.push_back(abs((int)s[i + 1] - (int)s[i]));
  }
  if (N == 2) {
    cout << a[0] << endl;
    return;
  }
  // judge 1
  int res = f(a);
  if (res == 1) {
    cout << 1 << endl;
    return;
  }
  // judge not 2
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 1) {
      cout << 0 << endl;
      return;
    }
  }
  // judge 0 or 2
  for (int i = 0; i < a.size(); i++) { a[i] /= 2; }
  int ret = f(a);
  if (ret == 1) {
    cout << 2 << endl;
  } else {
    cout << 0 << endl;
  }
  return;
}

signed main() {
  fastio();
  fac.resize(1000001);
  fac[0] = 0;
  fac[1] = 0;
  for (int i = 2; i <= 1000000; i++) { fac[i] = __builtin_ctz(i & -i); }
  for (int i = 2; i <= 1000000; i++) fac[i] += fac[i - 1];
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
