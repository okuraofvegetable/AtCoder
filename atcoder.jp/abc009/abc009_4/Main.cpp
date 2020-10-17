// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000              // 2e9
#define LLINF 2000000000000000000ll // 2e18 (llmax:9e18)
#define fi first
#define sec second
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define dmp(x) cerr << #x << ": " << x << endl;

template <class T>
void chmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, const T &b) {
  if (a < b) a = b;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.fi << ',' << p.sec;
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.fi >> p.sec;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 < vec.size()) os << ' ';
  }
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}
void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

#define endl "\n"

// matrix class
// constructor of T : T(1),T(0) must be unit of T
// verified DDCC B
// https://atcoder.jp/contests/ddcc2020-final/submissions/9941022
template <class T, const T &Zero, const T &Unit>
struct Matrix {
  int H, W;
  vector<vector<T>> elem;
  Matrix(int H, int W, T val = Zero) : H(H), W(W) {
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
  Matrix identity(int N) const {
    Matrix a(N, N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j)
          a.elem[i][i] = Unit;
        else
          a.elem[i][j] = Zero;
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

struct Ring {
  unsigned int x;
  Ring() {}
  Ring(unsigned int x) : x(x) {}
  Ring operator*(const Ring &a) const { return Ring(x & a.x); }
  Ring operator+(const Ring &a) const { return Ring(x ^ a.x); }
  friend ostream &operator<<(ostream &os, const Ring &x) {
    os << x.x;
    return os;
  }
  friend istream &operator>>(istream &is, Ring &x) {
    is >> x.x;
    return is;
  }
};

const Ring zero(0);
const Ring unit(~0);

void solve() {
  int K, M;
  cin >> K >> M;
  vector<unsigned int> A(K);
  cin >> A;
  vector<unsigned int> C(K);
  cin >> C;

  Matrix<Ring, zero, unit> B(K, K);
  for (int i = 0; i < K; i++) B[0][i] = Ring(C[i]);
  for (int i = 1; i < K; i++) B[i][i - 1] = Ring(~0);

  Matrix<Ring, zero, unit> Init(K, 1);
  for (int i = 0; i < K; i++) Init[i][0] = Ring(A[K - 1 - i]);

  B = B.pow(M - 1);

  auto Ans = B * Init;
  cout << Ans[K - 1][0] << endl;
}

signed main() {
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
