// https://www.spoj.com/problems/CLOPPAIR/
// nlogn solution

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pi pair<ll,ll>

vector<pi> input,inX,inY;
int n;

// sort based on x-values of input points
bool Xsort(pi x, pi y){
    if(x.first <= y.first)
        return true;
    return false;
}

// sort based on y-values of input points
bool Ysort(pi x, pi y){
    if(x.second < y.second)
        return true;
    return false;
}

// returns distance between two points on grid
double dist(pi x, pi y){
    return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}

// stores min dist, and pair of points having the stored distance
struct block{
    double d;
    pi a,b;
};

// splits the input array into two halves and recursively solve both of them
// joins the answer from both calls in O(n) making total complexity as O(nlogn)
block recur(vector<pi> x, vector<pi> y){
    if(x.size()==2){
        block var;
        var.d = dist(x[0],x[1]);
        var.a = x[0];
        var.b = x[1];
        return var;
    }

    // when dividing vector of 3 elements, one set might contain only
    // one element, return such a value, that is sure to be ignored
    else if(x.size()==1){
        block var;
        var.d = 1e8;
        var.a = x[0];
        var.b = x[0];
        return var;
    }

    int len = x.size();
    int mid = len/2;
    
    // basic divide and conquer step split points into 2 parts, 
    vector<pi> ypass,xpass(x.begin(),x.begin()+mid+1);
    vector<pi> ynext,xnext(x.begin()+mid+1,x.end());

    // preparing the array sorted according to y-coordinate to be
    // passed recursively. Think why we can't pass the first half
    // and second half as doing with array of sorted x-coordinate
    for(auto it:y){
        if(binary_search(x.begin(),x.begin()+mid+1,it))
            ypass.push_back(it);
        else 
            ynext.push_back(it);
    }
    
    block varpass = recur(xpass,ypass),varnext = recur(xnext,ynext);
    // divide input into 2 and recursively calculate for both parts
    
    // answer from left and right subhalves
    block curans;
    if(varpass.d < varnext.d)
        curans = varpass;
    else 
        curans = varnext;

    // check cases when one point lies in left part and other in right one
    // for each point, we need to check only 16 points before and after of it in the 
    // array sorted according to y-coordinate
    for(int j=0;j<xpass.size();j++){
        auto it = xpass[j];
        int index = lower_bound(y.begin(),y.end(),it) - y.begin();
        for(int i=max(0,index-15);i<min(index+16,(int)y.size());i++){
            // don't consider distance of point from itself.
            if(it==y[i])
                continue;
            double d = dist(it,y[i]);
            if(d < curans.d){
                curans.d = d;
                curans.a = it;
                curans.b = y[i];
            }
        }
    }

    return curans;
}

int main(){
    cin >> n;   map<pi,int> index;
    input.resize(n);
    for(int i=0;i<n;i++){
        cin >> input[i].first >> input[i].second;
        index[input[i]] = i;
    }

    inX = input;    inY = input;
    sort(inX.begin(),inX.end(),Xsort);
    sort(inY.begin(),inY.end(),Ysort);

    block ans = recur(inX,inY);
    if(index[ans.a] > index[ans.b])
        swap(ans.a, ans.b);

    cout << index[ans.a] << ' ' << index[ans.b] << ' ' << fixed << setprecision(6) << ans.d << '\n';

    return 0;
}