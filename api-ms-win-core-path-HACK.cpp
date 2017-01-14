// api-ms-win-core-path-HACK.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")


HRESULT PathCchCanonicalizeEx(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn, unsigned long dwFlags)
{
	auto ret = PathCanonicalize(pszPathOut, pszPathIn);
	return ret ? S_OK : E_FAIL;
}

HRESULT PathCchRemoveFileSpec(PWSTR pszPath, size_t cchPath)
{
	auto ret = PathRemoveFileSpec(pszPath);
	return ret ? S_OK : E_FAIL;
}


