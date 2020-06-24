// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include <bits/stdc++.h>
using namespace std;

class FindMedian{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		double median; //Stores current median
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		void balanceHeaps(); //Method used by insertHeap
};

// Function to insert heap
void FindMedian::insertHeap(int &x) {
	if (this->max.empty())
		this->max.push(x);
	else if (this->min.empty())
		this->min.push(x);
	else if (x > this->max.top())
		this->min.push(x);
	else this->max.push(x);

	this->balanceHeaps();
}

// Function to balance heaps
void FindMedian::balanceHeaps() {
	int n = this->max.size(), m = this->min.size();
	while (abs(n-m) > 1) {
		if (n > m) {
			int cur = this->max.top();
			this->max.pop();
			this->min.push(cur);
		}
		else {
			int cur = this->min.top();
			this->min.pop();
			this->max.push(cur);
		}

		n = this->max.size();
		m = this->min.size();
	}
	
	while (n > 0 && m > 0 && this->max.top() > this->min.top()) {
	    int a = this->max.top(); this->max.pop();
	    int b = this->min.top(); this->min.pop();
	    this->max.push(b); this->min.push(a);
	}
}

// Function to return getMedian
double FindMedian::getMedian() {
    int n = this->max.size(), m = this->min.size();
    
    if (n > m)
        return this->max.top();
    else if (n < m)
        return this->min.top();
    return double(this->max.top() + this->min.top())/2;
}

int main(){
    int n, x;
	FindMedian Ans;
	cin >> n;
	for(int i = 1;i<= n; ++i) {
		cin >> x;
		Ans.insertHeap(x);
	    cout << floor(Ans.getMedian()) << endl;
	}
	return 0;
}  