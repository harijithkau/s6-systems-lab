#include<stdio.h>

#define MAX_RESOURCES   10
#define MAX_PROCESSES   10

void main() {

//    int available[MAX_RESOURCES];
//    int max[MAX_PROCESSES][MAX_RESOURCES];
//    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];    
    int finish[MAX_PROCESSES];

    int i, j, k, l, flagOK;
	int resource_count = 3;
 	int process_count = 5;

	int allocation[5][3] = {0,1,0,2,0,0,3,0,2,2,1,1,0,0,2};
	int max[5][3] = {7,5,3,3,2,2,9,0,2,2,2,2,4,3,3};
	int available[3] = {3,3,2};
	int safeorder[6];
    
    for (i = 0; i < resource_count; i++) work[i] = available[i];
    for (i = 0; i < process_count; i++) finish[i] = 0;
 
   	for (i = 0; i < process_count ; i++) {
        for (j = 0; j < resource_count; j++)
             need[i][j] = max[i][j] - allocation[i][j];
    }
    
    i = 0;
	int pnumber = 0;
	int unsafe = 0;

    safeorder[0] = -1;
    do {

        flagOK = i;  
        if (finish[i] == 0) {

            for (j = 0; j < resource_count; j++) {
                 if (need[i][j] > work[j]) {
                    flagOK = -1;
                    break;
                }
            }
            
            if (flagOK != -1) {
                safeorder[++pnumber] = flagOK;
                printf("\nRunning process P[%d]", flagOK);

                for (j = 0; j <  resource_count; j++) {
                    work[j] = work[j] + allocation[flagOK][j];
                    printf("\nNew availability of resource R[%d] = %d", j, work[j]);
                }
				finish[i] = 1;
            }
        }
		i = i + 1;
		if (i > process_count) i = 0;
    } while (safeorder[pnumber] != i);

	
    for (i = 0; i < process_count ; i++) {
		if (finish[i] == 0) unsafe = 1;
	};

	if (unsafe == 0) {
	    printf("\nSystem is in Safe state.");
	    printf("\nSafe order.");
	    for (i = 1; i <= process_count ; i++) printf(" %d", safeorder[i]);
	}
	else {
	    printf("\nSystem is in Unsafe state.");
	}
	printf("\n");
}
