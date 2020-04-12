// https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        auto power = [](int x)->int{
            int step = 0;
            while (x != 1) {
                if (x % 2 == 0)
                    x /= 2;
                else 
                    x = 3*x + 1;
                step += 1;
            }
            return step;
        };
        
        auto cmp = [&](int i, int j)->bool{
            // returns if (i < j)
            if (power(i) != power(j))
                return power(i) < power(j);
            return i < j;
        };
        
        vector<int> numbers;
        for (int i = lo; i <= hi; i += 1) 
            numbers.push_back(i);
        sort(numbers.begin(), numbers.end(), cmp);
        
        return numbers[k-1];
    }
};