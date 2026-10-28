#include <stdio.h>

void inputReadings(int sensors, int hours, float temp[50][50]) {
    int i, j;
    for(i = 0; i < sensors; i++) {
        printf("Sensor %d readings: ", i + 1);
        for(j = 0; j < hours; j++) {
            scanf("%f", &temp[i][j]);
        }
    }
}

void analyzeSensor(float readings[], int hours, int sensor_id, float *avg_out) {
    float tot = 0;
    float max = readings[0];
    float min = readings[0];
    int critical = 0;
    int warning = 0;
    int max_streak = 0;
    int curr_streak = 0;
    
    int j;
    for(j = 0; j < hours; j++) {
        tot += readings[j];
        if(readings[j] > max) max = readings[j];
        if(readings[j] < min) min = readings[j];
        
        if(readings[j] >= 40.0) critical++;
        if(readings[j] >= 35.0 && readings[j] < 40.0) warning++;
        
        if(readings[j] >= 35.0) {
            curr_streak++;
            if(curr_streak > max_streak) max_streak = curr_streak;
        } else {
            curr_streak = 0;
        }
    }
    
    float avg = tot / hours;
    *avg_out = avg;
    
    printf("Sensor %d: Total=%.0f Critical=%d Warning=%d Max=%.0f Min=%.0f Avg=%.2f Longest hot streak=%d\n", 
           sensor_id, tot, critical, warning, max, min, avg, max_streak);
}

int main() {
    int s_count, h_count;
    printf("Enter sensors and hours: ");
    scanf("%d %d", &s_count, &h_count);
    
    float temps[50][50];
    inputReadings(s_count, h_count, temps);
    
    float best_avg = -1;
    int best_sensor = 1;
    
    int i;
    for(i = 0; i < s_count; i++) {
        float current_avg;
        analyzeSensor(temps[i], h_count, i + 1, &current_avg);
        if(current_avg > best_avg) {
            best_avg = current_avg;
            best_sensor = i + 1;
        }
    }
    
    printf("Highest average: Sensor %d (%.2f)\n", best_sensor, best_avg);
    return 0;
}
