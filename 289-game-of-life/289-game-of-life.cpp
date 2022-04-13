class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int c=0,m,n,i,j;
        m=board.size();
        n=board[0].size();
        vector<vector<int>> vec( m+2, vector<int> (n+2, 2));
        for( i = 1; i < m+1; i++)
        {
            for(j = 1; j < n+1; j++)
            {
                vec[i][j]=board[i-1][j-1];
            }
        }
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<n+1;j++)
            {
                c=vec[i-1][j-1]==1?c+1:c+0;
                c=vec[i-1][j]==1?c+1:c+0;
                c=vec[i-1][j+1]==1?c+1:c+0;
                c=vec[i][j-1]==1?c+1:c+0;
                c=vec[i][j+1]==1?c+1:c+0;
                c=vec[i+1][j-1]==1?c+1:c+0;
                c=vec[i+1][j]==1?c+1:c+0;
                c=vec[i+1][j+1]==1?c+1:c+0;
                if(c<2&&board[i-1][j-1]==1)
                    board[i-1][j-1]=0;
                else if((c==2||c==3)&&board[i-1][j-1]==1)
                    board[i-1][j-1]=1;
                else if(c>3&&board[i-1][j-1]==1)
                    board[i-1][j-1]=0;
                else if(c==3)
                    board[i-1][j-1]=1;
                c=0;
            }
        }
        vec.clear();
    }
};