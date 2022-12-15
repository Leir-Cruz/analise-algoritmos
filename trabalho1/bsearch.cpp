#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> getInputs (string input) {
    vector<int> numbers;
    string s;
    istringstream stringStream(input);
    while(getline(stringStream, s, ' ' )) {
        numbers.push_back(stoi(s));
    }
    return numbers;
}

vector<int> getArray(string input, int size) {
    vector<int> array;
    string s;
    int aux = 0;
    istringstream stringStream(input);
    while(getline(stringStream, s, ' ' )) {
        array.push_back(stoi(s));
        aux +=1;
    }
    return array;
}

int bSearch(vector<int> array, int size, int query) {
    int middle = size / 2;
    if (array[middle] == query) {
        return middle;
    }
    if (size == 0) {
        return -1;
    }
    if (array[middle] > query) {
        vector<int> halfArray;
        for(int i = 0; i < middle; i++ ) {
            halfArray.push_back(array[i]);
        }
        return bSearch(halfArray, halfArray.size(), query);
    } else {
        vector<int> halfArray;
        for(int i = middle; i < size; i++ ) {
            halfArray.push_back(array[i]);
        }
        return bSearch(halfArray, halfArray.size(), query);
    }

}

int main () {
    string numbers, inputArray;
    vector<int> myNumbers, positions;
    vector<int> array;

    getline(cin, numbers);
    getline(cin, inputArray);

    myNumbers = getInputs(numbers);
    array = getArray(inputArray, myNumbers[0]);

    for(int i = 0; i < myNumbers[1]; i++) {
        string query;
        getline(cin, query);
        positions.push_back(bSearch(array, myNumbers[0], stoi(query)));

    }

    for (int i = 0; i < positions.size(); i++) {
        cout << positions[i] << endl;
    }
    return 0;
}
