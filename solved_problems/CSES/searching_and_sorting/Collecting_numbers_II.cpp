#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
using namespace std;

typedef complex<double> pt;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	int n, m;
	cin>>n>>m;
	vector<int> pos(n+1);
	vector<int> v(n+1);
	int ans = 0;
	loop(n){
		int x;
		cin>>x;
		if(!pos[x-1]){
			ans++;
		}
		pos[x]=i+1;
		v[i+1] = x;
	}
	loop(m){
		int a, b;
		cin>>a>>b;
		if(a==b){
			cout<<ans<<endl;
			continue;
		}
		if(a>b) swap(a,b);
		int x = v[a];
		int y = v[b];
		if(pos[x-1]>a&&pos[x-1]<b){
			ans--;
		}
		if(x<n&&pos[x+1]>a&&pos[x+1]<b){
			ans++;
		}
		if(pos[y-1]>a&&pos[y-1]<b){
			ans++;
		}
		if(pos[y+1]>a&&pos[y+1]<b){
			ans--;
		}
		if(x+1==y) ans++;
		if(x-1==y) ans--;
		swap(v[a], v[b]);
		swap(pos[x], pos[y]);
		cout<<ans<<endl;
	}
	
	return 0;
}