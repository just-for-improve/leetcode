/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        bool inserted = false;
        vector<Interval> result;
        int start = 0, end = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            auto interval = intervals[i];
            if (inserted) {
                result.push_back(interval);
                continue;
            }
            // 后面
            if (interval.start < newInterval.start && interval.end < newInterval.start) {
                result.push_back(interval);
            } 
            else if (newInterval.start < interval.start && newInterval.end < interval.start) {
                result.push_back(newInterval);
                result.push_back(interval);
                inserted = true;
            }
            // 中间
            else if (interval.start <= newInterval.start && interval.end >= newInterval.end) {
                result.push_back(interval);
                inserted = true;
            } 
            else if (interval.start >= newInterval.start && interval.end >= newInterval.end) {
                Interval tmp(newInterval.start, interval.end);
                result.push_back(tmp);
                inserted = true;
            }
            else if (interval.end <= newInterval.end) {
                int j;
                start = min(interval.start, newInterval.start);
                for (j = i; j < intervals.size(); ++j) {
                    if (intervals[j].start > newInterval.end)
                        break;
                }
                i = --j;
                Interval tmp(start, max(newInterval.end, intervals[j].end));
                result.push_back(tmp);
                inserted = true;
            } 
               
        }
        if (!inserted)
            result.push_back(newInterval);
        return result;
    }
};