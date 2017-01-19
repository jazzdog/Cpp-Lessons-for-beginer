#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>

#define OP_ADD  1  //加法
#define OP_SUB  2  //減法
#define OP_MUTP 3  //乘法
#define OP_DIV  4  //除法

void goClass2(int nExpNumber)
{
	bool blContinue = true;
	int nAns = -1;
	switch (nExpNumber)
	{
		case 1:
			nAns = C2_ex1_functionReturn(10, 1000, OP_DIV); //嘗試使用 OP_ADD,OP_SUB,OP_MUTP,OP_DIV
			printf("[goClass2]得到答案:(%d)\n",nAns);
			break;
		case 2:
			C2_ex2_Pointer1();
			break;
		case 3:
			C2_ex3_Pointer2(100);
			break;
		case 4:
			C2_ex4_Pointer3();
			break;
		case 5:
			C2_ex5_Pointer4();
			break;
		case 6:
			C2_ex6_Pointer5();
			break;
		case 7:
			printLottery();
				break;
		case 8:
			printLottery_Homework();
			break;
		default:
			return;
			break;	
	}
	printf("\n從class2回到主函式(輸入bye結束)...\n");

}
int C2_ex1_functionReturn(int nNumber1, int nNumber2,int nOpSelect)
{
	int nAns = -1;
	switch (nOpSelect)
	{
	case OP_ADD:
		nAns = nNumber1 + nNumber2;
		printf("執行加法(%d): [%d]+[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);
		
		break;
	case OP_SUB:
		nAns = nNumber1 - nNumber2;
		printf("執行減法(%d): [%d]-[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);

		break;
	case OP_MUTP:
		nAns = nNumber1 * nNumber2;
		printf("執行乘法(%d): [%d]*[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);

		break;
	case OP_DIV:
		nAns = nNumber1 / nNumber2;
		printf("執行除法(%d): [%d]/[%d]=[%d]\n", nOpSelect, nNumber1, nNumber2, nAns);

		break;
	}

	return nAns;
}
void C2_ex2_Pointer1()
{
	int nBePointerNumber = 300;
	printf("nBePointerNumber=%d Addr=0x%X\n", nBePointerNumber, &nBePointerNumber);
	int* pnNumber = NULL;
	//printf("*pnNumber=%d\n", *pnNumber); //why?
	printf("pnNumber=0x%X Addr=0x%X\n",  pnNumber, &pnNumber);
	
	pnNumber = &nBePointerNumber;
	printf("★[pnNumber給予值之後]\n");
	printf("*pnNumber=%d\n", *pnNumber); //why?
	printf("pnNumber=0x%X Addr=0x%X\n", pnNumber, &pnNumber);

	/*======================================================================
		一般變數
		int nNumber = 123;
		nNumber=>數值
		&nNumber=>變數在記憶體中的位址

		指標
		int* pnNumber=&nNumber;
		pnNumber=>存放[變數在記憶體中的位址]
		&pnNumber => 指標在記憶體中的位址
		*pnNumber => 取出 (存放在 pnNumber 中 [變數在記憶體中的位址] 的) 數值


		位址       變數
		0x1DFD2C    300
		0x1DFD20   0x1DFD2C
	
		 pnNumber 等於 &nNumber
		*pnNumber 等於  nNumber
	===================================================================*/

	*pnNumber = 900;
	printf("★[改變pnNumber保存位址的變數值之後]\n");
	printf("nBePointerNumber=%d Addr=0x%X\n", nBePointerNumber, &nBePointerNumber);
	
	printf("*pnNumber=%d\n", *pnNumber); //why?
	printf("pnNumber=0x%X Addr=0x%X\n", pnNumber, &pnNumber);

}


void C2_ex3_Pointer2(int nArraySize)
{
	if (nArraySize < 100)
		nArraySize += 100; //why?

	///宣告指標指向一塊nArraySize個int大小的記憶體
	int *pnNumAry = new int[nArraySize]; 
	memset(pnNumAry, 0, nArraySize*4); ///初始化

	///宣告一塊記憶體大小為 4* nArraySize byte
	int *pnMemory = (int*)malloc(4* nArraySize);
	memset(pnMemory, 0, nArraySize*4);//初始化

	///宣告一個有100個int大小的陣列
	int  nNumAry[100] = {0}; 

	///宣告一個指標指向int陣列 nNumAry
	int* pnNumber = nNumAry;

	printf("sizeof(pnNumAry)=%d Addr:0x%X\n", sizeof(pnNumAry), pnNumAry);
	printf("sizeof(nNumAry)=%d ★ Addr:0x%X\n", sizeof(nNumAry), nNumAry);
	printf("sizeof(pnNumber)=%d Addr:0x%X\n", sizeof(pnNumber), pnNumber);
	printf("sizeof(pnMemory)=%d Addr:0x%X\n", sizeof(pnMemory), pnMemory);

	/*================================================
		int  nAryNumber[];
		int* paryNumber;
		  paryNumber     等於 nAryNumber 
		*(paryNumber+0)  等於 nAryNumber[0] 等於 *(nAryNumber+0)
		*(paryNumber+1)  等於 nAryNumber[1] 等於 *(nAryNumber+1)

	=================================================*/

	//再下面這行設定[中斷點]
	for (int i = 0; i < 100; i++) 
	{
		*(pnNumber+i) = i;
		pnNumAry[i] = i;
		pnMemory[i] = i;
	}

	for (int j = 0; j < 100; j++)
	{
		printf("<%d>\n",j);
		printf("[nNumAry]數值陣列\n");
		printf("nNumAry[%d]=%d (Addr:0x%X (nNumAry+%d))\n"  , j, nNumAry[j], nNumAry + j, j);
		printf("[pnNumber]指標指向nNumAry數值陣列\n");
		printf("pnNumber[%d]=%d (Addr:0x%X (pnNumber+%d))\n", j,pnNumber[j],pnNumber + j, j);
		printf("*(pnNumber+%d)[%d]=%d (Addr:0x%X (pnNumber+%d))\n", j, j, *(pnNumber + j), pnNumber + j, j);
		printf("[pnNumAry]指標宣告指向陣列\n");
		printf("pnNumAry[%d]=%d (Addr:0x%X (pnNumAry+%d))\n", j, pnNumAry[j], pnNumAry + j, j);
		printf("*(pnNumAry+%d)[%d]=%d (Addr:0x%X (pnNumAry+%d))\n", j, j, *(pnNumAry + j), pnNumAry + j, j);
		printf("[pnMemory]指標宣告指向記憶體\n");
		printf("pnMemory[%d]=%d (Addr:0x%X (pnMemory+%d))\n", j, pnMemory[j], pnMemory + j, j);
		printf("*(pnMemory+%d)[%d]=%d (Addr:0x%X (pnMemory+%d))\n", j, j, *(pnMemory + j), pnMemory + j, j);

		
	}
	delete []pnNumAry;
	free(pnMemory);

}

void C2_ex4_Pointer3()
{
	int nNumber1=100;
	int* pnNumber1 = &nNumber1;
	int** ppnNumber1 = &pnNumber1;

	printf("nNumber1=%d Addr=0x%X\n", nNumber1, &nNumber1);
	printf("*pnNumber1=%d pnNumber1=0x%X Addr=0x%X\n", *pnNumber1,pnNumber1, &pnNumber1);
	printf("**ppnNumber1=%d *ppnNumber1=0x%X ppnNumber1=0x%X Addr=0x%X\n", **ppnNumber1, *ppnNumber1, ppnNumber1, &ppnNumber1);

}

void C2_ex5_Pointer4()
{
	int* pNumArry[10]; //陣列 中每個元素都是int指標
	int(*pArryNum)[10]; //指標 指向一個int[10]的陣列
	int AryNum[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		*(AryNum + i) = i; ///why?
		pNumArry[i] = (AryNum + i);
	}

	pArryNum = &AryNum;


	for (int j = 0; j < 10; j++)
	{
		printf("====<%d>=====\n",j);
		printf("AryNum[%d]=%d Addr[AryNum+%d]=0x%X Addr(AryNum)=0x%X\n", j, AryNum[j], j, AryNum + j, AryNum);
		printf("*(AryNum+%d)=%d Addr[AryNum+%d]=0x%X\n", j, (*AryNum+j), j, AryNum + j);
		printf("*(pNumArry[%d])=%d pNumArry[%d] =0x%X  Addr=0x%X\n", 
			j, *(pNumArry[j]), j, pNumArry[j], pNumArry+j);
		printf("*pArryNum[%d]=%d pArryNum=0x%X\n",
			j, (*pArryNum)[j], pArryNum);


	}

	//Q: pArryNum+1==??


	/*
	★★★[口訣]★★★
	●
	()[]是第一優先權左結合,
	左結合=> x()[] ==> (x<-())<-[]

	●
	而*是第二優先權右結合。
	右結合=> **x =>  *->(*->x)

	在看變數宣告時,如同運算式的推演過程,必須遵守C程式語言對*()[]的優先權定義。接下來請讀者背誦下面的口訣

	* 看見[]就說array[] of (一個陣列裡面有...)
	* 看見*就說pointer to (一個指標指向...)
	* 看見變數後面的()就說function() returning (一個函式回傳...)

	上述口訣配合*()[]的優先權,依序找出其執行的順序,每看到運算符號就把這幾句口訣念出來。因此變數的意義如下面範例

	char *x; // x: a pointer to char (一個指標指向....char)
	char x[3]; // x: an array[3] of char (一個陣列裡面有....char)
	char x(); // x: a function() returning char (一個函式回傳...char)
	char *x[3]; // x: an array[3] of pointer to char (一個陣列裡面有...一個指標指向....char)
	char (*x)[3]; // x: a pointer to array[3] of char (一個指標指向...一個陣列裡面有...char)
	char **x; // x: a pointer to pointer to char
	char *x(); // x: a function() returning pointer to char
	char *x()[3]; // x: a function() returning array[3] of pointer to char
	char (*x[])(); // x: an array[] of pointer to function() returning char
	char (*x())(); // x: a function() returning pointer to function() returning char
	char (*(*x)[])(int, int); // x: a pointer to array[] of pointer to function(int,int) returning char

	*/
}

void C2_ex6_Pointer5()
{
	/*
				[0]---->[0][0]='A', [0][1]='B'
	the2DArray
				[1]---->[1][0]=2, [1][1]=4, [1][2]=6, ....
	*/
	char the2DArray[2][10] = { {'A','B'}, {2,4,6,8,10,12,14,16,18,20} };
	char* ptheArray_D0 = the2DArray[0];
	char* ptheArray_D1 = the2DArray[1];
	char* pPointArray[2] = { ptheArray_D0, ptheArray_D1 };
	char** ppPointToPointArray = pPointArray;

	printf("列印陣列 the2DArray[2][10]....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
			printf("the2DArray[%d][%d]=%d\n", nD1, nD2, the2DArray[nD1][nD2]);
	}
	printf("列印指標 ptheArray_D0 與 ptheArray_D1....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
		{
			if (nD1==0)
				printf("ptheArray_D0[%d][%d]=%d (%c)\n", nD1, nD2, *(ptheArray_D0 + nD2), *(ptheArray_D0 + nD2));
			if (nD1 == 1)
				printf("ptheArray_D1[%d][%d]=%d\n", nD1, nD2, *(ptheArray_D1 + nD2));
		}
	}

	printf("列印陣列指標 pPointArray....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
		{
			
			printf("pPointArray[%d][%d]=%d\n", nD1, nD2, *(pPointArray[nD1] + nD2));
		}
	}

	printf("列印雙重指標 ppPointToPointArray....\n");
	for (int nD1 = 0; nD1 < 2; nD1++)
	{
		for (int nD2 = 0; nD2 < 10; nD2++)
		{

			printf("pPointArray[%d][%d]=%d\n", nD1, nD2, *(*(ppPointToPointArray+nD1) + nD2));
		}
	}

}

void printLottery()
{
	//是否可以用統一發票獎項來替代?為什麼?

	setlocale(LC_ALL, ""); //設定中文
	//wchar_t aryLty1051104[2][10] = { { L"第1051104期" }, { 16, 14, 22, 23, 30, 31 } };

	//要顯示寬字元(wchar_t)字串，前方要用L""來表示
	wchar_t aryLty1051104[2][10] = { { 0 }, { 0 } };
	memcpy_s(aryLty1051104[0], 10 * 2, L"第1051104期", sizeof(L"第1051104期"));
	aryLty1051104[1][0] = 16;
	aryLty1051104[1][1] = 14;
	aryLty1051104[1][2] = 22;
	aryLty1051104[1][3] = 23;
	aryLty1051104[1][4] = 30;
	aryLty1051104[1][5] = 31;

	wchar_t aryLty1051111[2][10] = { { L"第1051111期" }, { 2, 8, 25, 29, 30, 41 } };
	wchar_t aryLty1051118[2][10] = { { L"第1051118期" }, { 3, 14, 17, 19, 20, 31 } };
	wchar_t aryLty1051125[2][10] = { { L"第1051125期" }, { 18, 20, 22, 27, 31, 35 } };
	wchar_t(*paryAll[4])[2][10]; //請寫出敘述，這是甚麼宣告?
	paryAll[0] = &aryLty1051104;
	paryAll[1] = &aryLty1051111;
	paryAll[2] = &aryLty1051118;
	paryAll[3] = &aryLty1051125;

	for (int i = 0; i < 4; i++)
	{

		printf("\n<%d> [%S]====\n", i, ((*(paryAll[i]))[0]));
		for (int j = 0; j <10; j++)
		{
			int nNubmer = (*(paryAll[i]))[1][j];
			if (nNubmer > 0)
				printf("[%02d]", nNubmer);
		}

	}

}


/*
作業:
將printLottery()用指標改寫陣列

*/



