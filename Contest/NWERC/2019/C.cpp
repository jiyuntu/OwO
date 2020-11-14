#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef pair<int,int> pii;

int main()
{
	int n;
	scanf("%d",&n);
	vector<pii> vec(n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&vec[i].l,&vec[i].r);
	}
	int p;
	scanf("%d",&p);
	unordered_set<int> place;
	vector<int> cnt(n,0);
	for(int i=0;i<p;i++){
		int xx;
		scanf("%d",&xx);
		place.insert(xx);
		auto it=lower_bound(vec.begin(),vec.end(),pii(xx,xx));
		if(it!=vec.end() && it->l <= xx && xx<=it->r) cnt[it-vec.begin()]++;
		if(it!=vec.begin()){
			it--;
			if(it->l<=xx && xx<=it->r) cnt[it-vec.begin()]++;
		}  
	}
	/*for(int i=0;i<n;i++) printf("%d ",cnt[i]);
	puts("");*/
	int suc=1, ans=0;
	vector<int> output;
	for(int i=0;i<n;i++){
		if(cnt[i]>2) {suc=0; break;}
		while(cnt[i]<2){
			for(int j=vec[i].r;j>=vec[i].l;j--){
				if(place.find(j)==place.end()){
					if(i<n-1 && vec[i+1].l<=j && vec[i+1].r>=j){
						if(cnt[i+1]>=2) continue;
						else cnt[i+1]++;
					}
					place.insert(j);
					output.push_back(j);
					cnt[i]++;
					ans++;
					break;
				}
			}
		}
	}
	if(!suc) puts("impossible");
	else{
		printf("%d\n",ans);
		for(int v: output) printf("%d ",v);
		printf("\n");
	}
}
