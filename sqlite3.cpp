#include<string.h>
#include<iostream>
#include<sqlite3.h>
#include<stdlib.h>
using namespace std;

int printout(void *arg,int column,char **value,char **name)
{
    int i;
    for(i = 0;i < column;i++)
    {
    	printf("%s = %s",name[i],value[i]);
    }
    printf("\n");
    return 0;
}

int printspecify(void *arg,int column,char **value,char **name)
{
    int i;
    for(i = 0;i < column;i++)
    {
      printf("%s = %s",name[i],value[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    sqlite3 *ppdb;
    int ret = sqlite3_open("student.db",&ppdb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(ppdb));
	exit(1);
    }
    
    //create table
    char sql[128]={0};
    sprintf(sql,"create table if not exists student (id integer,name text,age integer);");
    ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_creat_table: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    }
    
    //insert data
    int age,id;
    char name[32] = {0};
    memset(sql,0,sizeof(sql));
    sprintf(sql,"insert into student(id,name,age) values(11,\"dd\",33);");
    ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_insert data: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    } 
    
    //show data
    //first way
    printf("show data first way\n");
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select * from student;");
    ret = sqlite3_exec(ppdb,sql,printout,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_print_data: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    } 
    //second way
    printf("show data second way\n");
    char **result;
    int row,column;
    ret = sqlite3_get_table(ppdb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_print_data_second: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    } 
    
    int i,j;
    int Index = column;
    for(i = 0;i < row;i++)
    {
    	for(j = 0;j < column;j++)
    	{
    	    printf("%s = %s",result[j],result[Index]);
    	    Index++;
    	}
    	printf("\n");
    }
    
    //specific data
    printf("show specific data\n");
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select * from student where age == 22");
    ret = sqlite3_exec(ppdb,sql,printout,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_specific data: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    }  
    
    //delete data
    memset(sql,0,sizeof(sql));
    sprintf(sql,"delete from student where age = 33;");
    ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
      printf("sqlite3_delete_data:%s \n",sqlite3_errmsg(ppdb));
  exit(1);
    }
    
    printf("show data after delete\n");
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select * from student;");
    ret = sqlite3_exec(ppdb,sql,printout,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_print_data: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    } 


}
