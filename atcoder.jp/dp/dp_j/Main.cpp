#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl;
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
template<class T,class U>
ostream& operator << (ostream& os,pair<T,U>& p){
  os << p.fi << ',' << p.sec; return os;
}
template<class T,class U>
istream& operator >> (istream& is,pair<T,U>& p){
  is >> p.fi >> p.sec; return is;
}
template<class T>
ostream& operator << (ostream &os,const vector<T> &vec){
  for(int i=0;i<vec.size();i++){
    os << vec[i];
    if(i+1<vec.size())os << ' ';
  }
  return os;
}
template<class T>
istream& operator >> (istream &is,vector<T>& vec){
  for(int i=0;i<vec.size();i++)is >> vec[i];
  return is;
}
void fastio(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(20);
}
double dp[305][305][305];
int N;
int a[305];
double rec(int x,int y,int z){
 if(dp[x][y][z]!=-1.0)return dp[x][y][z];
 double p = (double)(N-x-y-z)/(double)N;
 auto& t = dp[x][y][z];
 t = 1.0;
 if(x>0)t += rec(x-1,y,z)*(double)x/(double)N;
 if(y>0)t += rec(x+1,y-1,z)*(double)y/(double)N;
 if(z>0)t += rec(x,y+1,z-1)*(double)z/(double)N;
 t /= (1.0-p);
 return t;
}
int main(){
  fastio();
  cin >> N;
  int x=0,y=0,z=0;
  for(int i=0;i<N;i++){
    cin >> a[i];
    if(a[i]==1)x++;
    if(a[i]==2)y++;
    if(a[i]==3)z++;
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
      for(int k=0;k<=N;k++){
        dp[i][j][k] = -1.0;
      }
    }
  }
  dp[0][0][0] = 0.0;
  cout << rec(x,y,z) << endl;
  return 0;
}
