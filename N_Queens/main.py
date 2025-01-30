class Solution:
    m = 0
    res = []

    def fun(self, b: List[chr], c: int, x: List[int], y: List[int], d: List[int], n: int):
        if c >= self.m:
            a = []
            for i in range(n):
                s = ""
                for j in range(n):
                    s += str(b[i][j])
                a.append(s)
            self.res.append(a)
        for i in range(n):
            if not x[i + c] and not y[n - 1 + c - i] and not d[i]:
                b[i][c] = 'Q'
                x[i + c] = 1
                y[n - 1 + c - i] = 1
                d[i] = 1
                self.fun(b, c + 1, x, y, d, n)
                b[i][c] = '.'
                x[i + c] = 0
                y[n - 1 + c - i] = 0
                d[i] = 0

    def solveNQueens(self, n: int) -> List[List[str]]:
        self.m = n
        b = [['.'] * n] * n
        x, y, d = [0] * (2 * n), [0] * (2 * n), [0] * (2 * n)
        self.fun(b, 0, x, y, d, n)
        return self.res
