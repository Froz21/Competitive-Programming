//South America South Finals - 2015-2016 // Problem A - At most twice
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
 
int most[11];

string go(string s){
	int i=0;
	int flag=0;
	while(i<s.size()){
		int u= (int)(s[i]-'0');
		most[u]++;
		if (flag) most[u]--;
		if(most[u]>2 or flag){
			most[u]--;
			if(s[i]=='0'){
				i--;
				flag=1;
				continue;
			}
			s[i]--;
			REP(j,i+1,s.size()){
				s[j]='9';
			}
			flag=0;
		}
		else i++;
	}
	return s;
}

int main() {
	fast_io();
	string s;
	while(cin>>s){
		memset(most,0,sizeof(most));
		string n=go(s);
		int flag=0;
		REP(i,0,n.size()){
			if(!flag and n[i]=='0'){
				continue;
			}
			flag=1;
			cout<<n[i];
		}
		cout<<endl;
	}
    return 0;
}
