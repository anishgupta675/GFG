#User function Template for python3


class Solution:

    def aggressiveCows(self, stalls, k):
        stalls.sort()
        low, high, ans = stalls[0], stalls[-1], 0
        while low <= high:
            mid, cow, prev = (low + high) >> 1, 1, stalls[0]
            for i in range(1, len(stalls)):
                if stalls[i] - prev > mid:
                    cow += 1
                    prev = stalls[i]
                    if k == cow:
                        break
            if k == cow:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.aggressiveCows(A, D)
        print(ans)
        print("~")
# } Driver Code Ends
