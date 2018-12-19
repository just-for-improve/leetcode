class Solution {
public:
    bool judgeCircle(string moves) {
        int loc_x = 0, loc_y = 0;
        for (auto move: moves) {
            switch(move) {
                case 'R':
                   ++loc_x; break;
                case 'L':
                   --loc_x; break;
                case 'U':
                   ++loc_y; break;
                case 'D':
                   --loc_y; break; 
            }
        }
        return (loc_x || loc_y) ? false: true;
    }
};