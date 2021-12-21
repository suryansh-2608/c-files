#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[50];
    char branch[10];
};

struct studentmarks
{
    int id;
    float dbms;
    float ds;
    float c;
    float total;
    float percent;
};

int stuid[50] = {0};
int i = 0;

int upstr(char *s);
int minsert();
int mmodify();
int mdelete(int id);
int msearchper();
int msearchbranchper();
int mdisplay();

int main()
{

    FILE *datafile;
    datafile = fopen("students.dat", "w");
    if (datafile == NULL)
    {
        fprintf(stderr, "\nError\n");
        return 0;
    }
    struct student stu;
    while (fread(&stu, sizeof(struct student), 1, datafile))
    {
        stuid[i] = stu.id;
        i++;
    }
    if (!i)
    {
        printf("\nError opening student databse make sure it is not empty\n");
        return 0;
    }

    for (int p = 0; p < i - 1; p++)
    {
        for (int q = 0; q < i - p - 1; q++)
        {
            if (stuid[q] > stuid[q + 1])
            {
                int temp = stuid[q];
                stuid[q] = stuid[q + 1];
                stuid[q + 1] = temp;
            }
        }
    }
    fclose(datafile);
    while (1)
    {
        int choice = 0;
        printf("SELECT AN OPTION\n");
        printf("1.  Insert Marks of All Registered Students\n");
        printf("2.  Modify Marks\n");
        printf("3.  Search by Threshold %% \n");
        printf("4.  Search by Branch and %%\n");
        printf("5.  EXIT\n");
        printf("\n6.  Display\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            minsert();
            break;
        case 2:
            mmodify();
            break;
        case 3:
            msearchper();
            break;
        case 4:
            msearchbranchper();
            break;
        case 5:
            return 0;
            break;
        case 6:
            printf("\e[1;1H\e[2J");
            mdisplay();
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

int minsert()
{
    FILE *marksfile, *datafile;
    marksfile = fopen("marks.dat", "w");
    if (marksfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return 1;
    }
    fclose(marksfile);
    struct student stu;
    struct studentmarks stu1;
    for (int t = 0; t < i; t++)
    {
        datafile = fopen("students.dat", "r");
        while (fread(&stu, sizeof(struct student), 1, datafile))
        {
            if (stu.id == stuid[t])
            {
                float dbms = 0, ds = 0, c = 0;
                printf("Entery For ID : %d    Name : %s\n", stu.id, stu.name);
                printf("DBMS : ");
                scanf(" %f", &dbms);
                printf("DS : ");
                scanf(" %f", &ds);
                printf("C : ");
                scanf(" %f", &c);
                if (dbms >= 0 && ds >= 0 && c >= 0 && dbms + ds + c <= 300)
                {
                    stu1.id = stu.id;
                    stu1.dbms = dbms;
                    stu1.ds = ds;
                    stu1.c = c;
                    stu1.total = dbms + ds + c;
                    stu1.percent = stu1.total / 3;
                    marksfile = fopen("marks.dat", "a");
                    fwrite(&stu1, sizeof(struct studentmarks), 1, marksfile);
                    if (fwrite != 0)
                    {
                        printf("contents to file written successfully !\n");
                    }
                    else
                    {
                        printf("error writing file !\n");
                    }
                    fclose(marksfile);
                }
                else
                {
                    printf("Wrong Input\n");
                }
                break;
            }
        }
        fclose(datafile);
    }
    struct studentmarks inp;
    marksfile = fopen("marks.dat", "r");
    if (marksfile == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        return 0;
    }
    while (fread(&inp, sizeof(struct studentmarks), 1, marksfile))
    {
        printf("roll_no = %d DBMS = %f DS = %f C = %f TOTAL = %f PERCENTAGE = %f\n", inp.id, inp.dbms, inp.ds, inp.c, inp.total, inp.percent);
    }
    fclose(marksfile);
    printf("\e[1;1H\e[2J");
    return 0;
}

int mmodify()
{
    FILE *datafile, *temp, *marksfile;
    temp = fopen("marks2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    marksfile = fopen("students.dat", "r");
    if (marksfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return 1;
    }
    fclose(marksfile);
    int e = 0;
    while (1)
    {
        int id = 0, flag = 1;
        struct studentmarks stu;
        struct studentmarks stu1;
        printf("Enter Student ID to be Modified : ");
        scanf(" %d", &id);
        marksfile = fopen("marks.dat", "r");
        while (fread(&stu, sizeof(struct studentmarks), 1, marksfile))
        {
            if (stu.id == id)
            {
                flag = 0;
                break;
            }
        }
        fclose(marksfile);
        if (flag)
        {
            printf("Entry Does Not Exists\n");
        }
        else
        {
            char db, d, C;
            float dbms = 0, ds = 0, c = 0;
            printf("Modify DBMS marks? [1/0] : ");
            scanf(" %c", &db);
            printf("Modify DS marks? [1/0] : ");
            scanf(" %c", &d);
            printf("Modify C marks? [1/0] : ");
            scanf(" %c", &C);
            if (db != '0')
            {
                printf("Enter NEW DBMS marks : ");
                scanf(" %f", &dbms);
            }
            if (d != '0')
            {
                printf("Enter NEW DS marks : ");
                scanf(" %f", &ds);
            }
            if (C != '0')
            {
                printf("Enter NEW C marks : ");
                scanf(" %f", &c);
            }
            if (db != '0' || d != '0' || C != '0')
            {
                temp = fopen("marks2.dat", "w");
                marksfile = fopen("marks.dat", "r");
                while (fread(&stu, sizeof(struct studentmarks), 1, marksfile))
                {
                    if (stu.id == id)
                    {
                        stu1.id = stu.id;
                        if (db != '0')
                        {
                            stu1.dbms = dbms;
                        }
                        else
                        {
                            stu1.dbms = stu.dbms;
                        }
                        if (d != '0')
                        {
                            stu1.ds = ds;
                        }
                        else
                        {
                            stu1.ds = stu.ds;
                        }
                        if (C != '0')
                        {
                            stu1.c = c;
                        }
                        else
                        {
                            stu1.c = stu.c;
                        }
                        stu1.total = stu1.dbms + stu1.ds + stu1.c;
                        stu1.percent = stu1.total / 3;
                        fwrite(&stu1, sizeof(struct studentmarks), 1, temp);
                        continue;
                    }
                    stu1.id = stu.id;
                    stu1.dbms = stu.dbms;
                    stu1.ds = stu.ds;
                    stu1.c = stu.c;
                    stu1.total = stu1.dbms + stu1.ds + stu1.c;
                    stu1.percent = stu1.total / 3;
                    fwrite(&stu1, sizeof(struct studentmarks), 1, temp);
                }
                printf("Student Marks Modified Successfuly\n");
                e = 1;
                fclose(temp);
                fclose(marksfile);
                remove("marks.dat");
                rename("marks2.dat", "marks.dat");
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
        remove("marks2.dat");
        printf("\e[1;1H\e[2J");
        return 0;
    }
    printf("\e[1;1H\e[2J");
    return 0;
}



int msearchper()
{
    float per;
    printf("Enter Threshold %% : ");
    scanf(" %f", &per);
    if (per < 0 || per > 100)
    {
        printf("Input Not Valid \n");
    }
    else
    {
        int flag = 0;
        printf("\e[1;1H\e[2J");
        FILE *marksfile, *datafile;
        struct studentmarks inp;
        struct student stu;
        marksfile = fopen("marks.dat", "r");
        if (marksfile == NULL)
        {
            fprintf(stderr, "\nError to open the file\n");
            return 0;
        }
        while (fread(&inp, sizeof(struct studentmarks), 1, marksfile))
        {
            datafile = fopen("students.dat", "r");
            while (fread(&stu, sizeof(struct student), 1, datafile))
            {

                if (stu.id == inp.id)
                {
                    break;
                }
            }
            fclose(datafile);
            if (inp.percent >= per)
            {
                flag = 1;
                printf("roll_no = %d name = %s Percentage = %f\n", inp.id, stu.name, inp.percent);
            }
        }
        if (!flag)
        {
            printf("No Entry Found\n");
        }
        fclose(marksfile);
    }
    return 0;
}

int msearchbranchper()
{
    char branch[10];
    printf("Enter Student Branch : ");
    scanf(" %[^\n]%*c", branch);
    upstr(branch);
    float per;
    printf("Enter Threshold %% : ");
    scanf(" %f", &per);
    int checkbranch = !(strcmp(branch, "CSE") == 0 || strcmp(branch, "ECE") == 0 || strcmp(branch, "EE") == 0);
    if (checkbranch || (per < 0 || per > 100))
    {
        printf("Input Not Valid \n");
    }
    else
    {
        int flag = 0;
        printf("\e[1;1H\e[2J");
        FILE *datafile, *marksfile;
        struct student inp;
        datafile = fopen("students.dat", "r");
        if (datafile == NULL)
        {
            fprintf(stderr, "\nError to open the file\n");
            return 0;
        }
        while (fread(&inp, sizeof(struct student), 1, datafile))
        {
            marksfile = fopen("marks.dat", "r");
            struct studentmarks mark;
            while (fread(&mark, sizeof(struct studentmarks), 1, marksfile))
            {
                if (mark.id == inp.id)
                {
                    break;
                }
            }
            fclose(marksfile);
            if (strcmp(inp.branch, branch) == 0 && mark.percent >= per)
            {
                flag = 1;
                printf("roll_no = %d name = %s branch = %s Percentage = %f\n", inp.id, inp.name, inp.branch, mark.percent);
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

int mdisplay()
{
    FILE *marksfile;
    struct studentmarks inp;
    marksfile = fopen("marks.dat", "r");
    if (marksfile == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        return 0;
    }
    while (fread(&inp, sizeof(struct studentmarks), 1, marksfile))
    {
        printf("roll_no = %d DBMS = %f DS = %f C = %f TOTAL = %f PERCENTAGE = %f\n", inp.id, inp.dbms, inp.ds, inp.c, inp.total, inp.percent);
    }
    fclose(marksfile);
}