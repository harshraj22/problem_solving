// https://leetcode.com/problems/flatten-nested-list-iterator/
// The worst problem that I have seen so far, lacks proper explaination !

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 *
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    int row, col,  n, remover = INT_MIN;
    vector<NestedInteger> nums;
    stack<NestedInteger> stk;
    deque<int> orgstk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        row = col = 0;
        nums = nestedList;   
        n = nums.size();
        if (n > 0)
            stk.push(nums[0]);
        
        while(col != remover) {
            col = this->nextInt();
            if (col == remover)
                break;
            orgstk.push_back(col);
        }
    }
    
    int nextInt() {
        if (row >= n-1 && stk.empty())
            return remover;
        
        if (stk.empty()) {
            row += 1;
            stk.push(nums[row]);
        }
        
        NestedInteger cur = stk.top();  stk.pop();

        if (cur.isInteger()) 
            return cur.getInteger();
        
        vector<NestedInteger> nest = cur.getList();
        // if (nest.size() == 0)
        //     return this->nextInt();
        
        reverse(nest.begin(), nest.end());
        for (auto list: nest) 
            stk.push(list);
        
        return this->nextInt();
    }
    
    int next() {
        int number = orgstk.front();
        orgstk.pop_front();  return number;
    }
    
    bool hasNext() {
        // return false;
        return !orgstk.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */