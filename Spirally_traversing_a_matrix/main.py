class Solution:
    # Function to return a list of integers denoting spiral traversal of matrix.
    def spirallyTraverse(self, mat):
        # code here
        res, left, right, top, bottom = [], 0, len(mat[0]), 0, len(mat)
        while left < right and top < bottom:
            for i in range(left, right):
                res.append(mat[top][i])
            top += 1
            for i in range(top, bottom):
                res.append(mat[i][right - 1])
            right -= 1
            if not (left < right and top < bottom):
                break
            for i in range(right - 1, left, -1):
                res.append(mat[bottom - 1][i])
            bottom -= 1
            for i in range(bottom, top - 1, -1):
                res.append(mat[i][left])
            left += 1
        return res

#{ 
 # Driver Code Starts
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

        solution = Solution()
        result = solution.spirallyTraverse(matrix)
        print(" ".join(map(str, result)))
        print("~")

# } Driver Code Ends
