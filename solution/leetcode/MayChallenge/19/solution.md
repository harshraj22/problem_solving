Problem: 
   - [Day 19](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/)

Tried: 
   - Used `segment tree`
   - Obiously, it was easier than the standard efficient method 

```c++
class StockSpanner {
    vector<int> seg;
    int n, index;

    void update(int node, int sl, int sr, int index, int price) {
        if (sl == sr) {
            seg[node] = price;
            return;
        }

        int mid = (sl + sr)/2;
        if (index <= mid)
            update(node*2, sl, mid, index, price);
        else 
            update(node*2+1, mid+1, sr, index, price);
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }

    int query(int node, int sl, int sr, int ql, int qr) {
        if (qr < sl || ql > sr)
            return 0;
        else if (ql <= sl && qr >= sr)
            return seg[node];
        int mid = (sl + sr)/2;
        return max(
            query(node*2, sl, mid, ql, qr),
            query(node*2+1, mid+1, sr, ql, qr)
        );
    }

public:
    StockSpanner() {
        n = 1e5 + 2;    index = 0;
        seg.resize(4*n+5);        
    }
    
    int next(int price) {
        index += 1;
        // find largest
        int past = query(1, 1, n, price+1, n);
        int ans = index - past;
        update(1, 1, n, price, index);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```


```python
class StockSpanner:
    # remember recursion limit in python is generally set to 1000
    import sys
    sys.setrecursionlimit(10**6)

    def __init__(self):
        self.index = 0
        self.n = 10**5 + 5
        self.seg = [0 for _ in range(4*self.n+5)]        

    def query(self, node, sl, sr, ql, qr):
        if ql > sr or qr < sl:
            return 0
        elif ql <= sl and qr >= sr:
            return self.seg[node]
        mid = (sl + sr)//2
        return max(self.query(node*2, sl, mid, ql, qr), self.query(node*2+1, mid+1, sr, ql, qr))

    def update(self, node, sl, sr, index, price):
        if sl == sr:
            self.seg[node] = price
            return None
        mid = (sl + sr)//2
        if index <= mid:
            self.update(node*2, sl, mid, index, price)
        else:
            self.update(node*2+1, mid+1, sr, index, price)
        self.seg[node] = max(self.seg[node*2], self.seg[node*2+1])
        return None

    def next(self, price: int) -> int:
        self.index += 1
        past = self.query(1, 1, self.n, price+1, self.n)
        ans = self.index - past
        self.update(1, 1, self.n, price, self.index)
        return ans
        
# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```