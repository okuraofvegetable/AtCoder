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

#include <atcoder/maxflow>
using namespace atcoder;

// kuriagari kaisuu
int sub(const vector<int> &scnt, const vector<int> &tcnt) {
  mf_graph<int> g(22);
  int S = 20, T = 21;
  int k = 0;
  auto edge_id = vect(10, vect(10, -1));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i + j < 9) continue;
      edge_id[i][j] = k++;
      g.add_edge(i, 10 + j, 200000);
    }
  }
  for (int i = 0; i < 10; i++) {
    g.add_edge(S, i, scnt[i]);
    g.add_edge(10 + i, T, tcnt[i]);
  }
  return g.flow(S, T);
}

void trim_leading_zero(string &s) {
  int idx = 0;
  while (idx < s.size() && s[idx] == '0') idx++;
  s = s.substr(idx);
}

void solve() {
  string s, t;
  cin >> s >> t;
  vector<int> scnt(10, 0), tcnt(10, 0);
  for (char c : s) scnt[c - '0']++;
  for (char c : t) tcnt[c - '0']++;
  if (s.size() < t.size()) scnt[0] += t.size() - s.size();
  if (t.size() < s.size()) tcnt[0] += s.size() - t.size();
  dmp(scnt, tcnt);

  int mx_num_carry = 0;
  int mx_i = -1, mx_j = -1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i + j < 10) continue;
      if (scnt[i] == 0 || tcnt[j] == 0) continue;
      scnt[i]--;
      tcnt[j]--;
      int num_carry = sub(scnt, tcnt);
      scnt[i]++;
      tcnt[j]++;
      if (chmax(mx_num_carry, num_carry + 1)) { mx_i = i, mx_j = j; }
    }
  }

  if (mx_num_carry == 0) {
    cout << s << endl;
    cout << t << endl;
    return;
  }

  assert(mx_i != -1);

  dmp(mx_num_carry, mx_i, mx_j);

  string A_up, B_up;
  string A_rem, B_rem;
  {
    scnt[mx_i]--;
    tcnt[mx_j]--;

    mf_graph<int> g(22);
    int S = 20, T = 21;
    int k = 0;
    auto edge_id = vect(10, vect(10, -1));
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (i + j < 9) continue;
        edge_id[i][j] = k++;
        g.add_edge(i, 10 + j, 200000);
      }
    }
    for (int i = 0; i < 10; i++) {
      g.add_edge(S, i, scnt[i]);
      g.add_edge(10 + i, T, tcnt[i]);
    }
    g.flow(S, T);
    auto es = g.edges();

    for (int i = 0; i < es[edge_id[0][9]].flow; i++) {
      A_up += '0';
      B_up += '9';
    }
    for (int i = 0; i < es[edge_id[9][0]].flow; i++) {
      A_up += '9';
      B_up += '0';
    }
    for (int i = 1; i < 10; i++) {
      for (int j = 1; j < 10; j++) {
        if (edge_id[i][j] == -1) continue;
        for (int a = 0; a < es[edge_id[i][j]].flow; a++) {
          A_up += (char)('0' + i);
          B_up += (char)('0' + j);
        }
      }
    }

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (i + j < 9) continue;
        scnt[i] -= es[edge_id[i][j]].flow;
        tcnt[j] -= es[edge_id[i][j]].flow;
      }
    }

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < scnt[i]; j++) { A_rem += (char)('0' + i); }
      for (int j = 0; j < tcnt[i]; j++) { B_rem += (char)('0' + i); }
    }

    A_up += (char)('0' + mx_i);
    B_up += (char)('0' + mx_j);
  }

  dmp(A_rem, B_rem, A_up, B_up);
  assert(A_rem.size() == B_rem.size());

  int idx = 0;
  while (idx < A_rem.size() && (A_rem[idx] == '0' || B_rem[idx] == '0')) {
    idx++;
  }

  string A_rem_upper = A_rem.substr(0, idx);
  string B_rem_upper = B_rem.substr(0, idx);

  string A_rem_lower = A_rem.substr(idx);
  string B_rem_lower = B_rem.substr(idx);

  string A = A_rem_upper + A_up + A_rem_lower;
  string B = B_rem_upper + B_up + B_rem_lower;

  trim_leading_zero(A);
  trim_leading_zero(B);

  cout << A << endl;
  cout << B << endl;

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
