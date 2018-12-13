class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int l = (int)sqrt(area); l > 0; --l) {
            if (area % l == 0 )
                return vector<int>{area/l, l};
        }
        return vector<int>();
    }
};