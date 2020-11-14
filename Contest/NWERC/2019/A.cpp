#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll w;
int score[300005];
int n;
double output[300005];

struct Treap{
  int pri,sz;
  pii cur;
  ll val, add;
  Treap *l, *r;
  Treap(int id){
  	sz=1;
  	cur = pii(0,id);
    val = w;
    pri = rand();
    l = r = NULL;
    add = 0ll;
  }
};
void push(Treap *a){
  if (a->add!=0){
  	if(a->l) a->l->val+=a->add, a->l->add+=a->add;
  	if(a->r) a->r->val+=a->add, a->r->add+=a->add;
  	a->add=0;
  }
}
int Size(Treap *a) { return a ? a->sz : 0; }
void pull(Treap *a){
  a->sz = Size(a->l) + Size(a->r) + 1;
}
Treap *merge(Treap *a, Treap *b){ 
//a的val全小於b的val
  if (!a || !b)
    return a ? a : b;
  if (a->pri > b->pri){
    push(a);
    a->r = merge(a->r, b);
    pull(a);
    return a;
  }
  else{
    push(b);
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}
void split(Treap *t, pii k, Treap *&a, Treap *&b){
  if (!t){
    a = b = NULL;
    return;
  }
  push(t);
  if (t->cur <= k){
    a = t;
    split(t->r, k, a->r, b);
    pull(a);
  }
  else{
    b = t;
    split(t->l, k, a, b->l);
    pull(b);
  }
};

Treap* root=NULL;

void debug(Treap* u)
{
	if(!u) return;
	//push(u);
	printf("%d %d %lld\n",u->cur.first,u->cur.second,u->val);
	debug(u->l);
	debug(u->r);
	//pull(u);
}

void update(int x,int curw)
{
	//printf("%d %d\n",x,curw);
	int ori=score[x], minus=0;
	score[x]++;
	Treap *tl,*target,*tr;
	split(root,pii(score[x],n+1),tl,tr);
	minus=Size(tr);
	//printf("%d\n",minus);
	root=merge(tl,tr);
	tl=tr=NULL;
	split(root,pii(ori,n+1),tl,tr);
	minus=Size(tr)-minus;
	root=merge(tl,tr);
	//puts("Yes");
	tl=target=tr=NULL;
	split(root,pii(ori,x),target,tr);
	split(target,pii(ori,x-1),tl,target);
	target->cur=pii(score[x],x);
	if(minus) target->val-=1ll*minus*(w-curw);
	root=merge(tl,tr);
	tl=tr=NULL;
	split(root,target->cur,tl,tr);
	//puts("yes");
	root=merge(merge(tl,target),tr);
	tl=target=tr=NULL;
	//debug(root);
	//printf("n=%d ori=%d\n",n,ori);
	split(root,pii(ori,n+1),target,tr);
	split(target,pii(ori,0),tl,target);
	//puts("tl:");
	//debug(tl);
	//puts("");
	//puts("tr");
	//debug(tr);
	//puts("");
	if(target){
		//puts("yes");
		target->val+=w-curw;
		target->add+=w-curw;
	}
	root=merge(merge(tl,target),tr);
	/*puts("root:");
	debug(root);
	puts("");*/
}
void dfs(Treap* u)
{
	if(!u) return;
	push(u);
	output[u->cur.second]=1.0*u->val/w;
	dfs(u->l);
	dfs(u->r);
	pull(u);
}

int main()
{
	scanf("%d%lld",&n,&w);
	for(int i=1;i<=n;i++){
		root=merge(root,new Treap(i));
	}
	for(int i=1;i<=n;i++) score[i]=0;
	for(int i=0;i<w;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			update(x,i);			
		}
	}
	/*puts("root:");
	debug(root);
	puts("");*/
	dfs(root);
	for(int i=1;i<=n;i++) printf("%.10lf\n",output[i]);
}
