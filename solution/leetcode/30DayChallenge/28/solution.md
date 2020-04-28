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

``` python
from collections import defaultdict
class FirstUnique:

    def __init__(self, nums: List[int]):
        self.que = nums
        self.freq = defaultdict(lambda: 0)
        for num in nums:
            self.freq[num] += 1

    def showFirstUnique(self) -> int:
        if len(self.que) == 0:
            return -1
        while len(self.que):
            if self.freq[self.que[0]] > 1:
                self.que.pop(0)
            else :
                return self.que[0]
        return -1
        

    def add(self, value: int) -> None:
        self.que.append(value)
        self.freq[value] += 1


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)

```