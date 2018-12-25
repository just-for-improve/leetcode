// how to prove
// 1. suppose the location of max-area is [ml, mr]
// 2. begin with l = 0, r = height.size
// 3. l move to right and r move to left
// 4. when l == ml (or r == mr)
//    if r <= mr: contradiction
//    else r > mr: if l > r: so the area > max-area, contradiction
//    done
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int marea = (r - l) * min(height[l], height[r]);
        
        while (l < r) {
            if (height[l] < height[r]) ++l;
            else if (height[l] > height[r]) --r;
            else { ++l; --r; }
            int area = (r - l) * min(height[l], height[r]);
            marea = max(area, marea);
        }
        return marea;
    }
};
