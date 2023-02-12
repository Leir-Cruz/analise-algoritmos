#include <stdio.h>

int max(int numberA, int numberB) {
    return numberA > numberB ? numberA : numberB;
}

int binarySolution (int weights[], int values[], int numberOfItems, int capacity) {
    if (capacity == 0 || numberOfItems == 0) return 0;
    if(weights[numberOfItems -1] > capacity) {
        return binarySolution(weights, values, numberOfItems - 1, capacity);
    } else {
        return max(
                values[numberOfItems - 1] +
                binarySolution(weights, values, numberOfItems - 1, capacity - weights[numberOfItems - 1]),
                binarySolution(weights, values, numberOfItems - 1, capacity)
        );
    }
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

    int maxValue = binarySolution(weightArray, valueArray, numberOfItems, sackSize);
    printf("%d", maxValue);

    return 0;
}