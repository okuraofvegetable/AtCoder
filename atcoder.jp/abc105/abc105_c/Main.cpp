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
  ll N;
  cin >> N;
  vector<ll> l(40), r(40);
  l[0] = 0, r[0] = 1;
  for (int i = 1; i < 40; i++) {
    if (i % 2 == 0) {
      l[i] = l[i - 1];
      r[i] = r[i - 1] + (1ll << i);
    } else {
      l[i] = l[i - 1] - (1ll << i);
      r[i] = r[i - 1];
    }
  }
  int idx = 0;
  while (N < l[idx] || r[idx] < N) idx++;
  ll rem = N;
  for (int i = idx; i >= 0; i--) {
    ll sgn = (i % 2 == 0) ? 1ll : -1ll;
    if (i == 0) {
      assert(rem == 0 || rem == 1);
      cout << rem;
    } else {
      if (l[i - 1] <= rem && rem <= r[i - 1])
        cout << 0;
      else {
        cout << 1;
        rem -= sgn * (1ll << i);
      }
    }
  }
  cout << endl;

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
