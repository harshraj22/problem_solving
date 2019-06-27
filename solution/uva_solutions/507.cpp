// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=448
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define pii pair<int,pi>

int main(){
ios_base::sync_with_stdio(false);
int test;
cin>>test;
for(int iit=1;iit<=test;iit++){
	int i,j,k,n,m;
	cin>>n;	n--;
	vector<int> v(n);
	vector<pii> sm(n);
	for(i=0;i<n;i++)
		cin>>v[i];

	for(i=0;i<n;i++){
		int var=0,max_so_far=0;
		sm[i].second.second=-i;//min 'i' => max -i , this will help us in sorting
		sm[i].second.first=0;	sm[i].first=0;
//while comparision of pair, first element is compared, in case of tie comparision goes to second element
		for(j=i;j<n;j++){
			var+=v[j];
			if(var<0)
				break;
			else if(var>=max_so_far){
				max_so_far=var;
				sm[i].first=var;
				sm[i].second.first=j-i;
			}
		}
	}
	sort(sm.begin(), sm.end());
	//first priority is sum,second priority is j-i , third priority is i (min i)
	if(sm[n-1].first<=0)
		cout<<"Route "<<iit<<" has no nice parts\n";
	else {
		cout<<"The nicest part of route "<<iit<<" is between stops ";
		cout<<-sm[n-1].second.second+1<<" and "<<2-sm[n-1].second.second+sm[n-1].second.first<<"\n";
	}
}
	return 0;
}