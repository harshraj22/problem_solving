# https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/


from collections import deque

class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        self.nodes = dict()
        x, y = start[0], start[1]
        toVisit = deque([Node(x, y, 0, grid[x][y])])

        # perform a dfs
        while toVisit:
            curNode = toVisit.popleft()

            # check if curNode updates the self.nodes if not, already a better solution
            # was found, so continue
            if not self.should_insert(curNode):
                continue
            x, y = curNode.x, curNode.y
            self.nodes[(x, y)] = curNode

            # for all it's neighbours, check if any of them needs to be visited again
            for nx, ny in self.get_neighbours(x, y, grid):
                neighbouringNode = Node(nx, ny, curNode.dist + 1, grid[nx][ny])
                # if so, append right to the queue
                if self.should_insert(neighbouringNode):
                    toVisit.append(neighbouringNode)

        # finally, filter and sort the self.nodes.values() and return ans
        filtered_list = [node for node in self.nodes.values() if pricing[0] <= node.price <= pricing[1]]
        filtered_list.sort(key=lambda node: (node.dist, node.price, node.x, node.y))

        return [(node.x, node.y) for node in filtered_list[:k]]
    
    def get_neighbours(self, x, y, grid):
        # returns an iterator over all neighbouring points
        if self.is_valid(x-1, y, grid) and grid[x-1][y] != 0:
            yield x-1, y

        if self.is_valid(x+1, y, grid) and grid[x+1][y] != 0:
            yield x+1, y

        if self.is_valid(x, y-1, grid) and grid[x][y-1] != 0:
            yield x, y-1
        
        if self.is_valid(x, y+1, grid) and grid[x][y+1] != 0:
            yield x, y+1

    def is_valid(self, x, y, grid):
        n, m = len(grid), len(grid[0])
        return 0 <= x < n and 0 <= y < m

    def should_insert(self, node) -> bool:
        x, y = node.x, node.y
        if (x, y) not in self.nodes:
            return True
        elif self.nodes[(x, y)].dist > node.dist:
            return True
        return False



class Node:
    def __init__(self, x, y, dist, price):
        self.x = x
        self.y = y
        self.dist = dist
        self.price = price

    def update_dist(self, dist):
        self.dist = dist
