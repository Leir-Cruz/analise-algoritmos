#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sackSize, numberOfItems;
    cin >> sackSize >> numberOfItems;
    vector<int> itemsArray, weightArray;

    for(int i = 0; i < numberOfItems; i++) {
        int item, weight;
        cin >> item >> weight;

        itemsArray.push_back(item);
        weightArray.push_back(weight);
    }

    int itemsArraySize = itemsArray.size();
    int weightArraySize = weightArray.size();

    if( itemsArraySize != weightArraySize || itemsArraySize != numberOfItems || weightArraySize != numberOfItems ) {
        return -1;
    }

    return 0;
}
