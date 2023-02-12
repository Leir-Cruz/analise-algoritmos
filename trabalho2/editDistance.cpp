#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int min(int number1, int number2, int number3) {
    return min(min(number1, number2), number3);
}

int findDistance(string from, string to, int fromLength, int toLength) {
    int table[fromLength + 1][toLength + 1];

    for(int i = 0; i <= fromLength; i++) {
        for(int j = 0; j <= toLength; j++) {
            if (i == 0) table[i][j] = j;
            else if (j == 0) table[i][j] = i;
            else if (from[i - 1] == to[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = 1 + min(table[i][j -1],
                                      table[i -1][j],
                                      table[i -1][j -1]);
            }
        }
    }
    return table[fromLength][toLength];


}

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for(int i = 0; i < numberOfTestCases; i++) {
        string startString, finalString;
        cin >> startString >> finalString;
        cout << findDistance(startString, finalString, startString.length(), finalString.length()) << endl;
    }

    return 0;
}