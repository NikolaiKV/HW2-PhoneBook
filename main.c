#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

typedef struct phoneBook {
    char name[NAME];
    char lastName[NAME];
    long phoneNumber;
} phoneBook;

int main(void) {

    phoneBook pBook[PHONE_BOOK] = {
            {"Петр", "Акиньшин", 89130009900},
            {"Герман", "Шмидт", 89231554321},
            {"Иван", "Сусанин", 89139998765},
            {"Евстратий", "Коловратий", 89236541234},
            {"Илья", "Крапивин", 89527654325},
            {"Антон", "Рябтцев", 89765431267},
            {"Олег", "Газманов", 89139997412},
            {"Елена", "Фадеева", 89521324567},
            {"Анжела", "Краснова", 81110987654},
            {"Стефания", "Пушкина", 89765439876},
            {"Александра", "Пупкина", 89541235632},
            {"Акакий", "Люфт", 89137651234},
            {"Жерар", "Пике", 89123428754},
            {"Леонель", "Месси", 89432316543},
            {"Майк", "Тайсон", 82341765412}};

    char help[HELP], name[NAME], lastName[LAST_NAME], phone[PHONE];
    int id = 0;
    long phoneNum = 0;

    printf("Для вызова меню введите: help\n");

    fgets(help, HELP + 1, stdin);
    if (!strcmp("help", help)){
        printf("Для поиска абонента по имени введите цифру: 1\n");
        printf("Для поиска абонента по фамилии введите цифру: 2\n");
        printf("Для поиска абонента по номеру телефона введите цифру: 3\n");
    }

    printf("Выберите пункт меню для поиска: ");
    scanf("%d", &id);
    fpurge(stdin);
    switch (id) {
        case  1:
            printf("Введите имя абонента: ");
            fgets(name, NAME, stdin);

            for (int i = 0; i < PHONE_BOOK; ++i) {
                if (!strncmp(name, pBook[i].name, strlen(name) - 1)) {
                    printf("Имя: %s, Фамилия: %s, Номер: +7%ld\n",
                           pBook[i].name, pBook[i].lastName, pBook[i].phoneNumber);
                    break;
                } else {
                    if (i == PHONE_BOOK - 1)
                        printf("Абонент с таким именем не найден!\n");
                }
            }
            break;
        case 2:
            printf("Введите фамилию абонента: ");
            fgets(lastName, LAST_NAME, stdin);

            for (int i = 0; i < PHONE_BOOK; ++i) {
                if (!strncmp(lastName, pBook[i].lastName, strlen(lastName) - 1)) {
                    printf("Имя: %s, Фамилия: %s, Номер: +7%ld\n",
                           pBook[i].name, pBook[i].lastName, pBook[i].phoneNumber);
                    break;
                } else {
                    if (i == PHONE_BOOK - 1)
                        printf("Абонент с такой фамилией не найден!\n");
                }
            }
            break;
        case 3:
            printf("Введите номер абонента: +7");
            fgets(phone, PHONE, stdin);
            phoneNum = atol(phone);
            for (int i = 0; i < PHONE_BOOK; ++i) {
                if (phoneNum == pBook[i].phoneNumber) {
                    printf("Имя: %s, Фамилия: %s, Номер: +7%ld\n",
                           pBook[i].name, pBook[i].lastName, pBook[i].phoneNumber);
                    break;
                } else {
                    if (i == PHONE_BOOK - 1)
                        printf("Абонент с таким телефоном не найден!\n");
                }
            }
            break;
    }

    return 0;
}