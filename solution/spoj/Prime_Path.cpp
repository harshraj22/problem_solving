#include<bits/stdc++.h>
using namespace std;


int main(){
int test,i,j;
cin>>test;
int arr[10002]={0};
for(i=2;i<10002;i++){
if(!arr[i]){
    for(j=2*i;j<10002;j=j+i){
        arr[j]=1;
    }
  }
}


while(test--){
 int n,m,a,b,c=0,k;
string num1,num2;
cin>>num1>>num2;
if(num1==num2){
    cout<<"0\n";
    continue;
}
int arr1[10002]={0};
pair<string,int> pi;
char ch;
queue<pair<string ,int> > q;
q.push(make_pair(num1,0));
while(q.size() && num1!=num2){
    pi=q.front();
    q.pop();
    num1=pi.first;
    c=stoi(num1);
    arr1[c]=1;

//    cout<<num1<<endl;

    c=pi.second;
    for(i=0;i<4;i++){
        num1=pi.first;
        ch=num1[i];
        j=ch-'0';

        for(k=0;k<10;k++){
            if(j==k)
                continue;
        num1[i]=k+'0';
        b=stoi(num1);
        if(!arr[b] && b>999 && !arr1[b]){
         //       arr[b]=1;   // not visiting the prime number again
            q.push(make_pair(num1,c+1));
        }
      }

    }
    num1=pi.first;
}
 if(num1==num2)
        cout<<pi.second<<"\n";
 else cout<<"-1\n";

}


return 0;
}
