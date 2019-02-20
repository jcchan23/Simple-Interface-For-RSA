#pragma once
#include<mpir.h>
#include<mpirxx.h>
#include<iostream>
#include<Windows.h>
using namespace std;

class __declspec(dllexport)RSA
{
public:
	RSA();
	virtual ~RSA();
	/* 初始化一系列需要的数 */
	void InitialNumbers(int InputBits);

	/* 加密和解密函数 */
	LPCSTR Cal(LPCSTR text, LPCSTR key, LPCSTR BigInteger);

	/* 只有唯一指定的人可以访问解密函数 */
	mpz_class get_Decryption();

	/* 只有唯一指定的人可以访问分解因子 */
	mpz_class get_Factor();
	/* 大整数n */
	mpz_class BigInteger_n;
	/* 加密指数e */
	mpz_class Encryption_Index;

private:
	/* 创建大素数的函数 */
	mpz_class CreatePrimes(int bits);
	/* 解密指数d */
	mpz_class Decryption_Index;
	/* 欧拉函数 */
	mpz_class Euler_Function;
	/* n的分解因子p和q */
	mpz_class Factor_p;
	mpz_class Factor_q;

};