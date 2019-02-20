#pragma once
#include"RSA.h"

namespace RSAWrapper 
{
	extern "C" __declspec(dllexport) LPCSTR Cal(LPCSTR text, LPCSTR key, LPCSTR integer);
	extern "C" __declspec(dllexport) void	InitialNumbers(int InputBits);
	extern "C" __declspec(dllexport) LPCSTR GetBigInteger_n();
	extern "C" __declspec(dllexport) LPCSTR GetEncryption_Index();
	extern "C" __declspec(dllexport) LPCSTR GetDecryption_Index();
}