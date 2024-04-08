#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Address {
    int houseNumber;
    int zipCode;
    char state[50];
};

struct Employee {
    char name[50];
    struct Date dob;
    struct Address address; //nested struct
};

int main() {
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    struct Employee *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));
   
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Date of Birth (day month year): ");
        scanf("%d %d %d", &employees[i].dob.day, &employees[i].dob.month, &employees[i].dob.year);

        printf("Address (house_number zip_code state): ");
        scanf("%d %d %s", &employees[i].address.houseNumber, &employees[i].address.zipCode, employees[i].address.state);
    }

    printf("\nEmployee details:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nDetails of employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %d-%d-%d\n", employees[i].dob.day, employees[i].dob.month, employees[i].dob.year);
        printf("Address: %d, %s, %d\n", employees[i].address.houseNumber, employees[i].address.state, employees[i].address.zipCode);
    }
}
