vector<int> Solution::spiralOrder(const vector<vector<int> > &matrix) {
	vector<int> result;
    int m=matrix.size();
    int n=matrix[0].size();
    int dir = 0;
        vector< vector<int> > mark(m, vector<int> (n, 0));
        int i = 0, j = 0, k = 1;
        while (k <= n * m) {
            result.push_back(matrix[i][j]);
            k++;
            mark[i][j]=1;
            if (dir == 0){
                j++;
                if (j == n || mark[i][j] != 0) dir = 1, j--, i++;
            } else
            if (dir == 1) {
                i++;
                if (i == m || mark[i][j] != 0) dir = 2, i--, j--;
            } else
            if (dir == 2) {
                j--;
                if (j < 0 || mark[i][j] != 0) dir = 3, j++, i--;
            } else
            if (dir == 3) {
                i--;
                if (i < 0 || mark[i][j] != 0) dir = 0, i++, j++;
            }
        }


	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
