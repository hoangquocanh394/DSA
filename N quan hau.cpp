#include<bits/stdc++.h>
using namespace std;
//duong cheo chinh used1[i-j+n]
//duong cheo phu used2[i+j-1]
int used[1000],used1[1000],used2[1000],mt[9][9];
vector<int> v;
int n=8;
int sum=0;
void Try(int i){
	for(int j=1;j<=n;j++){
		if(used[j]==0 && used1[i-j+n]==0 && used2[i+j-1]==0){
			sum+=mt[i][j];
			used[j]=1;
			used1[i-j+n]=1;
			used2[i+j-1]=1;
			if(i==n){
				v.push_back(sum);
			}else{
				Try(i+1);
			}
			sum-=mt[i][j];
			used[j]=0;
			used1[i-j+n]=0;
			used2[i+j-1]=0;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		v.clear();
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				cin >> mt[i][j];
			}
		}
		memset(used,0,sizeof(used));
		memset(used1,0,sizeof(used1));
		memset(used2,0,sizeof(used2));
		Try(1);
		cout<< *max_element(v.begin(),v.end()) << endl;
		
	}
	return 0;
}
