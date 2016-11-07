//South America South Finals - 2015-2016 // Problem I - Identifying Tea
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0); 
//#define NDEBUG 1
#define fst first
#define snd second
#define sz(v) ((int)v.size())
#define oo 200000000
#define itm1 fst
#define itm2 snd.fst
#define itm3 snd.snd 
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> tri;
typedef vector<ii> vii;
typedef vector<tri> vt;
 
int main() {
	fast_io();
	int t,a,b,c,d,e;
	while(cin>>t){
		cin>>a>>b>>c>>d>>e;
		cout<<(t==a)+(t==b)+(t==c)+(t==d)+(t==e)<<endl;
    }
    return 0;
}
