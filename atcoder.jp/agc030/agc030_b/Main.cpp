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

ll sub(int L, int N, vector<ll> &X) {
  ll ret = 0ll;
  ll base = 0ll;
  auto dist = [&](int a, int b, int dir) {
    if (dir == 1) swap(a, b);
    if (a <= b)
      return X[b] - X[a];
    else
      return L - X[a] + X[b];
  };

  dmp(X);

  {
    // calculate base
    int cur = 0, l = 1, r = N - 1;
    for (int i = 0; i < N - 1; i++) {
      if (i % 2 == 1) {
        base += dist(cur, l, 0);
        cur = l;
        l++;
      } else {
        base += dist(cur, r, 1);
        cur = r;
        r--;
      }
      dmp(cur, base);
    }
    assert(r + 1 == l);
    dmp(base);
    chmax(ret, X[0] + base);
  }

  for (int i = 0; i + 1 < N; i++) {
    int border = (i + (N - i) / 2) % N;
    if ((N - i) % 2 == 0) {
      base += dist(i + 1, border, 0);
      base -= dist(border, i, 0);
    } else {
      base += dist(i + 1, border, 0);
      base -= dist(border + 1, i, 0);
    }
    chmax(ret, X[i + 1] + base);
    dmp(border, base);
  }
  return ret;
}

void solve() {
  int L, N;
  cin >> L >> N;
  vector<ll> X(N);
  cin >> X;

  if (N == 1) {
    cout << max(X[0], L - X[0]) << endl;
    return;
  }

  ll ans = 0ll;
  chmax(ans, sub(L, N, X));

  for (ll &x : X) x = L - x;
  sort(all(X));
  chmax(ans, sub(L, N, X));

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
