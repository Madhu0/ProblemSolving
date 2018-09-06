#include <stdio.h>

int main() {
    int queries;
    scanf("%d", &queries);
    while(queries--) {
        long int numberOfCities, numberOfRoads, costLib, costRoad;
        scanf("%ld%ld%ld%ld", &numberOfCities, &numberOfRoads, &costLib, &costRoad);
        if (costLib < costRoad) {
            printf("%ld", costLib*numberOfCities);
        } else {

        }
    }
    return 0;
}