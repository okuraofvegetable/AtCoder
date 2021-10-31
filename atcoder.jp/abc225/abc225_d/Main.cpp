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

// Link Cut Tree
// 木をHeavy-Light decompositionし、各pathをsplay木(平衡二分木)で管理
// 各splay木において、左にあるほど根に近い。
// root以外はspaceships,road_developmentでverify済

// LinkCutTreeは本来、(根方向に有向な)有向木を扱うものであるから、無向木を扱う際は
// linkやcutする時に注意深くevertを行うこと。

// pathに対する様々な操作が可能。AからBへのpathに対する操作を行いたい時、
// Aをevertし、BをexposeすることでAとBは同じsplay木に含まれる様になる。
// (さらに,Bはexposeによってsplay木の根となっている)
// よって、各splay木内においてSegtree同様にデータを保持しておけば(遅延評価等も),
// 任意のpathに対するクエリに答えられる。

// is_root,rotr,rotl,splay,expose,cut,link,root,lcaはいじる必要ない。
// update,toggle,push,set,getを適宜変更して用いること。

// 対応クエリ:
// 根までのpathのコストを全てxにする
// 根までのpathのコストの和を求める

struct Node {
  Node *pp, *lp, *rp;
  int id;   // 頂点番号 初期化時に必ず指定すること。
  int size; // 自分の属するsplay木における自分以下の頂点数
  bool rev; // 反転フラグ

  typedef int val_t; // 適宜long longに変更すること。

  struct Data {
    val_t up, sum_up, down, sum_down;
  } data;

  Node(int id) : pp(NULL), lp(NULL), rp(NULL), id(id), size(1) {}

  Node(int id, val_t v) : pp(NULL), lp(NULL), rp(NULL), id(id) {
    data.up = data.sum_up = data.down = data.sum_down = v;
  }
  void update() { //子から、size,dataを更新する
    if (this == NULL) return;
    size = 1;
    data.sum_up = data.up;
    data.sum_down = data.down;
    if (lp != NULL) {
      data.sum_up += lp->data.sum_up;
      data.sum_down += lp->data.sum_down;
      size += lp->size;
    }
    if (rp != NULL) {
      data.sum_up += rp->data.sum_up;
      data.sum_down += rp->data.sum_down;
      size += rp->size;
    }
    return;
  }
  // 左右の子を反転させて変わる値がある時はtoggleでいじるのを忘れないこと。
  void toggle() {
    assert(this != NULL);
    swap(lp, rp);
    swap(data.up, data.down);
    swap(data.sum_up, data.sum_down);
    rev ^= true;
  }
  void push() {
    // 遅延評価とrevフラグの伝搬を行う。
    // もちろんrevよりも先に遅延評価しないと意味がない
    bool lch = (lp != NULL), rch = (rp != NULL);
    if (rev) {
      if (lch) { lp->toggle(); }
      if (rch) { rp->toggle(); }
      rev = false;
    }
  }
  void push_all() {
    // splay前に一気に根までpushする。
    // stack overflowする可能性があるので、する場合は
    // 下のsplayを使用すること。
    if (!is_root()) pp->push_all();
    push();
  }
  bool is_root() { // splay木の根か
    return !pp || (pp->lp != this && pp->rp != this);
  }
  void rotr() { // splay木　右回転
    Node *q = pp, *r = q->pp;
    if ((q->lp = rp)) rp->pp = q;
    rp = q;
    if (q) {
      q->pp = this;
      q->update();
    }
    update();
    if ((pp = r)) {
      if (r->lp == q) r->lp = this;
      if (r->rp == q) r->rp = this;
    }
    if (r) { r->update(); }
  }
  void rotl() { // splay木 左回転
    Node *q = pp, *r = q->pp;
    if ((q->rp = lp)) lp->pp = q;
    lp = q;
    if (q) {
      q->pp = this;
      q->update();
    }
    update();
    if ((pp = r)) {
      if (r->lp == q) r->lp = this;
      if (r->rp == q) r->rp = this;
    }
    if (r) { r->update(); }
  }

  /*
  void splay() { // splay操作。 頂点を属するsplay木の根に持っていく
    push_all();
    while (!is_root()) {
      Node *q = pp;
      if (q->is_root()) {
        if (q->lp == this)
          rotr();
        else
          rotl();
      } else {
        Node *r = q->pp;
        if (r->lp == q) {
          if (q->lp == this) {
            q->rotr();
            rotr();
          } else {
            rotl();
            rotr();
          }
        } else {
          if (q->rp == this) {
            q->rotl();
            rotl();
          } else {
            rotr();
            rotl();
          }
        }
      }
    }
  }
  */

  void splay() { // stack overflow する時用。こっちのほうが早いかも。
    push();
    while (!is_root()) {
      Node *q = pp;
      if (q->is_root()) {
        q->push();
        push();
        if (q->lp == this)
          rotr();
        else
          rotl();
      } else {
        Node *r = q->pp;
        r->push();
        q->push();
        push();
        if (r->lp == q) {
          if (q->lp == this) {
            q->rotr();
            rotr();
          } else {
            rotl();
            rotr();
          }
        } else {
          if (q->rp == this) {
            q->rotl();
            rotl();
          } else {
            rotr();
            rotl();
          }
        }
      }
    }
  }

  void expose() { // 実際の木の根を含むsplay木に属する様に変形する
    // 自分の子孫とは別のsplay木に属することになる、
    // すなわちexpose後のpath分解において自分が自分を含むpathの中で最も深くなる
    // のは仕様(lca,evertが楽)
    Node *rp = NULL;
    for (Node *p = this; p; p = p->pp) {
      p->splay();
      p->rp = rp;
      p->update();
      rp = p;
    }
    splay(); // 一応根に持っていっとくと色々便利(cutとかlinkとか遅延評価の時)
  }

  // 無向木を扱う際、link,cut時に注意深くevertを行うこと。

  void cut() { // 実際の木において親への辺をcut
    expose();
    Node *p = lp;
    if (p != NULL) {
      lp = NULL;
      p->pp = NULL;
    }
    update();
  }
  void link(Node *p) { // 実際の木においてpへ辺を張る(pのほうが親)
    assert(this != p);
    expose(); // 既に同じ木に属してるもの同士をlinkするとヤバいから注意。
    p->expose();
    pp = p; // 両方向にリンクを張ってもいいが、updateが面倒
  }
  void evert() {
    // exposeで自分の子孫とは別のsplay木に属することになるからこれでOK
    expose();
    toggle();
  }
  Node *root() { // 実際の木において、このnodeが所属する木の根
    expose();
    Node *u = this;
    while (u->lp) u = u->lp;
    u->splay();
    return u;
  }
  Node *lca(Node *p) {
    p->expose();
    expose();
    Node *ret = p;
    while (p->pp != NULL) {
      // exposeで自分の子孫とは別のsplay木に属することになるからこれでOK
      if (p->is_root()) ret = p->pp;
      p = p->pp;
    }
    return (this == p) ? ret : NULL;
  }
  val_t get() { // 根までのpath上のコストの和
    expose();
    return data.sum_up;
  }
  void set(val_t u, val_t d) { // コストをxにする
    expose();
    data.up = u;
    data.down = d;
    update();
  }
};

Node *nodes[100100];

void solve() {
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) nodes[i] = new Node(i);

  vector<int> child(N, -1);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      child[x] = y;
      nodes[y]->link(nodes[x]);
    }
    if (t == 2) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      child[x] = -1;
      nodes[y]->cut();
    }
    if (t == 3) {
      int x;
      cin >> x;
      x--;
      int cur = nodes[x]->root()->id;
      vector<int> ans;
      while (cur != -1) {
        ans.push_back(cur);
        cur = child[cur];
      }
      cout << ans.size();
      for (int v : ans) cout << ' ' << v + 1;
      cout << endl;
    }
  }

  // for (int i = 0; i < N; i++) delete nodes[i];
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
