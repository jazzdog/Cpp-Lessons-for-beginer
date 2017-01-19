// Win32EmptyConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ClassIndex.h"

//void printLottery_Homework(){}
//bool class1_homework(){ return false; }


int _tmain(int argc, _TCHAR* argv[])
{
	char caDummy[4]={0};
	printf("\n主函式開始(輸入bye結束)...\n");


	goClass1(0);
	goClass2(8);
	goClass3(0);


	fgets(caDummy,4,stdin);
	
	while(strcmp(caDummy,"bye")!=0)
	{
		fgets(caDummy,4,stdin);
		
	}
	return 0;

}






