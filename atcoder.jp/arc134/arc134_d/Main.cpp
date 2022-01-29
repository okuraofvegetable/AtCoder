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

const bool multitest = false;

void solve() {
  int N;
  cin >> N;
  vector<int> a(2 * N);
  cin >> a;
  vector<int> mi(N);
  for (int i = 0; i < N; i++) { mi[i] = a[i]; }
  for (int i = N - 2; i >= 0; i--) chmin(mi[i], mi[i + 1]);
  vector<int> ids;
  for (int i = 0; i < N; i++) {
    if (mi[i] == a[i]) {
      ids.push_back(i);
      dmp(i, a[i]);
    }
  }
  vector<vector<int>> gs;
  for (int i = 0; i < ids.size(); i++) {
    if (gs.empty() || a[gs.back().back()] != a[ids[i]]) {
      gs.push_back(vector<int>());
      gs.back().push_back(ids[i]);
    } else {
      gs.back().push_back(ids[i]);
    }
  }
  dmp(gs);

  vector<int> cand1;
  {
    int mi = INF;
    for (int i = 0; i < gs.front().size(); i++) {
      chmin(mi, a[gs.front()[i] + N]);
    }

    if (mi <= a[gs.front().front()]) {
      cand1.push_back(a[gs.front().front()]);
      cand1.push_back(mi);
    } else {
      for (int v : gs.front()) { cand1.push_back(a[v]); }
      for (int v : gs.front()) { cand1.push_back(a[v + N]); }
    }
  }

  if (gs.size() == 1) {
    cout << cand1 << endl;
    return;
  }

  auto get_cand = [&](int v) {
    vector<int> former, latter;
    for (int id : ids) {
      if (a[id] > v) break;
      former.push_back(a[id]);
      latter.push_back(a[id + N]);
    }
    former.insert(former.end(), all(latter));
    return former;
  };

  vector<int> cand2 = get_cand(a[gs.front().front() + N] - 1);
  vector<int> cand3 = get_cand(a[gs.front().front() + N]);

  auto ans = min(cand1, min(cand2, cand3));

  cout << ans << endl;

  return;
}

int main() {
  fastio();
  if (!multitest) {
    solve();
  } else {
    cerr << "[Warning] Multi testcase mode on" << endl;
    int t;
    cin >> t;
    while (t--) solve();
  }
  return 0;
}
