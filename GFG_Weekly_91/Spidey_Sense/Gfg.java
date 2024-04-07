//{ Driver Code Starts
import java.util.*;
import java.math.*;

class Pair{
    
    int x,y;
    Pair(int x,int y)
    {
        this.x = x;
        this.y = y;
    }
}

class Gfg
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.next());
        while(t-- > 0)
        {
            int m = Integer.parseInt(sc.next());
            int n = Integer.parseInt(sc.next());
            char mat[][] = new char[m][n];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j] = sc.next().charAt(0);
                }
            }
           
            Solution T = new Solution();
            int ans[][] = T.findDistance(mat, m, n);
            
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    System.out.print(ans[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends


class Solution
{
    private static int[] dx = {1, -1, 0, 0};
    private static int[] dy = {0, 0, 1, -1};
    private static boolean safe(int x, int y, int m, int n) {
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }
    public static int[][] findDistance(char mat[][], int m,int n)
    {
        // Your code goes here
        int[][] d = new int[m][n];
        Arrays.fill(d, 1e9);
        Deque<int[]> q = new ArrayDeque<int[]>();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 'B') {
                    q.addFirst(new int[]{i, j});
                    d[i][j] = 0;
                }
            }
        }
        while(!q.isEmpty()) {
            int[] p = q.removeLast();
            for(int k = 0; k < 4; k++) {
                int nr = p[0] + dx[k], nc = p[1] + dy[k];
                if(safe(nr, nc, m, n) && mat[nr][nc] != 'W' && d[nr][nc] > d[p[0]][p[1]] + 1) {
                    d[nr][nc] = d[p[0]][p[1]] + 1;
                    q.addFirst(new int[]{nr, nc});
                }
            }
        }
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(d[i][j] == 1e9) d[i][j] = -1;
        return d;
    }
}