#ifndef FunctionDirectory_H
#define FunctionDirectory_H
#include <vle/utils/DateTime.hpp>
#include <vle/utils/Trace.hpp>
#include <map>
#include <string>
#include <iostream>

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include "Compatibility.hpp"

using namespace std;
namespace vu = vle::utils;

namespace generated {

class FunctionDirectory {
private:
	std::map<const std::string, void*> functions;

public:
	FunctionDirectory() { TraceAlways(vu::DateTime::simpleCurrentDate() + "FunctionDirectory constructor"); }

	__EXPORT__ void addFunction(const std::string& name, void* fct) {
		if(functions.find(name) == functions.end()) {
			TraceAlways(vu::DateTime::simpleCurrentDate() + "FunctionDirectory::addFunction - add function \" " + name + " \"");
			functions[name] = fct;
		}
	}

	__EXPORT__ void* getFunction(const std::string& name) {
		std::map<std::string,void*>::iterator it = functions.find(name);
	    if (it!=functions.end()) return (*it).second;
	    else {
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - FunctionDirectory::getFunction - Failed for " + name); 
			/*throw "getUserFunction failed for " + name;*/
			return NULL;
		}
	}
	__EXPORT__ unsigned int size() { return functions.size(); }

};

extern "C" FunctionDirectory* _pFuncDirectory;

class LibraryLoader {
private:
	void* libhandle;
public:
	__EXPORT__ LibraryLoader(const char* libname) {
		libhandle = 0;
#ifdef WIN32
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - LibraryLoader - loading library " + libname);
    	libhandle = LoadLibrary(libname);
#else
    	TraceAlways(vu::DateTime::simpleCurrentDate() + " - LibraryLoader - loading library " + libname);
    	libhandle = dlopen(libname, RTLD_LAZY);
    	//TraceAlways(vu::DateTime::simpleCurrentDate() + " - LibraryLoader - handle is " + libhandle);
#endif

    	if(!libhandle)
      		throw("Library could not be loaded.");
	}
	__EXPORT__ ~LibraryLoader() {
		if(libhandle){
#ifdef WIN32
			FreeLibrary((HINSTANCE)libhandle);
#else
			dlclose(libhandle);
#endif
		}
	}
	__EXPORT__ void* getFunction(char* funcName) {
		void* func = 0;
		if(libhandle){
#ifdef WIN32
			func = GetProcAddress((HINSTANCE)libhandle, funcName);
#else
			func = dlsym(libhandle, funcName);
#endif
		}

		if(!func)
			throw("Function could not be loaded.");

    	return func;
	}
};
}
#endif /* FunctionDirectory_H*/
