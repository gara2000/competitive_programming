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
	vector<ll> a(n);
	loop(n) cin>>a[i];
	ll sum = 0;
	sort(all(a));
	ll target = 1;
	loop(n){
		if(a[i]>target)
			break;
		target += a[i];
	}
	cout<<target<<endl;
	
	return 0;
}