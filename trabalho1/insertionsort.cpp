#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


int insertionSort(string input, int size) {
    int numberOfSwaps = 0;
    int array[size];
    string s;
    int aux = 0;
    istringstream stringStream(input);
    while(getline(stringStream, s, ' ' )) {
        array[aux] = (stoi(s));
        aux +=1;
    }
    for(int i = 1; i < size; i++) {
        int reference = array[i];
        int j = i - 1;
        while(j >= 0 && (array[j] > reference)) {
            array[j + 1] = array[j];
            j--;
            numberOfSwaps += 1;
        }
        array[j + 1] = reference;
    }

    return numberOfSwaps;
}

int main () {
    string numberTestCases;
    vector<int> swaps;
    getline(cin, numberTestCases);
    for(int i = 0; i < stoi(numberTestCases); i++){
        string nu;
        int* myNumbers;
        getline(cin, nu);
        int numberElements = stoi(nu);
        string input;
        getline(cin, input);
        int swapsInsertionSort = insertionSort(input, numberElements);
        swaps.push_back(swapsInsertionSort);
    }
    for (int i = 0; i <swaps.size(); i++) {
        cout << swaps[i] << endl;
    }
    return 0;
}
