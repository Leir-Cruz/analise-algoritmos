#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> getNumbers(string input) {
    vector<int> array;
    string s;
    istringstream stringStream(input);
    while(getline(stringStream, s, ' ' )) {
        array.push_back(stoi(s));
    }
    return array;
}

vector<int> merge(vector<int> leftHalf, vector<int> rightHalf) {
    vector<int> mergedArray;
    while (leftHalf.size() > 0 && rightHalf.size() > 0){
        if (leftHalf[0] > rightHalf[0]) {
            mergedArray.push_back(rightHalf[0]);
            rightHalf.erase(rightHalf.begin());
        } else {
            mergedArray.push_back(leftHalf[0]);
            leftHalf.erase(leftHalf.begin());
        }
    }
    while(leftHalf.size() > 0 ) {
        mergedArray.push_back(leftHalf[0]);
        leftHalf.erase(leftHalf.begin());
    }
    while(rightHalf.size() > 0 ) {
        mergedArray.push_back(rightHalf[0]);
        rightHalf.erase(rightHalf.begin());
    }
    return mergedArray;
}

vector<int> mergeSort(vector<int> array) {
    if(array.size() <= 1) {
        return array;
    }
    vector<int> leftHalf(array.begin(), array.begin() + array.size() / 2);
    vector<int> rightHalf(array.begin() + array.size() / 2 , array.end());

    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    vector<int>sortedArray = merge(leftHalf, rightHalf);
    return sortedArray;

}

int main() {
    string input;
    getline(cin, input);
    vector<int> myNumbers = getNumbers(input);
    vector<int> mergedNumbers = mergeSort(myNumbers);

    for (int i = 0; i <mergedNumbers.size(); i++) {
        cout << mergedNumbers[i] << " ";
    }
    return 0;
}
