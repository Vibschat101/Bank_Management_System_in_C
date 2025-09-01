#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    long accnum;
    int pin;
    int accbal;
    char actype;
    char acholder[25];
};

int check_valid_acc_number(struct Account ac[], long a) {
    for (int i = 0; i < 5; i++) {
        if (ac[i].accnum == a) {
            return i;
        }
    }
    return -1; // Account not found
}

int check_valid_pin(int p, struct Account ob) {
    return ob.pin == p;
}

int main() {
    struct Account ac[5];
    int ind, tpin, och, conf, wamt, damt, t1, t2;
    long tacnum;

    printf("Accepting Account Information\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEnter Information for account %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%ld", &ac[i].accnum);
        printf("Initial Account Balance: ");
        scanf("%d", &ac[i].accbal);
        getchar();
        printf("Account Type (S/C): ");
        scanf("%c", &ac[i].actype);
        getchar();
        printf("Account Holder's Name: ");
        fgets(ac[i].acholder, 25, stdin);
        ac[i].acholder[strcspn(ac[i].acholder, "\n")] = 0;
        printf("Create 4-digit PIN: ");
        scanf("%d", &ac[i].pin);
    }

    while (1) {
        printf("\nSelect Operation:\n");
        printf("1 - Withdrawal\n2 - Deposit\n3 - PIN Change\n4 - Balance Enquiry\n5 - View Account Details\n6 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &och);

        switch (och) {
            case 1:
                printf("Enter Account Number: ");
                scanf("%ld", &tacnum);
                ind = check_valid_acc_number(ac, tacnum);
                if (ind == -1) {
                    printf("Invalid Account Number\n");
                    break;
                }
                printf("Enter Current PIN: ");
                scanf("%d", &tpin);
                if (!check_valid_pin(tpin, ac[ind])) {
                    printf("PIN did not match\n");
                    break;
                }
                printf("Enter Amount to Withdraw: ");
                scanf("%d", &wamt);
                if (wamt > ac[ind].accbal) {
                    printf("Insufficient Balance\n");
                } else {
                    ac[ind].accbal -= wamt;
                    printf("Withdrawal Successful. Updated Balance: Rs.%d\n", ac[ind].accbal);
                }
                break;

            case 2:
                printf("Enter Account Number: ");
                scanf("%ld", &tacnum);
                ind = check_valid_acc_number(ac, tacnum);
                if (ind == -1) {
                    printf("Invalid Account Number\n");
                    break;
                }
                printf("Enter Amount to Deposit: ");
                scanf("%d", &damt);
                ac[ind].accbal += damt;
                printf("Deposit Successful. Updated Balance: Rs.%d\n", ac[ind].accbal);
                break;

            case 3:
                printf("Enter Account Number: ");
                scanf("%ld", &tacnum);
                ind = check_valid_acc_number(ac, tacnum);
                if (ind == -1) {
                    printf("Invalid Account Number\n");
                    break;
                }
                printf("Enter Current PIN: ");
                scanf("%d", &tpin);
                if (!check_valid_pin(tpin, ac[ind])) {
                    printf("PIN did not match\n");
                    break;
                }
                printf("Enter New PIN: ");
                scanf("%d", &t1);
                printf("Re-enter New PIN: ");
                scanf("%d", &t2);
                if (t1 == t2) {
                    ac[ind].pin = t1;
                    printf("PIN Changed Successfully\n");
                } else {
                    printf("PIN Confirmation did not match\n");
                }
                break;

            case 4:
                printf("Enter Account Number: ");
                scanf("%ld", &tacnum);
                ind = check_valid_acc_number(ac, tacnum);
                if (ind == -1) {
                    printf("Invalid Account Number\n");
                    break;
                }
                printf("Enter Current PIN: ");
                scanf("%d", &tpin);
                if (!check_valid_pin(tpin, ac[ind])) {
                    printf("PIN did not match\n");
                    break;
                }
                printf("Current Account Balance: Rs.%d\n", ac[ind].accbal);
                break;

            case 5:
                printf("Enter Account Number: ");
                scanf("%ld", &tacnum);
                ind = check_valid_acc_number(ac, tacnum);
                if (ind == -1) {
                    printf("Invalid Account Number\n");
                    break;
                }
                printf("Enter Current PIN: ");
                scanf("%d", &tpin);
                if (!check_valid_pin(tpin, ac[ind])) {
                    printf("PIN did not match\n");
                    break;
                }
                printf("Account Number: %ld\n", ac[ind].accnum);
                printf("Account Balance: Rs.%d\n", ac[ind].accbal);
                printf("Account Holder: %s\n", ac[ind].acholder);
                printf("Account Type: %c\n", ac[ind].actype);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}