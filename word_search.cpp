// Time Complexity: mn*3^L
// Space Complexity: O(n)
// Did this code run successfully on Leetcode : Yes

// Approach:
// 1. We need a visited 2D vector and a directions array
// 2. Dfs traversal is done  for each cell in the board
// 3. If the first character of the word matches the cell, then we will check if the word size is 1. If it is, then we will return true.
// 4. We will mark the cell as visited and iterate through each direction in the directions array.
// 5. If the dfs function returns true, then we will return true and backtrack.

class Solution {
    vector<vector<bool>> visited;
    int m; 
    int n; 
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
    public:
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();
            n = board[0].size();
            visited = vector<vector<bool>>(m, vector<bool>(n, false));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(dfs(board, word, i, j)){return true;}
                }
            }
            return false;
        }
    private :
        bool dfs(vector<vector<char>>& board, string word, int i, int j){
            //base/boundary check case
            if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]){
                return false;
            }
    
            //logic
            if(word[0] == board[i][j]){
                if(word.size() == 1){return true;}
                visited[i][j] = true;
                for(auto dir : directions){
                    int r = dir.first + i;
                    int c = dir.second + j;
                    if(dfs(board, word.substr(1), r, c)){return true;}
                    
                }
                //backtrack
                visited[i][j] = false;
            }
            return false;
        }
    };