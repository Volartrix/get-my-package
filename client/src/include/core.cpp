#include <core.hpp>

namespace gmp {
namespace core {
    
sysinfo_t get_info() {
    std::string os;
    std::string arch;

#if defined(_WIN32) || defined(_WIN64)
    os = "windows";
#elif defined(__linux__)
    os = "linux";
#elif defined(__APPLE__) && defined(__MACH__)
    os = "darwin";
#elif defined(__FreeBSD__)
    os = "freebsd";
#else
    os = "other";
#endif

#if defined(__x86_64__) || defined(_M_X64)
    arch = "x86_64";
#elif defined(__i386__) || defined(_M_IX86)
    arch = "x86";
#elif defined(__aarch64__)
    arch = "aarch64";
#elif defined(__arm__)
    arch = "arm";
#else
    arch = "unknown_arch";
#endif

    sysinfo_t info = {arch, os};
    return info;

}

std::string sysinfo_str(sysinfo_t info) {
    std::string os = info.os;
    std::string arch = info.arch;

    std::string result = arch + "-" + os;
    return result;
}

}
}
