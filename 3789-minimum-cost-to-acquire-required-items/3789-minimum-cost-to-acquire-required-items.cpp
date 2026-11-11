
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        if (1LL * cost1 + cost2 <= costBoth) {
            return 1LL * cost1 * need1 +
                   1LL * cost2 * need2;
        }

        long long totalCost = 0;

        int both = min(need1, need2);

        totalCost += 1LL * costBoth * both;

        need1 -= both;
        need2 -= both;

        if (need1 > 0) {
            totalCost += 1LL * need1 * min(cost1, costBoth);
        }

        if (need2 > 0) {
            totalCost += 1LL * need2 * min(cost2, costBoth);
        }

        return totalCost;
    }
};
