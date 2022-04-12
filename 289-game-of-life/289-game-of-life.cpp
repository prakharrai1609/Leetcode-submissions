class Solution {
public:
    int count_nbr(const vector<vector<int> >& board, int i, int j) {
        int cnt = 0;
        int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int k = 0; k < 8; k++) {
            int xc = i + x[k];
            int yc = j + y[k];
            
            if (xc < 0 or yc < 0 or xc >= board.size() or yc >= board[0].size())
                continue;
            
            if (board[xc][yc] == 1 or board[xc][yc] == 2)
                cnt++;
        }
        
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        /*
            APPROACH
            - keep a third variable 2 for the posn which are alive but are going to die 
            - consider only the currenet case and not the possibilities of the future i.e. alive and dead only depend on the given case and not the things that are aobut to happen!
        */
        
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int nbr = count_nbr(board, i, j);
                if (board[i][j] == 1) {
                    if (nbr < 2 or nbr > 3)
                        board[i][j] = 2;
                } else {
                    if (nbr == 3) 
                        board[i][j] = 3;
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};