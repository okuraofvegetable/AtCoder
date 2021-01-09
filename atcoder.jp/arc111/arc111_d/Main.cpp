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

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  vector<int> dir(M, -1);
  vector<vector<int>> es(N);
  rep(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    es[a[i]].push_back(i);
    es[b[i]].push_back(i);
  }
  vector<int> c(N);
  cin >> c;

  vector<int> t(N);
  rep(i, N) t[i] = i;

  auto comp = [&](int x, int y) { return c[x] < c[y]; };
  sort(all(t), comp);

  vector<bool> marked(N, false);
  for (int i = 0; i + 1 < N; i++) {
    marked[t[i]] = true;
    for (int j = 0; j < M; j++) {
      if (dir[j] != -1) continue;
      if (c[a[j]] == c[b[j]]) continue;
      if (marked[a[j]] == marked[b[j]]) continue;
      if (marked[a[j]]) {
        dir[j] = 0; // <-
      } else {
        dir[j] = 1; // ->
      }
    }
  }

  for (int i = 0; i < N; i++) {
    vector<bool> used(N, false);
    function<void(int)> dfs = [&](int v) {
      used[v] = true;
      for (int j : es[v]) {
        if (dir[j] != -1) continue;
        if (a[j] == v) {
          dir[j] = 0;
          if (!used[b[j]]) dfs(b[j]);
        } else if (b[j] == v) {
          dir[j] = 1;
          if (!used[a[j]]) dfs(a[j]);
        }
      }
    };
    dfs(i);
  }

  for (int i = 0; i < M; i++) {
    // assert(dir[i] != -1);
    if (dir[i] == -1) dir[i] = 0;
    if (dir[i] == 0)
      cout << "<-" << endl;
    else
      cout << "->" << endl;
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
