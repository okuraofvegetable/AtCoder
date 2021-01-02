#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define drep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)

#define popcount __builtin_popcount
#define next __next
#define prev __prev

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

template <class T>
struct BIT {
  int N;
  vector<T> bit;
  BIT(int N) : N(N) { bit = vector<T>(N + 1, T(0)); }
  void add(int i, T x) {
    i++;
    while (i <= N) {
      bit[i] += x;
      i += i & -i;
    }
    return;
  }
  T sum(int i) {
    i++;
    T res = T(0);
    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }
  T sum(int l, int r) { // [l,r]
    if (l > r) return 0;
    assert(l <= r);
    if (l == 0)
      return sum(r);
    else
      return sum(r) - sum(l - 1);
  }
};

void solve() {
  int N;
  cin >> N;
  vector<int> a(N);
  cin >> a;

  // b[0, k)
  vector<ll> b(N + 1, 0);
  // c[k, N)
  vector<ll> c(N, 0);

  {
    BIT<ll> bit(N);
    for (int i = 0; i < N; i++) {
      b[i + 1] += b[i];
      b[i + 1] += bit.sum(a[i], N - 1);
      bit.add(a[i], 1);
    }
    dmp(b);
  }

  {
    BIT<ll> bit(N);
    for (int i = N - 1; i >= 0; i--) {
      if (i < N - 1) c[i] += c[i + 1];
      c[i] += bit.sum(0, a[i]);
      bit.add(a[i], 1);
    }
    dmp(c);
  }

  vector<ll> ans(N);
  ans[0] = c.front();
  for (int i = 1; i < N; i++) {
    int rightmost = i - 1;
    ans[i] = ans[i - 1];
    dmp(a[rightmost]);
    ans[i] += (ll)(N - 1 - a[rightmost]);
    ans[i] -= (ll)a[rightmost];
  }
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
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