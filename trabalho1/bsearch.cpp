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


int bSearch(int* array, int startArray, int endArray, int query) {
    int middle = (startArray + endArray) / 2;
    if (array[middle] == query) {
        return middle;
    }
    if (startArray == endArray) {
        return -1;
    }
    if (array[middle] > query) {
        return bSearch(array, startArray,middle - 1, query);
    } else {
        return bSearch(array, middle + 1, endArray, query);
    }

}

int main () {
    string numbers, inputArray;
    vector<int> myNumbers;

    getline(cin, numbers);
    getline(cin, inputArray);

    myNumbers = getInputs(numbers);
    int array[myNumbers[0]];
    int positions[myNumbers[1]];

    string s;
    int aux;
    istringstream stringStream(inputArray);
    while(getline(stringStream, s, ' ' )) {
        array[aux] = stoi(s);
        aux += 1;
    }


    for(int i = 0; i < myNumbers[1]; i++) {
        string query;
        getline(cin, query);
        positions[i] = bSearch(array, 0,myNumbers[0], stoi(query));

    }

    for (int i = 0; i < myNumbers[1]; i++) {
        cout << positions[i] << endl;
    }
    return 0;
}
