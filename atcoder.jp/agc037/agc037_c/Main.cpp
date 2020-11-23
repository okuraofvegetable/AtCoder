#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

#ifndef LOCAL
#define dmp(...) ;
#else
#define dmp(...)                                                               \
  cerr << "[ " << #__VA_ARGS__ << " ] : " << dump_str(__VA_ARGS__) << endl
#endif

// ---------------- Utility ------------------

template <class T>
bool chmin(T &a, const T &b) {
  if (a <= b) return false;
  a = b;
  return true;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a >= b) return false;
  a = b;
  return true;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

// ----------------- Input -------------------

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}

template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}

// ----------------- Output ------------------

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ',' << p.second;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const T &e : v) os << e << " ";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const deque<T> &d) {
  for (const T &e : d) os << e << " ";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{ ";
  for (const T &e : s) os << e << " ";
  return os << "}";
}

template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
  os << "{ ";
  for (const auto &[key, val] : m) os << "( " << key << " -> " << val << " ) ";
  return os << "}";
}

void dump_str_rec(ostringstream &) {}

template <class Head, class... Tail>
void dump_str_rec(ostringstream &oss, Head &&head, Tail &&... tail) {
  oss << ", " << head;
  dump_str_rec(oss, forward<Tail>(tail)...);
}

template <class T, class... U>
string dump_str(T &&arg, U &&... args) {
  ostringstream oss;
  oss << arg;
  dump_str_rec(oss, forward<U>(args)...);
  return oss.str();
}

// --------------- Fast I/O ------------------

void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

// ------------ End of template --------------

#define endl "\n"
using P = pair<int, ll>;

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  cin >> A;
  cin >> B;

  queue<int> q;

  auto checkAndPush = [&](int x) {
    if (B[x] == A[x]) return;
    int p = (x + N - 1) % N;
    int n = (x + 1) % N;
    if (B[p] <= B[x] && B[x] >= B[n]) q.push(x);
    return;
  };

  for (int i = 0; i < N; i++) checkAndPush(i);

  ll ans = 0ll;

  while (!q.empty()) {
    int x = q.front();
    int p = (x + N - 1) % N;
    int n = (x + 1) % N;
    q.pop();
    ll l = 0ll, r = 1000000000ll;
    while (r - l > 1ll) {
      ll mid = (l + r) / 2ll;
      ll res = B[x] - (B[p] + B[n]) * mid;
      if (res >= max(max(B[p], B[n]), A[x] + 1))
        l = mid;
      else
        r = mid;
    }
    ll ret = B[x] - (B[p] + B[n]) * r;
    if (ret < A[x]) {
      cout << -1 << endl;
      return;
    }
    dmp(B);
    dmp(x, r, ret);
    ans += r;
    if (ret >= max(B[p], B[n]) && ret != A[x]) {
      cout << -1 << endl;
      return;
    }
    B[x] = ret;
    checkAndPush(p);
    checkAndPush(n);
  }

  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      cout << -1 << endl;
      return;
    }
  }

  cout << ans << endl;

  return;
}

int main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
