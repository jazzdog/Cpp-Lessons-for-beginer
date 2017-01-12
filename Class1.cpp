#include "stdafx.h"
#include "ClassIndex.h"


void goClass1(int nExpNumber)
{
	bool blContinue = true;

	switch (nExpNumber)
	{
	case 1:
		C1_ex1_testPrint(); //範例一: 列印
		break;
	case 2:
		C1_ex2_forloop();
		break;
	case 3:
		C1_ex3_while(123);
		break;
	case 4:
		C1_ex4_switch();
		break;
	case 5:
		///重覆執行兌獎函式直到blContinue為false
		while (blContinue == true)
		{
			blContinue = class1_homework();
		}
		printf("離開兌獎函式。\n");
		
		break;
	default:
		return;
		break;
	}
	printf("\n從class1 回到主函式(輸入bye結束)...\n");

}


void C1_ex1_testPrint()
{
	/*
	範例一: 列印
	目標:
	- 了解資料型態: 具有大小，記憶體配置
	- 了解如何列印結果，程式必要的debug除錯手段
	參考資料:
	資料型態(DataType)大小: https://msdn.microsoft.com/en-us/library/s3f49ktz(v=vs.80).aspx
	列印(printf)格式: http://www.cplusplus.com/reference/cstdio/printf/


	*/
	printf("●[testPrint()]============\n\n");
	printf("●=====[char]============\n");
	char caString[20] = { "jimmy is good!" };
	printf("字串:%s\n", caString);
	printf("單字:%c\n", caString[0]);
	//printf("%s\n",caString[0]); //why?
	printf("大小:%d\n", sizeof(caString));
	printf("位址:0x%x\n", caString);
	printf("位址:0x%X\n", caString);
	printf("●=====[wchar_t]============\n");
	wchar_t szString[20] = { L"jimmy is good!" };
	printf("字串:%S\n", szString);
	printf("單字:%C\n", szString[0]);
	printf("單字:%c\n", szString[0]);
	printf("大小:%d\n", sizeof(szString));
	printf("位址:0x%X\n", szString);

	printf("●=====[int]============\n");
	int nNumber = 123;
	printf("數值:%d\n", nNumber);
	printf("大小:%d\n", sizeof(nNumber));
	printf("數值:0x%X\n", nNumber);
	printf("位址:0x%X\n", &nNumber);

	printf("●=====[short]============\n");
	short sNumber = 123;
	printf("數值:%d\n", sNumber);
	printf("大小:%d\n", sizeof(sNumber));
	printf("數值:0x%X\n", sNumber);
	printf("位址:0x%X\n", &sNumber);

	printf("●=====[long]============\n");
	long lNumber = 123;
	printf("數值:%d\n", lNumber);
	printf("大小:%d\n", sizeof(lNumber));
	printf("數值:0x%X\n", lNumber);
	printf("位址:0x%X\n", &lNumber);

	printf("●=====[float]============\n");
	float fNumber = 123.123;
	printf("數值:%f\n", fNumber);
	printf("大小:%d\n", sizeof(fNumber));
	printf("數值:0x%X\n", fNumber);
	printf("位址:0x%X\n", &fNumber);

	printf("●=====[bool]============\n");
	bool blFlagTrue = false;
	printf("數值:%d\n", blFlagTrue);
	printf("大小:%d\n", sizeof(blFlagTrue));
	printf("數值:0x%X\n", blFlagTrue);
	printf("位址:0x%X\n", &blFlagTrue);

	printf("●=====[bool]============\n");
	bool blFlagFalse = false;
	printf("數值:%d\n", blFlagFalse);
	printf("大小:%d\n", sizeof(blFlagFalse));
	printf("位址:0x%X\n", &blFlagFalse);


	return;
}

void C1_ex2_forloop()
{
	int nLoop = 0;
	//(for(起始狀態;  終止條件  ; 每次執行))
	for (nLoop = 0; nLoop<100; nLoop++)
		//for(nLoop=0;;nLoop++) //沒有[終止條件]??
	{
		if (nLoop % 2 == 0)//除以2餘數為0
			printf("nLoop: %d \n", nLoop);
		if (nLoop>1000)
			break;
	}
}

void C1_ex3_while(int nMaxNumber)
{
	int nWhileLoop = 0;
	while (nWhileLoop<nMaxNumber)
	{
		if (nWhileLoop % 2 == 0)//除以2餘數為0
			printf("nWhileLoop: %d \n", nWhileLoop);
		if (nWhileLoop>1000)
			break;
		nWhileLoop++;
	}

}


void C1_ex4_switch()
{
	int nArray[100] = { 0 };
	char caName[][123] = { "Jimmy", "Dog", "Jazzdog" };
	for (int i = 0; i<100; i++)
	{
		nArray[i] = i;
	}
	for (int i = 0; i<100; i++)
	{
		int nResult = nArray[i] % 3;
		switch (nResult)
		{
		case 0:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		case 1:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		case 2:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		default:
			printf("%s : %d\n", caName[nResult], nArray[i]);
			break;
		}
	}
}

/*
設計發票兌獎功能
http://invoice.etax.nat.gov.tw/

1. 預設中獎號碼
2. 輸入8個數字
輸出結果 獎項以及金額

*/

