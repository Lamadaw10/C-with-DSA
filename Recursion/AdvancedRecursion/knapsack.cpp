//Advanced Recursion Problem - 6
//WAP where n items with weight and value is given and put those weight 
//And value in knapsack of capacity W to get the maximum tool value in knapsack
#include <iostream>
using namespace std;

// Recursive function to solve the 0/1 Knapsack problem
int knapsack(int value[], int wt[], int n, int W)
{
    // Base cases
    if (n == 0 || W == 0) // No items left or knapsack capacity is zero
    {
        return 0;
    }

    // If the weight of the current item is greater than the remaining capacity, skip this item
    if (wt[n-1] > W)
    {
        return knapsack(value, wt, n-1, W);
    }

    // Recursive relation:
    // We have two choices:
    // 1. Include the current item: knapsack(value, wt, n-1, W-wt[n-1]) + value[n-1]
    // 2. Exclude the current item: knapsack(value, wt, n-1, W)
    return max(knapsack(value, wt, n-1, W-wt[n-1]) + value[n-1], knapsack(value, wt, n-1, W));
}

int main()
{
    //Arrays of values and weights of the item
    int value[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int W = 50; //Total capacity of knapsack

    //Testing the knapsack function to find the maximumvalue we can carry in our knapsack
    cout << knapsack(value, wt, 3, W) << endl;
    return 0;
}