#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mdelete.c"

struct student
{
    int id;
    char name[50];
    char branch[10];
};

int upstr(char *s);
int insert();
int modify();
int delete ();
int searchbranch();
int searchname();
int display();

int main()
{
    while (1)
    {
        int choice = 0;
        printf("SELECT AN OPTION\n");
        printf("1.  Insert New Student Data\n");
        printf("2.  Modify Name or Branch of a Student\n");
        printf("3.  Delete a Student Information\n");
        printf("4.  Search List of Student Branchwise\n");
        printf("5.  Search Student by Name\n");
        printf("6.  EXIT\n");
        printf("\n7.  Display\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            insert();
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            modify();
            break;
        case 3:
            printf("\e[1;1H\e[2J");
            delete ();
            break;
        case 4:
            printf("\e[1;1H\e[2J");
            searchbranch();
            break;
        case 5:
            printf("\e[1;1H\e[2J");
            searchname();
            break;
        case 6:
            return 0;
            break;
        case 7:
            display();
            break;
        default:
            printf("Choose a Valid Option\n");
        }
    }
}

int upstr(char *s)
{
    while (*s)
    {
        if (*s >= 'a' && *s <= 'z')
        {
            *s = *s - 32;
        }
        s++;
    }
    return 0;
}

int insert()
{
    FILE *datafile;
    datafile = fopen("students.dat", "w");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return 1;
    }
    fclose(datafile);
    while (1)
    {
        printf("\e[1;1H\e[2J");
        int flag = 1, id = 0;
        struct student stu1;
        struct student stu2;
        printf("Enter Student ID : ");
        scanf("%d", &id);
        datafile = fopen("students.dat", "r");
        while (fread(&stu2, sizeof(struct student), 1, datafile))
        {
            if (stu2.id == id)
            {
                printf("Student Already Exists\n");
                flag = 0;
                break;
            }
        }
        fclose(datafile);
        if (flag)
        {
            char name[50];
            char branch[10];
            stu1.id = id;
            printf("Enter Student Name : ");
            scanf(" %[^\n]%*c", name);
            printf("Enter Student Branch : ");
            scanf(" %[^\n]%*c", branch);
            upstr(name);
            upstr(branch);
            int checkbranch = !(strcmp(branch, "CSE") == 0 || strcmp(branch, "ECE") == 0 || strcmp(branch, "EE") == 0);
            if (checkbranch)
            {
                printf("Banch Not Valid \n");
            }
            else
            {
                strcpy(stu1.name, name);
                strcpy(stu1.branch, branch);
                datafile = fopen("students.dat", "a");
                fwrite(&stu1, sizeof(struct student), 1, datafile);
                if (fwrite != 0)
                {
                    printf("contents to file written successfully !\n");
                }
                else
                {
                    printf("error writing file !\n");
                }
                fclose(datafile);
            }
        }
        char c;
        printf("Enter Another Student [y/n] : ");
        scanf(" %c", &c);
        if (c == 'y')
        {
            printf("\e[1;1H\e[2J");
            continue;
        }
        else
        {
            break;
        }
    }
    struct student inp;
    datafile = fopen("students.dat", "r");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        return 0;
    }
    while (fread(&inp, sizeof(struct student), 1, datafile))
    {
        printf("roll_no = %d name = %s branch = %s\n", inp.id, inp.name, inp.branch);
    }
    fclose(datafile);
    printf("\e[1;1H\e[2J");
    return 0;
}

int modify()
{
    display();
    FILE *datafile, *temp;
    temp = fopen("students2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    datafile = fopen("students.dat", "r");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return 1;
    }
    fclose(datafile);
    int e = 0;
    while (1)
    {
        printf("\e[1;1H\e[2J");
        display();
        int id = 0, flag = 1;
        struct student stu;
        struct student stu1;
        printf("Enter Student ID to be Modified : ");
        scanf(" %d", &id);
        datafile = fopen("students.dat", "r");
        while (fread(&stu, sizeof(struct student), 1, datafile))
        {
            if (stu.id == id)
            {
                flag = 0;
                break;
            }
        }
        fclose(datafile);
        if (flag)
        {
            printf("Entry Does Not Exists\n");
        }
        else
        {
            char n, b;
            char name[50];
            char branch[10];
            printf("Modify Name? [1/0] : ");
            scanf(" %c", &n);
            printf("Modify Branch? [1/0] : ");
            scanf(" %c", &b);
            if (n != '0')
            {
                printf("Enter Student Name : ");
                scanf(" %[^\n]%*c", name);
                upstr(name);
            }
            if (b != '0')
            {
                printf("Enter Student Branch : ");
                scanf(" %[^\n]%*c", branch);
                upstr(branch);
                int checkbranch = !(strcmp(branch, "CSE") == 0 || strcmp(branch, "ECE") == 0 || strcmp(branch, "EE") == 0);
                if (checkbranch)
                {
                    n = '0';
                    b = '0';
                    printf("Banch Not Valid \n");
                }
            }
            if (n != '0' || b != '0')
            {
                temp = fopen("students2.dat", "w");
                datafile = fopen("students.dat", "r");
                while (fread(&stu, sizeof(struct student), 1, datafile))
                {
                    if (stu.id == id)
                    {
                        stu1.id = stu.id;
                        if (n != '0')
                        {
                            strncpy(stu1.name, name, 50);
                        }
                        else
                        {
                            strncpy(stu1.name, stu.name, 50);
                        }
                        if (b != '0')
                        {
                            strncpy(stu1.branch, branch, 10);
                        }
                        else
                        {
                            strncpy(stu1.branch, stu.branch, 10);
                        }
                        fwrite(&stu1, sizeof(struct student), 1, temp);
                        continue;
                    }
                    stu1.id = stu.id;
                    strncpy(stu1.name, stu.name, 50);
                    strncpy(stu1.branch, stu.branch, 10);
                    fwrite(&stu1, sizeof(struct student), 1, temp);
                }
                printf("Student Details Modified Successfuly\n");
                e = 1;
                fclose(temp);
                fclose(datafile);
                remove("students.dat");
                rename("students2.dat", "students.dat");
            }
        }
        char c;
        printf("Modify Another Student [y/n] : ");
        scanf(" %c", &c);
        if (c == 'y')
        {
            printf("\e[1;1H\e[2J");
            continue;
        }
        else
        {
            break;
        }
    }
    if (!e)
    {
        remove("students2.dat");
        printf("\e[1;1H\e[2J");
        return 0;
    }
    printf("\e[1;1H\e[2J");
    return 0;
}

int delete ()
{
    FILE *datafile, *temp;
    temp = fopen("students2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    datafile = fopen("students.dat", "r");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return 1;
    }
    fclose(datafile);
    int e = 0;
    while (1)
    {
        printf("\e[1;1H\e[2J");
        display();
        int id = 0, flag = 1;
        struct student stu;
        struct student stu1;
        printf("Enter Student ID to be deleted : ");
        scanf(" %d", &id);
        datafile = fopen("students.dat", "r");
        while (fread(&stu, sizeof(struct student), 1, datafile))
        {
            if (stu.id == id)
            {
                flag = 0;
                break;
            }
        }
        fclose(datafile);
        if (flag)
        {
            printf("Entry Does Not Exists\n");
        }
        else
        {
            temp = fopen("students2.dat", "w");
            datafile = fopen("students.dat", "r");
            while (fread(&stu, sizeof(struct student), 1, datafile))
            {
                if (stu.id == id)
                {
                    continue;
                }
                stu1.id = stu.id;
                strncpy(stu1.name, stu.name, 50);
                strncpy(stu1.branch, stu.branch, 10);
                fwrite(&stu1, sizeof(struct student), 1, temp);
            }
            printf("Student Details Deleted Successfuly\n");
            e = 1;
            fclose(temp);
            fclose(datafile);
            remove("students.dat");
            rename("students2.dat", "students.dat");
            mdelete(id);
        }
        char c;
        printf("Delete Another Student [y/n] : ");
        scanf(" %c", &c);
        if (c == 'y')
        {
            printf("\e[1;1H\e[2J");
            continue;
        }
        else
        {
            break;
        }
    }
    if (!e)
    {
        remove("students2.dat");
        printf("\e[1;1H\e[2J");
        return 0;
    }
    printf("\e[1;1H\e[2J");
    return 0;
}

int searchbranch()
{
    char branch[10];
    printf("Enter Student Branch : ");
    scanf(" %[^\n]%*c", branch);
    upstr(branch);
    int checkbranch = !(strcmp(branch, "CSE") == 0 || strcmp(branch, "ECE") == 0 || strcmp(branch, "EE") == 0);
    if (checkbranch)
    {
        printf("Banch Not Valid \n");
    }
    else
    {
        int flag = 0;
        printf("\e[1;1H\e[2J");
        FILE *datafile;
        struct student inp;
        datafile = fopen("students.dat", "r");
        if (datafile == NULL)
        {
            fprintf(stderr, "\nError to open the file\n");
            return 0;
        }
        while (fread(&inp, sizeof(struct student), 1, datafile))
        {
            if (strcmp(inp.branch, branch) == 0)
            {
                flag = 1;
                printf("roll_no = %d name = %s branch = %s\n", inp.id, inp.name, inp.branch);
            }
        }
        if (!flag)
        {
            printf("No Entry Found\n");
        }
        fclose(datafile);
    }
    return 0;
}

int searchname()
{
    char name[50];
    printf("Enter Student Name : ");
    scanf(" %[^\n]%*c", name);
    upstr(name);
    int flag = 0;
    printf("\e[1;1H\e[2J");
    FILE *datafile;
    struct student inp;
    datafile = fopen("students.dat", "r");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        return 0;
    }
    while (fread(&inp, sizeof(struct student), 1, datafile))
    {
        if (strcmp(inp.name, name) == 0)
        {
            flag = 1;
            printf("roll_no = %d name = %s branch = %s\n", inp.id, inp.name, inp.branch);
        }
    }
    if (!flag)
    {
        printf("No Entry Found\n");
    }
    fclose(datafile);
    return 0;
}

int display()
{
    printf("\e[1;1H\e[2J");
    FILE *datafile;
    struct student inp;
    datafile = fopen("students.dat", "r");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        return 0;
    }
    printf("\n");
    while (fread(&inp, sizeof(struct student), 1, datafile))
    {
        printf("roll_no = %d name = %s branch = %s\n", inp.id, inp.name, inp.branch);
    }
    printf("\n");
    fclose(datafile);
}