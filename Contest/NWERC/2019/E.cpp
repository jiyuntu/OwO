    #include <bits/stdc++.h>
    using namespace std;
    #define maxn 200005
    #define inf 2001
     
    int t;
    int a[5],b[5];
     
    bool C(int x){
    	for(int i=0;i<4;i++)
    		b[i]=a[i];
    	b[4]=x;
    	sort(b,b+5);
    	int tot=0;
    	for(int i=1;i<4;i++) 
    		tot+=b[i];
    	if(tot<=t*3) 
    		return 1;
    	return 0;
    }
     
    int main(){
    	for(int i=0;i<5;i++){
    		string s;
    		a[i]=0;
    		cin>>s;
    		for(char c:s){
    			if(isdigit(c))
    				a[i]=a[i]*10+c-'0';
    		}
    	}
    	t=a[4];
    	int l=100,r=inf;
    	if(C(r)){
    		printf("infinite\n");
    		return 0;
    	}
    	if(!C(100)){
    		printf("impossible\n");
    		return 0;
    	}
    	while(r-l>1){
    		int m=(l+r)/2;
    		if(C(m)) l=m;
    		else r=m;
    	}
    	printf("%d.%02d\n",l/100,l%100);
    }
