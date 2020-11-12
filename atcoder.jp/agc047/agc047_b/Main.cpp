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

struct AhoCorasick {
  const static int alphabet_size = 26;
  const int root = 0;
  const char base = 'a';

  AhoCorasick() : T(1) {}
  // AhoCorasick(const vector<string> &ss) : T(1) {
  //   for (const string &s : ss) add_string(s);
  //   build();
  // }

  struct Node {
    vector<int> child; // children of this node in Trie
    bool leaf;
    int par;    // parent
    char par_c; // character on the edge from parent to this node
    // int suf_link;    // suffix link
    // int exit_link;   // exit link : direct suffix link to the nearest match
    // vector<int> go;  // transition of the automaton
    // int match_count; // the number of matches of this state
    vector<int> cnt;
    Node(int par = -1, char par_c = '$')
        : child(alphabet_size, -1), leaf(false), par(par), par_c(par_c),
          cnt(26, 0) {}
  };

  vector<Node> T;

  int add_string(const string &s) {
    int v = root;

    vector<int> _cnt(26, 0);
    for (char ch : s) _cnt[ch - base]++;

    for (int j = 0; j < 26; j++)
      if (_cnt[j] > 0) T[root].cnt[j]++;

    for (char ch : s) {
      int c = ch - base;
      if (T[v].child[c] == -1) {
        T[v].child[c] = T.size();
        T.emplace_back(v, ch);
      }
      v = T[v].child[c];
      _cnt[c]--;
      for (int j = 0; j < 26; j++) {
        if (_cnt[j] > 0) T[v].cnt[j]++;
      }
    }
    T[v].leaf = true;
    return v;
  }

  int find_node(const string &s, int len) {
    int v = root;
    for (int i = 0; i < len; i++) {
      int c = s[i] - base;
      dmp(v, c, i);
      v = T[v].child[c];
      if (v == -1) return -1;
    }
    return v;
  }

  // int suf_link(int v) {
  //   if (T[v].suf_link == -1) {
  //     if (v == root || T[v].par == root) {
  //       T[v].suf_link = root;
  //     } else {
  //       int par_suf_link = suf_link(T[v].par);
  //       T[v].suf_link = go(par_suf_link, T[v].par_c);
  //     }
  //   }
  //   return T[v].suf_link;
  // }

  // int go(int v, char ch) {
  //   int c = ch - base;
  //   if (T[v].go[c] == -1) {
  //     if (T[v].child[c] != -1)
  //       T[v].go[c] = T[v].child[c];
  //     else
  //       T[v].go[c] = (v == root) ? root : go(suf_link(v), ch);
  //   }
  //   return T[v].go[c];
  // }

  // int match_count(int v) {
  //   if (T[v].match_count == -1) {
  //     if (v == root)
  //       T[v].match_count = 0;
  //     else {
  //       T[v].match_count = match_count(suf_link(v)) + (T[v].leaf ? 1 : 0);
  //     }
  //   }
  //   return T[v].match_count;
  // }

  // int exit_link(int v) {
  //   if (T[v].exit_link == -1) {
  //     if (v == root)
  //       T[v].exit_link = 0;
  //     else {
  //       int suf = suf_link(v);
  //       T[v].exit_link = T[suf].leaf ? suf : exit_link(suf);
  //     }
  //   }
  //   return T[v].exit_link;
  // }

  // void build() {
  //   for (int v = 0; v < T.size(); v++) {
  //     suf_link(v);
  //     match_count(v);
  //     exit_link(v);
  //     for (int i = 0; i < alphabet_size; i++) go(v, base + i);
  //   }
  // }

  Node &operator[](int v) { return T[v]; }
  int size() const { return T.size(); }
};

void solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  cin >> S;
  sort(all(S),
       [](const string &s, const string &t) { return s.size() > t.size(); });
  for (int i = 0; i < N; i++) reverse(all(S[i]));
  dmp(S);
  AhoCorasick ac;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    char c = S[i].back();
    int v = ac.find_node(S[i], S[i].size() - 1);
    if (v != -1) ans += ac[v].cnt[c - 'a'];
    ac.add_string(S[i]);
  }
  cout << ans << endl;
  return;
}

int main() {
  fastio();
  solve();
  // while (solve()) {}
  // int t; cin >> t; while(t--)solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
