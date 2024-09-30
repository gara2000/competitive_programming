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
	int n;;
	cin>>n;
	vector<int> v(2*n+1);
	loop(n+1) v[i] = i;
	int curr = 1;
	int tot = n;
	while(tot){
		if(curr%2){
			v[curr+tot] = v[curr];
		} else {
			cout<<v[curr]<<" ";
			tot--;
		}
		curr++;
	}
	cout<<endl;
	return 0;
}