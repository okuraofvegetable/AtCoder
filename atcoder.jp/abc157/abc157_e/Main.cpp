#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
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

template <class D>
struct SegmentTree {
  using DMerger = function<D(D, D)>;
  int length;
  vector<D> seg;
  const D d_unit;
  const DMerger dm;

  SegmentTree() {}
  SegmentTree(int n, const DMerger dm, const D &d_unit)
      : dm(dm), d_unit(d_unit) {
    length = 1;
    while (length < n) length <<= 1;
    seg.assign(2 * length, d_unit);
  }
  SegmentTree(vector<D> vec, const DMerger dm, const D &d_unit)
      : dm(dm), d_unit(d_unit) {
    length = 1;
    while (length < vec.size()) length <<= 1;
    seg.assign(2 * length, d_unit);
    for (int i = 0; i < vec.size(); i++) seg[length - 1 + i] = vec[i];
    for (int i = length - 2; i >= 0; i--)
      seg[i] = dm(seg[i * 2 + 1], seg[i * 2 + 2]);
  }

  void update(int k, D x) {
    k += length - 1;
    seg[k] = x;
    while (k) {
      k = (k - 1) / 2;
      seg[k] = dm(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }

  D query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return d_unit;
    } else if (a <= l && r <= b) {
      return seg[k];
    } else {
      D lch = query(a, b, k * 2 + 1, l, (l + r) / 2);
      D rch = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return dm(lch, rch);
    }
  }
  D query(int a, int b) { return query(a, b, 0, 0, length); }
};

void solve() {
  int N, Q;
  string S;
  cin >> N >> S >> Q;
  vector<SegmentTree<int>> segs(
      26, SegmentTree<int>(N, [](int x, int y) { return x + y; }, 0));
  for (int i = 0; i < S.size(); i++) {
    int d = S[i] - 'a';
    segs[d].update(i, 1);
  }
  for (int i = 0; i < Q; i++) {
    int type, idx;
    char c;
    cin >> type;
    if (type == 1) {
      cin >> idx >> c;
      int d = c - 'a';
      idx--;
      segs[S[idx] - 'a'].update(idx, 0);
      S[idx] = c;
      segs[d].update(idx, 1);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      int ans = 0;
      for (int j = 0; j < 26; j++) {
        if (segs[j].query(l, r) > 0) ans++;
      }
      cout << ans << endl;
    }
  }
  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();
  return 0;
}
