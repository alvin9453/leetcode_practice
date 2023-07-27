class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(dfs(board, word, i, j, word.length()))
                    return true;
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int len)
    {
        if( len == 0)
            return true;

        if( row < 0 || row >= board.size() || col < 0 || col >= board[0].size() )
            return false;

        // cout << " row = " << row << " , col = " << col << ", word = " << word << endl;

        if( board[row][col] == word[0] )
        {
            // cout << " - found " << word[0] << endl;
            board[row][col] = '*'; // mark as visited
            
            if( dfs(board, word.substr(1, len - 1), row + 1, col, len - 1) || 
                dfs(board, word.substr(1, len - 1), row - 1, col, len - 1) ||
                dfs(board, word.substr(1, len - 1), row, col + 1, len - 1) ||
                dfs(board, word.substr(1, len - 1), row, col - 1, len - 1)  
              )
                return true; 
            else
                board[row][col] = word[0];
            
        }

        return false;
    }
};
