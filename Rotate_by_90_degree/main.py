#User function Template for python3


class Solution:
    def rotateBy90Util(self, mat):
        for i in range(len(mat) >> 1):
            for j in range(i, len(mat) - i - 1):
                temp = mat[i][j]
                mat[i][j] = mat[len(mat) - 1 - j][i]
                mat[len(mat) - 1 - j][i] = mat[len(mat) - 1 - i][len(mat) - 1 - j]
                mat[len(mat) - 1 - i][len(mat) - 1 - j] = mat[j][len(mat) - 1 - i]
                mat[j][len(mat) - 1 - i] = temp
        return mat
    
    #Function to rotate matrix anticlockwise by 90 degrees.
    def rotateby90(self, mat): 
        # code here
        for i in range(3):
            mat = self.rotateBy90Util(mat)
        return mat

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1

    for _ in range(t):
        n = int(data[index])
        index += 1
        matrix = []
        for i in range(n):
            row = list(map(int, data[index:index + n]))
            matrix.append(row)
            index += n
        obj = Solution()
        obj.rotateby90(matrix)
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end=" ")
            print()

        print("~")

# } Driver Code Ends
