*******************************************************************************  Question  **************************************************************************************************************************************************

Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.

Example 1:

Input:
N = 2
matrix[][] = 1 2
            3 4
Output:
1 2 3 4
Explanation:
List of anti-diagnoals in order is
{1}, {2, 3}, {4}
Example 2:

Input:
N = 3
matrix[][] = 3 2 3
            4 5 1
            7 8 9
Output:
3 2 4 3 5 7 1 8 9
Explanation:
List of anti-diagnoals in order is
{3}, {2, 4}, {3, 5, 7}, {1, 8}, {9}
Your Task:
You dont need to read input or print anything. Complete the function antiDiagonalPattern() that takes matrix as input parameter and returns a list of integers in order of the values visited in the anti-Diagonal pattern. 

Expected Time Complexity: O(N * N)
Expected Auxiliary Space: O(N * N)
 

Constraints:
1 <= N <= 100
0 <= mat[i][j] <= 100




*******************************************************************************  Solution  **************************************************************************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int>ans;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int k=i;
            for(int j=0;j<=i;j++){
            
                ans.push_back(matrix[j][k-j]);
            }
        }
        
         for(int i=1;i<n;i++){
            int k=i;
            int l=n-1;
            int j=0;
          while((l-j)>=1 && (k+j)<n ){
                
                ans.push_back(matrix[k+j][l-j]);
               
             j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

