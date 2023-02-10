#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>
#include <stdbool.h>
bool check_for_nums(char name[]) {
    bool flag;
    do {
        int i = 0;
        int count = 0;
        flag = false;
        while (name[i] != '\0') {
            if (name[i] >= '1' && name[i] <= '9') {
                count++;
                break;
            }
            i++;
        }
        if (count) {
            printf("�� ����� ����� � ���, ���������� ���\n");
            flag = true;
            return flag;
        }
    } while (flag);
}
void remove_space(char* s) {
    char* ptr = s;
    do {
        while (*ptr == ' ') {
            ++ptr;
        }
    } while (*s++ = *ptr++);
}
void ExNum2(char str[]) {
    bool flag = false;
    remove_space(str);
    int middle = strlen(str) / 2;
    if (strlen(str) == 1) {
        printf("������ 1 ������ - �� �� ���������\n");
    }
    else if (strlen(str) % 2 != 0) {
        for (int i = middle - 1, j = middle + 1; i >= 0 && j <= strlen(str) - 1; i--, j++) {
            if (str[i] != str[j]) {
                flag = true;
                break;
            }
        }
        if (flag) puts("�� ���������");
        else puts("���������");
    }
    else {
        for (int i = middle - 1, j = middle; i >= 0, j <= strlen(str) - 1; i--, j++) {
            if (str[i] != str[j]) {
                flag = true;
                break;
            }
        }
        if (flag) puts("�� ���������");
        else puts("���������");
    }

}
void ExNum4and2(char str[]) {
    char sep[2] = " ";
    char* ptr;
    ptr = strtok(str, sep);
    printf("��������� : \n");
    while (ptr != NULL) {
        ExNum2(ptr);
        ptr = strtok(NULL, sep);
    }
}
void ExNum4(char str[]) {
    char sep[2] = " ";
    char* ptr;
    ptr = strtok(str, sep);
    printf("��������� : \n");
    while (ptr != NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, sep);
    }
}
void ExNum6() {
    char str[43];
    char name[34];
    char phamil[34];
    bool flag;
    do {
        flag = false;
        printf("������� ���� ��� : "); gets(str);
        flag = check_for_nums(str);
        if (flag) continue;
        char sep[2] = " ";
        char* ptr;
        ptr = strtok(str, sep);
        int counter = 0;
        while (ptr != NULL) {
            if (!counter) strcpy(phamil, ptr);
            if (counter == 1) strcpy(name, ptr);
            ptr = strtok(NULL, sep);
            counter++;
        }
    } while (flag);
    printf("������, %s %s\n", name, phamil);
}
void ExNum8() {
    char str[60];
    gets(str);
    int j;
    for (int i = 0, j = i + 1; str[i] != '\0'; i += 2, j = i + 1) {
        if (str[j] == '\0') break;
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    puts(str);
}
void ExNum10() {
    char name[40];
    bool flag;
    do {
        flag = false;
        printf("����������, ������� ���� ��� : "); gets(name);
        flag = check_for_nums(name);
    } while (flag);
    printf("������, %s", name);
}
int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char menu[30];
    char str[30];
    do {
        do {
            printf("0.����� �� ����\n2.������ N2\n4.������ N4\n6.������ N6\n8.������ N8\n10.������ N10\n���� �����: ");
            gets(menu);
            if (strlen(menu) >= 2 && strcmp(menu, "10") != 0) {
                printf("���������� ��� ���: \n");
            }
        } while (strlen(menu) >= 2 && strcmp(menu, "10") != 0);
        switch (*menu) {
        case '2': printf("������� ����� ����������� : "); gets(str); ExNum2(str); printf("������� ������ : "); gets(str); ExNum4and2(str); break;
        case '4': printf("������� ����� ����������� : "); gets(str); ExNum4(str); break;
        case '6': ExNum6(); break;
        case '8': ExNum8(); break;
        case '1': ExNum10(); break;
        }
    } while (*menu != '0');
    return 0;
}