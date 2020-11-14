#include <bits/stdc++.h>
using namespace std;
#define maxn 200005

int n;
int f[maxn];
map<int,vector<int> >  mp;

int getf(int x){ return (f[x]==x)? x:f[x]=getf(f[x]); }
void unite(int x,int y){
	x=getf(x);
	y=getf(y);
	if(x!=y) f[y]=x;
}

struct E{
	int x,y;
	int num;
};
vector<E> ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		f[i]=i;
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			mp[x].push_back(i);
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		std::vector<int> &v=it->second;
		int sz=v.size();
		for(int j=0;j+1<sz;j++){
			int x=getf(v[j]);
			int y=getf(v[j+1]);
			if(x!=y){
				ans.push_back(E{v[j],v[j+1],it->first});
				f[y]=x;
			}
		}
	}

	if(ans.size()!=n-1) printf("impossible\n");
	else {
		for(E e:ans){
			printf("%d %d %d\n",e.x+1,e.y+1,e.num);
		}
	}

}
