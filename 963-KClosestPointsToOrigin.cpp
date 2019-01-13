class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        vector<double> distances;
        points.push_back(points[0]);
        for (auto point: points) {
            distances.push_back(point[0] * point[0] + point[1] * point[1]);
        }
        int len = points.size();
        for (int i = 0; i < K; ++i) {
            int j = (len - 1) / 2;
            for (; j > 0; --j) {
                if (2 * j < len && distances[2 * j] < distances[j]) {
                    swap(points[j], points[2 * j]);
                    swap(distances[j], distances[2 * j]);
                }
                if (2 * j + 1 < len && distances[2 * j + 1] < distances[j]) {
                    swap(points[j], points[2 * j + 1]);
                    swap(distances[j], distances[2 * j + 1]);
                }
            }
            result.push_back(points[1]);
            points[1] = points[--len]; 
            distances[1] = distances[len];
        }
        return result;
    }
};