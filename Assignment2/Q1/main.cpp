#include <stdio.h>

int main() {
    int rows, seats_per_row;
    printf("Enter rows and seats per row: ");
    scanf("%d %d", &rows, &seats_per_row);
    
    int hall[50][50];
    int i, j;
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < seats_per_row; j++) {
            scanf("%d", &hall[i][j]);
        }
    }
    
    int total_free = 0;
    printf("Free seats per row: ");
    for(i = 0; i < rows; i++) {
        int row_free = 0;
        for(j = 0; j < seats_per_row; j++) {
            if(hall[i][j] == 0) {
                row_free++;
            }
        }
        total_free += row_free;
        printf("%d ", row_free);
    }
    printf("Total free: %d\n", total_free);
    
    int k;
    printf("Enter group size k: ");
    scanf("%d", &k);
    
    int mid = rows / 2;
    int found = 0;
    int target_row = -1, start_seat = -1;
    
    for(int d = 0; d < rows && !found; d++) {
        int r_options[2];
        int count = 0;
        if(d == 0) {
            r_options[0] = mid;
            count = 1;
        } else {
            if(mid - d >= 0) { r_options[count++] = mid - d; }
            if(mid + d < rows) { r_options[count++] = mid + d; }
        }
        
        for(int r_idx = 0; r_idx < count && !found; r_idx++) {
            int curr_row = r_options[r_idx];
            int consec = 0;
            for(int s_idx = 0; s_idx < seats_per_row; s_idx++) {
                if(hall[curr_row][s_idx] == 0) {
                    consec++;
                    if(consec == k) {
                        target_row = curr_row;
                        start_seat = s_idx - k + 1;
                        found = 1;
                        break;
                    }
                } else {
                    consec = 0;
                }
            }
        }
    }
    
    if(found) {
        printf("Group of %d seated in Row %d, Seats %d to %d\n", k, target_row, start_seat, start_seat + k - 1);
        for(int x = start_seat; x < start_seat + k; x++) {
            hall[target_row][x] = 1;
        }
    } else {
        printf("No suitable block found for group.\n");
    }
    
    return 0;
}
```[cite: 3]

