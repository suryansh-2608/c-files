#include<stdio.h>

 void filewrite();
 void fileprint();
 void filesort();
 void stid();


void filewrite()
{
  int ID,ch;
  char nam[500], branch[50];
  printf("\n\n press 1 to continue,0 to stop");
  scanf("%d",&ch);
  FILE *fp;
  fp = fopen("student.txt","a");
   
  switch (ch)
  {
  case 0 :
      break;
    case 1 :  
   printf("ENTER STUDENT ID, NAME AND BRANCH \n");
    scanf("%d %s %d",&ID, &nam, &branch);
  fprintf(fp,"%d %s %s\n",ID,nam,branch);
  break;

  default:
      break;
  }
   fclose(fp) ;
}
void fileprint()
{
  int sid[100],x[100],i;
  char name[100][50], branch[50];
  FILE *fp;

  fp = fopen("student.txt","r");
   i=0;
   printf("STUDENT ID      NAME        BRANCH\n");
   while(!feof(fp))
  {
     fscanf(fp,"%d %s %s\n",&sid[i],&name[i],&branch[i]);
     printf(" %d          %s          %s\n",sid[i],name[i],branch[i]);
     i=i+1;
   }
   fclose(fp);
   printf("\n\n\nPRESS ANY KEY");

  }

void stid()
{   int i,id,ch,id1;
    char nam[50], branch[50];
    FILE *fm;

    ch=1;
  while(ch)
  {
    fm = fopen("student.txt","r");
    printf(" \n ENTER STUDENT ID - ");
    scanf("%d",&id1);
      i=0;
   while(! feof(fm))
    {
     fscanf(fm,"%d %s %s\n",&id,&nam,&branch);
     if(id1==id)
    {printf("\nSTUDENT ID     NAME        BRANCH\n ");
     printf(" %d              %s          %S\n",id,nam,branch);
     break;
     }
     else
     i=i+1;
      }
  printf("\n\npress 1 to see student info, 0 to return to main menu\n");
  scanf("%d",&ch);
  fclose(fm);
  }



 }
int main()
{
  int sid[100],x[100],n,i,j,id,c,id1;
  char name[100][10],nam[50], branch[50];
  

     printf("GIVE CHOICE--\n");
     printf("   1 TO ENTER STUDENT INFO.\n");
     printf("   2 TO SEE STUDENT.TXT FILE\n");
     printf("   3 TO PRINT STUDENT INFO. USING STUDENT ID\n");
     printf("   4 TO EXIT\n\n--");
     scanf("%d",&c);

     switch(c)
     {
     case 1:
          filewrite();
     case 2:
          fileprint();
     case 3:  stid();
     case 4:
     default:
     break;
     }

  }