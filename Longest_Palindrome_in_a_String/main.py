#User function Template for python3

class Solution:
    def longestPalindrome(self, S):
        # code here
        if len(S) == 1:
            return S
        if len(S) == 2:
            return S if S[0] == S[1] else S[:1]
        low, high, start, max_length = 0, 0, 0, 1
        for i in range(len(S)):
            low, high = i - 1, i + 1
            while low >= 0 and S[low] == S[i]:
                low -= 1
            while high < len(S) and S[high] == S[i]:
                high += 1
            while low >= 0 and high < len(S) and S[low] == S[high]:
                low -= 1
                high += 1
            if max_length < high - low - 1:
                max_length = high - low - 1
                start = low + 1
        return S[start:start + max_length]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()

        ob = Solution()

        ans = ob.longestPalindrome(S)

        print(ans)
        print("~")
# } Driver Code Ends
