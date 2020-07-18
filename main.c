#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#define MAX 10

int NhapNum() {
    int result = 0;
    char string[100];
    char* buffer;
    do {
        printf("\nMoi chon chuc nang    ");
        scanf("%s", &string);
        result = (int) strtol(string, &buffer, 10);
        if (*buffer != 0 || result > 7 || result <= 0)
            printf("Nhap sai. Moi nhap lai\n");
    } while (*buffer != 0 || result > 3 || result <= 0);
    return result;
}
double score = 10.00;

int TimTanSuatXuatHienMax(int a[]) {
    int Max = 1; // 1 phần tử tối thiêu xuất hiện
    for (int i = 0; i < MAX; i++) {
        int dem = 1; // Tính chính nó
        for (int j = i + 1; j < MAX; j++) {
            if (a[i] == a[j]) {
                dem++;
            }
        }
        if (dem > Max) {
            Max = dem;
        }
    }
    return Max;
}

void ran() {
    int res = rand() % 10;
    int res2 = rand() % 10;
    int res3 = rand() % 10;
    int res4 = rand() % 10;
    int res5 = rand() % 10;
    int res6 = rand() % 10;
    int res7 = rand() % 10;
    int res8 = rand() % 10;
    int res9 = rand() % 10;
    int res10 = rand() % 10;

    printf("The slot machine shows %d%d%d%d%d%d%d%d%d%d\n", res, res2, res3, res4, res5, res6, res7, res8, res9, res10);
    int b[MAX] = {res, res2, res3, res4, res5, res6, res7, res8, res9, res10};

    int dem;
    dem = TimTanSuatXuatHienMax(b);

    if (dem == 2) {
        printf("You win 0.25\n");
        score = score + 0.025 * 10;
        printf("You have %.2f\n", score);
    } else if (dem == 3) {
        printf("You win 2.5 \n");
        score = score + 0.025 * 100;
        printf("You have %.2f\n", score);
    } else if (dem == 4) {
        printf("You win 25\n");
        score = score + 0.025 * 1000;
        printf("You have %.2f\n", score);
    } else if (dem == 5) {
        printf("You win 250\n");
        score = score + 0.025 * 100000;
        printf("You have %.2f\n", score);
    } else if (dem == 6) {
        printf("You win 2.500\n");
        score = score + 0.025 * 100000;
        printf("You have %.2f\n", score);
    } else if (dem == 7) {
        printf("You win 25.000 \n");
        score = score + 0.025 * 10000000;
        printf("You have %.2f\n", score);
    } else if (dem == 8) {
        printf("You win 250.000 \n");
        score = score + 0.025 * 10000000;
        printf("You have %.2f\n", score);
    } else if (dem == 9) {
        printf("You win 2.500.000\n");
        score = score + 0.025 * 100000000;
        printf("You have %.2f\n", score);
    }


    else if (res == res2 && res2 == res3 && res3 == res4 && res5 == res6 && res6 == res7 && res7 == res8 && res8 == res9 && res9 == res10) {
        printf("You win 10.00 cent\n");
        score = score + 10.00;
        printf("You have %.2f\n", score);
    } else {
        printf("Sorry you don't win anything\n");
        score = score - 1000;
        printf("You have %.2f\n", score);
    }

    if (score == 0) {
        printf("Good bye\n");
        return;
    }
}

//}

void ghifile() {
    FILE *fp;
    fp = fopen("abc.txt", "w+");
    fprintf(fp, "%.2f", score);
    fclose(fp);
    printf("Your money had saved\n\n");
}

void docfile() {
    FILE *fp;
    fp = fopen("abc.txt", "r");
    fscanf(fp, "%.2f", score);
    printf("%.2f\n", score);
    fclose(fp);
}

int main() {
    int number;

    do {
        printf("1) Play the slot machine.\n");
        printf("2) Save game.\n");
        printf("3) Cash out.\n");
        number = NhapNum();

        switch (number) {
            case 1:
                docfile();
                ran();
                break;

            case 2:
                ghifile();
                break;

            case 3:
                printf("Thanks you for playing! You end with %.2f\n", score);
                break;
        }

    } while (number <= 3);
    return 0;
}