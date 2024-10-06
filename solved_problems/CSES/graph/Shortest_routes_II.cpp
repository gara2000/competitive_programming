#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define loopi(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
using namespace std;

typedef long long ll;

ll dis[501][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, m, q;
	cin>>n>>m>>q;
	loopi(n){
		loopj(n){
			dis[i+1][j+1] = ll(1e17);
		}
		dis[i+1][i+1] = 0;
	}
	loop(m){
		int u, v;
		ll c;
		cin>>u>>v>>c;
		dis[u][v] = min(dis[u][v], c);
		dis[v][u] = min(dis[v][u], c);
	}
	for(int pivot=1; pivot<=n;pivot++){
		for(int start=1; start<=n;start++){
			for(int end=1; end<=n;end++){
				dis[start][end] = min(dis[start][end], 
								dis[start][pivot]+dis[pivot][end]);
			}
		}
	}
	while(q--){
		int a, b;
		cin>>a>>b;
		if(dis[a][b]<ll(1e17))
			cout<<dis[a][b]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}