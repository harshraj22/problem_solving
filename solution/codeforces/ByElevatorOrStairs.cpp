// https://codeforces.com/problemset/problem/1249/E

// Basic DP
// Time: O(n) space: O(n), can be made in O(1) space as 
//      dp[..][i] always requires dp[..][i-1] and not any previous values
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int n, c;   cin >> n >> c;
    vector<ll> v(n+1), b(n+1);
    vector<vector<ll>> dp(2, vector<ll> (n+1, 0));
    for (int i = 1; i < n; i += 1)
        cin >> v[i];
    for (int i = 1; i < n; i += 1)
        cin >> b[i];

    // dp[0][i] : using stairs
    // dp[1][i] : using elevators
    dp[1][1] = c;
    
    for (int i = 2; i <= n; i += 1) {
        dp[0][i] = v[i-1] + min(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = b[i-1] + min(dp[1][i-1], c + dp[0][i-1]);
    }

    for (int i = 1; i <= n; i += 1)
        cout << min(dp[0][i], dp[1][i]) << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}


/* 
# Template: https://codeforces.com/profile/kabeer27
from __future__ import division, print_function

def solve():
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    dp = [[None for _ in range(n)] for __ in range(2)]
    # dp[0][i] : stairs
    # dp[1][i] : elevators
    dp[0][0], dp[1][0] = 0, c
    for i in range(1, n):
        dp[0][i] = a[i-1] + min(dp[0][i-1], dp[1][i-1])
        dp[1][i] = b[i-1] + min(dp[0][i-1]+c, dp[1][i-1])
    
    for i in range(n):
        print(min(dp[0][i], dp[1][i]), end=' ')
    print()

def main():
    tests = 1
    # tests = int(input().strip())
    for test in range(tests):
        solve() 

######## Python 2 and 3 footer by Pajenegod and c1729

# Note because cf runs old PyPy3 version which doesn't have the sped up
# unicode strings, PyPy3 strings will many times be slower than pypy2.
# There is a way to get around this by using binary strings in PyPy3
# but its syntax is different which makes it kind of a mess to use.

# So on cf, use PyPy2 for best string performance.

py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import IOBase, BytesIO

BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)

class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

# Cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = '\n'

# Read all remaining integers in stdin, type is given by optional argument, this is fast
def readnumbers(zero = 0):
    conv = ord if py2 else lambda x:x
    A = []; numb = zero; sign = 1; i = 0; s = sys.stdin.buffer.read()
    try:
        while True:
            if s[i] >= b'0' [0]:
                numb = 10 * numb + conv(s[i]) - 48
            elif s[i] == b'-' [0]: sign = -1
            elif s[i] != b'\r' [0]:
                A.append(sign*numb)
                numb = zero; sign = 1
            i += 1
    except:pass
    if s and s[-1] >= b'0' [0]:
        A.append(sign*numb)
    return A

if __name__== "__main__":
  main()

*/