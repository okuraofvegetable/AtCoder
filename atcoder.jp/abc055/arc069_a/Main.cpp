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

ll solve1(vector<ll> &a) {
  ll sum = 0ll;
  ll res = 0ll;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];
    if (i % 2 == 0) {
      if (sum <= 0) {
        res += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum >= 0) {
        res += sum + 1;
        sum = -1;
      }
    }
  }
  return res;
}

ll solve2(vector<ll> &a) {
  ll sum = 0ll;
  ll res = 0ll;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];
    if (i % 2 == 1) {
      if (sum <= 0) {
        res += 1 - sum;
        sum = 1;
      }
    } else {
      if (sum >= 0) {
        res += sum + 1;
        sum = -1;
      }
    }
  }
  return res;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  ll l = 0, r = 10000000000000ll;
  auto check = [&](ll k) {
    if (m < 2 * k) return false;
    ll a = n + (m - 2 * k) / 2;
    return a >= k;
  };
  while (r - l > 1ll) {
    ll mid = (l + r) / 2ll;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
