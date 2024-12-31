 #User function Template for python3
 
class Solution:
    
    # arr[] : the input array
    
    #Function to return length of longest subsequence of consecutive integers.
    def longestConsecutive(self,arr):
        #code here
        max_count, hset = 1, set()
        for i in range(len(arr)):
            hset.add(arr[i])
        for i in range(len(arr)):
            if arr[i] - 1 in hset:
                continue
            count, temp = 1, arr[i]
            while temp + 1 in hset:
                count += 1
                temp += 1
            max_count = max(count, max_count)
        return max_count

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        print(Solution().longestConsecutive(a))
        print("~")
# } Driver Code Ends
