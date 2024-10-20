#include <iostream>
#include <cstring>
#include <core.hpp>

int main(int argc, char* argv[]) {
    /*
    Arguments:
    -v / --vserion: print some information about the build
    -h / --help: print some help text
    -b / --build: build the package, not looking for caches
    */

   /*
   Modes:
   install: installs a package
   reinstall: reinstalls the package
   update: updates the packet and cache "database"
   upgrade: upgrade the package to the newest version
   add-repo: add a package repository to the repo database
   remove: uninstall a package
   */

    gmp::core::sysinfo_t info = gmp::core::get_info();

    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "-v") == 0 || std::strcmp(argv[i], "--version") == 0) {
            std::cout << "Get My Package Version " << GMP_VERSION_MAJOR_STR "." << GMP_VERSION_MINOR_STR << "." << GMP_VERSION_PATCH_STR << " ";
            std::cout << gmp::core::sysinfo_str(info) << std::endl;
            exit(EXIT_SUCCESS);
        }
    }

    std::cout << "Hello, world" << std::endl;
    return 0;
}

