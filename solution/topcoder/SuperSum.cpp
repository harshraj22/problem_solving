// https://community.topcoder.com/stat?c=problem_statement&pm=10240
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class ShorterSuperSum{
public:
	ll table[15][15];
	ShorterSuperSum(){
		memset(table,0,sizeof(table));
		for(int i=0;i<15;i++){
			for(int j=1;j<15;j++){
				if(i==0)table[i][j]=j;
				else{
					ll sum=0;
					for(int var=1;var<=j;var++)
						sum+=table[i-1][var];
					table[i][j]=sum;
				}
			}
		}
	}

	int calculate(int k,int n){
		return table[k][n];
	}

};

// int main(){
// 	ShorterSuperSum alpha;
// 	int n,k;
// 	cin>>k>>n;
// 	cout<<alpha.calculate(k,n)<<"\n";

// 	return 0;
// }