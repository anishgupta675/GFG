# User function Template for python3

class Solution:
    def longestSubarray(self, arr, k):  
        # code here
        res, curr, hmap = 0, 0, {}
        for i in range(len(arr)):
            curr += arr[i]
            if curr == k:
                res = i + 1
            elif curr - k in hmap:
                res = max(res, i - hmap[curr - k])
            if curr not in hmap:
                hmap[curr] = i
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        print(ob.longestSubarray(arr, k))
        tc -= 1
        print("~")
# } Driver Code Ends
