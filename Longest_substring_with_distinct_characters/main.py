#User function Template for python3

class Solution:
    def longestUniqueSubstr(self, s):
        # code here
        l, r, hmap, max_size = 0, 0, {}, -1
        while r < len(s):
            if s[r] in hmap and hmap[s[r]] >= l:
                l = hmap[s[r]] + 1
            hmap[s[r]] = r
            size = r - l + 1
            max_size = max(max_size, size)
            r += 1
        return max_size

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        ans = solObj.longestUniqueSubstr(s)

        print(ans)

        print("~")
# } Driver Code Ends
