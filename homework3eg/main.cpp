#include <iostream>

using namespace std;

int main() {

    int arr[7] = {5, 15, -30, 10, -5, 40, 10};
    int size = 7;
    int max=0, sum=0, begin=0, end=0, temp=0;

    for (int i = 0 ; i < size; i ++) {
        max += arr[i];
        if (sum < max) {
            sum = max;
            begin = temp + 1;
            end = i;
        }
        if (max < 0) {
            max = 0;
            temp+=i;
        }
    }
    cout << begin << endl;
    cout << end << endl;
    cout << sum << endl;

    return 0;
}