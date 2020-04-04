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
vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

ll mypow(ll a, ll x) {
  ll ret = 1ll;
  while (x) {
    if (x & 1) ret *= a;
    a *= a;
    x >>= 1;
  }
  return ret;
}

vector<ll> roots(ll x) {
  vector<ll> res({x});
  for (int i = 2; i < 43; i++) {
    double X = x;
    double cand = pow(x, 1.0 / i);
    ll cand_ll = (ll)cand;
    for (ll c = max(2ll, cand_ll - 2); c <= cand_ll + 2; c++) {
      if (mypow(c, i) == x) {
        res.push_back(c);
        break;
      }
    }
  }
  return res;
}

void solve() {
  ll N;
  cin >> N;
  vector<ll> ps = divisor(N);
  vector<ll> qs = divisor(N - 1ll);
  //   dmp(ps);
  //   dmp(qs);
  set<ll> s;
  for (ll div : ps) {
    if (div == 1ll) continue;
    vector<ll> rs = roots(div);
    for (ll r : rs) {
      ll tmp = N;
      while (tmp % r == 0ll) tmp /= r;
      if (tmp % r == 1ll) s.insert(r);
    }
  }
  // for (int val : s) { cout << val << endl; }
  cout << s.size() + qs.size() - 1 << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
