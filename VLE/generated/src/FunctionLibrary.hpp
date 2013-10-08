#ifndef FunctionLibrary_H
#define FunctionLibrary_H
#include <vle/utils/DateTime.hpp>
#include <vle/utils/Trace.hpp>
#include <vector>
#include "xml.hpp"
#include "FunctionDirectory.hpp"
using namespace std;
namespace generated {

class FunctionLibrary {
	
private:
	vector<LibraryLoader*> _libraries;

public:
	FunctionLibrary() {	

		TraceAlways(vu::DateTime::simpleCurrentDate() + " - FunctionLibrary::FunctionLibrary (BEGIN)"); 
		Xml conf("../exp/configTemplate.xml", true);
		XmlNode* xlibs = conf.get("config.user-libraries");
		if(xlibs != NULL) {
			for(unsigned int cpt = 0; cpt < xlibs->size(); cpt ++) {
				std::string libName = xlibs->get("library", cpt)->get();
				_libraries.push_back(new LibraryLoader(libName.c_str()));
			}
		}
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - FunctionLibrary::FunctionLibrary (END)");
	}

	~FunctionLibrary() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - FunctionLibrary::~FunctionLibrary (BEGIN)");
		while(_libraries.size() > 0) {
			delete *_libraries.begin();
			_libraries.erase(_libraries.begin());
		}
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - FunctionLibrary::~FunctionLibrary (END)");
	}
};	
extern "C" FunctionLibrary* _pFuncLibrary;
}
#endif /* FuntionLibrary_H */
