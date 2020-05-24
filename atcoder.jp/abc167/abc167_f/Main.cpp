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
#define INF 2000000000               // 2e9
#define LLINF 2000000000000000000ll  // 2e18 (llmax:9e18)
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

void solve() {
  int N;
  cin >> N;
  vector<string> s(N);
  cin >> s;
  vector<int> diff(N);
  vector<int> bot(N, 0);
  vector<P> pos;
  vector<P> neg;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int h = 0;
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '(')
        h++;
      else
        h--;
      chmin(bot[i], h);
    }
    diff[i] = h;
    sum += diff[i];
    if (diff[i] >= 0) {
      pos.emplace_back(bot[i], diff[i]);
    } else {
      h = 0;
      bot[i] = 0;
      for (int j = s[i].size() - 1; j >= 0; j--) {
        if (s[i][j] == ')')
          h++;
        else
          h--;
        chmin(bot[i], h);
      }
      neg.emplace_back(bot[i], h);
    }
  }
  if (sum != 0) {
    cout << "No" << endl;
    return;
  }
  sort(all(pos));
  reverse(all(pos));
  sort(all(neg));
  reverse(all(neg));
  auto check = [](vector<P> &vec) {
    int s = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (s + vec[i].first < 0) return false;
      s += vec[i].second;
    }
    return true;
  };
  if (check(pos) && check(neg))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return;
}

signed main() {
  fastio();
  solve();
  //   int t;
  //   cin >> t;
  //   while (t--) solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
