#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dump(X) cout << #X << ' ' << X << endl
#define pe(X) cout << X << endl
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
struct Node{
	Node *pp,*lp,*rp;
	int id;             // 頂点番号 初期化時に必ず指定すること。	
	int size;           // 自分の属するsplay木における自分以下の頂点数
	bool rev;           // 反転フラグ
	
	typedef int val_t;  // 適宜long longに変更すること。
	
	struct Data{
		val_t up,sum_up,down,sum_down;
	}data;
	
	
	Node(int id):pp(NULL),lp(NULL),rp(NULL),id(id),size(1){}
	
	Node(int id,val_t v):pp(NULL),lp(NULL),rp(NULL),id(id){
		data.up = data.sum_up = data.down = data.sum_down = v;
	}
	void update(){ //子から、size,dataを更新する
		if(this==NULL)return;
		size = 1;
		data.sum_up = data.up;
		data.sum_down = data.down;
		if(lp!=NULL){
			data.sum_up += lp->data.sum_up;
			data.sum_down += lp->data.sum_down;
			size += lp->size;
		}
		if(rp!=NULL){
			data.sum_up += rp->data.sum_up;
			data.sum_down += rp->data.sum_down;
			size += rp->size;
		}
		return;
	}
	// 左右の子を反転させて変わる値がある時はtoggleでいじるのを忘れないこと。
	void toggle(){
		assert(this!=NULL);
		swap(lp,rp);
		swap(data.up,data.down);
		swap(data.sum_up,data.sum_down);
		rev ^= true;
	}
	void push(){
		// 遅延評価とrevフラグの伝搬を行う。
		// もちろんrevよりも先に遅延評価しないと意味がない
		bool lch = (lp!=NULL),rch = (rp!=NULL);
		if(rev){
			if(lch){
				lp->toggle();
			}
			if(rch){
				rp->toggle();
			}
			rev = false;
		}
	}
	void push_all(){ 
		// splay前に一気に根までpushする。
		// stack overflowする可能性があるので、する場合は
		// 下のsplayを使用すること。
		if(!is_root())pp->push_all();
		push();
	}
	bool is_root(){ // splay木の根か
		return !pp||(pp->lp!=this&&pp->rp!=this);
	}
	void rotr(){ // splay木　右回転
		Node *q=pp,*r=q->pp;
		if((q->lp=rp))rp->pp=q;
		rp=q;q->pp=this;
		q->update();
		update();
		if((pp=r)){
			if(r->lp==q)r->lp=this;
			if(r->rp==q)r->rp=this;
		}
		r->update();
	}
	void rotl(){ // splay木 左回転
		Node *q=pp,*r=q->pp;
		if((q->rp=lp))lp->pp=q;
		lp=q;q->pp=this;
		q->update();
		update();
		if((pp=r)){
			if(r->lp==q)r->lp=this;
			if(r->rp==q)r->rp=this;
		}
		r->update();
	}
	/*void splay(){ // splay操作。 頂点を属するsplay木の根に持っていく
		push_all();
		while(!is_root()){
			Node *q=pp;
			if(q->is_root()){
				if(q->lp==this)rotr();
				else rotl();
			}else{
				Node *r=q->pp;
				if(r->lp==q){
					if(q->lp==this){q->rotr();rotr();}
					else {rotl();rotr();}
				}else{
					if(q->rp==this){q->rotl();rotl();}
					else {rotr();rotl();}
				}
			}
		}
	}*/
	void splay(){ // stack overflow する時用。こっちのほうが早いかも。
		push();
		while(!is_root()){
			Node *q=pp;
			if(q->is_root()){
				q->push();push();
				if(q->lp==this)rotr();
				else rotl();
			}else{
				Node *r=q->pp;
				r->push();q->push();push();
				if(r->lp==q){
					if(q->lp==this){q->rotr();rotr();}
					else {rotl();rotr();}
				}else{
					if(q->rp==this){q->rotl();rotl();}
					else {rotr();rotl();}
				}
			}
		}
	}
	void expose(){ // 実際の木の根を含むsplay木に属する様に変形する
		// 自分の子孫とは別のsplay木に属することになる、
		// すなわちexpose後のpath分解において自分が自分を含むpathの中で最も深くなる
		// のは仕様(lca,evertが楽)
		Node *rp=NULL;
		for(Node *p=this;p;p=p->pp){
			p->splay();
			p->rp=rp;
			p->update();
			rp=p;
		}
		splay();  // 一応根に持っていっとくと色々便利(cutとかlinkとか遅延評価の時)
	}
	
	// 無向木を扱う際、link,cut時に注意深くevertを行うこと。
	
	void cut(){ // 実際の木において親への辺をcut
		expose();
		Node *p=lp;
		if(p!=NULL){
			lp=NULL;
			p->pp=NULL;
		}
		update();
	}
	void link(Node *p){ // 実際の木においてpへ辺を張る(pのほうが親)
		assert(this!=p);
		expose();       // 既に同じ木に属してるもの同士をlinkするとヤバいから注意。
		p->expose();
		pp=p;           // 両方向にリンクを張ってもいいが、updateが面倒
	}
	void evert(){
		//exposeで自分の子孫とは別のsplay木に属することになるからこれでOK
		expose();
		toggle();
	}
	Node* root(){ // 実際の木において、このnodeが所属する木の根
		expose();
		Node* u = this;
		while(u->lp)u=u->lp;
		u->splay();
		return u;
	}
	Node* lca(Node *p){
		p->expose();
		expose();
		Node *ret=p;
		while(p->pp != NULL){
			//exposeで自分の子孫とは別のsplay木に属することになるからこれでOK
			if(p->is_root())ret=p->pp;
			p=p->pp;
		}
		return (this==p)?ret:NULL;
	}
	val_t get(){ // 根までのpath上のコストの和
		expose();
		return data.sum_up;
	}
	void set(val_t u,val_t d){ // コストをxにする
		expose();
		data.up = u;
		data.down = d;
		update();
	}
};
Node* nv[100100];
Node* ne[100100];

Node* mv[100100];
Node* me[100100];

int N,Q;
int p[100100],q[100100],c[100100],d[100100];
vector<int> es[100100];
int ans[100100];
struct Query{
	int id,col,len,u,v;
	Query(){}
	Query(int id,int col,int len,int u,int v):id(id),col(col),len(len),u(u),v(v){}
};
vector<Query> qs[100100];
int main(){
	cin >> N >> Q;
	for(int i=0;i<N;i++)nv[i]=new Node(i,0);
	for(int i=0;i<N-1;i++)ne[i]=new Node(i,1);
	for(int i=0;i<N-1;i++){
		scanf("%d %d %d %d",&p[i],&q[i],&c[i],&d[i]);
		c[i]--;
		if(p[i]>q[i])swap(p[i],q[i]);
		p[i]--;q[i]--;
		nv[p[i]]->evert();
		nv[p[i]]->link(ne[i]);
		ne[i]->link(nv[q[i]]);

		nv[q[i]]->evert();
		ne[i]->set(d[i],d[i]);

		es[c[i]].pb(i);
	}
	for(int i=0;i<N;i++)mv[i]=new Node(i,0);
	for(int i=0;i<N-1;i++)me[i]=new Node(i,0);
	for(int i=0;i<N-1;i++){
		mv[p[i]]->evert();
		mv[p[i]]->link(me[i]);
		me[i]->link(mv[q[i]]);

		mv[q[i]]->evert();
		me[i]->set(0,0);
	}
	for(int i=0;i<Q;i++){
		int x,y,u,v;
		cin >> x >> y >> u >> v;
		u--;v--;
		x--;
		qs[x].pb(Query(i,x,y,u,v));
	}
	for(int i=0;i<N-1;i++){
		
		for(int j=0;j<es[i].size();j++){
			int eid = es[i][j];
			nv[q[eid]]->evert();
			ne[eid]->set(0,0);

			mv[q[eid]]->evert();
			me[eid]->set(1,1);
		}
		for(int j=0;j<qs[i].size();j++){
			Query que = qs[i][j];
			nv[que.v]->evert();
			mv[que.v]->evert();
			int sum = nv[que.u]->get();
			int k = mv[que.u]->get();
			ans[que.id] = sum+k*que.len;
		}
		for(int j=0;j<es[i].size();j++){
			int eid = es[i][j];
			nv[q[eid]]->evert();
			ne[eid]->set(d[eid],d[eid]);

			mv[q[eid]]->evert();
			me[eid]->set(0,0);
		}
	}
	for(int i=0;i<Q;i++){
		cout << ans[i] << endl;
	}
	return 0;
}