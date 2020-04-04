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

vector<pair<ll, int>> factorize(ll x) {
  ll tmp = x;
  vector<pair<ll, int>> ret;
  for (ll i = 2ll; i * i <= x; i++) {
    int cnt = 0;
    while (tmp % i == 0ll) {
      tmp /= i;
      cnt++;
    }
    if (cnt > 0) ret.push_back(pair<ll, int>(i, cnt));
  }
  if (tmp != 1ll) ret.push_back(pair<ll, int>(tmp, 1));
  return ret;
}

void solve() {
  int N;
  cin >> N;
  map<ll, int> m;
  for (int i = 2; i <= N; i++) {
    auto f = factorize(i);
    for (auto p : f) {
      if (m.find(p.first) == m.end()) m[p.first] = 0;
      m[p.first] += p.second;
    }
  }
  ll ans = 1ll;
  for (auto p : m) { ans = ans * (1 + p.second) % 1000000007; }
  cout << ans << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
