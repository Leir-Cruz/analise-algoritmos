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

int bSearch(vector<int> array, int startArray, int endArray, int query) {
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
    vector<int> myNumbers, positions;
    vector<int> array;

    getline(cin, numbers);
    getline(cin, inputArray);

    myNumbers = getInputs(numbers);
    array = getArray(inputArray, myNumbers[0]);

    for(int i = 0; i < myNumbers[1]; i++) {
        string query;
        getline(cin, query);
        positions.push_back(bSearch(array, 0,myNumbers[0], stoi(query)));

    }

    for (int i = 0; i < positions.size(); i++) {
        cout << positions[i] << endl;
    }
    return 0;
}
