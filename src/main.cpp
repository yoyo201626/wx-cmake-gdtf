
#include <iostream>
#include <string>
#include <fstream>

#include "VectorworksMVR.h"
#include "GDTFPrefix.h"
#include "IMediaRessourceVectorInterface.h"

using namespace VectorworksMVR;



#ifdef _WINDOWS
#define kSeparator  '\\'
#else
#define kSeparator  '/'
#endif


#define __checkVCOM(x) checkVCOM(x, #x)

bool checkVCOM(VectorworksMVR::VCOMError error, const std::string& check)
{
    if (kVCOMError_NoError == error) return true;

    return false;
};

// windows api
std::string GetAbsolutePath(const std::string& relativePath) {
    char fullPath[_MAX_PATH];
    if (_fullpath(fullPath, relativePath.c_str(), _MAX_PATH) != nullptr) {
        return std::string(fullPath);
    }
    else {
        return relativePath; // 如果转换失败，则返回原路径
    }
}

int main() {

    IGdtfFixturePtr fixture(IID_IGdtfFixture);

    std::string relativeFilePath = "./test/allWorking.gdtf";

    std::string absoluteFilePath = GetAbsolutePath(relativeFilePath);

	if (__checkVCOM(fixture->ReadFromFile(absoluteFilePath.c_str())))
	{
		size_t bufferLength = 0;
		fixture->GetBufferLength(bufferLength);


	}

    return 0;
}