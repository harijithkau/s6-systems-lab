#incliude<stdio.h>

#define MAX_RESOURCES   10
#define MAX_PROCESSES   10

void main() {
    int no_resources, no_processes;
    int r_total[MAX_RESOURCES] = { };
    int r_run[MAX_RESOURCES];
    int r_maximum[MAX_PROCESSES][MAX_RESOURCES];
    int r_allocation[MAX_PROCESSES][MAX_RESOURCES];
    int r_need[MAX_PROCESSES][MAX_RESOURCES];
    int r_available[MAX_RESOURCES];
    
    int safestate = false;
    int safeorder[MAX_PROCESSES];
        
    int i, j;
    int sum;
    int flag;
    
    for (i = 0; i < MAX_RESOURCES; i++) r_run[i] = 0;
    for (i = 0; i < MAX_RESOURCES; i++) {
        sum = 0;
        for (j = 0; j < MAX_PROCESSES; j++) {
             sum = sum + r_allocated[j][i];
        }    
        r_available[i] = r_total[MAX_RESOURCES] - sum;
    }

    for (i = 0; i < MAX_PROCESSES ; i++) {
        for (j = 0; j < MAX_RESOURCES; j++) {
             r_need[i][j] = r_required[i][j] - r_allocated[i][j];
        }    
    } 

    int pnumber = 0;
    
    for (i = 0; i < MAX_PROCESSES ; i++) {
        int flagOK = i;  
        if (r_run[i] == 0) {
            for (j = 0; j < MAX_RESOURCES; j++) {
                 if (r_need[i][j] > r_available[j]) {
                     flagOK = -1;
                    break;
                }
            }
            if (flagOK != -1) {
                safeorder[pnumber] = flagOK;
                r_run[i] = 1;
                pnumber = pnumber + 1;
                printf("Running process P[%d]", flagOK);
                for (j = 0; j <  MAX_RESOURCES; j++) {
                    r_available[j] = r_available[j] + r_need[flagOK][j];
                    printf("New availability of resource R[%d] = %d", j, r_available[j]);
                }
                i = 0;
            }
        }
    }
    printf("\nSafe order.");
    for (i = 0; i < MAX_PROCESSES ; i++) printf(" %d", safeorder[pnumber]);
}
