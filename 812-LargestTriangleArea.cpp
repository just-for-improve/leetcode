class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // S=(1/2)*(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
        double max_area = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    double area = 0.5 * (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
                    max_area = max(max_area, abs(area));
                    
                }
            }
        }
        return max_area;
    }
};