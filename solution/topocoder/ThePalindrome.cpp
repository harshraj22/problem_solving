// https://community.topcoder.com/stat?c=problem_statement&pm=10182
// Method Recursion 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int v[51][51];
string str;

class ThePalindrome{
public:
	int find(string s){
		memset(v,-1,sizeof(v));
		int len = s.size();
		int l=0,h=len-1;
		str = s;
		return calc(l,h);
	}

	int calc(int i,int j){
		if(v[i][j]!=-1)return v[i][j];
		if(i>=j)return v[i][j]=0;
		else if(str[i]==str[j])
			return v[i][j]=min({this->calc(i+1,j-1),
					1+this->calc(i+1,j),1+this->calc(i,j-1)});
		else return v[i][j]=min(1+this->calc(i+1,j),
					1+this->calc(i,j-1));
	}
};


// int main(){
// 	ThePalindrome alpha;
// 	string s;
// 	cin>>s;
// 	cout<<s.size()+alpha.find(s)<<"\n";

// 	return 0;
// }