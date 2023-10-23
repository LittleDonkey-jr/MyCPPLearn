#include <iostream>
#include <sqlite3.h>
#include <cstring>
#include <stdlib.h>


int printout(void *arg,int column,char **value,char **name)
{
    int i;
    for(i = 0;i < column;i++)
    {
    	printf("%s = %s",name[i],value[i]);
      printf(",");
    }
    printf("\n");
    return 0;
}

int main()
{
    sqlite3 *ppdb;
    char sql[120] = {0};
    int ret;
    ret = sqlite3_open("temperature.db",&ppdb);
    if(ret != SQLITE_OK)
    {
       printf("open temperature.db fail");
       exit(1);
    }
    memset(sql,0,sizeof(sql));
    sprintf(sql,"create table if not exists temp(id integer,cpu integer,env integer); ");
    ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
       printf("create table_temperature fail");
       exit(1);
    }
    
    int i;
    for(i = 1;i <= 10;i++)
    {	    
       memset(sql,0,sizeof(sql));
       sprintf(sql,"insert into temp(id,cpu,env) values(%d,42000,23000);",i);
       ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
       if(ret != SQLITE_OK)
       {
         printf("add data to temp error");
         exit(1);
       }
    }
    
    printf("show data\n");
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select * from temp;");
    ret = sqlite3_exec(ppdb,sql,printout,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_print_data: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    }

   if(i=10)
   {
     for(i=1;i <= 10;i++)
     {
        memset(sql,0,sizeof(sql));
        sprintf(sql,"update temp set cpu = 44000,env = 24000 where id = %d ;",i);
        ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
        if(ret != SQLITE_OK)
        {
          printf("sqlite3_update data: %s\n",sqlite3_errmsg(ppdb));
	  exit(1);
        }

     }
   }


    printf("show data\n");
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select * from temp;");
    ret = sqlite3_exec(ppdb,sql,printout,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_print_data: %s\n",sqlite3_errmsg(ppdb));
	exit(1);
    }
    
    //delete data
    memset(sql,0,sizeof(sql));
    sprintf(sql,"delete from temp where id <= 11;");
    ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
      printf("sqlite3_delete_data:%s \n",sqlite3_errmsg(ppdb));
  exit(1);
    }  
   

   



}

