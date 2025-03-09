// Time Complexity: O(n!)
// Space Complexity: O(n)
// Did this code run successfully on Leetcode : Yes

// Approach:
// 1. Create a 2D vector board of size n x n and initialize all elements to 0.
// 2. Call the placeQueens function with board, n, and row as parameters.
// 3. In the placeQueens function, if the row is equal to n, then we have reached the base case. So, we will create a vector of strings and add the board elements to it.
// 4. If the row is not equal to n, then we will iterate through each column of the row and check if it is safe to place the queen.
// 5. If it is safe, then we will place the queen at that position and call the placeQueens function recursively with row+1.
// 6. After the recursive call, we will remove the queen from that position and continue with the next column.
// 7. The isSafe function checks if the queen can be placed at that position by checking the same column, left diagonal, and right diagonal.


class Solution {
    vector<vector<string>> result; 
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<int>> board(n, vector<int>(n));
            placeQueens(board, n, 0);
            return result; 
        }
        bool placeQueens(vector<vector<int>>& board, int n, int r){
            //base case
            if(r == n){
                vector<string> temp;
                for(int i = 0; i < n; i++){
                    string a = "";
                    for(int j = 0; j < n; j++){
                        if(board[i][j] == 1){
                            a += 'Q';
                        }else{
                            a += '.';
                        }
                        
                    }
                    temp.push_back(a);
                }
                result.push_back(temp);
                return false;
            }
    
            //logic
            for(int i = 0; i < n; i++){
                if(isSafe(board, n, r, i)){
                    board[r][i] = 1;
                    placeQueens(board, n, r+1);
                    board[r][i] = 0; 
                }
                
            }
            return false;
        }
        bool isSafe(vector<vector<int>> board, int n, int i, int j){
            //same column
            for(int r = 0; r < i; r++){
                if(board[r][j] == 1){return false;}
            }
            //left diagonal
            int x = i - 1;
            int y = j - 1;
            while(x >= 0 && y >= 0){
                if(board[x][y] == 1){return false;}
                x--;
                y--;
            }
            //right diagonal
            x = i - 1;
            y = j + 1;
            while(x >= 0 && y < n){
                if(board[x][y] == 1){return false;}
                x--;
                y++;
            }
            return true;
        }
    };