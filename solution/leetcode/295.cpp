// https://leetcode.com/problems/find-median-from-data-stream/
// Finding median of stream of data: log(n) per query using min & max heap

class MedianFinder {
	priority_queue<int> larger;
	priority_queue<int, vector<int>, greater<int>> smaller;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
		if (larger.empty())
			larger.push(num);
		else if (num > larger.top()) {
			smaller.push(num);
			if (smaller.size() == larger.size() + 2) {
				int cur = smaller.top(); 	smaller.pop();
				larger.push(cur);
			}
		}
		else {
			larger.push(num);
			if (larger.size() == smaller.size() + 2) {
				int cur = larger.top();  larger.pop();
				smaller.push(cur);
			}
		}
    }
    
    double findMedian() {
		if (smaller.size() == larger.size()) {
			int a = smaller.top(), b = larger.top();
			return (a+b)*1.0/2;
		}
		else if (smaller.size() > larger.size())
			return smaller.top();
		return larger.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


/* 
	My ideas for coverup problems:
	1. If all nums are in [1, 100], use simple array of frequencies and 
		record of total numbers encountered. For every findMedian query
		scan throught the array and find the answer.
	2. If 99% of nums are in [1, 100], the one which is not in range, can't
		be the median. So if it is less than 1, assume it to be 1, else 
		assume it to be 100 and repeat the follow up 1.

*/