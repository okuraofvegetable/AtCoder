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

struct FullyIndexableDictionary {
  static const int smallBlockSize = 16;
  static const int bigBlockSize = 1024;
  static constexpr int smallInBig = bigBlockSize / smallBlockSize;

  vector<uint16_t> bit; // raw data

  vector<uint32_t> bigBlockAcc;           // not succinct, optimal : 22 bit
  vector<vector<uint16_t>> smallBlockAcc; // not succinct, optimal : 10 bit

  int length;
  int bigBlockNum;
  int smallBlockNum;

  bool is_built;

  FullyIndexableDictionary() {}

  FullyIndexableDictionary(int len) : length(len), is_built(false) {
    bigBlockNum = (length + bigBlockSize - 1) / bigBlockSize;
    smallBlockNum = bigBlockNum * smallInBig;
    bit.assign(smallBlockNum, 0);
    bigBlockAcc.assign(bigBlockNum + 1, 0);
    smallBlockAcc.assign(bigBlockNum, vector<uint16_t>(smallInBig, 0));
  }

  void set(int id) {
    int sid = id / smallBlockSize;
    int offset = id % smallBlockSize;
    bit[sid] |= (uint16_t)(1u << offset);
  }

  void unset(int id) {
    int sid = id / smallBlockSize;
    int offset = id % smallBlockSize;
    bit[sid] &= (uint16_t)(~(1u << offset));
  }

  bool operator[](int id) {
    int sid = id / smallBlockSize;
    int offset = id % smallBlockSize;
    return (bool)((bit[sid] >> offset) & 1u);
  }

  void build() {
    is_built = true;
    bigBlockAcc[0] = 0;
    for (int i = 0; i + 1 < bigBlockAcc.size(); i++) {
      smallBlockAcc[i][0] = 0;
      for (int j = 0; j + 1 < smallBlockAcc[i].size(); j++) {
        smallBlockAcc[i][j + 1] =
            smallBlockAcc[i][j] + __builtin_popcount(bit[i * smallInBig + j]);
      }
      bigBlockAcc[i + 1] = bigBlockAcc[i] + smallBlockAcc[i].back() +
                           __builtin_popcount(bit[(i + 1) * smallInBig - 1]);
    }
  }

  int rank(int id) const {
    assert(is_built);
    int bid = id / bigBlockSize;
    int sid = (id % bigBlockSize) / smallBlockSize;
    int offset = id % smallBlockSize;
    uint16_t rem = bit[bid * smallInBig + sid] & ((1u << offset) - 1u);
    return bigBlockAcc[bid] + smallBlockAcc[bid][sid] + __builtin_popcount(rem);
  }

  // number of b in [0,id)
  int rank(int b, int id) const {
    if (b == 1)
      return rank(id);
    else
      return id - rank(id);
  }

  // return the position of num-th b
  // namely, the minimum id that holds rank(b,id+1) = num+1
  // attention : num is 0-indexed
  int select(int b, int num) const {
    assert(is_built);
    if (num < 0 || num >= rank(b, length)) return -1;
    int l = 0, r = length;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (rank(b, mid) >= num + 1)
        r = mid;
      else
        l = mid;
    }
    return l;
  }
  int select(int num) { return select(1, num); }
  int select(int b, int num, int l) { return select(b, num + rank(b, l)); }
};

// T must be unsigned type

template <class T, int LOG>
struct WaveletMatrix {
  int length;
  FullyIndexableDictionary mat[LOG];
  int zeroNum[LOG];
  int buf1[LOG], buf2[LOG];

  WaveletMatrix(vector<T> data) {
    length = data.size();
    vector<T> lv(length), rv(length);
    for (int i = 0; i < LOG; i++) {
      mat[i] = FullyIndexableDictionary(length + 1);
      int lp = 0, rp = 0;
      for (int j = 0; j < length; j++) {
        int bit = (data[j] >> (LOG - i - 1)) & (T(1));
        if (bit == 1) {
          rv[rp++] = data[j];
          mat[i].set(j);
        } else {
          lv[lp++] = data[j];
        }
      }
      mat[i].build();
      zeroNum[i] = lp;
      // cout << lp << ' ' << rp << endl;
      for (int j = 0; j < rp; j++) lv[lp + j] = rv[j];
      swap(data, lv);
      /*cout << zeroNum[i] << endl;
      for(int j=0;j<length;j++){
        cout << data[j] << ' ';
      }
      cout << endl; */
    }
  }

  // get id-th element
  T access(int id) {
    T res = T(0);
    for (int i = 0; i < LOG; i++) {
      int bit = mat[i][id];
      res = (res << 1) | bit;
      id = mat[i].rank(bit, id) + zeroNum[i] * bit;
    }
    return res;
  }

  // number of v in [0,id)
  int rank(T v, int id) {
    int l = 0, r = id;
    for (int i = 0; i < LOG; i++) {
      buf1[i] = l;
      buf2[i] = r;
      int bit = (v >> (LOG - i - 1)) & (T(1));
      l = mat[i].rank(bit, l) + zeroNum[i] * bit;
      r = mat[i].rank(bit, r) + zeroNum[i] * bit;
    }
    return r - l;
  }

  // position of num-th v
  // id is 0-indexed
  int select(T v, int num) {
    rank(v, length); // store path in buf
    for (int i = LOG - 1; i >= 0; i--) {
      int bit = (v >> (LOG - i - 1)) & (T(1));
      num = mat[i].select(bit, num, buf1[i]);
      if (num >= buf2[i] || num < 0) return -1;
      num -= buf1[i];
    }
    return num;
  }

  int select(T v, int k, int l) { return select(v, k + rank(v, l)); }

  // k-th largest value
  T quantile(int l, int r, int k) {
    if (r - l <= k || k < 0) return -1;
    T res = T(0);
    for (int i = 0; i < LOG; i++) {
      int lp = mat[i].rank(1, l);
      int rp = mat[i].rank(1, r);
      if (rp - lp > k) {
        l = lp + zeroNum[i];
        r = rp + zeroNum[i];
        res |= (T(1) << (LOG - i - 1));
      } else {
        k -= (rp - lp);
        l -= lp;
        r -= rp;
      }
    }
    assert(k == 0);
    return res;
  }

  T kth_max(int l, int r, int k) { return quantile(l, r, k); }

  T kth_min(int l, int r, int k) { return quantile(l, r, r - l - 1 - k); }

  // auxiliary function for range_freq
  int freq_dfs(int depth, int l, int r, T val, T low, T high) {
    if (l == r) return 0;
    if (depth == LOG) return (low <= val && val < high) ? r - l : 0;
    T right_val = ((T(1) << (LOG - depth - 1)) | val);
    T right_most = (((T(1) << (LOG - depth - 1)) - 1) | right_val);
    if (right_most < low || high <= val) return 0;
    if (low <= val && right_most < high) return r - l;
    int lp = mat[depth].rank(1, l);
    int rp = mat[depth].rank(1, r);
    int lch = freq_dfs(depth + 1, l - lp, r - rp, val, low, high);
    int rch = freq_dfs(depth + 1, lp + zeroNum[depth], rp + zeroNum[depth],
                       right_val, low, high);
    return lch + rch;
  }

  // occurence of value of [low,high) in [l,r)
  int rangefreq(int l, int r, T low, T high) {
    return freq_dfs(0, l, r, T(0), low, high);
  }

  pair<int, int> less_equal(int l, int r, T v) {
    int lessNum = 0;
    for (int i = 0; i < LOG; i++) {
      buf1[i] = l;
      buf2[i] = r;
      int bit = (v >> (LOG - i - 1)) & (T(1));
      if (bit) lessNum += (r - mat[i].rank(bit, r)) - (l - mat[i].rank(bit, l));
      l = mat[i].rank(bit, l) + zeroNum[i] * bit;
      r = mat[i].rank(bit, r) + zeroNum[i] * bit;
    }
    return make_pair(lessNum, r - l);
  }

  int less_freq(int l, int r, T v) { return less_equal(l, r, v).first; }

  int less_equal_freq(int l, int r, T v) {
    pair<int, int> res = less_equal(l, r, v);
    return res.first + res.second;
  }

  int next_value(int l, int r, T v) {
    int k = less_equal_freq(l, r, v);
    if (k == r - l)
      return -1;
    else
      return kth_min(l, r, k);
  }

  int prev_value(int l, int r, T v) {
    int k = less_freq(l, r, v);
    if (k == 0)
      return -1;
    else
      return kth_min(l, r, k - 1);
  }
};

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> g(N);
  vector<int> par(N);
  for (int i = 1; i < N; i++) {
    cin >> par[i];
    par[i]--;
    g[par[i]].push_back(i);
    g[i].push_back(par[i]);
  }

  vector<unsigned int> euler_tour;
  vector<int> begin(N), end(N);
  int k = 0;

  function<void(int, int, int)> dfs = [&](int v, int p, unsigned int d) {
    begin[v] = k;
    euler_tour.push_back(d);
    k++;
    for (int i = 0; i < g[v].size(); i++) {
      if (g[v][i] != p) {
        dfs(g[v][i], v, d + 1);
        euler_tour.push_back(10000000);
        k++;
      }
    }
    end[v] = k;
  };

  dfs(0, -1, 0);

  WaveletMatrix<unsigned int, 32> wm(euler_tour);

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, d;
    cin >> u >> d;
    u--;
    cout << wm.rank(d, end[u]) - wm.rank(d, begin[u]) << endl;
  }

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
