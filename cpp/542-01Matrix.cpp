class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        char visited[10001];
        vector<vector<int>> result = matrix;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != 0) {
                    memset(visited, '\0', 10001);
                    result[i][j] = findDistance(matrix, visited, i, j);
                }
            }
        }
        return result;
    }
    int findDistance(vector<vector<int>> &matrix, char visited[], int i, int j) {
        int distance = 1;
        int row = matrix.size();
        int col = matrix[0].size();
        queue<int> q;
        q.push(i * col + j);
        q.push(-1);
        while (true) {
            if (q.front() == -1) {
                q.pop();
                q.push(-1);
                ++distance;
                continue;
            }
            int y = q.front() / col;
            int x = q.front() % col;
            if (visited[y * col + x]) {
                q.pop();
                continue;
            }
            visited[y * col + x] = 'y';
            // up
            if (y  - 1 >= 0) {
                if (matrix[y - 1][x] == 0)
                    return distance;
                q.push((y-1) * col + x);
            }
            // down
            if (y  + 1 < row) {
                if (matrix[y + 1][x] == 0)
                    return distance;
                q.push((y + 1) * col + x);
            }
            // left
            if (x  - 1 >= 0) {
                if (matrix[y][x - 1] == 0)
                    return distance;
                q.push((y) * col + x - 1);
            }
            //right
            if (x + 1 < col) {
                if (matrix[y][x + 1] == 0)
                    return distance;
                q.push((y) * col + x + 1);
            }
            q.pop();
        }
        
        return distance;
    }
};