#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define pb push_back
#define loop(n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

typedef struct elem {
	int l;
	int r;
	int min_;
	int val;
} elem;
int main(){
	unordered_set<int> s;
	s.insert(6);
	s.insert(3);
	s.insert(5);
	s.insert(2);
	for(auto x: s)cout<<x<<" ";cout<<endl;
	cout<<s.count(5)<<endl;
	
	return 0;
}