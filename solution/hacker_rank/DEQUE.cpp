// https://www.hackerrank.com/challenges/deque-stl/problem

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq;
    // dq.front stores the index of max value in the given range.
    for(int i=0;i<k;i++){
        if(dq.empty()==true){
            dq.push_back(i);
            continue;
        }
        else{
            while(dq.empty()==false && arr[dq.back()] < arr[i])
                dq.pop_back();
            // if(dq.empty()==true)
                dq.push_back(i);
        }
    }
    cout << arr[dq.front()] << " ";
    for(int i=k;i<n;i++){
        while(dq.empty()==false && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
        while(dq.front() <= i-k)
            dq.pop_front();
        cout << arr[dq.front()] << " ";
        // cout << "with size " << dq.size() << " : ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

