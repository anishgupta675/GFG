#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3

class Solution:
    def longestStringChain(self, words):
        # Code here
        words.sort(key = len)
        word_dict = {}
        for word in words:
            word_dict[word] = 1
            for i in range(len(word)):
                predecessor = word[:i]+word[i + 1:]
                if predecessor in word_dict:
                    word_dict[word] = max(word_dict[word], word_dict[predecessor] + 1)
        return max(word_dict.values())


#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input())
    for _ in range (t):
        words = input().split()
        ob = Solution()
        res = ob.longestStringChain(words)
        print(res)
        print("~")
# } Driver Code Ends
