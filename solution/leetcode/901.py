# https://leetcode.com/problems/online-stock-span/

class StockSpanner:

    def __init__(self):
        self.stack = []
        self.prices = []

    def next(self, price: int) -> int:
        self.prices.append(price)
        while self.stack and self.prices[self.stack[-1]] <= price:
            self.stack.pop()
        self.stack.append(len(self.prices) - 1)
        
        if len(self.stack) == 1:
            return len(self.prices) 
        return len(self.prices) - self.stack[-2] - 1


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)