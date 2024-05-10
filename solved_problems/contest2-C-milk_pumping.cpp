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

typedef struct entry{
	int a;
	int b;
	int c;
	int f;
} entry;

vector<entry> v;

vector<plli> adj[1001];
vector<ll> dist(1001);

void solve()
{
	int n, m;
	cin>>n>>m;
	int max_f = 0;
	for(int i=0;i<m; i++){
		entry e;
		cin>>e.a>>e.b>>e.c>>e.f;
		v.pb(e);
		max_f = max(max_f, e.f);
	}
	ll INF = int(1e6)+1;
	double ans = 0.;

	for(int f=0; f<=max_f; f++)
	{
		for(auto e: v){
			if(e.f>=f)
			{
				adj[e.a].pb({e.b, e.c});
				adj[e.b].pb({e.a, e.c});
			}
		}

		// Initialisation
		dist[1] = 0;
		for(int i=2;i<=n;i++)
			dist[i] = INF;

		// Dijkstra
		priority_queue<plli, vector<plli>, greater<plli>> pq;
		pq.push(make_pair(dist[1], 1));
		while(!pq.empty()){ 
			auto [node_dist, node] = pq.top();
			pq.pop();
			if(dist[node]==node_dist){ // Lazy approach, if the distance has already changed then no need to enter
				for(auto u: adj[node]){
					if(node_dist+u.se<dist[u.fi]){
						dist[u.fi] = node_dist + u.se;
						pq.push(make_pair(dist[u.fi], u.fi));
					}
				}
			}
		}
		if(dist[n]<INF){
			double curr_ans = double(f)/double(dist[n]);
			curr_ans*=1e6;
			ans = max(ans, curr_ans);
		}

		// Clean the vectors
		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
		}
	}

	cout<<(ll)ans<<endl;
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

