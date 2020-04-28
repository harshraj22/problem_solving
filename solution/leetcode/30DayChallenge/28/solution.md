Problem:
   - [Day28](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/)

Tried:
   - A simple `Design` based problem
   - O(1) average per query (each number is added and removed one time in the deque)

``` c++
class FirstUnique {
    deque<int> numbers;
    unordered_map<int, int> freq;
public:
    FirstUnique(vector<int>& nums) {
        for (auto num: nums) {
            numbers.push_back(num);
            freq[num] += 1;
        }
    }
    
    int showFirstUnique() {
        if (numbers.empty())
            return -1;
        while (numbers.empty() == false) {
            if (freq[numbers.front()] == 1)
                return numbers.front();
            numbers.pop_front();
        }
        return -1;
    }
    
    void add(int value) {
        numbers.push_back(value);
        freq[value] += 1;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
```
