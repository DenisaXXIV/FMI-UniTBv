#pragma once
//#pragma warning(disable : 4996)

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

class PasswordHelper {
public:
    static void readPassword()
    {
        char password[20] = "";
        char my_password[20] = "123";
        int i;
        char ch;
        printf("PASSWORD: ");

        i = 0;

        do
        {
            ch = getchar();
            password[i] = ch;
            if (ch != 27 && ch != 13 && ch != 10)
                putchar('*');
            else break;
            i++;
        }while (i < 19);

        password[i] = '\0';

        if (!verifyPassword(password, my_password)) {
            readPassword();
        }

        printf("\n\nThe password is correct so the program is executed !\n");
    }

private:
    static bool verifyPassword(char password[], char my_password[])
    {
        //if you want that password don't be case-sensitive
        // strupr(password);
        //if false
        
        if (strcmp(password, my_password) != 0) // verify password
        {
            system("cls");
            printf("\n\nIncorrect password !!!\n\n");
            return false;
        }

        return true;
    }
};