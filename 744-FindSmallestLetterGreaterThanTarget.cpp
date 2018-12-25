class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int b = 0, e = letters.size() - 1, mid;
        while (b <= e) {
            mid = (b + e) / 2;
            if (letters[mid] == target)
                break;
            else if (letters[mid] < target)
                b = mid + 1;
            else
                e = mid - 1;
        }
        while (mid + 1 < letters.size() && letters[mid] == letters[mid + 1]) ++mid; 
        return letters[mid] > target ? letters[mid % letters.size()] : letters[(mid + 1) % letters.size()];
    }
};