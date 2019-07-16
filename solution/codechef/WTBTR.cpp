#include<bits/stdc++.h>
using namespace std;

#define pi pair<long long int,long long int>
/* idea used :
For n-2 points, the road will be build passing through them. For two closest 
points(whose x intercepts are closest), road will be drawn passing through the mid point
of their x intercept.The claim is that this will provide the optimum distance of
required type because the distance between the lines (inclined at slope 1 or -1 and passing
through the two points) will be minimum amongst the all pair of points.

Note : y intercept can also be used instead of x intercept
*/

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
long long int test;
cin>>test;
while(test--){
    long long int i,j,k,n,m,flag=0;
    cin>>n;
    set<long long int> stc1,stc2;
    //to store the x intercepts of straight line with slope 1 or -1 passing through the given points
    vector<pi> v(n);//to store the given points
    long double ans=1e9+1;
    for(i=0;i<n;i++){
        long long int x,y;
        cin>>x>>y;
        v[i]=make_pair(x,y);
        // c1==x intercept of -ve slope, c2==x intercep of positive slope
        long long int c1=x+y,c2=x-y;
        if(stc1.find(c1)!=stc1.end() || stc2.find(c2)!=stc2.end())
            flag=1;//two elements found at 1 or -1 slope (having same x intercept)

        stc1.insert(c1);//for faster lookup use set (sorted container)
        stc2.insert(c2);
    }
    if(flag==1){
        cout<<0.000000<<"\n";
        continue;
    }
    for(i=0;i<n;i++){
        long long int x=v[i].first,y=v[i].second;
        long long int c1=x+y,c2=x-y;
        auto d1=stc1.upper_bound(c1);//greater than c1
        auto d2=stc2.upper_bound(c2);//greater than c2
        if(d1!=stc1.end()){
            long double mid=(*d1+c1)*1.0L/2;
            long double val=(abs(mid-x-y)*1.0L/sqrt(2))*sqrt(2);
            ans=min(ans,val);
        }
        if(d2!=stc2.end()){
            long double mid=(*d2+c2)*1.0L/2;
            long double val=(abs(mid-x+y)*1.0L/sqrt(2))*sqrt(2);
            ans=min(ans,val);
        }
    }

    cout<<fixed<<setprecision(7)<<ans<<"\n";
}
    return 0;
}





        
