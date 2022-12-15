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

int* getArray(string input, int size) {
    int array[size];
    string s;
    int aux = 0;
    istringstream stringStream(input);
    while(getline(stringStream, s, ' ' )) {
        array[aux] = (stoi(s));
        aux +=1;
    }
    return array;
}

int bSearch(int* array, int size, int query) {
    int middle = size / 2;
    if (array[middle] == query) {
        return middle;
    }
    if (size == 0) {
        return -1;
    }
    if (array[size / 2] < query) {
        int halfArray[middle];
        for(int i = 0; i < middle; i++ ) {
            halfArray[i] = array[i];
        }
        return bSearch(halfArray, middle, query);
    } else {
        int halfArray[middle];
        for(int i = middle; i < size; i++ ) {
            halfArray[i] = array[i];
        }
        return bSearch(halfArray, middle, query);
    }

}

int main () {
    string numbers, inputArray;
    vector<int> myNumbers, positions;
    int* array;

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
