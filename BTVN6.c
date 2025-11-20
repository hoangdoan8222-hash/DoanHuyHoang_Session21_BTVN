#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};


void searchStudent(struct Student students[], int size, char key[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(students[i].name, key) == 0) {
            printf("\n=== Hoc sinh duoc tim thay ===\n");
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("Diem trung binh: %.2f\n", students[i].grade);
            return;
        }
    }
    printf("\nKhong tim thay hoc sinh voi ten: %s\n", key);
}

int main() {
    struct Student students[5];
    int i;
    char searchName[50];

    for (i = 0; i < 5; i++) {
        printf("\n=== Nhap thong tin hoc sinh %d ===\n", i + 1);

        printf("Nhap ten: ");
        fflush(stdin);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap diem trung binh: ");
        scanf("%f", &students[i].grade);
        getchar(); 
    }

    printf("\nNhap ten hoc sinh can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    searchStudent(students, 5, searchName);

    return 0;
}

