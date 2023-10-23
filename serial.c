#include "stdlib.h"
#include "string.h"
#include <stdio.h>
#include <errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<termios.h>
#include <unistd.h>
#include "unistd.h"
#include "MQTTClient.h"
#include "cJSON.h"
#include "myuart.h"

#define FALSE -1
#define TRUE 0

int main(int argc, char* argv[])
{
  int fd;
  int retA;
  char* uart3 = "/dev/ttyS5";//receive envirenment temperture through Uart
  char* uart2 = "/sys/class/thermal/thermal_zone0/temp";//Cpu temperture on linux device
  char rcv_buf[128];
  memset(rcv_buf, 1, sizeof(rcv_buf));
  fd = UART_Open(fd, uart3);
  retA = UART_Init(fd, 115200, 0, 8, 1, 'N');
  if (FALSE == fd)
  {
    printf("Set Port Error\n");
  }
  else
  {
    printf("Set Port Success!\n");
  }
  //数据发送
  /*while(1)
  {
    sleep(1);
    cJSON* cjson_test = NULL;
    char* str = NULL;
    cjson_test = cJSON_CreateObject();
    cJSON_AddStringToObject(cjson_test, "name", "mculover666");
    str = cJSON_Print(cjson_test);
    printf("%s\n", str);
    retA = UART_Send(fd, str, strlen(str));
   }*/
   //数据接收
   while(1)
   {
     sleep(1);
     UART_Recv(fd,rcv_buf,sizeof(rcv_buf));
     if (retA != FALSE)
     {
        printf("%s",rcv_buf);
     }
     else
    {
        printf("\n receive data error!\n");
    }
   }
}



