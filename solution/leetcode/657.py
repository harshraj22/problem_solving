# https://leetcode.com/problems/robot-return-to-origin/description/

class Solution:
    def judgeCircle(self, moves: str) -> bool:
        move_mapping = {
            'L': (-1, 0),
            'R': (1, 0),
            'U': (0, 1),
            'D': (0, -1)
        }

        position = [0, 0]
        for move in moves:
            x, y = move_mapping[move]
            position = [position[0] + x, position[1] + y]

        return position == [0, 0]
