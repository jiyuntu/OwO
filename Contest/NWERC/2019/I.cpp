#include <bits/stdc++.h>
using namespace std;

int n;
int v[1000005];
int si;
int ti;
int ok;
int s;
int t;

int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	si = 1; ti = 1;

	// int cas = 0;
	int l = 1, now = 1;
	for (int i = 2; i <= n; ++i){
		if (!ok){
			if (v[i] != v[i-1]){
				l = now;
				now = i;
			}
			if (v[i] < v[l]){
					si = l;
					ok = 1;
			}
			
		}else if (ok == 1){
			if (v[i] > v[i-1]){
				ti = i-1;
				ok = 2;
			}
		}else{
			if (v[i] < v[i-1]){
				ok = 3;
				break;
			}
		}
	}
	
	if (ok == 3){
		cout << "impossible\n";
	}else{
		if (ok == 1){
			if (v[n] >= v[si - 1]){
				cout << si << " " << n << "\n";
			}else {
				cout << "impossible\n";
			}
		}else if (ok == 2){
			if (v[ti] >= v[si - 1] && v[si] <= v[ti + 1]){
				cout << si << " " << ti << "\n";
			}else {
				cout << "impossible\n";
			}
		}else{
			cout << si << " " << ti << endl;
		}
	}

}
