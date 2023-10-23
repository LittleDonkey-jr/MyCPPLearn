#include<iostream>
#include<string.h>
#include "cJSON.h"
#include "cJSON.c"
#include<sqlite3.h>
#include<stdlib.h>
using namespace std;

int main()
{
    sqlite3 *ppDb;
    int ret = sqlite3_open("student.db",&ppDb);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_open: %s\n",sqlite3_errmsg(ppDb));
        exit(1);
    } 
    return 0;
}
