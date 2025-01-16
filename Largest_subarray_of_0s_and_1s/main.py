class Solution:
    def maxLen(self, arr):
        # code here
        ans, hmap, p0, p1 = 0, {}, 0, 0
        hmap[0] = -1
        for i in range(len(arr)):
            if not arr[i]:
                p0 += 1
            else:
                p1 += 1
            if p0 - p1 in hmap:
                ans = max(ans, i - hmap[p0 - p1])
            else:
                hmap[p0 - p1] = i
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    a = list(map(int, input().split()))
    s = Solution().maxLen(a)
    print(s)

# } Driver Code Ends
