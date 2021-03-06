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

template <int MOD> // if inv is needed, this shold be prime.
struct ModInt {
  ll val;
  ModInt() : val(0ll) {}
  ModInt(const ll &v) : val(((v % MOD) + MOD) % MOD) {}
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return !(*this == x); }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return !(*this < x); }
  bool operator<=(const ModInt &x) const { return !(*this > x); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt inv() const { return this->pow(MOD - 2); }
  ModInt &operator+=(const ModInt &x) {
    if ((val += x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &x) {
    if ((val += MOD - x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &x) {
    (val *= x.val) %= MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &x) { return *this *= x.inv(); };
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend istream &operator>>(istream &i, ModInt &x) {
    ll v;
    i >> v;
    x = v;
    return i;
  }
  friend ostream &operator<<(ostream &o, const ModInt &x) {
    o << x.val;
    return o;
  }
  ModInt pow(ll x) const {
    auto res = ModInt(1ll);
    auto b = *this;
    while (x) {
      if (x & 1) res *= b;
      x >>= 1;
      b *= b;
    }
    return res;
  }
};

template <int MOD>
ModInt<MOD> pow(ModInt<MOD> a, ll x) {
  ModInt<MOD> res = ModInt<MOD>(1ll);
  while (x) {
    if (x & 1) res *= a;
    x >>= 1;
    a *= a;
  }
  return res;
}

constexpr int MOD = 1e9 + 7;
// constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

#define DOUBLE_INF 1e50
#define Points vector<Point>
#define EQ(a, b) (abs((a) - (b)) < eps)

inline double add(double a, double b) {
  if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
  return a + b;
}

#define Vector Point
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(Point p) { return Point(add(x, p.x), add(y, p.y)); }
  Point operator-(Point p) { return Point(add(x, -p.x), add(y, -p.y)); }
  Point operator*(double d) { return Point(x * d, y * d); }
  Point operator/(double d) { return Point(x / d, y / d); }
  double dot(Point p) { return add(x * p.x, y * p.y); }
  double det(Point p) { return add(x * p.y, -y * p.x); }
  double norm() { return sqrt(x * x + y * y); }
  double norm2() { return x * x + y * y; }
  double dist(Point p) { return ((*this) - p).norm(); }
  double dist2(Point p) { return sq(x - p.x) + sq(y - p.y); }
  double arg() { return atan2(y, x); }             // [-PI,PI]
  double arg(Vector v) { return v.arg() - arg(); } // henkaku
  double angle(Vector v) {                         // [0,PI]
    return acos(cos(arg(v)));
  }
  Vector normalize() { return (*this) * (1.0 / norm()); }
  Point vert() { return Point(y, -x); }

  // signed area of triange (0,0) (x,y) (p.x,p.y)
  double area(Point p) { return (x * p.y - p.x * y) / 2.0; }
  friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};
// direction a -> b -> c
// verified AOJ CGL_1_C
enum { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };
Point divide_rate(Point a, Point b, double A, double B) {
  assert(!EQ(A + B, 0.0));
  return (a * B + b * A) * (1.0 / (A + B));
}
Vector polar(double len, double arg) {
  return Vector(cos(arg) * len, sin(arg) * len);
}
int ccw(Point a, Point b, Point c) {
  Vector p = b - a;
  Vector q = c - a;
  if (p.det(q) > 0.0) return COUNTER_CLOCKWISE; // counter clockwise
  if (p.det(q) < 0.0) return CLOCKWISE;         // clockwise
  if (p.dot(q) < 0.0) return ONLINE_BACK;       // c--a--b online_back
  if (p.norm() < q.norm()) return ONLINE_FRONT; // a--b--c online_front
  return ON_SEGMENT;                            // a--c--b on_segment
}
struct Line {
  Point a, b;
  Line() {}
  Line(Point a, Point b) : a(a), b(b) {}
  bool on(Point q) { return (a - q).det(b - q) == 0; }
  // folloing 2 functions verified AOJ CGL_2_A
  bool is_parallel(Line l) { return (a - b).det(l.a - l.b) == 0; }
  bool is_orthogonal(Line l) { return (a - b).dot(l.a - l.b) == 0; }
  Point intersection(Line l) {
    assert(!is_parallel(l));
    return a + (b - a) * ((l.b - l.a).det(l.a - a) / (l.b - l.a).det(b - a));
  }
  // projection of p to this line
  // verified AOJ CGL_1_A
  Point projection(Point p) {
    return (b - a) * ((b - a).dot(p - a) / (b - a).norm2()) + a;
  }
  double distance(Point p) {
    Point q = projection(p);
    return p.dist(q);
  }
  // reflection point of p onto this line
  // verified AOJ CGL_1_B
  Point refl(Point p) {
    Point proj = projection(p);
    return p + ((proj - p) * 2.0);
  }
  bool left(Point p) {
    if ((p - a).det(b - a) > 0.0)
      return true;
    else
      return false;
  }
  friend istream &operator>>(istream &is, Line &l) { return is >> l.a >> l.b; }
  friend ostream &operator<<(ostream &os, const Line &l) {
    return os << l.a << " -> " << l.b;
  }
};
struct Segment {
  Point a, b;
  Segment() {}
  Segment(Point a, Point b) : a(a), b(b) {}
  Line line() { return Line(a, b); }
  bool on(Point q) {
    return ((a - q).det(b - q) == 0 && (a - q).dot(b - q) <= 0);
  }
  // verified AOJ CGL_2_B
  bool is_intersect(Segment s) {
    if (line().is_parallel(s.line())) {
      if (on(s.a) || on(s.b)) return true;
      if (s.on(a) || s.on(b)) return true;
      return false;
    }
    Point p = line().intersection(s.line());
    if (on(p) && s.on(p))
      return true;
    else
      return false;
  }
  bool is_intersect(Line l) {
    if (line().is_parallel(l)) {
      if (l.on(a) || l.on(b))
        return true;
      else
        return false;
    }
    Point p = line().intersection(l);
    if (on(p))
      return true;
    else
      return false;
  }
  // following 2 distance functions verified AOJ CGL_2_D
  double distance(Point p) {
    double res = DOUBLE_INF;
    Point q = line().projection(p);
    if (on(q)) res = min(res, p.dist(q));
    res = min(res, min(p.dist(a), p.dist(b)));
    return res;
  }
  double distance(Segment s) {
    if (is_intersect(s)) return 0.0;
    double res = DOUBLE_INF;
    res = min(res, s.distance(a));
    res = min(res, s.distance(b));
    res = min(res, this->distance(s.a));
    res = min(res, this->distance(s.b));
    return res;
  }
  friend istream &operator>>(istream &is, Segment &s) {
    return is >> s.a >> s.b;
  }
  friend ostream &operator<<(ostream &os, const Segment &s) {
    return os << s.a << " -> " << s.b;
  }
};
void solve() {
  int Ax, Ay, Bx, By;
  cin >> Ax >> Ay >> Bx >> By;
  Segment seg(Point(Ax, Ay), Point(Bx, By));
  int N;
  cin >> N;
  vector<Point> ps(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    ps[i] = Point(x, y);
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    Segment s(ps[i], ps[(i + 1) % N]);
    if (seg.is_intersect(s)) cnt++;
  }
  assert(cnt % 2 == 0);
  cout << 1 + cnt / 2 << endl;
  return;
}

signed main() {
  fastio();
  solve();
  // int t;
  // cin >> t;
  // while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
