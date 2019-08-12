// https://community.topcoder.com/stat?c=problem_statement&pm=13159

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class FibonacciDiv2{
public:
	long long int N;
	vector<long long int> v;

	FibonacciDiv2(){
		N = 1e6+2;
		v.resize(N,0);
		v[0]=0,v[1]=1;
		for(auto it=2;it<v.size();it++){
			v[it]=v[it-1]+v[it-2];
			if(v[it]>N){
				v.resize(it);
				break;
			}
		}
	}

	int find(int num){
		if(binary_search(v.begin(),v.end(),num))
			return 0;
		auto itr = lower_bound(v.begin(),v.end(),num);
		auto itl = itr-1;
		// cout<<(*itl)<<" "<<(*itr)<<"\n";
		return min(abs(*itl-num),abs(*itr-num));
	}
};

/*int main(){
	FibonacciDiv2 alpha;
	int n;	cin>>n;
	cout<<alpha.find(n)<<endl;

	return 0;
}*/