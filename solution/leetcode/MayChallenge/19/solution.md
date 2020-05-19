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