#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product products[5];
    int i;
    float totalValue = 0;

    for (i = 0; i < 5; i++) {
        printf("\n=== Nhap thong tin san pham %d ===\n", i + 1);

        printf("Nhap ten san pham: ");
        fflush(stdin);
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';

        printf("Nhap gia san pham: ");
        scanf("%f", &products[i].price);

        printf("Nhap so luong: ");
        scanf("%d", &products[i].quantity);
        getchar(); 
    }

    for (i = 0; i < 5; i++) {
        totalValue += products[i].price * products[i].quantity;
    }

    printf("\n===== TONG GIA TRI SAN PHAM =====\n");
    printf("Tong gia tri cua tat ca san pham: %.2f\n", totalValue);

    return 0;
}

