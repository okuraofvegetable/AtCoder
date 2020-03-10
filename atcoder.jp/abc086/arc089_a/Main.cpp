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
  int N;
  cin >> N;
  vector<int> t, x, y;
  t.push_back(0);
  x.push_back(0);
  y.push_back(0);
  for (int i = 0; i < N; i++) {
    int tt, xx, yy;
    cin >> tt >> xx >> yy;
    t.push_back(tt);
    x.push_back(xx);
    y.push_back(yy);
  }
  for (int i = 1; i <= N; i++) {
    int dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    int tdist = t[i] - t[i - 1];
    if (tdist < dist || tdist % 2 != dist % 2) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
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
