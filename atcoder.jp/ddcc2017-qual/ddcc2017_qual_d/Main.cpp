#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int H,W;
int A,B;
string s[205];
int main(){
	cin >> H >> W;
	cin >> A >> B;
	for(int i=0;i<H;i++)cin >> s[i];
	int tate = 0, yoko = 0, naname = 0;
	int three = 0, four= 0,one = 0,zero=0;
	for(int i=0;i<H/2;i++){
		for(int j=0;j<W/2;j++){
			int a=0,b=0,c=0;
			if(s[i][j]=='S')a++;
			if(s[H-1-i][j]=='S')a++;
			if(s[i][W-1-j]=='S')a++;
			if(s[H-1-i][W-1-j]=='S')a++;
			//cout << a << endl;
			if(a==2){
				if(s[i][j]=='S'&&s[H-1-i][j]=='S')b++;
				if(s[H-1-i][j]=='S'&&s[H-1-i][W-1-j]=='S')c++;
				if(s[i][j]=='S'&&s[i][W-1-j]=='S')c++;
				if(s[i][W-1-j]=='S'&&s[H-1-i][W-1-j]=='S')b++;
				if(b)tate++;
				else if(c)yoko++;
				else naname++;
			}
			if(a==3)three++;
			if(a==4)four++;
			if(a==0)zero++;
			if(a==1)one++;
		}
	}
	//printf("%d %d %d %d %d %d\n",zero,one,tate,yoko,three,four);
	if(one==0&&three==0&&naname==0){
		if(tate==0){
			if(yoko==0){
				cout << max(four*(max(A,B)+(A+B)),A+B) << endl;
				return 0;
			}else{
				cout << (yoko-1)*B+(A+B)+four*(max(A,B)+(A+B)) << endl;
				return 0;
			}
		}else if(yoko==0){
			cout << (tate-1)*A+(A+B)+four*(max(A,B)+(A+B)) << endl;
			return 0;
		}else{
			cout << max(tate*A+(A+B),yoko*B+(A+B))+four*(max(A,B)+(A+B)) << endl;
			return 0;
		}
	}else{
		cout << max((tate+three)*A+(A+B),(yoko+three)*B+(A+B))+four*(max(A,B)+(A+B)) << endl;
		return 0;
	}
	return 0;
}