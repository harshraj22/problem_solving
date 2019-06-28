#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 4*100000+1
ll lazy[MAX],st[MAX],arr[MAX];


void lconstruct(ll ss,ll se,ll si){
	if(ss==se){	// if leaf node
		st[si]=arr[ss];
		return ;
	}
	ll mid = ss+(se-ss)/2;
	lconstruct(ss,mid,2*si+1); lconstruct(mid+1,se,2*si+2);
	st[si]=st[2*si+1]+st[2*si+2];
}

void lupdate(ll qs,ll qe,ll ss,ll se,ll si,ll dif){
	if(lazy[si]){	// if lazy update is pending
		st[si]+=(lazy[si]*(se-ss+1));
		if(ss!=se){
			lazy[2*si+1]+=lazy[si];
			lazy[2*si+2]+=lazy[si];
		}
		lazy[si]=0;
	}
	if(ss>se || qe<ss || qs>se)	// if invalid
		return;
	if(ss>=qs && se<=qe){	//if node comes in update range compleately
		st[si]+=(dif*(se-ss+1));
		if(ss!=se){
			lazy[2*si+1]+=dif;
			lazy[2*si+2]+=dif;
		}
		return;
	}
	if(ss!=se){
		ll mid=ss+(se-ss)/2;	//if node range intersects update range
		lupdate(qs,qe,ss,mid,2*si+1,dif);
		lupdate(qs,qe,mid+1,se,2*si+2,dif);
	}
	st[si]=st[2*si+1]+st[2*si+2];
}
 
ll lget_sum(ll qs,ll qe,ll ss,ll se,ll si){
	if(lazy[si]){	//if lazy update is pending
		st[si]+=(lazy[si]*(se-ss+1));
		if(ss!=se){
			lazy[2*si+1]+=lazy[si];
			lazy[2*si+2]+=lazy[si];
		}
		lazy[si]=0;
	}
	if(ss>se || qs>se || qe<ss)	// if doesn't intersect
		return 0;
	if(ss>=qs && se<=qe)	//if node range compleately lies inside sum range
		return st[si];
	ll mid=ss+(se-ss)/2;	// if node range intersects sum range
	return lget_sum(qs,qe,ss,mid,2*si+1)+lget_sum(qs,qe,mid+1,se,2*si+2);

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);		cout.tie(0);
int test;
cin>>test;
while(test--){
	int i,j,k,n,m,c;
	cin>>n>>c;
	memset(st,0,sizeof(st));
	memset(lazy,0,sizeof(lazy));
	memset(arr,0,sizeof(arr));
	lconstruct(0,n-1,1);
	while(c--){
		cin>>m;
		if(m==0){
			int p,q,v;
			cin>>p>>q>>v;
			// lupdate(p,q,0,n-1,1,v);
			lupdate(p,q,1,n,1,v);
		}
		else {
			int p,q;
			cin>>p>>q;
			// cout<<lget_sum(p,q,0,n-1,1)<<"\n";
			cout<<lget_sum(p,q,1,n,1)<<"\n";
		}
		// for(i=0;i<=n;i++)
		// 	cout<<lazy[i]<<" \n"[i==n];
		// // for(i=0;i<=n;i++)
		// 	// cout<<"seg "<<st[i]<<" \n"[i==n];
	}
}
	return 0;
}
