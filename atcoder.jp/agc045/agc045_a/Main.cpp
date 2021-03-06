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

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  cin >> A;
  string S;
  cin >> S;

  const int MX = 62;
  auto mat = vect(MX, vect(0, 0));

  auto add_column = [&](ll x) {
    for (int i = 0; i < MX; i++) { mat[i].push_back((x >> i) & 1); }
  };

  auto remove_column = [&]() {
    for (int i = 0; i < MX; i++) { mat[i].pop_back(); }
  };

  auto get_rank = [&]() -> int {
    auto tmp = mat;
    int C = tmp[0].size();
    for (int r = 0; r < min(MX, C); r++) {
      if (tmp[r][r] == 0) {
        int sr = -1;
        for (int nr = r + 1; nr < MX; nr++) {
          if (tmp[nr][r]) {
            sr = nr;
            break;
          }
        }
        if (sr == -1) return r;
        for (int i = 0; i < C; i++) swap(tmp[r][i], tmp[sr][i]);
      }
      for (int i = r + 1; i < MX; i++) {
        if (tmp[i][r] == 1) {
          for (int j = r; j < C; j++) tmp[i][j] = (tmp[r][j] + tmp[i][j]) % 2;
        }
      }
    }
    return min(MX, C);
  };

  auto dump_mat = [&]() -> void {
    for (const auto &row : mat) cerr << row << endl;
    cerr << endl;
  };

  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == '0') {
      add_column(A[i]);
      int rank = get_rank();
      dmp(i, S[i], rank);
      // dump_mat();
      if (rank < mat[0].size()) remove_column();
    } else {
      add_column(A[i]);
      int rank = get_rank();
      dmp(i, S[i], rank);
      // dump_mat();
      if (rank < mat[0].size()) {
        remove_column();
      } else {
        cout << 1 << endl;
        return;
      }
    }
  }

  cout << 0 << endl;
  return;
}

int main() {
  fastio();
  // solve();
  int t;
  cin >> t;
  while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
