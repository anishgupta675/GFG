
#User function Template for python3

class Solution:
    
    def searchColumn(self, arr: list, low: int, high: int, target: int) -> bool:
        if low > high:
            return False
        mid = (low + high) >> 1
        if arr[mid] == target:
            return True
        if arr[mid] > target:
            return self.searchColumn(arr, low, mid - 1, target)
        return self.searchColumn(arr, mid + 1, high, target)
    
    def searchRow(self, mat: list, low: int, high: int, target: int) -> int:
        if low > high:
            return -1
        mid = (low + high) >> 1
        if mat[mid][0] <= target and mat[mid][-1] >= target:
            return mid
        if mat[mid][0] > target and mat[mid][-1] > target:
            return self.searchRow(mat, low, mid - 1, target)
        return self.searchRow(mat, mid + 1, high, target)
    
    #Function to search a given number in row-column sorted matrix.
    def searchMatrix(self, mat, x): 
    	# code here 
    	row = self.searchRow(mat, 0, len(mat) - 1, x)
    	if row == -1:
    	    return False
    	return self.searchColumn(mat[row], 0, len(mat[row]) - 1, x)

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
        if ob.searchMatrix(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends
