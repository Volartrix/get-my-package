#include <iostream>
#include <cstring>
#include <core.hpp>

int main(int argc, char* argv[]) {

    gmp::core::package_info_t packet;
    

    int argument_counter = 0;

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

   Also you can use gpg/1.1.4 to install version 1.1.4 of the gpg package
   */

    gmp::core::sysinfo_t info = gmp::core::get_info();

    packet.info = info;


    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "-v") == 0 || std::strcmp(argv[i], "--version") == 0) {
            std::cout << "Get My Package Version " << GMP_VERSION_MAJOR_STR "." << GMP_VERSION_MINOR_STR << "." << GMP_VERSION_PATCH_STR << " ";
            std::cout << gmp::core::sysinfo_str(info) << std::endl;
            std::cout << "(c) 2024 GMP contributors. Licensed under the Apache License Version 2.0" << std::endl;
            std::cout << "Github: https://github.com/Volartrix/get-my-package" << std::endl;
            exit(EXIT_SUCCESS);
        } else if (std::strcmp(argv[i], "-h") == 0 || std::strcmp(argv[i], "--help") == 0) {
            std::cout << "Help for Get My Package" << std::endl;
            std::cout << "Common commands:" << std::endl;
            std::cout << "\tgmp install gpg: Installs the package GPG" << std::endl;
            std::cout << "\tgmp add-repo gmp.shittydev.com: Adds the Repository to the Repository list" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "\t-v / --version: Prints some information about the build of GMP" << std::endl;
            std::cout << "\t-h / --help: Shows this help screen" << std::endl;
            std::cout << "\t-b / --build: Dont check for a cache just build it" << std::endl;
            exit(EXIT_SUCCESS);
        } else {
            if (argv[i][0] == '-') {
                std::cerr << "Error unknown argument: " << argv[i] << ". Use -h for help!" << std::endl;
                exit(EXIT_FAILURE);
            } else {
                if (argument_counter == 0) {
                    packet.mode = argv[i];
                    std::cout << "Mode to sue: " << packet.mode << std::endl;
                } else if (argument_counter == 1) {
                    packet.package = argv[i];
                    std::cout << "Package to use: " << packet.package << std::endl; 
                }
            }
        }
    }

    std::cout << "Hello, world" << std::endl;
    return 0;
}

