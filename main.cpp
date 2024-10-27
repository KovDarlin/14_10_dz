#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    FILE* File_main = fopen("Text1.in", "rt");
    if (File_main == NULL) {
        printf("I can't open your file!\n");
        return 1;
    }

    FILE* File_neg = fopen("Negative.out", "wt");
    if (File_neg == NULL) {
        cout << "Problem with file!" << endl;
        fclose(File_main);
        return 1;
    }

    FILE* File_pos = fopen("Positive.out", "wt");
    if (File_pos == NULL) {
        cout << "Problem with file!" << endl;
        fclose(File_main);
        fclose(File_neg);
        return 1;
    }

    double i;
    int k_neg = 0;
    int k_pos = 0;
    while (fscanf(File_main, "%lf", &i) != EOF) {
        if (i < 0) {
            fprintf(File_neg, "%lf\n", i);
            k_neg++;
        }
        else if (i > 0) {
            fprintf(File_pos, "%lf\n", i);
            k_pos++;
        }
    }

    fclose(File_main);
    fclose(File_neg);
    fclose(File_pos);

    cout << "Count of negative elements: " << k_neg << endl;
    cout << "Count of positive elements: " << k_pos << endl;

    return 0;
}
