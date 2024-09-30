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
	map<int,int> vis;
	int ans = 0;
	int curr = 0;
	loop(n){
		int x;
		cin>>x;
		if(!vis[x]){
			curr++;
		}
		else{
			int diff = i+1-vis[x];
			if(diff<=curr){
				curr = diff;
			} else {
				curr++;
			}
		}
		ans = max(ans, curr);
		vis[x] = i+1;
	}
	
	cout<<ans<<endl;
	return 0;
}