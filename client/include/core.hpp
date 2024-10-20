#pragma once

#include <string>

#define GMP_VERSION_MAJOR 0
#define GMP_VERSION_MINOR 1
#define GMP_VERSION_PATCH 0

#define GMP_VERSION_MAJOR_STR "0"
#define GMP_VERSION_MINOR_STR "1"
#define GMP_VERSION_PATCH_STR "0"

namespace gmp {
namespace core {

typedef struct sysinfo {
    std::string arch;
    std::string os;
} sysinfo_t;

sysinfo_t get_info();
std::string sysinfo_str(sysinfo_t info);


}
}