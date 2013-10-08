#ifndef Compatibility_H
#define Compatibility_H
#ifdef WIN32
#define __IMPORT__ __declspec(dllimport)
#define __EXPORT__ __declspec(dllexport)
#else
#include <cstring>
#define __IMPORT__ 
#define __EXPORT__
#define __WHICHPORT__
#endif /* WIN32 */
#endif /* Compatibility_H */
