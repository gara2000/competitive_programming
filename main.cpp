#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>
// #define endl '\n' 
#define mod 1000000007ll
#define pb push_back
#define all(v) v.begin(),v.end()
#define M_PI           3.14159265358979323846
#define prime6 347717
#define loop(start, end, step) for(int i=start; i<end; i+=step)
#define fi first
#define se second
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> plli;
 
const ll inf=ll(1e14)+5;
const ll mo=998244353;
//const int p=31;
 
template<typename T>
void repr(vector<T> a, int N)
{
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
 
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

vector<ii> links;
vector<int> diff[500001];
vector<ii> d;
int parent[500001];
int n, m;
void init(){
	for(int i=1;i<=n; i++){
		parent[i]  = i;
	}
}
int find(int x){
	if(x==parent[x])
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	parent[find(y)] = find(x);
}
void solve()
{
	cin>>n>>m;

	init();
	for(int i=0; i<m; i++){
		char c;
		int u, v;
		cin>>c>>u>>v;
		links.pb(make_pair(u, v));
		if(c=='S'){
			// s.pb(make_pair(u, v));
			Union(u, v);
		} 
		else {
			d.pb(make_pair(u, v));
			diff[u].pb(v);
			diff[v].pb(u);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<diff[i].size(); j++){
			Union(diff[i][j], diff[i][j-1]);
		}
	}
	bool test = true;
	for(auto p: d){
		// cout<<find(p.fi)<<", "<<find(p.se)<<endl;
		if(find(p.fi)==find(p.se))
		{
			// cout<<"found different: "<<p.fi<<" "<<p.se<<endl;
			test = false;
			break;
		}
	}
	if(!test)
		cout<<0<<endl;
	else
	{
		init();
		for(auto link: links){
			Union(link.fi, link.se);
		}
		string ans = "10";
		int curr = find(1);
		for(int i=2;i<=n;i++)
		{
			if(find(i)!=curr){
				curr = find(i);
				ans+= '0';
			}
			// cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
	// freopen("polygon.in", "r", stdi n);
 
    cout<<setprecision(20);
 
	int t=1;
	bool test = false;
	if(test)
		cin>>t;
	while(t--)
		solve();
 
	return 0;
}

