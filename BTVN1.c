#include <stdio.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {
    struct Car myCar;

    snprintf(myCar.model, sizeof(myCar.model), "Toyota Camry");
    myCar.year = 2020;
    myCar.price = 35000.50;

    printf("Thong tin xe:\n");
    printf("Mau xe: %s\n", myCar.model);
    printf("Nam san xuat: %d\n", myCar.year);
    printf("Gia xe: %.2f$\n", myCar.price);

    return 0;
}

