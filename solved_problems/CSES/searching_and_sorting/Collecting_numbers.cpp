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
	int n;
	cin>>n;
	vector<int> vis(n+1);
	int ans = 0;
	loop(n){
		int x;
		cin>>x;
		if(!vis[x-1]){
			ans++;
		}
		vis[x]=1;
	}
	cout<<ans<<endl;
	
	return 0;
}