class Solution {
public:
    int largestSubmatrix2(vector<vector<int>>& matrix) {
        /*
            1
            3
            2

            2 1 3
            0 0 1
            1 1 2
            2 0 3
        */

        int N = matrix.size();
        int M = matrix[0].size();
        int result = 0;
        auto prev = matrix[0];
        vector<int> currRow(M,0);

        for (int i = 1; i<N; i++)
        {
            for (int j = 0; j<M; j++)
            {
                if (matrix[i][j]!=0)
                {
                    currRow[j] = prev[j]+matrix[i][j];
                }
            }

            auto row = currRow;
            sort(row.begin(),row.end(),greater());
            for (int j=0; j<M; j++)
            {
                result = max(result,row[j]*(j+1));
            }
            prev = currRow;
        }

        return result;

    }










    int largestSubmatrix3(vector<vector<int>>& matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        int result = 0;
        vector<int> row(nCol,0);
        for (int i = 0; i<nRow;i++)
        {
            for (int j = 0; j<nCol; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[j] = 0;
                }
                else
                {
                    row[j]+=matrix[i][j];
                }
            }
            auto sortRow = row;
            sort(sortRow.begin(),sortRow.end(), greater());
            for (int j = 0; j< nCol; j++)
            {
                result = max(result,sortRow[j]*(j+1));
            }
        }
        return result;
    }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        int ans = 0;
        for (int i = 0; i<nRow; i++)
        {
            for (int j = 0; j<nCol; j++)
            {
                if ((matrix[i][j] !=0) && (i>0))
                {
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            auto currRow = matrix[i];
            sort(currRow.begin(), currRow.end(),greater());
            for (int j = 0; j<nCol; j++)
            {
                ans = max(ans,currRow[j]*(j+1));
            }
        }
        return ans;
    }
};