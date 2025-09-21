#include <stdio.h>

int main() {
    float apple_price = 5.99, carrot_price = 3.99, chip_price = 2.99, candy_price = 1.50 ;
    float carrot_max = 4.1, apple_max = 7.2;
    int chip_max = 9, candy_max = 3;
    float tax_rate = 0.05;
    float carrots, apples;
    int chips, candy, num;

    printf("Apples     (7.20  kg) : ");
    num = scanf("%f", &apples);
    if (num != 1 || apples < 0 || apples > apple_max) {
        return 1;
    }

    printf("Carrots    (4.10  kg) : ");
    num = scanf("%f", &carrots);
    if (num != 1 || carrots < 0 || carrots > carrot_max) {
        return 1;
    }

    printf("Chips      (9  units) : ");
    num = scanf("%d", &chips);
    if (num != 1 || chips < 0 || chips > chip_max) {
        return 1;
    }

    printf("Candy      (3  units) : ");
    num = scanf("%d", &candy);
    if (num != 1 || candy < 0 || candy > candy_max) {
        return 1;
    }

    

    if (apples==0 && carrots==0 && chips==0 && candy==0) {
        return 1;
    }
    printf("\n");
    float apple_cost = apples * apple_price;
    float carrot_cost = carrots * carrot_price;
    float chip_cost = chips * chip_price;
    float candy_cost = candy * candy_price;
    float candy_discount = 0, total_cost;


    if(chips >= 2 && candy >= 1) {
        int discount_candies = chips / 2;
        if(discount_candies > candy) {
            discount_candies = candy;
        }
        candy_discount = discount_candies * 0.5 * candy_price;
        candy_cost -= candy_discount;
    }

    printf("-------------------------------------------------------------------\n");
    printf("| Item     | Quantity     | Cost       | Discount    | Total      |\n");
           
    if (apples > 0) {
        printf("| %-8s | %-10.2fkg | $%9.2f | -$%9.2f | $%9.2f |\n","Apples", apples, apple_cost, 0.0, apple_cost);
    }

    if (carrots > 0) {
        printf("| %-8s | %-10.2fkg | $%9.2f | -$%9.2f | $%9.2f |\n","Carrots", carrots, carrot_cost, 0.0, carrot_cost);
    }

    if (chips > 0) {
        printf("| %-8s | %-12d | $%9.2f | -$%9.2f | $%9.2f |\n","Chips", chips, chip_cost, 0.0, chip_cost);
    }

    if (candy > 0) {
        printf("| %-8s | %-12d | $%9.2f | -$%9.2f | $%9.2f |\n","Candy", candy, candy_cost + candy_discount, candy_discount, candy_cost);
    }

    printf("-------------------------------------------------------------------\n");
    printf("\n");

    float subtotal_before_discount = apple_cost + carrot_cost + chip_cost + candy_cost;
    float order_discount = 0;
    if (apples>=1 && carrots>=1 && chips>=1 && candy>=1)
        order_discount = subtotal_before_discount * 0.1;

    total_cost = subtotal_before_discount - order_discount;

    if (order_discount > 0)
        printf("Subtotal        : $%.2f - $%.2f = $%.2f\n", subtotal_before_discount, order_discount, total_cost);
    else
        printf("Subtotal        : $%.2f\n", subtotal_before_discount);

    float tax = total_cost * tax_rate;
    printf("Tax (5%%)        : $%.2f\n", tax);
    printf("----------------------------------------------------\n");
    printf("Total           : $%.2f\n", total_cost + tax);

    return 0;
}

