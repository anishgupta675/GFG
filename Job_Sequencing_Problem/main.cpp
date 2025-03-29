//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    static bool myComparator(Job j1, Job j2) {
        return j1.profit > j2.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int count = 0, max_profit = 0;
        vector<bool> done(n, 0);
        sort(arr, arr + n, myComparator);
        for(int i = 0; i < n; i++) {
            for(int j = min(n, arr[i].dead - 1); j >= 0; j--) {
                if(!done[j]) {
                    count++;
                    max_profit+= arr[i].profit;
                    done[j] = 1;
                    break;
                }
            }
        }
        return { count, max_profit };
    } 
};

// jobs          -> 
// units of time -> 0   1   2   3   4   5

// jobs = {3, 100}, {2, 11}, {1, 19}, {1, 27}, {1, 29}, {1, 15}}//{ Driver Code Starts.

int main() {

}

// } Driver Code Ends
// sorted(jobs) = {{2, 11}, {1, 15}, {1, 19}, {1, 27}, {1, 29}}

// greedy component -> profit


