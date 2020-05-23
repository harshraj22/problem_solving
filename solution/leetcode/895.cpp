// https://leetcode.com/problems/maximum-frequency-stack/
// Another good design based problem

class FreqStack {
    // for each number, stores the indexes it has occured on
    map<int, stack<int>> index;
    int Count;
    // pair of <freq, last index>
    set<pair<int, int>> best;
    vector<int> nums;
public:
    FreqStack() {
        Count = 0; best.clear();
        index.clear(); nums.clear();
        nums.resize(100000);
    }
    
    void push(int x) {
        if (index[x].size())
            best.erase({index[x].size(), index[x].top()});
        index[x].push(Count);
        best.insert({index[x].size(), Count});
        nums[Count] = x; Count += 1;
    }
    
    int pop() {
        pair<int, int> cur = *best.rbegin();
        best.erase(cur);
        int num = nums[cur.second];
        index[num].pop();
        if (index[num].empty())
            index.erase(num);
        else 
            best.insert({index[num].size(), index[num].top()});
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */