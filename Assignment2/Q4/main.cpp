#include <stdio.h>

int getValidDays() {
    int days;
    do {
        printf("Enter number of festival days (1-7): ");
        scanf("%d", &days);
    } while(days < 1 || days > 7);
    return days;
}

float calculateDailySales(int dayNumber) {
    int orders;
    printf("Day %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);
    
    float total_sales = 0;
    float highest_order = 0;
    
    printf("Order amounts: ");
    int i;
    for(i = 0; i < orders; i++) {
        float amt;
        do {
            scanf("%f", &amt);
        } while(amt <= 0);
        
        total_sales += amt;
        if(amt > highest_order) highest_order = amt;
    }
    
    float avg_order = total_sales / orders;
    printf("Total sales: Rs. %.2f\n", total_sales);
    printf("Average order: Rs. %.2f\n", avg_order);
    printf("Highest order: Rs. %.2f\n", highest_order);
    
    return total_sales;
}

int findHighestSalesDay(float dailySales[], int numberOfDays) {
    int best_day = 0;
    float max_sale = dailySales[0];
    int i;
    for(i = 1; i < numberOfDays; i++) {
        if(dailySales[i] > max_sale) {
            max_sale = dailySales[i];
            best_day = i;
        }
    }
    return best_day + 1;
}

void displayBarChart(float dailySales[], int numberOfDays) {
    printf("\n===== DAILY SALES BAR CHART =====\n");
    int i, j;
    for(i = 0; i < numberOfDays; i++) {
        printf("Day %d: ", i + 1);
        int stars = (int)(dailySales[i] / 100);
        for(j = 0; j < stars; j++) {
            printf("*");
        }
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

int main() {
    int days = getValidDays();
    float dailySales[7];
    
    int i;
    for(i = 0; i < days; i++) {
        dailySales[i] = calculateDailySales(i + 1);
    }
    
    float total_festival = 0;
    for(i = 0; i < days; i++) {
        total_festival += dailySales[i];
    }
    
    int highest_day = findHighestSalesDay(dailySales, days);
    
    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total festival sales: Rs. %.2f\n", total_festival);
    printf("Day with highest sales: Day %d\n", highest_day);
    
    displayBarChart(dailySales, days);
    
    return 0;
}
```[cite: 6, 7]




        }
    } while(choice != 6);
    
    return 0;
}
```[cite: 8, 9]
