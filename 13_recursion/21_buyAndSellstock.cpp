#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
    // Base case: if we've processed all days
    if (i == prices.size()) {
        return;
    }

    // Update minPrice if current price is lower
    if (prices[i] < minPrice) {
        minPrice = prices[i];
    }

    // Calculate today's profit and update maxProfit if it's higher
    int todayProfit = prices[i] - minPrice;
    if (todayProfit > maxProfit) {
        maxProfit = todayProfit;
    }

    // Recursive call for the next day
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    // Start the recursive function
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
 