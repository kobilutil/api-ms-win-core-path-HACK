# api-ms-win-core-path-l1-1-0.dll HACK
This is (extremely) hacky implementation of some of the functions in the original `api-ms-win-core-path-l1-1-0.dll` which is needed during the installation of Windows SDK 10.0.14393.0 on Windows 7.

## Description

As explained [here], WinSDK 10.0.14393 fails to install correctly on Windows 7 because `mdmerge.exe` depends on `api-ms-win-core-path-l1-1-0.dll` which AFAIK does not exist for Windows 7.

`mdmerge.exe` only imports `PathCchCanonicalizeEx` and `PathCchRemoveFileSpec` from `api-ms-win-core-path-l1-1-0.dll`

So this project implements these 2 functions so that `mdmerge.exe` is able to run.

## Installaion (tested on Win7-x64 only)
- Option 1:
<br>After building copy the x64 dll to `system32` and the x86 dll to `SysWOW64`.
- Option 2:
<br>Copy to the install directory where `mdmerge.exe` resides.
<br>By default it is `C:\Program Files (x86)\Windows Kits\10\bin\[x86|x64]`

After the WinSDK setup installs successfully it might be safer to delete the hacky dlls from the system and hope that MS will fix this issue soon.

[here]: https://connect.microsoft.com/VisualStudio/feedback/details/3054875/windows-sdk-1%200-0-14393-0-install-fails-on-windows-7
