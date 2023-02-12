#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sackSize, numberOfItems;
    cin >> sackSize >> numberOfItems;
    vector<int> weightArray, valueArray;
    vector<float> benefitArray;

    for(int i = 0; i < numberOfItems; i++) {
        int weight, value;
        cin >> weight >> value;

        weightArray.push_back(weight);
        valueArray.push_back(value);
        benefitArray.push_back(item/weight);
    }

    int weightArraySize = weightArray.size();
    int valueArraySize = valueArray.size();

    if( valueArraySize != weightArraySize || valueArraySize != numberOfItems || weightArraySize != numberOfItems ) {
        return -1;
    }

    return 0;
}
