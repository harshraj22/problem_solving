// https://community.topcoder.com/stat?c=problem_statement&pm=14361
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Arrfix{
public:
	int mindiff(vector<int> A,vector<int> B,vector<int> F){
		map<int,int> _mp;
		int len = F.size();
		for(auto i=0;i<len;i++)_mp[F[i]]++;

		int lim=A.size(),cn=0;
		for(int i=0;i<lim;i++){
			if(A[i]!=B[i]){
				if(_mp[B[i]]>0)_mp[B[i]]--;
				else cn++;
			}
		}
		return cn;
	}
};

// int main(){
// 	Arrfix alpha;
// 	vector<int> A= {1,2,3};
// 	vector<int> B= {3,2,1};
// 	vector<int> F= {};
// 	cout<<alpha.mindiff(A,B,F)<<"\n";

// 	return 0;
// }