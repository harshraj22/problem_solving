# https://www.codechef.com/LRNDSA04/problems/QHOUSE
# An interesting binary search problem
import sys

def getCoordinate(heightFromAxis=0, horizontal=True):
    '''
        Binary Searches the corresponding coordinate
        @param:
            horizontal: boolean value depicting if search is to be expanded
                horizontally, ie. y is fixed 
            heightFromAxis: the hight perpendicular to expanding axis
        @returns:
            the corresponding coordinate in the specified axis
    '''
    low, high = 0, 1000
    while low < high:
        mid = (low + high + 1)//2
        if horizontal:
            print(f'? {mid} {heightFromAxis}')
        else:
            print(f'? {heightFromAxis} {mid}')
        sys.stdout.flush()
        response = input()
        if response == 'YES':
            low = mid 
        else:
            high = mid-1

    return low


def solve():
    x, y = getCoordinate(), getCoordinate(horizontal=False)
    side, height = 2*x, y - 2*x
    base = 2*getCoordinate(side)
    print('!', side*side + (base*height)//2)

def main():
    solve()

if __name__ == '__main__':
    main()