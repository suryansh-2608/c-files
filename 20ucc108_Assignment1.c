#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

int student_ids[50] = {0};
int i = 0;

int upstr(char *s);
int insert_student();
int modify_student();
int delete_student();
int search_student_branch();
int search_student_name();
int display_student();

int insert_marks();
int modify_marks();
int delete_marks(int id);
int search_marks_per();
int search_marks_branch_per();
int display_marks();

int main()
{
    while (1)
    {
        printf("\e[1;1H\e[2J");
        int c = 0;
        printf("SELECT A DATABASE\n");
        printf("1.  STUDENT DATABASE\n");
        printf("2.  MARKS DATABASE\n");
        printf("3.  EXIT\n");
        printf("Enter Choice : ");
        scanf(" %d", &c);
        switch (c)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            while (1)
            {
                int choice = 0, f = 0;
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
                    insert_student();
                    break;
                case 2:
                    printf("\e[1;1H\e[2J");
                    modify_student();
                    break;
                case 3:
                    printf("\e[1;1H\e[2J");
                    delete_student();
                    break;
                case 4:
                    printf("\e[1;1H\e[2J");
                    search_student_branch();
                    break;
                case 5:
                    printf("\e[1;1H\e[2J");
                    search_student_name();
                    break;
                case 6:
                    f = -1;
                    break;
                case 7:
                    display_student();
                    break;
                default:
                    printf("Choose a Valid Option\n");
                }
                if (f == -1)
                {
                    break;
                }
            }
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            while (1)
            {
                int f = 0;
                FILE *studentdata;
                studentdata = fopen("students.dat", "r");
                if (studentdata == NULL)
                {
                    fprintf(stderr, "\nError opening student databse make sure it exists and is not empty\n");
                    fflush(stdin);
                    getchar();
                    break;
                }
                struct student stu;
                while (fread(&stu, sizeof(struct student), 1, studentdata))
                {
                    student_ids[i] = stu.id;
                    i++;
                }
                if (!i)
                {
                    printf("\nError opening student databse make sure it is not empty\n");
                    fflush(stdin);
                    getchar();
                    break;
                }

                for (int p = 0; p < i - 1; p++)
                {
                    for (int q = 0; q < i - p - 1; q++)
                    {
                        if (student_ids[q] > student_ids[q + 1])
                        {
                            int temp = student_ids[q];
                            student_ids[q] = student_ids[q + 1];
                            student_ids[q + 1] = temp;
                        }
                    }
                }
                fclose(studentdata);
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
                        insert_marks();
                        break;
                    case 2:
                        modify_marks();
                        break;
                    case 3:
                        search_marks_per();
                        break;
                    case 4:
                        search_marks_branch_per();
                        break;
                    case 5:
                        f = -1;
                        break;
                    case 6:
                        printf("\e[1;1H\e[2J");
                        display_marks();
                        break;
                    default:
                        printf("Choose a Valid Option\n");
                    }
                    if (f == -1)
                    {
                        break;
                    }
                }
                if (f == -1)
                {
                    break;
                }
            }
            break;
        case 3:
            return 0;
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

int insert_student()
{
    FILE *studentdata;
    studentdata = fopen("students.dat", "a");
    if (studentdata == NULL)
    {
        fprintf(stderr, "\nError Accessing Database\n");
        return 1;
    }
    fclose(studentdata);
    while (1)
    {
        printf("\e[1;1H\e[2J");
        int flag = 1, id = 0;
        struct student stu1;
        struct student stu2;
        printf("Enter Student ID : ");
        scanf("%d", &id);
        studentdata = fopen("students.dat", "r");
        while (fread(&stu2, sizeof(struct student), 1, studentdata))
        {
            if (stu2.id == id)
            {
                printf("Student Already Exists\n");
                flag = 0;
                break;
            }
        }
        fclose(studentdata);
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
                studentdata = fopen("students.dat", "a");
                fwrite(&stu1, sizeof(struct student), 1, studentdata);
                if (fwrite != 0)
                {
                    printf("Entry Made Successfully\n");
                }
                else
                {
                    printf("Entry Failed\n");
                }
                fclose(studentdata);
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
    studentdata = fopen("students.dat", "r");
    if (studentdata == NULL)
    {
        fprintf(stderr, "\nError in Accessing Database\n");
        return 0;
    }
    printf("ID\tNAME\tBRANCH\n\n");
    while (fread(&inp, sizeof(struct student), 1, studentdata))
    {
        printf("%d\t%s\t%s\n", inp.id, inp.name, inp.branch);
    }
    fclose(studentdata);
    printf("\e[1;1H\e[2J");
    return 0;
}

int modify_student()
{
    display_student();
    FILE *studentdata, *temp;
    temp = fopen("students2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    studentdata = fopen("students.dat", "r");
    if (studentdata == NULL)
    {
        fprintf(stderr, "\nError Accessing Database\n");
        return 1;
    }
    fclose(studentdata);
    int e = 0;
    while (1)
    {
        printf("\e[1;1H\e[2J");
        display_student();
        int id = 0, flag = 1;
        struct student stu;
        struct student stu1;
        printf("Enter Student ID to be Modified : ");
        scanf(" %d", &id);
        studentdata = fopen("students.dat", "r");
        while (fread(&stu, sizeof(struct student), 1, studentdata))
        {
            if (stu.id == id)
            {
                flag = 0;
                break;
            }
        }
        fclose(studentdata);
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
                studentdata = fopen("students.dat", "r");
                while (fread(&stu, sizeof(struct student), 1, studentdata))
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
                fclose(studentdata);
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

int delete_student()
{
    FILE *studentdata, *temp;
    temp = fopen("students2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    studentdata = fopen("students.dat", "r");
    if (studentdata == NULL)
    {
        fprintf(stderr, "\nError Accessing Database\n");
        return 1;
    }
    fclose(studentdata);
    int e = 0;
    while (1)
    {
        printf("\e[1;1H\e[2J");
        display_student();
        int id = 0, flag = 1;
        struct student stu;
        struct student stu1;
        printf("Enter Student ID to be deleted : ");
        scanf(" %d", &id);
        studentdata = fopen("students.dat", "r");
        while (fread(&stu, sizeof(struct student), 1, studentdata))
        {
            if (stu.id == id)
            {
                flag = 0;
                break;
            }
        }
        fclose(studentdata);
        if (flag)
        {
            printf("Entry Does Not Exists\n");
        }
        else
        {
            temp = fopen("students2.dat", "w");
            studentdata = fopen("students.dat", "r");
            while (fread(&stu, sizeof(struct student), 1, studentdata))
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
            fclose(studentdata);
            remove("students.dat");
            rename("students2.dat", "students.dat");
            delete_marks(id);
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

int search_student_branch()
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
        FILE *studentdata;
        struct student inp;
        studentdata = fopen("students.dat", "r");
        if (studentdata == NULL)
        {
            fprintf(stderr, "\nError in Accessing Database\n");
            return 0;
        }
        printf("ID\tNAME\tBRANCH\n");
        while (fread(&inp, sizeof(struct student), 1, studentdata))
        {
            if (strcmp(inp.branch, branch) == 0)
            {
                flag = 1;
                printf("%d\t%s\t%s\n", inp.id, inp.name, inp.branch);
            }
        }
        if (!flag)
        {
            printf("\e[1;1H\e[2J");
            printf("No Entry Found\n");
        }
        fclose(studentdata);
    }
    return 0;
}

int search_student_name()
{
    char name[50];
    printf("Enter Student Name : ");
    scanf(" %[^\n]%*c", name);
    upstr(name);
    int flag = 0;
    printf("\e[1;1H\e[2J");
    FILE *studentdata;
    struct student inp;
    studentdata = fopen("students.dat", "r");
    if (studentdata == NULL)
    {
        fprintf(stderr, "\nError in Accessing Database\n");
        return 0;
    }
    printf("ID\tNAME\tBRANCH\n");
    while (fread(&inp, sizeof(struct student), 1, studentdata))
    {
        if (strcmp(inp.name, name) == 0)
        {
            flag = 1;
            printf("%d\t%s\t%s\n", inp.id, inp.name, inp.branch);
        }
    }
    if (!flag)
    {
        printf("\e[1;1H\e[2J");
        printf("No Entry Found\n");
    }
    fclose(studentdata);
    return 0;
}

int display_student()
{
    printf("\e[1;1H\e[2J");
    FILE *studentdata;
    struct student inp;
    studentdata = fopen("students.dat", "r");
    if (studentdata == NULL)
    {
        fprintf(stderr, "\nError in Accessing Database\n");
        return 0;
    }
    printf("\n");
    printf("ID\tNAME\tBRANCH\n\n");
    while (fread(&inp, sizeof(struct student), 1, studentdata))
    {
        printf("%d\t%s\t%s\n", inp.id, inp.name, inp.branch);
    }
    printf("\n");
    fclose(studentdata);
}

int insert_marks()
{
    FILE *marksdata, *studentdata;
    marksdata = fopen("marks.dat", "w");
    if (marksdata == NULL)
    {
        fprintf(stderr, "\nError Accessing Database\n");
        return 1;
    }
    fclose(marksdata);
    struct student stu;
    struct studentmarks stu1;
    for (int t = 0; t < i; t++)
    {
        studentdata = fopen("students.dat", "r");
        while (fread(&stu, sizeof(struct student), 1, studentdata))
        {
            if (stu.id == student_ids[t])
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
                    marksdata = fopen("marks.dat", "a");
                    fwrite(&stu1, sizeof(struct studentmarks), 1, marksdata);
                    if (fwrite != 0)
                    {
                        printf("Entry Made Successfully\n");
                    }
                    else
                    {
                        printf("Entry Failed\n");
                    }
                    fclose(marksdata);
                }
                else
                {
                    printf("Wrong Input\n");
                    t--;
                }
                break;
            }
        }
        fclose(studentdata);
    }
    struct studentmarks inp;
    marksdata = fopen("marks.dat", "r");
    if (marksdata == NULL)
    {
        fprintf(stderr, "\nError in Accessing Database\n");
        return 0;
    }
    printf("ID\tDBMS\tDS\tC\tTOTAL\tPERCENTAGE\n\n");
    while (fread(&inp, sizeof(struct studentmarks), 1, marksdata))
    {
        printf("%d\t%f\t%f\t%f\t%f\t%f\n", inp.id, inp.dbms, inp.ds, inp.c, inp.total, inp.percent);
    }
    fclose(marksdata);
    printf("\e[1;1H\e[2J");
    return 0;
}

int modify_marks()
{
    FILE *studentdata, *temp, *marksdata;
    temp = fopen("marks2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    marksdata = fopen("students.dat", "r");
    if (marksdata == NULL)
    {
        fprintf(stderr, "\nError Accessing Database\n");
        return 1;
    }
    fclose(marksdata);
    int e = 0;
    while (1)
    {
        int id = 0, flag = 1;
        struct studentmarks stu;
        struct studentmarks stu1;
        printf("Enter Student ID to be Modified : ");
        scanf(" %d", &id);
        marksdata = fopen("marks.dat", "r");
        while (fread(&stu, sizeof(struct studentmarks), 1, marksdata))
        {
            if (stu.id == id)
            {
                flag = 0;
                break;
            }
        }
        fclose(marksdata);
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
                marksdata = fopen("marks.dat", "r");
                while (fread(&stu, sizeof(struct studentmarks), 1, marksdata))
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
                fclose(marksdata);
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

int delete_marks(int id)
{
    FILE *marksdata, *temp;
    temp = fopen("marks2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    marksdata = fopen("marks.dat", "r");
    if (marksdata == NULL)
    {
        return 1;
    }
    fclose(marksdata);
    int e = 0;
    int flag = 1;
    struct studentmarks stu;
    struct studentmarks stu1;
    marksdata = fopen("marks.dat", "r");
    while (fread(&stu, sizeof(struct studentmarks), 1, marksdata))
    {
        if (stu.id == id)
        {
            flag = 0;
            break;
        }
    }
    fclose(marksdata);
    if (flag)
    {
        printf("Entry Does Not Exists\n");
    }
    else
    {
        temp = fopen("marks2.dat", "w");
        marksdata = fopen("marks.dat", "r");
        while (fread(&stu, sizeof(struct studentmarks), 1, marksdata))
        {
            if (stu.id == id)
            {
                continue;
            }
            stu1.id = stu.id;
            stu1.dbms = stu.dbms;
            stu1.ds = stu.ds;
            stu1.c = stu.c;
            stu1.total = stu.total;
            stu1.percent = stu.percent;
            fwrite(&stu1, sizeof(struct studentmarks), 1, temp);
        }
        printf("Student Marks Deleted Successfuly\n");
        e = 1;
        fclose(temp);
        fclose(marksdata);
        remove("marks.dat");
        rename("marks2.dat", "marks.dat");
    }
    if (!e)
    {
        remove("marks2.dat");
        return 0;
    }
    return 0;
}

int search_marks_per()
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
        FILE *marksdata, *studentdata;
        struct studentmarks inp;
        struct student stu;
        marksdata = fopen("marks.dat", "r");
        if (marksdata == NULL)
        {
            fprintf(stderr, "\nError in Accessing Database\n");
            return 0;
        }
        printf("ID\tNAME\tPERCENTAGE\n");
        while (fread(&inp, sizeof(struct studentmarks), 1, marksdata))
        {
            studentdata = fopen("students.dat", "r");
            while (fread(&stu, sizeof(struct student), 1, studentdata))
            {

                if (stu.id == inp.id)
                {
                    break;
                }
            }
            fclose(studentdata);
            if (inp.percent >= per)
            {
                flag = 1;
                printf("%d\t%s\t%f\n", inp.id, stu.name, inp.percent);
            }
        }
        if (!flag)
        {
            printf("\e[1;1H\e[2J");
            printf("No Entry Found\n");
        }
        fclose(marksdata);
    }
    return 0;
}

int search_marks_branch_per()
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
        FILE *studentdata, *marksdata;
        struct student inp;
        studentdata = fopen("students.dat", "r");
        if (studentdata == NULL)
        {
            fprintf(stderr, "\nError in Accessing Database\n");
            return 0;
        }
        printf("ID\tNAME\tBRANCH\tPERCENTAGE\n");
        while (fread(&inp, sizeof(struct student), 1, studentdata))
        {
            marksdata = fopen("marks.dat", "r");
            struct studentmarks mark;
            while (fread(&mark, sizeof(struct studentmarks), 1, marksdata))
            {
                if (mark.id == inp.id)
                {
                    break;
                }
            }
            fclose(marksdata);
            if (strcmp(inp.branch, branch) == 0 && mark.percent >= per)
            {
                flag = 1;
                printf("%d\t%s\t%s\t%f\n", inp.id, inp.name, inp.branch, mark.percent);
            }
        }
        if (!flag)
        {
            printf("\e[1;1H\e[2J");
            printf("No Entry Found\n");
        }
        fclose(studentdata);
    }
    return 0;
}

int display_marks()
{
    FILE *marksdata;
    struct studentmarks inp;
    marksdata = fopen("marks.dat", "r");
    if (marksdata == NULL)
    {
        fprintf(stderr, "\nError in Accessing Database\n");
        return 0;
    }
    printf("ID\tDBMS\t\tDS\t\tC\t\tTOTAL\t\tPERCENTAGE\n\n");
    while (fread(&inp, sizeof(struct studentmarks), 1, marksdata))
    {
        printf("%d\t%f\t%f\t%f\t%f\t%f\n", inp.id, inp.dbms, inp.ds, inp.c, inp.total, inp.percent);
    }
    fclose(marksdata);
}