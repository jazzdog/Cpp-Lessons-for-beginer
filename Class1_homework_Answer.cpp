#include "stdafx.h"
#include <string>
#include "ClassIndex.h"



/*
設計發票兌獎功能
http://invoice.etax.nat.gov.tw/

1. 預設中獎號碼
2. 輸入8個數字
輸出結果 獎項以及金額

*/
bool class1_homework()
{
	printf("\n請輸入號碼(輸入over結束)\n");
	char caInputNumber[9] = { 0 }; ///儲存發票號碼8位數字(預留結尾符號+1)，一共9個空間
	fgets(caInputNumber, 9, stdin); ///等待輸入

	if (caInputNumber[0] == 10) ///若輸入第一個字元為10(0x0A 為ASCII換行符號，擇離開此次函式
		return true; ///回傳true使此兌獎函式能再次執行

	///ASCII 參考 https://zh.wikipedia.org/zh-tw/ASCII

	///若輸入"over"則回傳為false以離開重覆執行的while 迴圈
	int nstrCmp = strcmp(caInputNumber, "over");
	if (nstrCmp >= 0)
		return false;


	///★★★將輸入的字串(char[9])轉為數值(int)
	int nNumber = atoi(caInputNumber);

	///預設獎項
	int nFirstSpacailNumber = 91909013;
	int nSpecailNumber = 95976127;
	int nFirstNumbers[3] = { 54845444, 41876525, 86331065 };//200,1000,4000,10000,40000,
	int nExtalNumbers[4] = { 352, 672, 731, 214 }; //200

	///與第一特獎完全相同
	if (nNumber == nFirstSpacailNumber)
	{
		printf("%d=>1,000W", nFirstSpacailNumber);
		return true;
	}

	///與特別獎完全相同
	if (nNumber == nSpecailNumber)
	{
		printf("%d=>200W", nSpecailNumber);
		return true;
	}

	///與任一頭獎之號碼完全相同
	for (int n = 0; n<3; n++)
	{
		if (nNumber == nFirstNumbers[n])
		{
			printf("%d =>20W", nFirstNumbers[n]);
			return true;
		}
	}
	///與任一頭獎的尾數7碼相同
	for (int n = 0; n<3; n++)
	{
		int nMod = 10000000;
		int nLast7 = nFirstNumbers[n] % nMod;
		int nInputLast7 = nNumber % nMod;
		if (nInputLast7 == nLast7)
		{
			printf("%d:[%d]=>40000", nFirstNumbers[n], nLast7);
			return true;
		}
	}

	///與任一頭獎的尾數6碼相同
	for (int n = 0; n<3; n++)
	{
		int nMod = 1000000;
		int nLast6 = nFirstNumbers[n] % nMod;
		int nInputLast6 = nNumber % nMod;
		if (nInputLast6 == nLast6)
		{
			printf("%d:[%d]=>10000", nFirstNumbers[n], nLast6);
			return true;
		}
	}

	///與任一頭獎的尾數5碼相同
	for (int n = 0; n<3; n++)
	{

		int nMod = 100000;
		int nLast5 = nFirstNumbers[n] % nMod;
		int nInputLast5 = nNumber % nMod;
		if (nInputLast5 == nLast5)
		{
			printf("%d:[%d]=>4000", nFirstNumbers[n], nLast5);
			return true;
		}
	}

	///與任一頭獎的尾數4碼相同
	for (int n = 0; n<3; n++)
	{
		int nMod = 10000;
		int nLast4 = nFirstNumbers[n] % nMod;
		int nInputLast4 = nNumber % nMod;
		if (nInputLast4 == nLast4)
		{
			printf("%d:[%d]=>1000", nFirstNumbers[n], nLast4);
			return true;
		}
	}

	///與任一頭獎的尾數3碼相同
	for (int n = 0; n<3; n++)
	{
		int nMod = 1000;
		int nLast3 = nFirstNumbers[n] % nMod;
		int nInputLast3 = nNumber % nMod;
		if (nInputLast3 == nLast3)
		{
			printf("%d:[%d]=>200", nFirstNumbers[n], nLast3);
			return true;
		}
	}

	///與任一增加獎的尾數3碼相同
	for (int n = 0; n<4; n++)
	{
		int nMod = 1000;
		int nInputLast3 = nNumber % nMod;
		if (nInputLast3 == nExtalNumbers[n])
		{
			printf("%d:[%d]=>200", nExtalNumbers[n], nInputLast3);
			return true;
		}
	}

	printf("可惜!您的號碼[%d]沒有中獎\n", nNumber);
	return true;

}

///想一想是否還有辦法能將此兌獎過程用迴圈簡短程式碼?
