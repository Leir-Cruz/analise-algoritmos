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

int binarySolution (vector<int> weights, vector<int> values, int numberOfItems, int capacity) {
    if (capacity == 0 || numberOfItems == 0) return 0;
    if(weights[numberOfItems -1] > capacity) {
        return binarySolution(weights, values, numberOfItems - 1, capacity);
    } else {
        return max(
                values[numberOfItems -1] +
                binarySolution(weights, values, numberOfItems -1, capacity - weights[numberOfItems - 1]),
                binarySolution(weights, values, numberOfItems - 1, capacity)
                );
    }


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
    //int maxValue = greedySolutionFractional(weightArray, valueArray, benefitArray, sackSize);

    int maxValue = binarySolution(weightArray, valueArray, numberOfItems, sackSize);
    cout << maxValue;


    return 0;
}
