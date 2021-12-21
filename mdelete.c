#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentmarks
{
    int id;
    float dbms;
    float ds;
    float c;
    float total;
    float percent;
};

int mdelete(int id)
{
    FILE *datafile, *temp;
    temp = fopen("marks2.dat", "w");
    if (temp == NULL)
    {
        fprintf(stderr, "\nError occured exiting\n");
        return 1;
    }
    fclose(temp);
    datafile = fopen("marks.dat", "r");
    if (datafile == NULL)
    {
        return 1;
    }
    fclose(datafile);
    int e = 0;
    int flag = 1;
    struct studentmarks stu;
    struct studentmarks stu1;
    datafile = fopen("marks.dat", "r");
    while (fread(&stu, sizeof(struct studentmarks), 1, datafile))
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
        temp = fopen("marks2.dat", "w");
        datafile = fopen("marks.dat", "r");
        while (fread(&stu, sizeof(struct studentmarks), 1, datafile))
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
        fclose(datafile);
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