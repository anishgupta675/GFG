class Solution:
    def isWordExistUtil(self, mat: list, word: str, i: int, j: int, count: int) -> bool:
        if i < 0 or i == len(mat) or j < 0 or j == len(mat[i]):
            return False
        if not count:
            return True
        if mat[i][j] != word[len(word) - count]:
            return False
        return self.isWordExistUtil(mat, word, i - 1, j, count - 1) or self.isWordExistUtil(mat, word, i, j - 1, count - 1) or self.isWordExistUtil(mat, word, i + 1, j, count - 1) or self.isWordExistUtil(mat, word, i, j + 1, count - 1)
	def isWordExist(self, mat, word):
		#Code here
		for i in range(len(mat)):
		    for j in range(len(mat[i])):
		        if mat[i][j] == word[0]:
		            if self.isWordExistUtil(mat, word, i, j, len(word)):
		                return True
		return False

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for tt in range(T):
        n = int(input())
        m = int(input())
        mat = []
        for i in range(n):
            a = list(input().strip().split())
            b = []
            for j in range(m):
                b.append(a[j][0])
            mat.append(b)
        word = input().strip()
        obj = Solution()
        ans = obj.isWordExist(mat, word)
        if ans:
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends
