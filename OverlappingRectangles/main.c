#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a < b) ? b : a)

int MOD(int a) {
    return a < 0 ? a * -1 : a;
}

int isOneRectangleInsideTheOther(int r1x1, int r1y1, int r1x2, int r1y2, int r2x1, int r2y1, int r2x2, int r2y2) {
    if (MAX(r1x1, r1x2) < MIN(r2x1, r2x2) && MAX(r1y1, r1y2) < MIN(r2y1, r2y2)) {
        return 1;
    }
    if (MAX(r2x1, r2x2) < MIN(r1x1, r1x2) && MAX(r2y1, r2y2) < MIN(r1y1, r1y2)) {
        return 1;
    }
    return 0;
}

long int findAreaOfRectangle(int x1, int y1, int x2, int y2) {
    long int area = (x2 - x1) * (y2 - y1);
    if (area < 0) {
        return area * -1;
    }
    return area;
}

int isOneRectangleCompletelyOutsideTheOther(int r1x1, int r1y1, int r1x2, int r1y2, int r2x1, int r2y1, int r2x2, int r2y2) {
    if (MAX(r1x1, r1x2) < MIN(r2x1, r2x2)) {
        return 1;
    }
    if (MAX(r2x1, r2x2) < MIN(r1x1, r1x2)) {
        return 1;
    }
    if (MAX(r1y1, r1y2) < MIN(r2y1, r2y2)) {
        return 1;
    }
    if (MAX(r2y1, r2y2) < MIN(r1y1, r1y2)) {
        return 1;
    }
    return 0;
}

long int areaOfNewRectangle(int r1x1, int r1y1, int r1x2, int r1y2, int r2x1, int r2y1, int r2x2, int r2y2) {

}

long int areaOccupiedByRectangles(int r1x1, int r1y1, int r1x2, int r1y2, int r2x1, int r2y1, int r2x2, int r2y2) {
    int isInside = isOneRectangleInsideTheOther(r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2);
    if (isInside == 2) {
        return findAreaOfRectangle(r2x1, r2y1, r2x2, r2y2);
    } else if (isInside) {
        return findAreaOfRectangle(r1x1, r1y1, r1x2, r1y2);
    }
    if (isOneRectangleCompletelyOutsideTheOther(r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2)) {
        return findAreaOfRectangle(r1x1, r1y1, r1x2, r1y2) + findAreaOfRectangle(r2x1, r2y1, r2x2, r2y2);
    }git
    return findAreaOfRectangle(r1x1, r1y1, r1x2, r1y2) + findAreaOfRectangle(r2x1, r2y1, r2x2, r2y2) - MOD(areaOfNewRectangle(r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2));
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    while(testcases--) {
        int r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2;
        scanf("%d%d%d%d", &r1x1, &r1y1, &r1x2, &r1y2);
        scanf("%d%d%d%d", &r2x1, &r2y1, &r2x2, &r2y2);
        printf("%ld\n", areaOccupiedByRectangles(r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2));
    }
    return 0;
}