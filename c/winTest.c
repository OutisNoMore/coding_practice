#include <stdio.h>
#include <windows.h>

int main(){
  SYSTEMTIME localTime;
  SYSTEMTIME sysTime;

  GetLocalTime(&localTime);
  GetSystemTime(&sysTime);
  printf("Hello world\n");
  printf("The local time is: %02d:%02d:%02d\n", localTime.wHour, localTime.wMinute, localTime.wSecond);
  printf("The system time is: %02d:%02d:%02d\n", sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	
  return 0;
}