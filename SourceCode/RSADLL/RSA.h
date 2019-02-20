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
	/* ��ʼ��һϵ����Ҫ���� */
	void InitialNumbers(int InputBits);

	/* ���ܺͽ��ܺ��� */
	LPCSTR Cal(LPCSTR text, LPCSTR key, LPCSTR BigInteger);

	/* ֻ��Ψһָ�����˿��Է��ʽ��ܺ��� */
	mpz_class get_Decryption();

	/* ֻ��Ψһָ�����˿��Է��ʷֽ����� */
	mpz_class get_Factor();
	/* ������n */
	mpz_class BigInteger_n;
	/* ����ָ��e */
	mpz_class Encryption_Index;

private:
	/* �����������ĺ��� */
	mpz_class CreatePrimes(int bits);
	/* ����ָ��d */
	mpz_class Decryption_Index;
	/* ŷ������ */
	mpz_class Euler_Function;
	/* n�ķֽ�����p��q */
	mpz_class Factor_p;
	mpz_class Factor_q;

};