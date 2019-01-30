#pragma once

#ifdef HZ_BUILD_DLL
#define HZ_API __declspec(dllexport)
#else
#define HZ_API __declspec(dllimport)
#endif  // DEMO_BUILD
