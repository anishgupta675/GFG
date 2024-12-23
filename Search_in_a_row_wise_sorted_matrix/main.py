
#User function Template for python3

class Solution:
    
    def binarySearch(self, arr: list, low: int, high: int, x: int):
        if low > high:
            return False
        mid = (low + high) >> 1
        if arr[mid] == x:
            return True
        if arr[mid] > x:
            return self.binarySearch(arr, low, mid - 1, x)
        return self.binarySearch(arr, mid + 1, high, x)
    
    #Function to search a given number in row-column sorted matrix.
    def searchRowMatrix(self, mat, x): 
    	# code here 
    	for i in mat:
    	    if self.binarySearch(i, 0, len(i) - 1, x):
    	        return True
    	return False

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
        if ob.searchRowMatrix(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends
