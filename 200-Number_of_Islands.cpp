class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[row].size(); col++)
            {
                if(grid[row][col] == '1')
                {
                    count++;
                    grid[row][col] = '2';

                    recursively_extend_scope(grid, row + 1, col);
                    recursively_extend_scope(grid, row - 1, col);
                    recursively_extend_scope(grid, row, col + 1);
                    recursively_extend_scope(grid, row, col - 1);
                }
            }
        }

        return count;
    }

    void recursively_extend_scope(vector<vector<char>>& grid, int row, int col)
    {
        if( row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;

        if(grid[row][col] == '1')
        {
            grid[row][col] = '2';
            recursively_extend_scope(grid, row + 1, col);
            recursively_extend_scope(grid, row - 1, col);
            recursively_extend_scope(grid, row, col + 1);
            recursively_extend_scope(grid, row, col - 1);
        }
        else
            return;
        
    }
};
