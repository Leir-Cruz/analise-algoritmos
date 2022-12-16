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


int bSearch(int* array, int size, int query) {
    int startArray = 0;
    int endArray = size;
    while(startArray <= endArray) {
        int middle = (startArray + endArray) / 2;
        if (array[middle] == query) {
            return middle;
        }
        if (array[middle] > query) {
            endArray = middle - 1;
        } else {
            startArray = middle + 1;
        }
    }
    return -1;

}

int main () {
    string numbers, inputArray;
    vector<int> myNumbers;

    getline(cin, numbers);
    getline(cin, inputArray);

    myNumbers = getInputs(numbers);
    int array[myNumbers[0]];

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
        cout << bSearch(array, myNumbers[0], stoi(query)) << endl;
    }

    return 0;
}
