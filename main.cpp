#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream File_main("Text7.in");
    if (!File_main.is_open()) {
        cout << "I can't open your file!" << endl;
        return 1;
    }

    ofstream File_sort("Sort.out");
    if (!File_sort.is_open()) {
        cout << "I can't open your file!" << endl;
        File_main.close();
        return 1;
    }


    double i;
    double pos[20];
    double zero[20];
    double neg[20];
    int k_pos = 0;
    int k_zero = 0;
    int k_neg = 0;
    while (File_main>> i) {
        if (i > 0) {
            pos[k_pos++] = i;
        }
        else if (i == 0) {
            zero[k_zero++] = i;
        }
        else {
            neg[k_neg++] = i;
        }
    }

    for (int j = 0; j < k_pos; j++) {
        File_sort << pos[j]<< " ";
    }

    for (int j = 0; j < k_zero; j++) {
        File_sort << zero[j] << " ";
    }

    for (int j = 0; j < k_neg; j++) {
        File_sort << neg[j] << " ";
    }

    File_main.close();
    File_sort.close();

    cout << "File copy! "  << endl;

    return 0;
}