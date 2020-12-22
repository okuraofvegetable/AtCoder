#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

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

vector<P> sub(ll K, ll X, ll Y) {
  bool swapped = false;
  if (X > Y) {
    swap(X, Y);
    swapped = true;
  }

  vector<P> ret;

  ll x = 0, y = 0;

  if ((X + Y) % K == 0) {
    for (int i = 1; i <= (X + Y) / K; i++) {
      ll dy = min(Y - y, K);
      y += dy;
      x += K - dy;
      ret.emplace_back(x, y);
    }
    if (swapped)
      for (auto &[a, b] : ret) swap(a, b);
    return ret;
  }

  if (K % 2 == 0) {
    ll p = (X + Y + K - 1) / K;
    ll a = (p * K - (X + Y)) / 2;
    if (p == 1) {
      ret.emplace_back(-(K / 2 + a), K / 2 - a);
      ret.emplace_back(X, Y);
    } else {
      for (int i = 0; i < p; i++) {
        ll rem = K;
        if (y == 0) {
          ll dx = min(x + a, rem);
          x -= dx;
          rem -= dx;
        }
        if (x == -a) {
          ll dy = min(Y - y, rem);
          y += dy;
          rem -= dy;
        }
        if (y == Y) {
          ll dx = min(X - x, rem);
          x += dx;
          rem -= dx;
        }
        ret.emplace_back(x, y);
        assert(rem == 0);
      }
    }
  } else if (K % 2 == 1 && (X + Y) % 2 == 0) {
    ll p = (X + Y + K - 1) / K;
    if (p % 2 == 1) p++;
    ll a = (p * K - (X + Y)) / 2;
    for (int i = 0; i < p; i++) {
      ll rem = K;
      if (y == 0) {
        ll dx = min(x + a, rem);
        x -= dx;
        rem -= dx;
      }
      if (x == -a) {
        ll dy = min(Y - y, rem);
        y += dy;
        rem -= dy;
      }
      if (y == Y) {
        ll dx = min(X - x, rem);
        x += dx;
        rem -= dx;
      }
      ret.emplace_back(x, y);
      assert(rem == 0);
    }
  } else {
    ll p = (X + Y + K - 1) / K;
    if (p % 2 == 0) p++;
    ll a = (p * K - (X + Y)) / 2;

    if (p == 1) {
      ret.emplace_back(-a, a + X + Y);
      ret.emplace_back(X, Y + K);
      ret.emplace_back(X, Y);
    } else {
      for (int i = 0; i < p; i++) {
        ll rem = K;
        if (y == 0) {
          ll dx = min(x + a, rem);
          x -= dx;
          rem -= dx;
        }
        if (x == -a) {
          ll dy = min(Y - y, rem);
          y += dy;
          rem -= dy;
        }
        if (y == Y) {
          ll dx = min(X - x, rem);
          x += dx;
          rem -= dx;
        }
        ret.emplace_back(x, y);
        assert(rem == 0);
      }
    }
  }

  if (swapped)
    for (auto &[a, b] : ret) swap(a, b);
  return ret;
}

void solve() {
  ll K;
  ll X, Y;
  cin >> K >> X >> Y;
  if (K % 2 == 0 && (abs(X) + abs(Y)) % 2 == 1) {
    cout << -1 << endl;
    return;
  }

  auto ans = sub(K, abs(X), abs(Y));
  for (auto &[x, y] : ans) {
    if (X < 0) x *= -1;
    if (Y < 0) y *= -1;
  }

  auto check = [&](vector<P> &ans) -> bool {
    for (int i = 1; i < ans.size(); i++) {
      ll d = abs(ans[i].first - ans[i - 1].first) +
             abs(ans[i].second - ans[i - 1].second);
      if (d != K) return false;
    }
    return true;
  };

  assert(check(ans));
  assert(ans.back() == P(X, Y));

  cout << ans.size() << endl;
  for (auto [x, y] : ans) cout << x << ' ' << y << endl;
  return;
}

int main() {
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
