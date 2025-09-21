#include <stdio.h>
#include <math.h>

int main() 
{
    float x1, y1, x2, y2, x3, y3;
    int check;

    printf("Point 1: ");
    check = scanf(" ( %f , %f )", &x1, &y1);
    if (check != 2) {
        return 1;
    }
    
    printf("Point 2: ");
    check = scanf(" ( %f , %f )", &x2, &y2);
    if (check != 2) {
        return 1;
    }

    printf("Point 3: ");
    check = scanf(" ( %f , %f )", &x3, &y3);
    if (check != 2) {
        return 1;
    }

    float dis1_2 = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    float dis1_3 = sqrtf((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    float dis2_3 = sqrtf((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));

    if (dis1_2 == dis1_3 && dis1_3 == dis2_3) 
    {
        printf("All points are equal distance: %'.2f\n", d12);
        return 0;
    }

    float min = dis1_2;
    if (dis1_3 < min) 
    {
        min = dis1_3;
    }
    if (dis2_3 < min) 
    {
        min = dis2_3;
    }

    if (dis1_2 == min) 
    {
        printf("P1<->P2: %'.2f\n", dis1_2);
    }
    if (dis1_3 == min) 
    {
        printf("P1<->P3: %'.2f\n", dis1_3);
    }
    if (dis2_3 == min) 
    {
        printf("P2<->P3: %'.2f\n", dis2_3);
    }

    return 0;
}
