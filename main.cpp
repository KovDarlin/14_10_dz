#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    FILE* File_main = fopen("Text6.in", "rt");
    if (File_main == NULL) {
        printf("I can't open your file!\n");
        return 1;
    }

    FILE* File_sort = fopen("Sort.out", "wt");
    if (File_sort == NULL) {
        cout << "Problem with file!" << endl;
        fclose(File_main);
        return 1;
    }

    double i;
    double pos[20];
    double zero[20];
    double neg[20];
    int k_pos = 0;
    int k_zero = 0;
    int k_neg = 0;

    while (fscanf(File_main, "%lf", &i) != EOF) {
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
        fprintf(File_sort, "%lf ", pos[j]);
    }

    for (int j = 0; j < k_zero; j++) {
        fprintf(File_sort, "%lf ", zero[j]);
    }

    for (int j = 0; j < k_neg; j++) {
        fprintf(File_sort, "%lf ", neg[j]);
    }

    fclose(File_main);
    fclose(File_sort);

    cout << "File copy!" << endl;
    return 0;
}
