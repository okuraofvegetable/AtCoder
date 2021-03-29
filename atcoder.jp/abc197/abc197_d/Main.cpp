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

// Geometry Library
// written by okuraofvegetable

#define pb push_back
#define DOUBLE_INF 1e50
#define Points vector<Point>
#define EQ(a, b) (abs((a) - (b)) < eps)

inline double add(double a, double b) {
  if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
  return a + b;
}

// --------------------- Point -----------------------

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

  // Signed area of triange (0,0) (x,y) (p.x,p.y)
  double area(Point p) { return (x * p.y - p.x * y) / 2.0; }
  friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << '(' << p.x << ',' << p.y << ')';
  }
};

Point divide_rate(Point a, Point b, double A, double B) {
  assert(!EQ(A + B, 0.0));
  return (a * B + b * A) * (1.0 / (A + B));
}

Vector polar(double len, double arg) {
  return Vector(cos(arg) * len, sin(arg) * len);
}

// Direction a -> b -> c
// verified AOJ CGL_1_C
enum { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };
int ccw(Point a, Point b, Point c) {
  Vector p = b - a;
  Vector q = c - a;
  if (p.det(q) > 0.0) return COUNTER_CLOCKWISE; // counter clockwise
  if (p.det(q) < 0.0) return CLOCKWISE;         // clockwise
  if (p.dot(q) < 0.0) return ONLINE_BACK;       // c--a--b online_back
  if (p.norm() < q.norm()) return ONLINE_FRONT; // a--b--c online_front
  return ON_SEGMENT;                            // a--c--b on_segment
}

#define endl "\n"
using ll = long long;
using pii = pair<int, int>;

void solve() {
  int N;
  cin >> N;
  Point a, b;
  cin >> a;
  cin >> b;
  auto c = (a + b) / 2.0;
  dmp(c);
  auto d = a - c;
  double arg = d.arg();
  double len = d.norm();
  arg += 2.0 * M_PI / (double)N;
  auto ans = c + polar(len, arg);
  cout << ans.x << ' ' << ans.y << endl;
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
