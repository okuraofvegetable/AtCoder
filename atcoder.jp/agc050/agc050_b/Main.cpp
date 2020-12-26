#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

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

template <class TupleTy, size_t... I>
void dump_tuple(ostream &os, const TupleTy t, std::index_sequence<I...>) {
  (..., (os << (I == 0 ? "" : ",") << std::get<I>(t)));
}

template <class... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
  os << "(";
  dump_tuple(os, t, std::make_index_sequence<sizeof...(Args)>());
  return os << ")";
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

int naive(int N, vector<int> a) {
  set<int> s;
  queue<int> q;
  q.push(0);
  s.insert(0);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int i = 0; i + 3 <= N; i++) {
      int mask = 0;
      for (int j = i; j < i + 3; j++) mask |= (1 << j);
      int pcnt = __builtin_popcount(a & mask);
      if (pcnt == 3 || pcnt == 0) {
        int b = a ^ mask;
        if (s.find(b) == s.end()) {
          s.insert(b);
          q.push(b);
        }
      }
    }
  }
  int ans = 0;
  for (int x : s) {
    int s = 0;
    for (int i = 0; i < N; i++) {
      if ((x >> i) & 1) s += a[i];
    }
    if (s == 389) cout << bitset<25>(x) << endl;
    chmax(ans, s);
  }
  dmp(ans);
  return ans;
}

void solve() {

  // int N = 25;
  // vector<int> a(N);
  // vector<int> a = {12,  -46, -83, -94, 69, -41, 57, -30, 71,  9,   -79, 48,
  // -95, -19, -50, -64, -22, 25, 93, 44, -35, -71, -88, 21, -56};
  // int N = 25;
  // vector<int> a = {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
  // 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1
  // };
  // assert(a.size() == 25);
  // dmp(a);
  int N;
  cin >> N;
  vector<int> a(N);
  cin >> a;

  // srand((unsigned int)time(NULL));
  // for (int i = 0; i < N; i++) a[i] = (rand() % 200) - 100;
  // naive(N, a);

  auto dp = vect(N, vect(N, -INF));
  function<int(int, int)> rec = [&](int l, int r) {
    if (r - l < 2) return 0;
    if (dp[l][r] != -INF) return dp[l][r];

    int res = -INF;

    chmax(res, rec(l + 1, r));
    chmax(res, rec(l, r - 1));

    for (int i = l + 1; i <= r; i++) { chmax(res, rec(l, i - 1) + rec(i, r)); }

    for (int i = 0;; i++) {
      int m = l + 3 * i + 1;
      if (m + 1 > r) break;
      chmax(res, a[l] + a[m] + a[m + 1] + rec(l + 1, m - 1) + rec(m + 2, r));
    }

    if ((r - l + 1) % 3 == 0) {
      for (int i = 0;; i++) {
        int m = l + 3 * i + 1;
        if (m >= r) break;
        chmax(res, a[l] + a[m] + a[r] + rec(l + 1, m - 1) + rec(m + 1, r - 1));
      }
    }

    for (int i = 0;; i++) {
      int m = l + 1 + 3 * i + 1;
      if (m > r) break;
      chmax(res, a[l] + a[l + 1] + a[m] + rec(l + 2, m - 1) + rec(m + 1, r));
    }
    return dp[l][r] = res;
  };
  cout << rec(0, N - 1) << endl;
  // for (int i = 0; i < N; i++) {
  //   cout << i << ": ";
  //   for (int j = 0; j < N; j++) { cout << rec(i, j) << ' '; }
  //   cout << endl;
  // }
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
