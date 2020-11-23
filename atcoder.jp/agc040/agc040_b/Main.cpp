#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

using P = pair<int, int>;

void solve() {
  int N;
  cin >> N;
  vector<P> rs;
  int Lmax = 0;
  int Rmin = INF;
  for (int i = 0; i < N; i++) {
    int L, R;
    cin >> L >> R;
    rs.emplace_back(L, R);
    chmax(Lmax, L);
    chmin(Rmin, R);
  }
  int Lcnt = 0, Rcnt = 0;
  for (int i = 0; i < N; i++) {
    if (rs[i].first == Lmax) Lcnt++;
    if (rs[i].second == Rmin) Rcnt++;
  }
  int lenmax = 0;
  for (int i = 0; i < N; i++) {
    int L = (rs[i].first == Lmax);
    int R = (rs[i].second == Rmin);
    if (Lcnt > L && Rcnt > R) chmax(lenmax, rs[i].second - rs[i].first + 1);
  }
  int ans = 0;
  chmax(ans, max(0, Rmin - Lmax + 1) + lenmax);
  dmp(ans);

  vector<P> qs;
  int L = -INF, R = INF;
  for (int i = 0; i < N; i++) {
    if (rs[i].first == Lmax) chmin(R, rs[i].second);
    if (rs[i].second == Rmin) chmax(L, rs[i].first);
    if (rs[i].first != Lmax && rs[i].second != Rmin) qs.push_back(rs[i]);
  }
  sort(all(qs));
  vector<int> Rmi(qs.size() + 1);
  vector<int> Lma(qs.size() + 1);
  Rmi.back() = R;
  Lma.front() = L;
  for (int i = (int)qs.size() - 1; i >= 0; i--) {
    Rmi[i] = min(Rmi[i + 1], qs[i].second);
  }
  for (int i = 0; i < qs.size(); i++) { Lma[i + 1] = max(Lma[i], qs[i].first); }
  dmp(qs);
  dmp(Rmi);
  dmp(Lma);
  for (int i = 0; i <= qs.size(); i++) {
    chmax(ans, max(0, Rmin - Lma[i] + 1) + max(0, Rmi[i] - Lmax + 1));
  }

  cout << ans << endl;
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
