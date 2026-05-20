#include<stdio.h>
typedef struct
{
  int id;
  char name[100];
  float salary;
}Record;
void  storeRecord();
void getMthRecord(int m);
void displayAll();
void deleteRecord(int m);
int countRecords();
int main()
{
  int choice,m;
  while(1)
  {
    printf("1. Store Record\n2. Get Mth Record\n3. Display All Records\n4. Delete Mth Record\n5. Count Records\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: storeRecord(); break;
      case 2: printf("Enter record number to retrieve: ");
              scanf("%d",&m);
              getMthRecord(m); break;
      case 3: displayAll(); break;
      case 4: printf("Enter record number to delete: ");
              scanf("%d",&m);
              deleteRecord(m); break;
      case 5: printf("Total records: %d\n", countRecords()); break;
      case 6: return 0;
      default: printf("Invalid choice! Please try again.\n");
    }
  }
}
void storeRecord()
{
  Record r;
  printf("Enter ID: ");
  scanf("%d",&r.id);
  printf("Enter Name: ");
  scanf("%s",r.name);
  printf("Enter Salary: ");
  scanf("%f",&r.salary);
  
  FILE *fp = fopen("records.dat","ab");
  if(fp == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  fwrite(&r,sizeof(Record),1,fp);
  fclose(fp);
}
void getMthRecord(int m)
{
  FILE *fp = fopen("records.dat","rb");
  if(fp == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  Record r;
  fseek(fp,(m-1)*sizeof(Record),SEEK_SET);
  if(fread(&r,sizeof(Record),1,fp) == 1)
  {
    printf("ID: %d\nName: %s\nSalary: %.2f\n", r.id, r.name, r.salary);
  }
  else
  {
    printf("Record not found!\n");
  }
  fclose(fp);
}
void displayAll()
{
  FILE *fp = fopen("records.dat","rb");
  if(fp == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  Record r;
  while(fread(&r,sizeof(Record),1,fp) == 1)
  {
    printf("ID: %d\nName: %s\nSalary: %.2f\n", r.id, r.name, r.salary);
    printf("-------------------------\n");
  }
  fclose(fp);
}
void deleteRecord(int m)
{
  FILE *fp = fopen("records.dat","rb");
  if(fp == NULL)
  {
    printf("Error opening file!\n");
    return;
  }
  FILE *temp = fopen("temp.dat","wb");
  if(temp == NULL)
  {
    printf("Error opening file!\n");
    fclose(fp);
    return;
  }
  Record r;
  int count = 0;
  while(fread(&r,sizeof(Record),1,fp) == 1)
  {
    count++;
    if(count != m)
    {
      fwrite(&r,sizeof(Record),1,temp);
    }
  }
  fclose(fp);
  fclose(temp);
  
  remove("records.dat");
  rename("temp.dat","records.dat");
}
int countRecords()
{
  FILE *fp = fopen("records.dat","rb");
  if(fp == NULL)
  {
    printf("Error opening file!\n");
    return 0;
  }
  fseek(fp,0,SEEK_END);
  int count = ftell(fp) / sizeof(Record);
  fclose(fp);
  return count;
}
