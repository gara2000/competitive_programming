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

vector<int> adj[40001];
vector<int> vis(40001);
vector<ll> dis1(40001);
vector<ll> dis2(40001);
vector<ll> disn(40001);
int n, m;

void init_dis(){
	for(int i=1;i<=n;i++){
		dis1[i] = ll(1e12);
		dis2[i] = ll(1e12);
		disn[i] = ll(1e12);
	}
}

void init(){
	for(int i=1;i<=n;i++)
		vis[i] = 0;
}

void fill_dis(int s){
	vector<ll>& dis = (s==1)? dis1 : ((s==2)? dis2 : disn);
	init();
	queue<pair<int, ll>> q;
	dis[s] = 0ll;
	vis[s] = 1;
	q.push(make_pair(s, dis[s]));
	while(!q.empty()){
		auto [curr, prev_d] = q.front();
		q.pop();
		for(auto v: adj[curr]){
			if(!vis[v])
			{
				vis[v] = 1;
				dis[v] = prev_d+1;
				// cout<<v<<" "<<dis[v]<<endl;
				q.push(make_pair(v, dis[v]));
			}
		}
	}
}

void solve()
{
	ll b, e, p;
	cin>>b>>e>>p>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll ans = ll(1e12);

	init_dis();

	fill_dis(1);
	fill_dis(2);
	fill_dis(n);

	// mp is the meeting point between the two friends
	for(int mp=1; mp<=n; mp++){
		ll d1 = dis1[mp];
		ll d2 = dis2[mp];
		ll df = disn[mp];

		ans = min(ans, d1*b+d2*e+df*p);
	}
	cout<<ans<<endl;
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

