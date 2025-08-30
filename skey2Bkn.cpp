#include "skey2Bkn.hpp"

#ifdef _WIN32
#define EXPORT_API __declspec(dllexport)
#else
#define ESPORT_API
#endif

EXPORT_API int __stdcall skey2bkn(const char* skey) {
    int hash_value = 5381;
    for (const char* c = skey; *c != '\0'; ++c) {
        hash_value += (hash_value << 5) + static_cast<int>(*c);
    }
    return hash_value & 2147483647
}