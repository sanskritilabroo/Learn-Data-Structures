#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coe, pow; //coefficient and power so 2 data fields
    struct node *link; // 1 link field
} Node;

Node *getNode() {
    return malloc(sizeof(Node));
}

void createp(Node **head, int coe, int pow) {
    Node *temp = getNode();
    temp->coe = coe;
    temp->pow = pow;
    temp->link = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        Node *current = *head;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = temp;
    }
}

void display(Node *head) {
    while (head != NULL) {
        printf("+%dx^%d ", head->coe, head->pow);
        head = head->link;
    }
    printf("\n");
}

Node* add(Node *head1, Node *head2) {
    Node *poly = NULL;
    Node *temp;

    while (head1 && head2) {
        if (head1->pow > head2->pow) {
            createp(&poly, head1->coe, head1->pow);
            head1 = head1->link;
        } else if (head1->pow < head2->pow) {
            createp(&poly, head2->coe, head2->pow);
            head2 = head2->link;
        } else {
            createp(&poly, head1->coe + head2->coe, head1->pow);
            head1 = head1->link;
            head2 = head2->link;
        }
    }

    while (head1) {
        createp(&poly, head1->coe, head1->pow);
        head1 = head1->link;
    }

    while (head2) {
        createp(&poly, head2->coe, head2->pow);
        head2 = head2->link;
    }

    return poly;
}


int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    int n = 1;
    int coe, pow;

    printf("Polynomial 1:\n");
    while (n != 0) {
        printf("Enter 1 to add element and 0 to end: ");
        scanf("%d", &n);
        if (n == 1) {
            printf("Enter coeff : ");
            scanf("%d", &coe);
            printf("Enter power : ");
            scanf("%d", &pow);
            createp(&head1, coe, pow);
        }
    }

    n = 1;
    printf("Polynomial 2:\n");
    while (n != 0) {
        printf("Enter 1 to add element and 0 to end: ");
        scanf("%d", &n);
        if (n == 1) {
            printf("Enter coeff : ");
            scanf("%d", &coe);
            printf("Enter power : ");
            scanf("%d", &pow);
            createp(&head2, coe, pow);
        }
    }

    printf("Polynomial 1:\n");
    display(head1);

    printf("Polynomial 2:\n");
    display(head2);

    printf("Sum=\n");
    Node *addi=add(head1,head2);
    display(addi);
    return 0;
}

