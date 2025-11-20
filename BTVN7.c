#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    char id[20];
    char title[100];
    char author[50];
    float price;
    char category[50];
};

void inputBooks(struct Book books[], int *n) {
    int i;
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    getchar();

    for (i = 0; i < *n; i++) {
        printf("\nNhap thong tin sach %d:\n", i + 1);

        printf("Ma sach: ");
        fgets(books[i].id, sizeof(books[i].id), stdin);
        books[i].id[strcspn(books[i].id, "\n")] = '\0';

        printf("Ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Gia: ");
        scanf("%f", &books[i].price);
        getchar();

        printf("The loai: ");
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = '\0';
    }
}

void displayBooks(struct Book books[], int n) {
    int i;
    if (n == 0) {
        printf("\nChua co sach nao!\n");
        return;
    }
    printf("\n===== DANH SACH SACH =====\n");
    for (i = 0; i < n; i++) {
        printf("\nSach %d:\n", i + 1);
        printf("Ma: %s\n", books[i].id);
        printf("Ten: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
    }
}

void addBookAtPosition(struct Book books[], int *n) {
    int pos, i;
    if (*n >= MAX) {
        printf("Mang da day!\n");
        return;
    }

    printf("Nhap vi tri can chen (0 -> %d): ", *n);
    scanf("%d", &pos);
    getchar();

    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (i = *n; i > pos; i--) {
        books[i] = books[i - 1];
    }

    printf("Nhap thong tin sach chen vao:\n");

    printf("Ma sach: ");
    fgets(books[pos].id, sizeof(books[pos].id), stdin);
    books[pos].id[strcspn(books[pos].id, "\n")] = '\0';

    printf("Ten sach: ");
    fgets(books[pos].title, sizeof(books[pos].title), stdin);
    books[pos].title[strcspn(books[pos].title, "\n")] = '\0';

    printf("Tac gia: ");
    fgets(books[pos].author, sizeof(books[pos].author), stdin);
    books[pos].author[strcspn(books[pos].author, "\n")] = '\0';

    printf("Gia: ");
    scanf("%f", &books[pos].price);
    getchar();

    printf("The loai: ");
    fgets(books[pos].category, sizeof(books[pos].category), stdin);
    books[pos].category[strcspn(books[pos].category, "\n")] = '\0';

    (*n)++;
    printf("Them thanh cong!\n");
}

void deleteByID(struct Book books[], int *n) {
    char id[20];
    int i, j, found = 0;

    if (*n == 0) {
        printf("Khong co sach de xoa!\n");
        return;
    }

    getchar();
    printf("Nhap ma sach can xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (i = 0; i < *n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            found = 1;
            for (j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("Xoa thanh cong!\n");
            break;
        }
    }

    if (!found) printf("Khong tim thay ma sach!\n");
}

void updateBook(struct Book books[], int n) {
    char id[20];
    int i;

    getchar();
    printf("Nhap ma sach can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("\nNhap thong tin moi:\n");

            printf("Ten sach: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';

            printf("Tac gia: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';

            printf("Gia: ");
            scanf("%f", &books[i].price);
            getchar();

            printf("The loai: ");
            fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].category[strcspn(books[i].category, "\n")] = '\0';

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay ma sach!\n");
}

void sortBooks(struct Book books[], int n) {
    int i, j, choice;
    struct Book tmp;

    printf("\n1. Tang dan theo gia\n2. Giam dan theo gia\nChon: ");
    scanf("%d", &choice);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((choice == 1 && books[i].price > books[j].price) ||
                (choice == 2 && books[i].price < books[j].price)) {
                tmp = books[i];
                books[i] = books[j];
                books[j] = tmp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchBook(struct Book books[], int n) {
    char keyword[100];
    int i, found = 0;

    getchar();
    printf("Nhap ten sach can tim: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strstr(books[i].title, keyword) != NULL) {
            found = 1;
            printf("\nTen: %s | Gia: %.2f | Tac gia: %s | The loai: %s\n",
                   books[i].title, books[i].price,
                   books[i].author, books[i].category);
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}

int main() {
    struct Book books[MAX];
    int n = 0, choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputBooks(books, &n); break;
            case 2: displayBooks(books, n); break;
            case 3: addBookAtPosition(books, &n); break;
            case 4: deleteByID(books, &n); break;
            case 5: updateBook(books, n); break;
            case 6: sortBooks(books, n); break;
            case 7: searchBook(books, n); break;
            case 8: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

