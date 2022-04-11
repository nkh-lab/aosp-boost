Project for integration Boost libraries into AOSP.

Project supports static and shared libraries linkage and includes:
* repo manifests - to get Boost source codes from https://git@github.com/boostorg/
* Android Soong build scripts - to compile Boost libraries in AOSP tree
* usage examples

## Fetching Boost sources to AOSP tree and compiling them
1. Add project to AOSP tree

Add this project to your AOSP manifest and use `repo sync` to download it or simply clone it via `git clone`:
```
mkdir -p vendor/nkh-lab
$ cd vendor/nkh-lab
$ git clone https://github.com/nkh-lab/aosp-boost.git
```

2. Fetch required version of Boost source codes

This is performed by selecting the appropriate manifest file from the [manifests](manifests/) folder.

Manifest file can be copied to your AOSP repo `local_manifests` folder: (e.g.: `.repo/local_manifests/aosp-boost-1_72_0.xml`) or linked:
```
$ mkdir -p .repo/local_manifests
$ cd .repo/local_manifests
$ ln -s ../../vendor/nkh-lab/aosp-boost/manifests/boost-1_72_0.xml boost-1_72_0.xml
```
or included from other manifest:
```xml
<manifest>
...
  <include name="aosp-boost-1_72_0.xml" />
...
</manifest>
```
After manifest applying use `repo sync` to fetch Boost source codes.

3. Apply Boost build script to AOSP tree 

Copy or use symlink:
```
$ cd external/boost
$ ln -s ../../vendor/nkh-lab/aosp-boost/make/boost-1_72_0.bp Android.bp
```

4. Compile

All is ready to compile now, just source environment, lunch your target and compile Boost sources:

```
$ cd external/boost/
$ mm
```

[NCAR Android Automotive Emulator Project](https://github.com/nkh-lab/aosp-ncar-manifest) can be used as a reference or example to see how the mentioned steps were applied to a real AOSP project.

## "Hello Boost" AOSP usage example

This project contains a simple example of using the Boost libraries in AOSP, which can be found at [examples/hello_boost](examples/hello_boost).

Given example can be compiled via `mm` make command (run it after setting environment and target):

```
$ cd examples/hello_boost
$ mm
```

 or added to whole AOSP build by adding corresponding include in target config file, e.g to 
`device/linaro/hikey/hikey960/device-hikey960.mk` for HiKey960 build:
```
include vendor/nkh-lab/aosp-boost/examples/hello_boost.mk
```
or
```
$(call inherit-product-if-exists, vendor/nkh-lab/aosp-boost/examples/hello_boost.mk)
```
Below is shell output from running `hello_boost_shared` and `hello_boost_static` example binaries:
```
$ adb shell
generic_x86:/ # hello_boost_shared                                                                                                                                                                                                                                               
Hello Boost
Hello from boost::thread
[2021-09-27 14:43:44.200203] [0xf6c75478] [trace]   A trace severity message
[2021-09-27 14:43:44.200690] [0xf6c75478] [debug]   A debug severity message
[2021-09-27 14:43:44.200720] [0xf6c75478] [info]    An informational severity message
[2021-09-27 14:43:44.200743] [0xf6c75478] [warning] A warning severity message
[2021-09-27 14:43:44.200764] [0xf6c75478] [error]   An error severity message
[2021-09-27 14:43:44.200786] [0xf6c75478] [fatal]   A fatal severity message
generic_x86:/ # 
generic_x86:/ # 
generic_x86:/ # hello_boost_static                                                                                                                                                                                                                                               
Hello Boost
Hello from boost::thread
[2021-09-27 14:43:54.157263] [0xf5108478] [trace]   A trace severity message
[2021-09-27 14:43:54.157636] [0xf5108478] [debug]   A debug severity message
[2021-09-27 14:43:54.157662] [0xf5108478] [info]    An informational severity message
[2021-09-27 14:43:54.157684] [0xf5108478] [warning] A warning severity message
[2021-09-27 14:43:54.157704] [0xf5108478] [error]   An error severity message
[2021-09-27 14:43:54.157723] [0xf5108478] [fatal]   A fatal severity message
```
