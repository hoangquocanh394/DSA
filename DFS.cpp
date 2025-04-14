#include<bits/stdc++.h>
using namespace std;
int v,e;
int visited[1001];
vector<int> a[1001];
void solve(int u){
	cout << u << " ";
	visited[u]=1;
	for(int i:a[u]){
		if(visited[i]==0){
			solve(i);
			
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> v >> e >> k;
		for(int i=0;i<e;i++){
			int x,y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		} 
		memset(visited,0,sizeof(visited));
		solve(k);
	}
	return 0;
}
