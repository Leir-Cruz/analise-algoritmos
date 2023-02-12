#include <stdio.h>

int max(int numberA, int numberB) {
    return numberA > numberB ? numberA : numberB;
}

int RecursiveSolution (int weights[], int values[], int numberOfItems, int capacity) {
    if (capacity == 0 || numberOfItems == 0) return 0;
    if(weights[numberOfItems -1] > capacity) {
        return RecursiveSolution(weights, values, numberOfItems - 1, capacity);
    } else {
        return max(
                values[numberOfItems - 1] +
                RecursiveSolution(weights, values, numberOfItems - 1, capacity - weights[numberOfItems - 1]),
                RecursiveSolution(weights, values, numberOfItems - 1, capacity)
        );
    }
}

int DinamycSolution(int weights[], int values[], int numberOfItems, int capacity) {
    int table[numberOfItems + 1][capacity +1];

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
    scanf("%d %d",&sackSize, &numberOfItems);
    int weightArray[numberOfItems], valueArray[numberOfItems];


    for(int i = 0; i < numberOfItems; i++) {
        int weight, value;
        scanf("%d %d",&weight, &value);

        if(weight >= 0 && value >= 0) {
            weightArray[i] = weight;
            valueArray[i] = value;
        }
    }

    int weightArraySize = sizeof(weightArray) / sizeof(weightArray[0]);
    int valueArraySize = sizeof(valueArray) / sizeof(valueArray[0]);

    if( valueArraySize != weightArraySize) {
        return -1;
    }

    int maxValue = DinamycSolution(weightArray, valueArray, numberOfItems, sackSize);
    printf("%d", maxValue);

    return 0;
}