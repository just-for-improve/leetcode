class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow{1}, thisRow{1};
        while (rowIndex--) {
            thisRow.clear();
            thisRow.push_back(1);
            for (int i = 1; i < lastRow.size(); ++i) {
                thisRow.push_back(lastRow[i - 1] + lastRow[i]);
            }
            thisRow.push_back(1);
            lastRow = thisRow;
        }
        return thisRow;
    }
};