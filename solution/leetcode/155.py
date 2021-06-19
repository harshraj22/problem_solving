class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []
        self.arrival_time = 0

    def push(self, val: int) -> None:
        self.stack.append((val, self.arrival_time))
        if not self.min_stack or val < self.min_stack[-1][0]:
            self.min_stack.append((val, self.arrival_time))
        self.arrival_time = self.arrival_time + 1

    def pop(self) -> None:
        # print(self.stack)
        val, time = self.stack[-1]
        self.stack.pop()
        if self.min_stack and self.min_stack[-1] == (val, time):
            self.min_stack.pop()
        

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.min_stack[-1][0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
