#include"RSAWrapper.h"

namespace RSAWrapper
{
	static RSA* g_pObj = new RSA();

	void InitialNumbers(int InputBits)
	{
		g_pObj->InitialNumbers(InputBits);
	}

	LPCSTR Cal(LPCSTR text, LPCSTR key, LPCSTR integer)
	{
		return g_pObj->Cal(text, key, integer);
	}

	LPCSTR GetBigInteger_n()
	{
		return g_pObj->BigInteger_n.get_str().c_str();
	}

	LPCSTR GetEncryption_Index()
	{
		return g_pObj->Encryption_Index.get_str().c_str();
	}

	LPCSTR GetDecryption_Index()
	{
		return g_pObj->get_Decryption().get_str().c_str();
	}

}