#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    char id[20];
    char name[50];
    float importPrice;  
    float salePrice;    
    int quantity;
};

float revenue = 0;  

int findProduct(struct Product products[], int n, char id[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(products[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void inputProducts(struct Product products[], int *n) {
    int i;
    printf("Nhap so luong san pham: ");
    scanf("%d", n);
    getchar();

    for (i = 0; i < *n; i++) {
        printf("\nNhap thong tin san pham %d:\n", i + 1);

        printf("Ma san pham: ");
        fgets(products[i].id, sizeof(products[i].id), stdin);
        products[i].id[strcspn(products[i].id, "\n")] = '\0';

        printf("Ten san pham: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';

        printf("Gia nhap: ");
        scanf("%f", &products[i].importPrice);

        printf("Gia ban: ");
        scanf("%f", &products[i].salePrice);

        printf("So luong: ");
        scanf("%d", &products[i].quantity);
        getchar();

        revenue -= products[i].quantity * products[i].importPrice;
    }
}

void displayProducts(struct Product products[], int n) {
    int i;
    if (n == 0) {
        printf("Chua co san pham nao!\n");
        return;
    }

    printf("\n===== DANH SACH SAN PHAM =====\n");
    for (i = 0; i < n; i++) {
        printf("\nSan pham %d:\n", i + 1);
        printf("Ma: %s\n", products[i].id);
        printf("Ten: %s\n", products[i].name);
        printf("Gia nhap: %.2f\n", products[i].importPrice);
        printf("Gia ban: %.2f\n", products[i].salePrice);
        printf("So luong: %d\n", products[i].quantity);
    }
}

void importProduct(struct Product products[], int *n) {
    char id[20];
    int index, qty;
    float importPrice;

    getchar();
    printf("Nhap ma san pham: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    index = findProduct(products, *n, id);
    if (index != -1) {
        printf("Nhap so luong can nhap: ");
        scanf("%d", &qty);
        printf("Gia nhap: ");
        scanf("%f", &importPrice);
        getchar();

        products[index].quantity += qty;
        products[index].importPrice = importPrice;
        revenue -= qty * importPrice;
    } else {
        if (*n >= MAX) {
            printf("Kho day, khong the nhap them!\n");
            return;
        }

        strcpy(products[*n].id, id);

        printf("Ten san pham: ");
        fgets(products[*n].name, sizeof(products[*n].name), stdin);
        products[*n].name[strcspn(products[*n].name, "\n")] = '\0';

        printf("Gia nhap: ");
        scanf("%f", &products[*n].importPrice);

        printf("Gia ban: ");
        scanf("%f", &products[*n].salePrice);

        printf("So luong: ");
        scanf("%d", &products[*n].quantity);
        getchar();

        revenue -= products[*n].quantity * products[*n].importPrice;
        (*n)++;
    }
    printf("Nhap hang thanh cong!\n");
}

void updateProduct(struct Product products[], int n) {
    char id[20];
    int index;

    getchar();
    printf("Nhap ma san pham can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    index = findProduct(products, n, id);
    if (index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    printf("Nhap ten moi: ");
    fgets(products[index].name, sizeof(products[index].name), stdin);
    products[index].name[strcspn(products[index].name, "\n")] = '\0';

    printf("Gia nhap moi: ");
    scanf("%f", &products[index].importPrice);

    printf("Gia ban moi: ");
    scanf("%f", &products[index].salePrice);

    printf("So luong moi: ");
    scanf("%d", &products[index].quantity);
    getchar();

    printf("Cap nhat thanh cong!\n");
}

void sortProducts(struct Product products[], int n) {
    int i, j, choice;
    struct Product temp;

    printf("\n1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &choice);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((choice == 1 && products[i].salePrice > products[j].salePrice) ||
                (choice == 2 && products[i].salePrice < products[j].salePrice)) {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    printf("Sap xep thanh cong!\n");
}

void searchProduct(struct Product products[], int n) {
    char name[50];
    int i, found = 0;

    getchar();
    printf("Nhap ten san pham can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strstr(products[i].name, name) != NULL) {
            found = 1;
            printf("\nMa: %s | Ten: %s | Gia ban: %.2f | SL: %d\n",
                products[i].id, products[i].name,
                products[i].salePrice, products[i].quantity);
        }
    }

    if (!found) printf("Khong tim thay!\n");
}

void sellProduct(struct Product products[], int n) {
    char id[20];
    int index, qty;

    getchar();
    printf("Nhap ma san pham can ban: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    index = findProduct(products, n, id);
    if (index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    if (products[index].quantity == 0) {
        printf("Het hang!\n");
        return;
    }

    printf("Nhap so luong can ban: ");
    scanf("%d", &qty);
    getchar();

    if (qty > products[index].quantity) {
        printf("Khong con du hang!\n");
        return;
    }

    products[index].quantity -= qty;
    revenue += qty * products[index].salePrice;

    printf("Ban hang thanh cong!\n");
}

int main() {
    struct Product products[MAX];
    int n = 0, choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputProducts(products, &n); break;
            case 2: displayProducts(products, n); break;
            case 3: importProduct(products, &n); break;
            case 4: updateProduct(products, n); break;
            case 5: sortProducts(products, n); break;
            case 6: searchProduct(products, n); break;
            case 7: sellProduct(products, n); break;
            case 8: printf("Doanh thu hien tai: %.2f\n", revenue); break;
            case 9: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

