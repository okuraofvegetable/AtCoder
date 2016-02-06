#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
#define A first
#define B second.first
#define C second.second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct line{
	P p,q;
	line(){}
	line(P a,P b):p(a),q(b){}
};
int cross(P a,P b){
	return a.fi*b.sec-a.sec*b.fi;
}
bool same(line a,line b){
	P p = P(a.q.fi-a.p.fi,a.q.sec-a.p.sec);
	P q1 = P(b.p.fi-a.p.fi,b.p.sec-a.p.sec);
	P q2 = P(b.q.fi-a.p.fi,b.q.sec-a.p.sec);
	if(cross(p,q1)==0&&cross(p,q2)==0)return true;
	else return false;
}
int N;
T convert(line a){
	int dx = a.p.fi-a.q.fi;
	int dy = a.p.sec-a.q.sec;
	T ret;
	if(dx==0){
		ret.A = 1;
		ret.B = 0;
		ret.C = a.p.fi;
	}else{
		ret.B = dx;
		ret.A = -dy;
		ret.C = ret.A*a.p.fi+ret.B*a.p.sec;
	}
	return ret;
}
T intersection(T a,T b){
	T ret;
	ret.A = a.A*b.B-a.B*b.A;
	ret.B = a.C*b.B-a.B*b.C;
	ret.C = a.A*b.C-b.A*a.C;
	int ra = (ret.A>0)?ret.A:-ret.A;
	int rb = (ret.B>0)?ret.B:-ret.B;
	int rc = (ret.C>0)?ret.C:-ret.C;
	int g = __gcd(ra,__gcd(rb,rc));
	ret.A /= g;ret.B /= g;ret.C /= g;
	if(ret.A<0)ret.A *= -1,ret.B *= -1,ret.C *= -1;
	return ret;
}
vector<line> L;
vector<T> vec;
int ans = 1;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		line t;
		scanf("%d %d %d %d",&t.p.fi,&t.p.sec,&t.q.fi,&t.q.sec);
		bool flag = false;
		for(int j=0;j<L.size();j++){
			if(same(L[j],t)){
				flag = true;
				break;
			}
		}
		if(!flag){
			int cnt = 0;
			set<T> s;
			T ct = convert(t);
			//printf("%d %d %d\n",ct.A,ct.B,ct.C);
			for(int j=0;j<vec.size();j++){
				if(vec[j].A*ct.B-vec[j].B*ct.A==0)continue;
				T cp = intersection(vec[j],ct);
				if(s.find(cp)==s.end()){
					s.insert(cp);
					cnt++;
				}
			}
			L.pb(t);
			vec.pb(ct);
			ans += cnt+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}