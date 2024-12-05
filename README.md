# Template

A template project for quickly getting started making Wii homebrew with DevkitPPC and libogc. It uses some [systemwii](https://github.com/systemwii) setups, included as submodules.
- [**make**](https://github.com/systemwii/make): a build (Make) setup,
- [**monke/console**](https://github.com/systemwii/monke): a basic console library.

You can clone this as a basis for making applications.

***For libraries:*** it's recommended to do the same, then develop the library in a `lib/<library-name>` folder, with another clone of this repo residing there. You'd then use the root project as an application with which to test the library. Once the library is done, its repository can be uploaded online and it can be linked in as a submodule elsewhere.

## Quick Start
It's recommended to use Linux or WSL, since the build scripts are Linux commands (so they fail if you have a space in your repository path 😤). To set up:
1. **DevkitPPC** and **libogc** are required; install them via [these instructions](https://devkitpro.org/wiki/Getting_Started) – for the Unix-like instructions, select the `wii-dev` group.
2. Make a new folder for the repository, and from that folder, clone this repository with:
```bash
git clone --recurse-submodules https://github.com/systemwii/template .
```
3. Build and run the project on your Wii:
```bash
export WIILOAD=tcp:<local-ip-address-of-your-wii>
make
make run
```
You can give your Wii a fixed IP address in your router's DHCP reservation settings. If you can't get this to work, you can pick up the built `boot.dol` file in the `_` folder and copy it to removable media, with a `meta.xml` and an `icon.png` for the Homebrew Channel (in this case, ensure your `meta.xml` has `<ahb_access/>` in it).

For further work, check out the readmes of the two included submodules mentioned above.
