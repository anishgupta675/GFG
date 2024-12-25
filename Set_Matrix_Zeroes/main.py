#User function Template for python3
class Solution:
    def setMatrixZeroes(self, mat):
        is_col = False
        for i in range(len(mat)):
            if not mat[i][0]:
                is_col = True
            for j in range(1, len(mat[0])):
                if not mat[i][j]:
                    mat[i][0] = 0
                    mat[0][j] = 0
        for i in range(1, len(mat)):
            for j in range(1, len(mat[0])):
                if not mat[i][0] or not mat[0][j]:
                    mat[i][j] = 0
        if not mat[0][0]:
            for j in range(len(mat[0])):
                mat[0][j] = 0
        if is_col:
            for i in range(len(mat)):
                mat[i][0] = 0

#{ 
 # Driver Code Starts
import sys

# Position this line where user code will be pasted.
if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()

    idx = 0
    t = int(data[idx])
    idx += 1
    results = []

    for _ in range(t):
        n, m = map(int, data[idx:idx + 2])
        idx += 2
        arr = []
        for i in range(n):
            arr.append(list(map(int, data[idx:idx + m])))
            idx += m

        sol = Solution()
        sol.setMatrixZeroes(arr)

        for row in arr:
            results.append(" ".join(map(str, row)))

        results.append("~")

    sys.stdout.write("\n".join(results) + "\n")

# } Driver Code Ends
