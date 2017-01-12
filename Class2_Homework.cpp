
#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>


void printLottery_Homework()
{

	setlocale(LC_ALL, ""); //設定中文
	//wchar_t aryLty1051104[2][10] = { { L"第1051104期" }, { 16, 14, 22, 23, 30, 31 } };
	wchar_t* pLty101104_Title = (wchar_t*)malloc(10 * 2);
	memset(pLty101104_Title, 0, 10 * 2);
	pLty101104_Title = L"第1051104期";
	wchar_t* pLty101104_Numbers = (wchar_t*)malloc(10 * 2);
	memset(pLty101104_Numbers, 0, 10 * 2);
	*pLty101104_Numbers = 16;
	*(pLty101104_Numbers + 1) = 14;
	*(pLty101104_Numbers + 2) = 22;
	*(pLty101104_Numbers + 3) = 23;
	*(pLty101104_Numbers + 4) = 30;
	*(pLty101104_Numbers + 5) = 31;

	wchar_t** ppLty1051104 = (wchar_t**)malloc(2 * 2);
	memset(ppLty1051104, 0, 2 * 2);

	*ppLty1051104 = pLty101104_Title;
	*(ppLty1051104 + 1) = pLty101104_Numbers;



	//wchar_t aryLty1051111[2][10] = { { L"第1051111期" }, {  2,  8, 25, 29, 30, 41 } };
	wchar_t* pLty101111_Title = (wchar_t*)malloc(10 * 2);
	memset(pLty101111_Title, 0, 10 * 2);
	pLty101111_Title = L"第1051111期";
	wchar_t* pLty101111_Numbers = (wchar_t*)malloc(10 * 2);
	memset(pLty101111_Numbers, 0, 10 * 2);
	*pLty101111_Numbers = 2;
	*(pLty101111_Numbers + 1) = 8;
	*(pLty101111_Numbers + 2) = 25;
	*(pLty101111_Numbers + 3) = 29;
	*(pLty101111_Numbers + 4) = 30;
	*(pLty101111_Numbers + 5) = 41;
	wchar_t** ppLty1051111 = (wchar_t**)malloc(2 * 2);
	memset(ppLty1051111, 0, 2 * 2);
	*ppLty1051111 = pLty101111_Title;
	*(ppLty1051111 + 1) = pLty101111_Numbers;



	//wchar_t(*paryAllPrice[4])[2][10];
	wchar_t*** pppAll = (wchar_t***)malloc(2 * 2);
	memset(pppAll, 0, 2 * 2);

	*pppAll = ppLty1051104;
	*(pppAll + 1) = ppLty1051111;

	for (int i = 0; i < 2; i++)
	{

		printf("\n<%d> [%S]====\n", i, *(*(pppAll + i)));
		for (int j = 0; j <10; j++)
		{
			int nNubmer = *((*((*(pppAll + i)) + 1)) + j);
			if (nNubmer > 0)
				printf("[%02d]", nNubmer);
		}

	}

}