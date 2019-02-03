class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int nu_deck_i[10000];
        for (int i = 0; i < 10000; ++i) {
            nu_deck_i[i] = 0;
        }
        for (auto i: deck) {
            ++nu_deck_i[i];
        }
        int nu_min = INT_MAX;
        for (int i = 0; i < 10000; ++i) {
            if (nu_deck_i[i] != 0 && nu_deck_i[i] < nu_min)
                nu_min = nu_deck_i[i];
        }
        if (nu_min <= 1)
            return false;
        vector<int> common_devider;
        for (int i = 2; i <= nu_min; ++i) {
            if (nu_min % i == 0) {
                common_devider.push_back(i);
            }
        }
        for (int i = 0; i < 10000; ++i) {
            if (nu_deck_i[i] != 0) {
                bool yes = false;
                for (auto j: common_devider) {
                    if (nu_deck_i[i] % j == 0) {
                        yes = true;
                    }
                }
                if (!yes) {
                    return false;
                }
            }
        }
        return true;
    }
};
