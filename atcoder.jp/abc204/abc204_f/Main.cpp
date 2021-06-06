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

#include <atcoder/modint>
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint &v) {
  return os << v.val();
}

// ------------ End of template --------------

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

const bool multitest = false;

template <class T>
struct Matrix {
  int H, W;
  vector<vector<T>> elem;
  Matrix(int H, int W, T val = T(0)) : H(H), W(W) {
    elem.resize(H);
    for (int i = 0; i < H; i++) elem[i].assign(W, val);
  }
  Matrix(const vector<vector<T>> &m)
      : H(m.size()), W(m.size() ? m[0].size() : 0) {
    elem.resize(H);
    for (int i = 0; i < H; i++) elem[i].resize(W);
    for (int i = 0; i < H; i++) elem[i] = m[i];
  }
  vector<T> &operator[](int h) { return elem[h]; }
  static Matrix identity(int N) {
    Matrix a(N, N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j)
          a.elem[i][i] = T(1);
        else
          a.elem[i][j] = T(0);
      }
    }
    return a;
  }
  Matrix operator+(const Matrix &m) const {
    assert(H == m.H && W == m.W);
    Matrix a(H, W);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        a.elem[i][j] = this->elem[i][j] + m.elem[i][j];
      }
    }
    return a;
  }
  Matrix operator-(const Matrix &m) const {
    assert(H == m.H && W == m.W);
    Matrix a(H, W);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        a.elem[i][j] = this->elem[i][j] - m.elem[i][j];
      }
    }
    return a;
  }
  Matrix operator*(const Matrix &m) const {
    assert(W == m.H);
    Matrix a(H, m.W);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < m.W; j++) {
        for (int k = 0; k < W; k++) {
          a.elem[i][j] = a.elem[i][j] + (this->elem[i][k] * m.elem[k][j]);
        }
      }
    }
    return a;
  }
  Matrix &operator+=(const Matrix &m) { return *this = *this + m; }
  Matrix &operator-=(const Matrix &m) { return *this = *this - m; }
  Matrix &operator*=(const Matrix &m) { return *this = *this * m; }
  Matrix pow(long long x) const {
    Matrix a = identity(H);
    Matrix b = *this;
    while (x) {
      if (x & 1) a *= b;
      b *= b;
      x >>= 1;
    }
    return a;
  }

  T determinant() {
    Matrix m(*this);
    assert(m.W == m.H);
    T ret(1);
    for (int i = 0; i < m.H; i++) {
      int idx = -1;
      for (int j = i; j < m.H; j++) {
        if (m[j][i] != T(0)) idx = j;
      }
      if (idx == -1) return T(0);
      if (i != idx) {
        ret *= T(-1);
        swap(m[i], m[idx]);
      }
      ret *= m[i][i];
      T div = m[i][i];
      for (int j = i; j < m.W; j++) m[i][j] /= div;
      for (int j = i + 1; j < m.H; j++) {
        T a = m[j][i];
        for (int k = i; k < m.W; k++) m[j][k] -= m[i][k] * a;
      }
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const Matrix &x) {
    for (int i = 0; i < x.H; i++) {
      for (int j = 0; j < x.W; j++) {
        os << x.elem[i][j];
        if (j + 1 < x.W) cout << ' ';
      }
      if (i + 1 < x.H) cout << endl;
    }
    return os;
  }
  friend istream &operator>>(istream &is, Matrix &x) {
    for (auto &v : x.elem) is >> v;
    return is;
  }
};

void solve() {
  int H;
  ll W;
  cin >> H >> W;
  int M = (1 << H);
  Matrix<mint> A(M, M);
  for (int i = 0; i < M; i++) {
    function<void(int, int)> dfs = [&](int S, int x) {
      if (x == H) {
        A[S][i] += mint(1);
        return;
      }
      if ((i >> x) & 1) {
        dfs(S, x + 1);
      } else {
        dfs(S, x + 1);
        dfs(S | (1 << x), x + 1);
        if (x + 1 < H && !((i >> (x + 1)) & 1)) { dfs(S, x + 2); }
      }
    };
    dfs(0, 0);
  }
  A = A.pow(W);
  cout << A[0][0] << endl;
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
