// http://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

class ZigZag{
public:
	int longestZigZag(vector<int> v){
		ll i,j,k,n=v.size(),m;
		vector<int> inc(n,1),dec(n,1);
		// inc[0]=dec[0]=1;
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(v[i]<v[j])
					dec[i]=max(inc[j]+1,dec[i]);
				else if(v[i]>v[j])
					inc[i]=max(dec[j]+1,inc[i]);
			}
		}
		k=*max_element(inc.begin(), inc.end());
		m=*max_element(dec.begin(), dec.end());
		return max(k,m);
	}
};
/*
int main(){
	ZigZag obj;
	vector<int> v={ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244};
	cout<<obj.longestZigZag(v)<<"\n";

	return 0;
}*/