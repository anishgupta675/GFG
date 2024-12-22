#User function Template for python3
class Solution:
    def checkRow(self, row: list, x: int):
        if row[0] <= x and row[-1] >= x:
            return 0
        if row[0] > x:
            return 1
        return -1
    def searchColumn(self, row: list, low: int, high: int, x: int):
        if low > high:
            return False
        mid = (low + high) >> 1
        if row[mid] == x:
            return True
        if row[mid] > x:
            return self.searchColumn(row, low, mid - 1, x)
        return self.searchColumn(row, mid + 1, high, x)
    def searchRow(self, mat: list, low: int, high: int, x: int):
        if low > high:
            return False
        mid = (low + high) >> 1
        if not self.checkRow(mat[mid], x):
            return self.searchColumn(mat[mid], 0, len(mat[mid]) - 1, x)
        if self.checkRow(mat[mid], x) == 1:
            return self.searchRow(mat, low, mid - 1, x)
        return self.searchRow(mat, mid + 1, high, x)
	def matSearch(self, mat, x):
		# Complete this function
		return self.searchRow(mat, 0, len(mat) - 1, x)

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1
    for _ in range(t):
        r = int(data[index])
        c = int(data[index + 1])
        index += 2
        matrix = []
        for i in range(r):
            row = list(map(int, data[index:index + c]))
            matrix.append(row)
            index += c
        x = int(data[index])
        index += 1
        ob = Solution()
        if ob.matSearch(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends
