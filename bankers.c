#include<stdio.h>

#define MAX_RESOURCES   10
#define MAX_PROCESSES   10

void main() {
    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];    
    int finish[MAX_PROCESSES];

    int i, j, k, l;
    
    for (i = 0; i < MAX_RESOURCES; i++) work[i] = available[i];
    for (i = 0; i < MAX_PROCESSES; i++) finish[i] = 0;
    
    i = 0, pnumber = 0, unsafe = 0;
    
    for (i = 0; i < MAX_PROCESSES ; i++) {
        int flagOK = i;  
        un
        for (k = 0; k < MAX_PROCESSES ; k++) {
            for (l = 0; l < MAX_RESOURCES; l++) {
                 if (need[k][l] >= work[l]) {
                    unsafe = 0;
                    break;
                }
            }
        }
        if (finish[i] == 0) {
            for (j = 0; j < MAX_RESOURCES; j++) {
                 if (need[i][j] >= work[j]) {
                    flagOK = -1;
                    break;
                }
            }
            
            if (flagOK != -1) {
                safeorder[pnumber++] = flagOK;
                printf("Running process P[%d]", flagOK);
                for (j = 0; j <  MAX_RESOURCES; j++) {
                    work[j] = work[j] + allocation[flagOK][j];
                    printf("New availability of resource R[%d] = %d", j, work[j]);
                }
            }
        }
    }
    printf("\nSafe order.");
    for (i = 0; i < MAX_PROCESSES ; i++) printf(" %d", safeorder[pnumber]);
}
