class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int row, int col) {
        int n = A.size(), count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int Bi = i + row;
                int Bj = j + col;

                if(Bi < 0 || Bi >= n || Bj < 0 || Bj >= n) continue;
                if(A[i][j] == 1 && B[Bi][Bj] == 1) count++;
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maxOverlap = 0, n = A.size();

        for(int rowOff = -n+1; rowOff < n; rowOff++) {
            for(int colOff = -n+1; colOff < n; colOff++) {
                int count = countOverlaps(A, B, rowOff, colOff);
                maxOverlap = max(maxOverlap, count);
            }
        }

        return maxOverlap;
    }
};