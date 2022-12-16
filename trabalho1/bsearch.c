#include <stdio.h>

int bSearch(int* array, int size, int query) {
    int startArray = 0;
    int endArray = size;
    while(startArray <= endArray) {
        int middle = (startArray + endArray) / 2;
        if (array[middle] == query) {
            if(array[middle] == array[middle - 1]) {
                endArray -= 1;
            } else {
                return middle;
            }
        }
        if (array[middle] >= query) {
            endArray = middle - 1;
        } else {
            startArray = middle + 1;
        }
    }
    return -1;

}

int main () {
    int size, numberQuerys;
    scanf("%d %d", &size, &numberQuerys);

    int array[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < numberQuerys; i++) {
        int query;
        scanf("%d", &query);
        printf("%d\n", bSearch(array, size, query));
    }
    return 0;
}
