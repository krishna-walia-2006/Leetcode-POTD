
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Count items having each frequency
        vector<int> frequencyCount(n + 1, 0);

        for (auto& item : items) {
            int frequency = item[0];
            frequencyCount[frequency]++;
        }

        // Step 2: Count items whose frequency is a multiple of f
        vector<int> multipleCount(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                multipleCount[f] += frequencyCount[j];
            }
        }

        // Step 3: Find minimum price and create candidates
        int minimumPrice = INT_MAX;

        vector<pair<int, int>> candidates;

        for (auto& item : items) {

            int frequency = item[0];
            int price = item[1];

            minimumPrice = min(minimumPrice, price);

            int groupSize = multipleCount[frequency] - 1;

            if (groupSize > 0) {
                candidates.push_back({price, groupSize});
            }
        }

        // Step 4: Sort candidates by price
        sort(candidates.begin(), candidates.end());

        long long spent = 0;
        long long totalItems = 0;
        long long B = budget;

        // Step 5: Buy candidates greedily
        for (auto& [price, groupSize] : candidates) {

            if (price > 2LL * minimumPrice) {
                break;
            }

            long long canBuy = min(
                (long long)groupSize,
                (B - spent) / price
            );

            totalItems += canBuy * 2;
            spent += canBuy * price;
        }

        // Step 6: Buy remaining items at minimum price
        totalItems += (B - spent) / minimumPrice;

        return (int)totalItems;
    }
};
