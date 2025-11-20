#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("\n=== Nhap thong tin sach %d ===\n", i + 1);

        printf("Nhap ten sach: ");
        fflush(stdin);
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Nhap ten tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Nhap gia sach: ");
        scanf("%f", &books[i].price);
        getchar(); 
    }

    printf("\n===== THONG TIN CAC CUON SACH =====\n");
    for (i = 0; i < 3; i++) {
        printf("\nSach %d:\n", i + 1);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
    }

    return 0;
}

