class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int emptyBottles = numBottles;

        // Keep exchanging as long as we have enough empty bottles.
        while (emptyBottles >= numExchange) {
            // How many new bottles can we get?
            int newBottles = emptyBottles / numExchange;
            
            // What are the leftover empty bottles after the exchange?
            int leftoverEmpty = emptyBottles % numExchange;

            // Drink the new bottles.
            totalDrunk += newBottles;

            // The new bottles become empty, add them to our leftovers.
            emptyBottles = newBottles + leftoverEmpty;
        }

        return totalDrunk;
    }
};