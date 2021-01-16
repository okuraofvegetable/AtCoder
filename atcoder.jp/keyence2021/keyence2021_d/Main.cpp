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

void test() {
  constexpr int N = 4;
  constexpr int M = (1 << N);
  vector<int> vec;
  for (int i = 0; i < M; i++) {
    if (popcount(i) != 4) continue;
    vec.push_back(i);
  }
  int A = (1 << M);
  auto check = [&](int S) {
    auto cnt_same = vect(N, vect(N, 0));
    auto cnt_diff = vect(N, vect(N, 0));
    for (int i = 0; i < M; i++) {
      if ((S >> i) & 1) {
        if (popcount(i) != N / 2) return false;
        for (int j = 0; j < N; j++) {
          for (int k = j + 1; k < N; k++) {
            int a = ((i >> j) & 1);
            int b = ((i >> k) & 1);
            if (a == b)
              cnt_same[j][k]++;
            else
              cnt_diff[j][k]++;
          }
        }
      }
    }
    int X = cnt_same[0][1];
    int Y = cnt_diff[0][1];
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (cnt_same[i][j] != X) return false;
        if (cnt_diff[i][j] != Y) return false;
      }
    }
    return true;
  };

  int ans = INF, ans_v = -1;
  for (int i = 1; i < A; i++) {
    if (check(i)) {
      cerr << popcount(i) << ' ' << i << endl;
      if (chmin(ans, popcount(i))) ans_v = i;
    }
  }
  dmp(ans, ans_v);
  return;
}

vector<string> solve_rec(int n) {
  vector<string> ret;
  if (n == 1) {
    ret.push_back("AB");
    return ret;
  }

  string t;
  for (int i = 0; i < (1 << (n - 1)); i++) t += 'A';
  for (int i = 0; i < (1 << (n - 1)); i++) t += 'B';
  ret.push_back(t);

  auto b = solve_rec(n - 1);
  auto revb = b;
  for (auto &s : revb) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A')
        s[i] = 'B';
      else
        s[i] = 'A';
    }
  }
  for (int i = 0; i < b.size(); i++) { ret.push_back(b[i] + b[i]); }
  for (int i = 0; i < b.size(); i++) { ret.push_back(b[i] + revb[i]); }
  return ret;
}

void solve() {
  // test();
  int N;
  cin >> N;
  auto ans = solve_rec(N);
  cout << ans.size() << endl;
  for (const auto &s : ans) cout << s << endl;
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
