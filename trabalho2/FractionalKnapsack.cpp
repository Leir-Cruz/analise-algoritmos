#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int greedySolutionFractional (vector<int> weights, vector<int> values, vector<pair<float,int>> benefits, int capacity) {
    int size = benefits.size();
    int total_value = 0;
    for(int i = 0; i < size; i++) {
        if(capacity == 0) break;
        int indexMaxValue = benefits[i].second;
        if(weights[indexMaxValue] <= capacity) {
            capacity -= weights[indexMaxValue];
            total_value += values[indexMaxValue];
        } else {
            int fractionalValue = values[indexMaxValue] * (float(capacity) / float(weights[indexMaxValue]));
            total_value += fractionalValue;
            capacity = 0;
        }
    }
    return total_value;
}

int max(int numberA, int numberB) {
    return numberA > numberB ? numberA : numberB;
}

int RecursiveBinarySolution (vector<int> weights, vector<int> values, int numberOfItems, int capacity) {
    if (capacity == 0 || numberOfItems == 0) return 0;
    if(weights[numberOfItems -1] > capacity) {
        return RecursiveBinarySolution(weights, values, numberOfItems - 1, capacity);
    } else {
        return max(
                values[numberOfItems -1] +
                RecursiveBinarySolution(weights, values, numberOfItems -1, capacity - weights[numberOfItems - 1]),
                RecursiveBinarySolution(weights, values, numberOfItems - 1, capacity)
                );
    }
}

int DinamycBinarySolution(vector<int> weights, vector<int> values, int numberOfItems, int capacity) {
    vector<vector<int>> table(numberOfItems + 1, vector<int>(capacity + 1));

    for(int i = 0; i <= numberOfItems; i++) {
        for(int c = 0; c <= capacity; c++) {
            if(i == 0 || c == 0) table[i][c] = 0;
            else if (weights[i - 1] <= c ) {
                table[i][c] = max(
                        values[i - 1] + table[i -1][c - weights[i -1]],
                        table[i - 1][c]
                        );
            } else {
                table[i][c] = table[i - 1][c];
            }
        }
    }
    return table[numberOfItems][capacity];
}

int main() {
    int sackSize, numberOfItems;
    cin >> sackSize >> numberOfItems;
    vector<int> weightArray, valueArray;
    vector<pair<float,int>> benefitArray;

    for(int i = 0; i < numberOfItems; i++) {
        int weight, value;
        cin >> weight >> value;

        if(weight >= 0 && value >= 0) {
            weightArray.push_back(weight);
            valueArray.push_back(value);
            benefitArray.push_back(make_pair(value/weight, i));
        }
    }

    int weightArraySize = weightArray.size();
    int valueArraySize = valueArray.size();

    if( valueArraySize != weightArraySize) {
        return -1;
    }

    sort(benefitArray.rbegin(), benefitArray.rend());
    int maxValue = greedySolutionFractional(weightArray, valueArray, benefitArray, sackSize);
    //int maxValue = RecursiveBinarySolution(weightArray, valueArray, numberOfItems, sackSize);
    //int maxValue = DinamycBinarySolution(weightArray, valueArray, numberOfItems, sackSize);
    cout << maxValue;


    return 0;
}
