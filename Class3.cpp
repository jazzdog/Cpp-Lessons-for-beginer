#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>
#include <ctime>
#include<cmath> 

#define _TOSTR(x)			  #x    //遇到#不會再被展開
#define  TOSTR(x)			  _TOSTR(x)


/*
#define定義常用且固定的函式以簡化程式，增加程式的[閱讀性]
*/
#define PRINT_VAR(V)  printf("[變][ %s]==> v(%8d) a(0x%X)\n",TOSTR(V),V,&V);
//#define PRINT_PTR(p)  printf("[指][*%s]==> v(0x%X) a(0x%X)--->*(%d)\n",TOSTR(p),p,&p,*p); //當指標為NULL會出錯
#define PRINT_PTR(p)  if(p!=NULL){printf("[指][*%s]==> v(0x%X) a(0x%X)--->*(%d)\n",TOSTR(p),p,&p,*p);}else{printf("[指][*%s]==> NULL !!\n",TOSTR(p));}
#define TAB			  printf("%s",Tab);
#define TABL(x)	      for(int n=0;n<x;n++){printf("%s",Tab);}
char Tab[6] = { 0 };
void goClass3(int nExpNumber)
{
	//for (int n = 0; n < 6; n++)//試試看:會發生甚麼事?為什麼?
	for (int n = 0; n < 5; n++)
	{
		Tab[n] = 32;
	}

	int nAns = -1;
	switch (nExpNumber)
	{
	case 1:
	{
		/* [C3_ex1_functionWithPoint]=========================================================
			參考[什麼是傳值call by value、傳址call by address、傳參考call by reference]
			http://wp.mlab.tw/?p=176
		*/
		C3_ex1_functionWithPoint();
		break;
	}
	case 2:
	{
		C3_ex2_functionDefaultValue();
		break;
	}
	case 3:
	{
		C3_ex3_ByteOp();
		break;
	}
	case 4:
	{
		C3_ex4_BitOp();
		break;
	}
	case 5:
	{
		class3_Homework();
		
		break;
	}
	default:
		return;
		break;
	}
	printf("\n從class3回到主函式(輸入bye結束)...\n");

}

//===================================================================
//[class3][Ex1]函式傳址: 請仔細比較每個變數的[值]與[位址]的變化!!
//===================================================================
void C3_ex1_functionWithPoint()
{
	
	
	printf("================================================================\n");
	printf("[class3][Ex1]函式傳址: 請仔細比較每個變數的[值]與[位址]的變化!!\n");
	printf("================================================================\n");
	int nAddr = 200;
	int nNumb = 99; //用來給指標指定的整數數值
	int*pNumb = &nNumb;
	int nLocl = 300;

	printf("\n傳入之前: \n");
	PRINT_VAR(nAddr);
	PRINT_VAR(nNumb);
	PRINT_PTR(pNumb);
	PRINT_VAR(nLocl);

	//測試:將if中修改0或1
	//觀察[將nAddr與pNumb對調]時
	//==> 參數因應函式設定參數的(傳參)(傳址)，如何修改寫入方式
	if (0)
	{
		printf("\n[傳入]_C3_ex1_functionWithPoint(nAddr(傳參), pNumb(傳址), nLocl(傳值))\n");
		_C3_ex1_functionWithPoint(nAddr, pNumb, nLocl);
	}
	else
	{
	
		printf("\n[傳入]_C3_ex1_functionWithPoint(*pNumb(傳參), &nAddr(傳址), nLocl(傳值))\n");
		_C3_ex1_functionWithPoint(*pNumb, &nAddr, nLocl); 
	}

	printf("\n傳入之後: \n");
	PRINT_VAR(nAddr);
	PRINT_VAR(nNumb);
	PRINT_PTR(pNumb);
	PRINT_VAR(nLocl);
}
/*========================================================================================================================
參數:
[int& _refVar] : 傳入[變數的位址](傳參考call by reference, C++ only) == > << 自動 >> 抓取變數本身的[位址] = >傳址
[int* _addVar]: 傳入[整數指標](傳址call by address) == > 必須是一組[整數變數]的[位址], 變數的位址!變數的位址!變數的位址!(很重要)
[int _varVar]:     傳入[整數](傳值call by value) == > 就是變數本身的[值]
========================================================================================================================*/
void _C3_ex1_functionWithPoint(int& _refVar, int* _addVar, int _varVar)
{
	//printf("\n在[C3_ex1_functionWithPoint]改變之前:\n _refVar:[%d:0x%X]\n _addVar:[指向數值:%d,儲存位址:0x%X ,指標本身位址: 0x%X]\n _varVar:[%d:0x%X]\n\n",
	//	_refVar, &_refVar, *_addVar, _addVar, &_addVar, _varVar, &_varVar);
	//比較上面的寫法...用#define程式將大幅[易讀] 且[易改]!!!
	TAB printf("==========================================\n");
	TAB printf("[_C3_ex1_functionWithPoint]修改前.... \n");
	TAB PRINT_VAR(_refVar);
	TAB PRINT_PTR(_addVar);
	TAB PRINT_VAR(_varVar);
	
	//將各傳入的參數作數值的變化 (注意寫法 &,*,...)
	printf("\n");
	TAB  printf("修改各值....\n");
	TAB  printf(" _refVar(%d)+1000\n",_refVar);
	TAB  printf("*_addVar(%d)+2000\n", *_addVar);
	TAB  printf(" _varVar(%d)+3000\n", _varVar);
	
	 _refVar += 1000;
	*_addVar += 2000;
	 _varVar += 3000;

	printf("\n");
	TAB printf("[_C3_ex1_functionWithPoint]修改後.... \n");
	TAB PRINT_VAR(_refVar);
	TAB PRINT_PTR(_addVar);
	TAB PRINT_VAR(_varVar);
	TAB printf("==========================================\n");

}


//===================================================================
//[class3][Ex2]函式 傳入參數預設值 以及 回傳指標!!
//===================================================================
/*
函式宣告在最後加上初始值
int* _C3_ex2_functionDefaultValue(int* pValue,int nValue=100);
如此_C3_ex2_functionDefaultValue就只需填入第一個參數
★★★第二個參數nValue若是不填，則以預設值100★★★

注意:
函數預設值必須放在參數的最後
void myfuc(int v1, int v2, int v3=100);		//=>OK
void myfuc(int v1, int v2=50, int v3=100);	//=>OK
void myfuc(int v1, int v2=50, int v3);		//=>錯誤

*/
void C3_ex2_functionDefaultValue()
{
	printf("================================================================\n");
	printf("[class3][Ex2]函式 傳入參數預設值 以及 回傳指標\n");
	TAB printf("函式宣告:\n");
	TABL(2) printf("int* _C3_ex2_functionDefaultValue(int* pValue, int nValue = 100)\n");
	printf("================================================================\n");

	int nNumber = 5;
	int* pNumber = NULL;
	printf("●[Ex2]參數初始:\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	
	printf("\n================================================================\n");
	printf("●[Ex2]函式=>第一次::(NULL,   )\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	printf("================================================================\n");
	int* pRetru1 = _C3_ex2_functionDefaultValue(pNumber);
	printf("●[Ex2]函式=>第一次回傳::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	PRINT_PTR(pRetru1);



	pNumber = &nNumber;
	printf("\n\n================================================================\n");
	printf("●[Ex2]函式=>第二次:: (pNumber = &nNumber)\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	printf("================================================================\n");
	int* pRetru2 = _C3_ex2_functionDefaultValue(pNumber);
	printf("●[Ex2]函式=>第二次回傳::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	PRINT_PTR(pRetru2);
	//[?]pRetru2 == pNumber?? 兩者是否相同? 為什麼?

	printf("\n\n================================================================\n");
	printf("●[Ex2]函式=>第三次::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	printf("================================================================\n");
	
	int* pRetru3 = _C3_ex2_functionDefaultValue(pNumber, nNumber);
	printf("●[Ex2]函式=>第三次回傳::\n");
	PRINT_VAR(nNumber);
	PRINT_PTR(pNumber);
	PRINT_PTR(pRetru3);
	//[?]所以C3_ex2_functionDefaultValue回傳的[int*]的意思為何?
	//[?]再回頭看看C3_ex1 看看何為[傳址]

	for (int i = 0; i < 10; i++)
	{
		int* pRetru = _C3_ex2_functionDefaultValue(pNumber, nNumber);
		printf("●[Ex2]函式=>第[%d]次回傳::\n",i+4);
		PRINT_VAR(nNumber);
		PRINT_PTR(pNumber);
		PRINT_PTR(pRetru);
	}

}


/* [C3_ex2_functionDefaultValue]=========================================================
	參數:
	[int* pValue]:  傳入指向數值得指標
	[int nValue]: 指標指向的[數值]欲加上的值
	回傳:
	[int*]:  將傳入的(????)再回傳回去
*/
int* _C3_ex2_functionDefaultValue(int* pValue, int nValue)
{
	int* pValu2 = pValue;
	static int nLoop = 0;
	nLoop++;
	if (pValue == NULL)
	{
		//printf("\n[C3_ex2_functionDefaultValue] pValue為NULL! nValue=%d\n", nValue);
		TABL(2) printf("%d> [C3_ex2_functionDefaultValue] pValue為NULL!\n",nLoop);
		TABL(2) PRINT_VAR(nValue);
		TABL(2) printf("回傳:\n");
		TABL(2) PRINT_PTR(pValue);
		TABL(2) PRINT_PTR(pValu2);
	}
	else
	{
		TABL(2) printf("%d> [C3_ex2_functionDefaultValue]修改值之前:\n", nLoop);
		TABL(2) PRINT_VAR(nValue);
		TABL(2) PRINT_PTR(pValue);
		
		printf("\n");
		TABL(3) printf("修改值===>[*pValue(%d) += nValue(%d)]\n", *pValue, nValue);
		*pValue += nValue;
		printf("\n");
		TABL(2) printf("%d> [C3_ex2_functionDefaultValue]修改值之後:\n", nLoop);
		TABL(2) PRINT_VAR(nValue);
		TABL(2) PRINT_PTR(pValue);
		TABL(2) printf("回傳:\n");
		TABL(2) PRINT_PTR(pValue);
		TABL(2) PRINT_PTR(pValu2);
		//[?] pValue 與 pValu2 本身的位址?
	}
	return pValue;

}
/*
^: XOR
!: NOT
*/
void C3_ex3_ByteOp()
{
	printf("================================================================\n");
	printf("[class3][Ex3] 位元操作 與 邏輯運算\n");
	printf("================================================================\n");

	int nNum1 = 85;
	int nNum2 = 204;
	int nAns0 = 0;
	char caNum1[33] = { ' ' };
	char caNum2[33] = { ' ' };
	char caAns0[33] = { ' ' };

	_itoa_s(nNum1, caNum1,33, 2);
	_itoa_s(nNum2, caNum2,33, 2);

	printf("\n================================\n");
	printf("AND==>[&]\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf("&\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	nAns0 = nNum1 & nNum2;
	_itoa_s(nAns0, caAns0,33, 2);
	printf("-------------------------------\n"); 
	printf("nAns0(%8d): %10s\n", nAns0, caAns0);

	printf("\n================================\n");
	printf("OR==>[|]\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf("|\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	nAns0 = nNum1 | nNum2;
	_itoa_s(nAns0, caAns0, 33, 2);
	printf("-------------------------------\n");
	printf("nAns0(%8d): %10s\n", nAns0, caAns0);

	printf("\n================================\n");
	printf("XOR==>[^] (不同為1)\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf("^\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	nAns0 = nNum1 ^ nNum2;
	_itoa_s(nAns0, caAns0, 33, 2);
	printf("-------------------------------\n");
	printf("nAns0(%8d): %10s\n", nAns0, caAns0);
	

	printf("\n================================\n");
	printf("左移==>[<<] (乘2)\n");
	printf("================================\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);
	printf(">>1\n");
	nNum1 = nNum1 << 1;
	_itoa_s(nNum1, caNum1, 33, 2);
	printf("-------------------------------\n");
	printf("nNum1(%8d): %10s\n", nNum1, caNum1);


	printf("\n================================\n");
	printf("右移==>[>>] (除2)\n");
	printf("================================\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);
	printf(">>1\n");
	nNum2 = nNum2 >> 1;
	_itoa_s(nNum2, caNum2, 33, 2);
	printf("-------------------------------\n");
	printf("nNum2(%8d): %10s\n", nNum2, caNum2);

}


void C3_ex4_BitOp()
{
	printf("================================================================\n");
	printf("[class3][Ex4] ★★★進階位元操★★★\n");
	printf("[!]務必熟悉位元轉換，操作，以及指標[型態]與[計算]!!!\n");
	printf("================================================================\n");

	int nAarryRandNum[3] = { 0 }; //儲存亂數
	int* pAarryRandNum = nAarryRandNum; //指向nAarryRandNum來操作(int指標)
	char bMask = 0x01; //遮罩，用來取得1個bit的資料

	//測試五次以觀察亂數以及位元的操作變動
	for (int i = 0; i < 5; i++)
	{
		printf("======\n============[產生亂數(%d次)]==========\n======\n", i);
		char caAarryRandNumBinary[50 * 3] = { 0 }; //紀錄數值的2進位表示
		int nRandNumber = 0;
		int nRandRang = pow(2, 31) - 1; //亂數

		//---------------------
		//給予亂數
		nRandNumber = GetRandomNumber(nRandRang);
		nAarryRandNum[0] = nRandNumber;

		nRandNumber = GetRandomNumber(nRandRang);
		nAarryRandNum[1] = nRandNumber;

		nRandNumber = GetRandomNumber(nRandRang);
		nAarryRandNum[2] = nRandNumber;

		//---------------------
		//將[亂數]轉換為二進制(binary)表示，方便檢驗以及計算
		char* pAByte_Source = (char*)nAarryRandNum;			//指向亂數值來源★以[char*]指向[int陣列] !!! why???
		char* pAByte_Target = (char*)caAarryRandNumBinary;  //指向要[寫入]的二進制表示的[字串buffer]
		
		for (int nIDinInt = 0; nIDinInt < 4*3; nIDinInt++) //4*3??? why??
		{
			char caBinaryStringTemp[40] = { 0 }; ///儲存暫時轉換字串

			//方便閱讀每4組byte==>換行!!
			if (nIDinInt>0 && nIDinInt % 4 == 0)
			{
				pAByte_Target--;
				sprintf_s(pAByte_Target, 4, "\n\0");//增加換行符號 (★一定要加上"\0"字串結尾，以方便strlen()來計算[字串長度])
				pAByte_Target = caAarryRandNumBinary + strlen(caAarryRandNumBinary); //將pAByte_Target指向[下一個]寫入的buffer位置
			}
			//printf("欲轉換數值: 0x%X\n", (*pAByte_Source & 0x00FF)); //打開此行以驗證資料是否正確

			_itoa_s((*pAByte_Source & 0x00FF), caBinaryStringTemp, 33, 2); //每次轉換1個byte的數值為二進制表示,why?見下方說明
			/*
			進制轉換技巧:

				10進制(1085550060) 
				=16位元表示=> 0x40B42DEC 
				=2進制表示=>  1000000101101000010110111101100

				對照===>
						    0x    40       B4       2D       EC
				=2進制表示=>  01000000-10110100-00101101-11101100 //byte分開(8-bit)

							0x  4     0   B    4   2     D   E     C
				=2進制表示=>  0100 0000-1011 0100-0010 1101-1110 1100 //每4-bit分開
				
				★每4-bit就是表示一個8進制的[值]★

			*/

			/*
			0x0c =>"1100"
			                       0    1    2     3   4    5    6    7
			caBinaryStringTemp[]=[0x31 0x31 0x30 0x30 0x00 0xfe 0xfe 0xfe]
			                       '1'  '1'  '0'  '0'  '\0'  ?    ?    ?
			此處 0x31=>'1' 0x30=>'0'
			我們希望的表示方法能完整顯示8-bit模式 => "0000 11000"
			因此要將caBinaryStringTemp位元位置做調整==>向後推 
			字串長度4 ("1100"==>strlen(caBinaryStringTemp)=4) 
			因此要向後推8-4個差距(nOffset)
			
			且要從第[3]位開始搬移(長度-1==>(strlen(caBinaryStringTemp) - 1)==> 4-1)
			否則會蓋掉前面的資料(例如[0]-->[3]則原本[3]的資料來不及搬就被[0]蓋掉了)

			                       0    1    2    3    4    5    6    7     8
			caBinaryStringTemp[]=[0x30 0x30 0x30 0x30 0x31 0x31 0x30 0x30  0x00 ] //[8]結尾符號以方便計算字串長度(strlen())
								  '0'  '0'   '0'  '0'   '1'  '1'  '0'  '0'  '\0' 
			搬完後前面原本資料的位置(nOffset)需要填上0x30=>'0'

			*/
			if (strlen(caBinaryStringTemp) < 8)
			{
				int nIndex = 0;
				int nOffset = 8 - strlen(caBinaryStringTemp); //向後推的差距
				///資料向後[推]==>搬移
				for (nIndex = (strlen(caBinaryStringTemp) - 1); nIndex >=0; nIndex--)
				{
					caBinaryStringTemp[nIndex + nOffset] = caBinaryStringTemp[nIndex]; 
				}
				///前方原本資料的位置填入'0'
				for (nIndex = 0; nIndex < nOffset; nIndex++)
				{
					caBinaryStringTemp[nIndex] = 0x30; //'0'
				}
				caBinaryStringTemp[8] = 0; //'\0' 填入字串結束符號
			}
			//printf("修改後2進制表示: %s\n", caBinaryStringTemp); ///打開可以驗證轉換後的結果
			sprintf_s(pAByte_Target, 9, "%s", caBinaryStringTemp); //將資料填入pAByte_Target，即最終顯示字串的buffer,caAarryRandNumBinary[]
			
			pAByte_Target = caAarryRandNumBinary + strlen(caAarryRandNumBinary); ///將pAByte_Target指向[下一個]寫入的buffer位置
			
			///每byte增加分隔線'-'方便閱讀
			if (nIDinInt<4*3-1)
				sprintf_s(pAByte_Target, 3, "-\0");//增加分隔線
			pAByte_Target = caAarryRandNumBinary + strlen(caAarryRandNumBinary); ///將pAByte_Target指向[下一個]寫入的buffer位置
			pAByte_Source++;
		}
		
		printf("隨機數值:\n[%0.10d  (0x%0.8X)]\n[%0.10d  (0x%0.8X)]\n[%0.10d  (0x%0.8X)]\n", nAarryRandNum[0], nAarryRandNum[0], nAarryRandNum[1], nAarryRandNum[1], nAarryRandNum[2], nAarryRandNum[2]);
		printf("隨機數值(2進制)==>\n%s\n",caAarryRandNumBinary);


		///依照三個隨機數值得最小bit 0或1作字串選擇
		/*
			有了亂數，隨機取每個亂數最後(低)bit當作索引當作選擇旗標
			10進制(1085550060)
			=16位元表示=> 0x40B42DEC
			=2進制表示=>  100000010110100001011011110110[0]
			=記憶體表示=> 0x30 0x30 0x31 0x31 0x30.....(方向相反!!)
			              ^^^^
			caBinaryStringTemp[]=[0x30 0x30 0x31 0x31 0x30 ... ] 與記憶體表示相同
			                     ^^^^^
		*/
		char caWho[30] = { 0 };
		sprintf_s(caWho, "[%s]", ((*pAarryRandNum & bMask) == 0) ? ("Jimmy(0)") : ("Kai(1)"));
		char caWhere[30] = { 0 };
		sprintf_s(caWhere, "[%s]", ((*(pAarryRandNum+1) & bMask) == 0) ? ("Home(0)") : ("Park(1)"));
		char caDoing[30] = { 0 };
		sprintf_s(caDoing, "[%s]", ((*(pAarryRandNum+2) & bMask) == 0) ? ("Playing(0)") : ("Sleeping(1)"));
		printf("產生句子==> %s at %s to %s.\n\n", caWho, caWhere, caDoing);
		///試試看:如果要改成取最後第[3]個bit要怎麼改? (提示:bMask)



		//依照三個隨機數值低byte且最低[4-bit]當作幸運數字
		char caLuckNumber[3] = { 0 };
		memcpy(caLuckNumber, pAarryRandNum, 1);
		memcpy(caLuckNumber+1, (pAarryRandNum+1), 1);
		memcpy(caLuckNumber + 2, (pAarryRandNum + 2), 1);
		printf("[低4-bit]數值:[%8d][%8d][%8d]\n", caLuckNumber[0] & 0xF, caLuckNumber[1] & 0xF, caLuckNumber[2] & 0xF);


		//依照三個隨機數值[第二低]byte組合為一個int(4)
		int nBigNumber = 0;
		char* pDataBuffer = (char*)nAarryRandNum;
		char* pBigNumber = (char*)&nBigNumber; //★★★用char去指int ★★★
		memcpy(pBigNumber, pDataBuffer + 1, 1);		///??? +1
		memcpy(pBigNumber + 1, pDataBuffer + 5, 1);	///??? +5
		memcpy(pBigNumber + 2, pDataBuffer + 9, 1); ///??? +9
		char _caBigNumber[33] = { 0 };
		_itoa_s(nBigNumber, _caBigNumber, 33, 2);
		printf("\n[第二低]byte組合數值:%d(0x%0.8X) (%s)\n\n", nBigNumber, nBigNumber, _caBigNumber);



	}
}


int GetRandomNumber(int rangeMax,bool blZero)
{
	int randomNumber1 = 0;
	int randomNumber2 = 0;
	int randomNumber3 = 0;
	SYSTEMTIME stimeptr;
	GetLocalTime(&stimeptr);
	int nRetRandNumber = 0;
	while (randomNumber1 == 0)
	{
		srand((unsigned int)time(NULL) + stimeptr.wMilliseconds + rand() % rangeMax);
		randomNumber1 = rand() % (4);
	}
	GetLocalTime(&stimeptr);
	srand((unsigned int)time(NULL) + stimeptr.wMilliseconds + rand() % rangeMax);
	randomNumber2 = rand() ;
	GetLocalTime(&stimeptr);
	srand((unsigned int)time(NULL) + stimeptr.wMilliseconds + rand() % rangeMax);
	randomNumber3 = rand() ;

	

	if (rangeMax < 0)
		nRetRandNumber =(randomNumber1*randomNumber2*randomNumber3);
	else
		nRetRandNumber = ((randomNumber1*randomNumber2*randomNumber3) % (rangeMax));
	if (nRetRandNumber == 0 && blZero == false)
	{
		return GetRandomNumber(rangeMax, blZero);
	}
	else
		return nRetRandNumber;
};


//=============================================================================
//=============================================================================
/*[Class3] [Homework]解碼*/
//=============================================================================
//=============================================================================
/*
	程式產生一段加密後的資料，請將資料解密列印出資料內容(限定為字串)

	1. 由encryptData()固定產生一包[隨機加密]600bytes的資料封包
	2. 請經由封包格式，將此600bytes的資料封包解碼，還原其中包含的資料字串
	------------------
	將面對第一個複雜的程式:
	a.請先耐心看懂封包的製作方式(耐心!耐心!耐心!)
	b.理解封包格式之後，在著手[思考]如何還原封包資料(先後順序很重要!!)
	c.由於封包內容隨機產生，請多執行幾次，驗證自己的資料是正確(非運氣好正好解開!)

	[加密機制]
	https://goo.gl/UKrpwi

	byteA         XOR theKeyA = byteA_Encrypt //以鑰匙theKeyA對byteA作XOR所得數值 即是[加密資料(byteA_Encrypt)]
	byteA_Encrypt XOR theKeyA = byteA         //以鑰匙theKeyA對byteA_Encrypt作XOR所得數值 即是[解密還原資料(byteA)]



*/


///將輸入的資料依照byte為單位做XOR的操作
/*並由pEncryptDataOut返回
char caKey 輸入要做XOR的 鑰匙
char* pdata 原始的資料，以char*形式輸入 
int nSizeByte 資料長度
char* pEncryptDataOut 加密過的資料儲存的buffer
*/
bool xorData(char caKey, char* pdata, int nSizeByte, char* pEncryptDataOut)
{
	char _cakey = caKey;
	//輸入資料為NULL，或長度不正常(<=0)或是沒有設定輸出buffer，
	//=>則不處理回傳NULL
	if (pdata == NULL || nSizeByte <= 0 || pEncryptDataOut == NULL)
	{
		return false; 
	}
	char* pDataPos = pdata;			  //指向原始資料，以取得目前操作原始資料位址
	char* pDataOut = pEncryptDataOut; //指向輸出buffer,以取得目前操作寫入結果位址

	//將以byte為單位，處理加密，並寫入輸出資料
	for (int n = 0; n < nSizeByte; n++)
	{
		char theCode = (*pDataPos & 0x00FF) ^ _cakey;
		memcpy(pDataOut, &theCode, 1);
		pDataPos++;
		pDataOut++;
	}

	pDataPos = NULL;
	pDataOut = NULL;
	return true;
}


/*
封包格式:

   caKeyUseage(1)                  caTheKey_DataStartPos(1)			caTheKey_DataEncrypt(1)
		^									 ^								^                    
|----------------|----------------|----------------|----------------|----------------|-------.-------.-------.-------.-------.-------.-------.--------|-----------
					 v									 v													v     
			caTheKey_DataLenth(1)		      caTheKey_Key4DEncry(1)								nDataStartPos(4)


-------------|-------.-------.-------.-------.-------.-------.-------.--------|--------   .....  ----------|-----
										v
								    nDataLen(4)										caDataEncrypt(nDataLen)
封包:
byte0 : caKeyUseage => [加密規則]為是否要使用加密? (1 byte)
		 只有針對其最末3 bit對應是否要用  caTheKey_DataLenth, caTheKey_DataStartPos,caTheKey_Key4DEncry
		 例如:
			caKeyUseage=0xB9 =>(1011 1001)=>取最末三位(001)=>命名(cba)
			(a)=>為'1'則=> 使用caTheKey_DataLenth 
			(b)=>為'1'則=> 使用caTheKey_DataStartPos 
			(b)=>為'1'則=> 使用caTheKey_Key4DEncry 

byte1 : caTheKey_DataLenth		=> 加密[資料長度]之鑰匙，由caKeyUseage決定是否使用(1 byte)
byte2 : caTheKey_DataStartPos	=> 加密[資料起始位置]之鑰匙，由caKeyUseage決定是否使用(1 byte)
byte3 : caTheKey_Key4DEncry		=> 加密[資料加密鑰匙]之鑰匙，由caKeyUseage決定是否使用(1 byte)
byte4 : caTheKey_DataEncrypt    => 加密[資料]之鑰匙 一定使用(1 byte)，若caKeyUseage設定為1，則由caTheKey_Key4DEncry加密

byte5~8: nDataStartPos			=> 資料起始位置，紀錄第幾個byte為資料起始位置，為int占用4 byte
								  ，若caKeyUseage設定為1，則由caTheKey_DataStartPos加密
byte([資料起始位置(nDataStartPos)] 前的4個byte) : nDataLen  => 資料長度,必位於[資料起始位置]前的4個byte，為int占用4 byte
								若caKeyUseage設定為1，則由caTheKey_DataLenth加密
byte([資料起始位置(nDataStartPos)]) : caDataEncrypt, 資料本身，由caTheKey_DataEncrypt加密

★★★[限制 規則]★★★
[封包資料]為[字串] 且字串必須小於256 bytes
[加密規則]以及[加密鑰匙x4] =>為隨機產生之1-byte資料!每次都不同!
[資料起始位置]			   =>為隨機產生之4-byte資料!每次都不同!
                             其範圍將在21 ~ (600 - nDataLen)之間
							 必將在封包起始的byte5~8
[封包資料]將隨機擺放在封包中
[資料長度]必將位於[封包資料]之前的4byte
*/

//將輸入的資料(字串限定)，作成加密封包
//並且由設定的輸出buffer(pDataOut)回傳結果
bool encryptData(char* pData, char* pDataOut)
{

	//輸入格式有錯，部處理
	if (pData == NULL || strlen(pData) <= 0 || strlen(pData)>256)
		return NULL;

	char caOutputData[600] = { 0 };

	//避免封包內容太明顯，資料先填入隨機值
	for (int i = 0; i < 600; i++)
	{
		caOutputData[i] = (char)GetRandomNumber(255 - (i % 100), false) & 0x000000FF;
		if (i % 100 == 0)
			Sleep(1);
		caOutputData[i] &= 0x000000FF;
	}

	///產生鑰匙
	char caTheKey_DataLenth = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	char caTheKey_DataStartPos = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	char caTheKey_Key4DEncry = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	char caTheKey_DataEncrypt = (char)GetRandomNumber(255, false) & 0x000000FF;
	Sleep(1);
	caTheKey_DataLenth &= 0x000000FF;
	caTheKey_DataStartPos &= 0x000000FF;
	caTheKey_Key4DEncry &= 0x000000FF;
	caTheKey_DataEncrypt &= 0x000000FF;
	//printf("[Enc]Key: D.Len=0x%X S.Pos=0x%X K.Ecry=0x%X Data=0x%X \n", caTheKey_DataLenth, caTheKey_DataStartPos, caTheKey_Key4DEncry, caTheKey_DataEncrypt);


	//產生[加密規則]
	char caKeyUseage = (char)GetRandomNumber(255, false) & 0x000000FF;
	bool blUseKey_DataLenth = ((caKeyUseage & 0x01) == 0) ? false : true;
	bool blUseKey_DataStartPos = ((caKeyUseage & 0x02) == 0) ? false : true;
	bool blUseKey_Key4DEncry = ((caKeyUseage & 0x04) == 0) ? false : true;
	//printf("[Enc]blKey: D.Len=%d S.Pos=%d K.Ecry=%d\n", blUseKey_DataLenth, blUseKey_DataStartPos, blUseKey_Key4DEncry);

	//資料長度
	int nDataLen = strlen(pData) + 1; //why? +1
	//資料起始位置
	int nDataStartPos = GetRandomNumber(600 - nDataLen);
	while (nDataStartPos < 20)
	{
		nDataStartPos = GetRandomNumber(600 - nDataLen);
	}
	//加密資料
	char* caDataEncrypt = new char[nDataLen];
	memset(caDataEncrypt, 0, nDataLen);
	xorData(caTheKey_DataEncrypt, pData, nDataLen, caDataEncrypt);

	memcpy_s(caOutputData, 600, &caKeyUseage, 1);
	memcpy_s(caOutputData + nDataStartPos, 600, caDataEncrypt, nDataLen); ///將資料複製到caOutputData


	//加密=>資料長度
	int nDataLenEncrypt = 0;
	if (blUseKey_DataLenth == true)
		xorData(caTheKey_DataLenth, (char*)&nDataLen, 4, (char*)&nDataLenEncrypt);
	else
		nDataLenEncrypt = nDataLen;

	memcpy_s(caOutputData + nDataStartPos - 4, 600, &nDataLenEncrypt, 4);

	//加密=>起始位置
	int nDataStartPosEncrypt = 0;
	if (blUseKey_DataStartPos == true)
		xorData(caTheKey_DataStartPos, (char*)&nDataStartPos, 4, (char*)&nDataStartPosEncrypt);
	else
		nDataStartPosEncrypt = nDataStartPos;



	//加密=>資料加密鑰匙
	char caTheKey_DataEncrypt_Encrypt = 0;
	if (blUseKey_Key4DEncry == true)
		xorData(caTheKey_Key4DEncry, &caTheKey_DataEncrypt, 1, &caTheKey_DataEncrypt_Encrypt);
	else
		caTheKey_DataEncrypt_Encrypt = caTheKey_DataEncrypt;

	memcpy_s(caOutputData + 1, 600, &caTheKey_DataLenth, 1);
	memcpy_s(caOutputData + 2, 600, &caTheKey_DataStartPos, 1);
	memcpy_s(caOutputData + 3, 600, &caTheKey_Key4DEncry, 1);
	memcpy_s(caOutputData + 4, 600, &caTheKey_DataEncrypt_Encrypt, 1);
	memcpy_s(caOutputData + 5, 600, &nDataStartPosEncrypt, 4);


	///處理發生不可預期的事件(溢位等)
	try
	{
		memcpy_s(pDataOut, 600, caOutputData, 600);
	}
	catch (...)
	{
		pDataOut = NULL;
		return false;
	}
	return true;

}

void class3_Homework()
{
	printf("================================================================\n");
	printf("[class3][Homework] 資料解碼\n");
	printf("================================================================\n");
	for (int i = 0; i < 5; i++)
	{
		printf("●●●[資料解碼][%0.2d]==================\n", i + 1);
		char caMyDATA[] = { "Jimmy  is good!\n異或運算子常作為更為複雜的加密演算法的組成部分。對於其本身來說，如果使用不斷重複的金鑰，利用頻率分析就可以破解這種簡單的異或密碼。\0" };
		printf("輸入字串為:%s\n長度:%d byte\n", caMyDATA, strlen(caMyDATA));

		char caEncryptData[600] = { 0 };
		encryptData(caMyDATA, caEncryptData);

		/*
			 使用caEncryptData來解碼，還原資料!
		*/
		

	}
}
