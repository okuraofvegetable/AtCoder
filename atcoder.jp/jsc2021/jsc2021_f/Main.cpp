#include <bits/stdc++.h>

using namespace std;

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

// ------------------ ACL --------------------

// #include <atcoder/modint>
// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// using mint = atcoder::static_modint<MOD>;
// ostream &operator<<(ostream &os, const mint &v) {
//   return os << v.val();
// }

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

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
    // assert(l <= r);
    if (l > r) return T(0);
    if (l == 0)
      return sum(r);
    else
      return sum(r) - sum(l - 1);
  }
  T sum_right(int l) { return sum(l, bit.size() - 2); }
};

void solve() {
  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> A(N, 0), B(M, 0);
  vector<int> T(Q), X(Q), Y(Q);
  vector<int> zip;
  zip.push_back(0);

  for (int i = 0; i < Q; i++) {
    cin >> T[i] >> X[i] >> Y[i];
    X[i]--;
    zip.push_back(Y[i]);
  }

  sort(all(zip));
  zip.erase(unique(all(zip)), zip.end());

  // dmp(zip);

  for (int i = 0; i < Q; i++) {
    Y[i] = lower_bound(all(zip), Y[i]) - zip.begin();
  }

  int MX = zip.size() + 5;

  BIT<ll> Acnt(MX), Asum(MX), Bcnt(MX), Bsum(MX);
  Acnt.add(0, N);
  Bcnt.add(0, M);

  ll ans = 0ll;

  for (int i = 0; i < Q; i++) {
    if (T[i] == 1) {
      int x = X[i], y = Y[i];
      ans -= Bsum.sum_right(A[x] + 1);
      ans -= Bcnt.sum(0, A[x]) * zip[A[x]];
      Asum.add(A[x], -zip[A[x]]);
      Acnt.add(A[x], -1);

      ans += Bsum.sum_right(y + 1);
      ans += Bcnt.sum(0, y) * zip[y];
      Asum.add(y, zip[y]);
      Acnt.add(y, 1);
      A[x] = y;
    }
    if (T[i] == 2) {
      int x = X[i], y = Y[i];
      ans -= Asum.sum_right(B[x]);
      ans -= Acnt.sum(0, B[x] - 1) * zip[B[x]];
      Bsum.add(B[x], -zip[B[x]]);
      Bcnt.add(B[x], -1);

      ans += Asum.sum_right(y);
      ans += Acnt.sum(0, y - 1) * zip[y];
      Bsum.add(y, zip[y]);
      Bcnt.add(y, 1);
      B[x] = y;
    }

    cout << ans << endl;
  }

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
