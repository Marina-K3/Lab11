#include "My_file.h"
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

static struct work {
    float mat;
    float tech;
    float plata;
    float money;
    float tratu;
} *works;

int N;

extern void enter() {
    setlocale(LC_ALL, "rus");
    printf("\n ������� ���-�� ���������� ����� - ");
    scanf_s("%d", &N);
    works = (work*)malloc(N * sizeof(work));
    register int i;
    for (i = 0; i < N; i++) {
        printf("\n");
        printf("      ������ � %d", i + 1);
        printf("\n******************************");
        printf("\n* ������� �� ��������� - ");
        scanf_s("%f", &works[i].mat);
        printf("******************************\n");
        printf("* ������������ ������� - ");
        scanf_s("%f", &works[i].tech);
        printf("******************************\n");
        printf("* �������� ��� ������� - ");
        scanf_s("%f", &works[i].plata);
        printf("******************************\n");
        printf("* ���������� ������ - ");
        scanf_s("%f", &works[i].money);
        printf("******************************\n");
    }
}
 
extern int print() {
    int choice;
    printf("\n ����� ����� ������ �� ������ ������� ?");
    printf("\n ��� ����� : ");
    scanf_s("%d", &choice);

    printf("\n      ������ � %d", choice);
    printf("\n******************************");
    printf("\n* ������� �� ��������� -%5.2f", works[choice-1].mat);
    printf(" *\n******************************\n");
    printf("* ������������ ������� - %5.2f", works[choice-1].tech);
    printf(" *\n******************************\n");
    printf("* �������� ��� ������� - %5.2f", works[choice-1].plata);
    printf(" *\n******************************\n");
    printf("* ���������� ������ - %5.2f", works[choice-1].money);
    printf(" *\n******************************\n");
    return 0;
}

extern int plus() {
    setlocale(LC_ALL, "rus");
    int h;
    printf("\n ������� ����� �� ������ �������� ? - ");
    scanf_s("%d", &h);
    N = N + h;
    works = (work*)realloc(works, (N)*sizeof(work));
    register int i;
    for (i = N-h; i < N; i++) {
        printf("\n");
        printf("      ������ � %d", i + 1);
        printf("\n******************************");
        printf("\n* ������� �� ��������� - ");
        scanf_s("%f", &works[i].mat);
        printf("******************************\n");
        printf("* ������������ ������� - ");
        scanf_s("%f", &works[i].tech);
        printf("******************************\n");
        printf("* �������� ��� ������� - ");
        scanf_s("%f", &works[i].plata);
        printf("******************************\n");
        printf("* ���������� ������ - ");
        scanf_s("%f", &works[i].money);
        printf("******************************\n");
    }
    return 0;
}
extern int calculation() {
    setlocale(LC_ALL, "rus");
    float k;
    work buf;
    printf("\n ������� ����������� ����������� ������ - ");
    scanf_s("%f", &k);
    float sum;
    float res = 0;
    register int i;
    for (i = 0; i < N; i++) {
        works[i].tratu = works[i].mat + works[i].plata + works[i].tech;
        sum = works[i].money - works[i].tratu;
        res += sum;
    }
    printf("\n\n     ``~~ ��ר� ~~``\n      !!!!!*#*!!!!\n");
    if (res > 0)printf("\n ����� - %5.2f", res - res * k);
    else printf("\n � ��������� ������� ��������� ������\n ��� ������ - %5.2f", res);
    int d = 0;
    for (d = 0; d < N - 1; d++) {
        for (i = 0; i < N - d - 1; i++) {
            if (works[i].tratu < works[i + 1].tratu) {
                buf = works[i];
                works[i] = works[i + 1];
                works[i + 1] = buf;
            }
        }
    }
    float tratu=0;
    for (i = 0; i < N; i++) {
        printf("\n      ������ � %d", i + 1);
        printf("\n******************************");
        printf("\n* ������� �� ��������� -%5.2f", works[i].mat);
        printf(" *\n******************************\n");
        printf("* ������������ ������� - %5.2f", works[i].tech);
        printf(" *\n******************************\n");
        printf("* �������� ��� ������� - %5.2f", works[i].plata);
        printf(" *\n******************************\n");
        printf("* ���������� ������ - %5.2f", works[i].money);
        printf(" *\n******************************\n");
        printf("\n* ����� - %5.2f", works[i].tratu);
        printf(" *\n******************************\n");
        tratu += works[i].tratu;
    }
    printf("\n ****����� ����� - %5.2f****\n", tratu);
    return 0;

}
extern int del()
{
    printf(" ������� �� ? - 1\n ������� ���� �� �������� - 2\n");
    int del;
    scanf_s("%d", &del);
    register int i;
    if (del == 1) free(works);
    else {
        printf(" ������� �����, ������� ������ �������: ");
        scanf_s("%d", &del);
        for (i = del - 1; i <=N - 1; i++) {
            works[i] = works[i + 1];
        }
        N = N - 1;
        printf("\n ����������������� ������ :");
        for (i = 0; i < N; i++) {
            printf("\n      ������ � %d", i + 1);
            printf("\n******************************");
            printf("\n* ������� �� ��������� -%5.2f", works[i].mat);
            printf(" *\n******************************\n");
            printf("* ������������ ������� - %5.2f", works[i].tech);
            printf(" *\n******************************\n");
            printf("* �������� ��� ������� - %5.2f", works[i].plata);
            printf(" *\n******************************\n");
            printf("* ���������� ������ - %5.2f", works[i].money);
            printf(" *\n******************************\n");
        }
    }
    return 0;
 }