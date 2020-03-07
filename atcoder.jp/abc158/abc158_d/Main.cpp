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
  string s;
  cin >> s;
  int q;
  cin >> q;
  int rev = 0;
  deque<char> deq;
  for (int i = 0; i < s.size(); i++) deq.push_back(s[i]);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      rev ^= 1;
    } else {
      int f;
      char c;
      cin >> f >> c;
      f--;
      if ((rev ^ f) == 0)
        deq.push_front(c);
      else
        deq.push_back(c);
    }
  }
  if (rev) reverse(all(deq));
  for (int i = 0; i < deq.size(); i++) cout << deq[i];
  cout << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
