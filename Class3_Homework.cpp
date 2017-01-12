#include "stdafx.h"
#include "string.h"
#include "ClassIndex.h"
#include <locale.h>
#include <ctime>
#include<cmath> 

///資料解碼
void decryptData(char* pEncryptDataData, char* ptheData)
{
	printf("\n封包解碼------------------------------\n");
	//先取出[加密規則]
	char caKeyUseage = 0;
	memcpy_s(&caKeyUseage, 1, pEncryptDataData, 1);
	bool blUseKey_DataLenth = ((caKeyUseage & 0x01) == 0) ? false : true;
	bool blUseKey_DataStartPos = ((caKeyUseage & 0x02) == 0) ? false : true;
	bool blUseKey_Key4DEncry = ((caKeyUseage & 0x04) == 0) ? false : true;

	//取出鑰匙x4
	char caTheKey_DataLenth = 0;
	memcpy_s(&caTheKey_DataLenth, 1, pEncryptDataData+1, 1);
	char caTheKey_DataStartPos = 0;
	memcpy_s(&caTheKey_DataStartPos, 1, pEncryptDataData + 2, 1);
	char caTheKey_Key4DEncry = 0;
	memcpy_s(&caTheKey_Key4DEncry, 1, pEncryptDataData + 3, 1);
	char caTheKey_DataEncrypt = 0;
	memcpy_s(&caTheKey_DataEncrypt, 1, pEncryptDataData + 4, 1);
	
	char caTheKey_DataEncrypt_decode = 0;
	if (blUseKey_Key4DEncry == true)
		xorData(caTheKey_Key4DEncry, &caTheKey_DataEncrypt,1, &caTheKey_DataEncrypt_decode);
	else
		caTheKey_DataEncrypt_decode = caTheKey_DataEncrypt;


	printf("[加密鑰匙]--------\n資料長度Key=0x%X \n資料起始Key=0x%X \n資料加密鑰匙=0x%X \n資料加密=0x%X \n", caTheKey_DataLenth, caTheKey_DataStartPos, caTheKey_Key4DEncry, caTheKey_DataEncrypt_decode);
	char caKeyUsageBinary[33] = { 0 };
	_itoa(caKeyUseage, caKeyUsageBinary, 2);
	printf("[加密規則] 0x%X (%s)--------\n資料長度=%d \n資料起始=%d \n資料加密鑰匙=%d\n", caKeyUseage, caKeyUsageBinary,blUseKey_DataLenth, blUseKey_DataStartPos, blUseKey_Key4DEncry);
	int nDataStartPos = 0;
	
	memcpy_s(&nDataStartPos, 4, pEncryptDataData + 5, 4);
	int nDataStartPos_Decode = 0;
	if (blUseKey_DataStartPos == true)
		xorData(caTheKey_DataStartPos, (char*)&nDataStartPos, 4, (char*)&nDataStartPos_Decode);
	else
		nDataStartPos_Decode = nDataStartPos;

	int nDataLenth = 0;
	memcpy_s(&nDataLenth, 4, pEncryptDataData + nDataStartPos_Decode - 4, 4);
	int nDataLenth_Decode = 0;
	if (blUseKey_DataLenth == true)
		xorData(caTheKey_DataLenth, (char*)&nDataLenth, 4, (char*)&nDataLenth_Decode);
	else
		nDataLenth_Decode = nDataLenth;

	char* pDataDecode = new char[nDataLenth_Decode];
	memset(pDataDecode, 0, nDataLenth_Decode);
	memcpy_s(pDataDecode, nDataLenth_Decode, pEncryptDataData + nDataStartPos_Decode , nDataLenth_Decode);

	char* pDataDecode_decode = new char[nDataLenth_Decode+1];
	memset(pDataDecode_decode, 0, nDataLenth_Decode);

	xorData(caTheKey_DataEncrypt_decode, pDataDecode, nDataLenth_Decode, pDataDecode_decode);

	printf("還原資料------\n[%s]\n長度: %d\n\n\n", pDataDecode_decode, nDataLenth_Decode);
	ptheData = pDataDecode;

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

		char caDecodeData[600] = { 0 };
		decryptData(caEncryptData, caDecodeData); //請努力

	}
}