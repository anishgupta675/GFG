#User function Template for python3

class Solution:
    dp = []
    def longestPalinSubseq(self, s):
        # code here
        if len(s) == 1:
            return 1
        if len(s) == 2:
            return 2 if s[0] == s[1] else 1
        self.dp.extend([[0 for j in range(len(s))] for i in range(len(s))])
        for i in range(1, len(s) + 1):
            for j in range(len(s) - i + 1):
                k = i + j - 1
                if i == 1:
                    self.dp[j][k] = 1
                    continue
                if s[j] == s[k]:
                    self.dp[j][k] = self.dp[j + 1][k - 1] + 2
                else:
                    self.dp[j][k] = max(self.dp[j + 1][k], self.dp[j][k - 1])
        return self.dp[0][len(s) - 1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        ans = ob.longestPalinSubseq(s)
        print(ans)
        print("~")
# } Driver Code Ends
