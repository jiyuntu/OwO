#include <bits/stdc++.h>
using namespace std;
#define maxn 505

int n,k;
long double f[maxn],p[maxn],o[maxn];
long double ans[maxn];

int main(){
	cin>>n>>k;
	k=n-k;
	for(int i=0;i<n;i++) 
		cin>>o[i];
	for(int i=1;i<=n;i++) 
		f[i]=f[i-1]+log(i);
	long double mi=f[n]-f[n-k]-f[k];
	for(int x=0;x<n;x++){
		if(k<x) 
			continue;
		p[x]=exp(f[n-1-x]-f[k-x]-f[n-1-k]-mi);
	}
	for(int i=0;i<n;i++){
		for(int x=0;x<n;x++){
			int to=(i+x)%n;
			ans[to]+=o[i]*p[x];
		}
	}
	for(int i=0;i<n;i++) 
		cout<<fixed<<setprecision(15)<<ans[i]<<" ";
	cout<<"\n";
}
