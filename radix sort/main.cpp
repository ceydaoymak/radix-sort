//
// Created by ceyda oymak on 20.12.2023.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#endif //SORT_SORT_H
#include <iostream>
#include <random>

using namespace std;

#define prettyPrint(value) (value?"Passed":"Failed")

void print(int *numbers, int length) {
    cout << endl;
    for (int i = 0; i < length; i++) {
        cout << numbers[i] << " | ";
    }
    cout << endl;
}

void radixSort(int *numbers, int length) {

    int max = numbers[0];
    for (int i = 1; i < length; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    int *count = new int[10]{0};

    for (int digit = 1; max/digit > 0; digit=digit*10) {

        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }


        for (int i = 0; i < length; i++) {
            count[(numbers[i] / digit) % 10]++;
        }


        for (int i = 1; i < 10; i++) {
            count[i] = count[i] + count[i - 1];
        }

        int *output = new int[length];

        for (int i = length - 1; i >= 0; i--) {
            output[count[(numbers[i] / digit) % 10] - 1] = numbers[i];
            count[(numbers[i] / digit) % 10]--;
        }


        for (int i = 0; i < length; i++) {
            numbers[i] = output[i];
        }

        delete[] output;
    }

    delete[] count;
}}


void fillNumbers(int *numbers, int length) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> randInt(1, 1000);
    for (int i = 0; i < length; i++) {
        numbers[i] = randInt(rng);
    }
}

bool isSorted(int *numbers, int length) {
    bool sorted = true;
    for (int i = 0; i < length - 1; i++) {
        if (numbers[i] > numbers[i + 1]) {
            sorted = false;
            break;
        }
    }
    return sorted;
}

int main() {
    int length = 30;
    int numbers[30];
    fillNumbers(numbers, length);
    print(numbers, length);
    radixSort(numbers, length);
    print(numbers, length);
    cout << "Test case 1 : " << prettyPrint(isSorted(numbers, length)) << endl;
    return 0;
}
