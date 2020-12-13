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

void test() {
  const int BIT = 3;
  vector<int> a;
  const int N = (1 << BIT);
  for (int i = 0; i < N; i++) { a.push_back(i); }
  auto ans = vect(N, vect(N, false));

  vector<bool> used(N, false);
  vector<int> seq;

  function<void(int)> dfs = [&](int n) -> void {
    // dmp(n, seq);
    if (n == N) {
      ans[seq.front()][seq.back()] = ans[seq.front()][seq.back()] = true;
      return;
    }
    for (int i = 0; i < N; i++) {
      if (used[i]) continue;
      if (!seq.empty() && __builtin_popcount(seq.back() ^ i) != 1) continue;
      seq.push_back(i);
      used[i] = true;
      dfs(n + 1);
      seq.pop_back();
      used[i] = false;
    }
  };

  dfs(0);

  for (auto &row : ans) dmp(row);
  return;
}

vector<int> f(int bit, int a, int b) {
  assert(a < (1 << bit));
  assert(b < (1 << bit));
  if (bit == 2) {
    deque<int> res = {1, 0, 2, 3};
    while (max(res.front(), res.back()) != max(a, b) ||
           min(res.front(), res.back()) != min(a, b)) {
      int last = res.back();
      res.pop_back();
      res.push_front(last);
    }
    if (res.front() != a) reverse(all(res));
    vector<int> ret;
    for (int i = 0; i < res.size(); i++) ret.push_back(res[i]);
    return ret;
  }

  int A = (a >> (bit - 1)) & 1;
  int B = (b >> (bit - 1)) & 1;
  int mask = (1 << (bit - 1)) - 1;
  if (A == B) {
    auto v = f(bit - 1, (a & mask), (b & mask));
    vector<int> ret;
    for (int i = 0; i < v.size(); i++) {
      ret.push_back(v[i]);
      ret.push_back(v[i]);
    }
    for (int i = 0; i < ret.size(); i++) {
      if (i % 4 == 0 || i % 4 == 3)
        ret[i] ^= (A << (bit - 1));
      else
        ret[i] ^= ((1 - A) << (bit - 1));
    }
    return ret;
  } else {
    int l = a & mask;
    int r = b & mask;
    int mid = l ^ 1;
    auto L = f(bit - 1, l, mid);
    auto R = f(bit - 1, mid, r);
    for (int i = 0; i < L.size(); i++) {
      L[i] ^= (A << (bit - 1));
      R[i] ^= (B << (bit - 1));
    }
    vector<int> ret;
    for (int i = 0; i < L.size(); i++) ret.push_back(L[i]);
    for (int i = 0; i < R.size(); i++) ret.push_back(R[i]);
    return ret;
  }
}

void solve() {
  // test();
  int N, A, B;
  cin >> N >> A >> B;
  if (N == 1) {
    cout << "YES" << endl;
    cout << A << ' ' << B << endl;
    return;
  }
  if (__builtin_popcount(A) % 2 == __builtin_popcount(B) % 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  cout << f(N, A, B) << endl;
  return;
}

int main() {
  fastio();
  // init(5000100);
  solve();
  // int t; cin >> t; while(t--)solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
