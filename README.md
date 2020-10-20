# aosp-boost
Using Boost under AOSP.

Project supports static and shared libraries linkage and includes:
* repo manifests - to get Boost source codes from https://git@github.com/boostorg/
* Android Soong build scripts - to compile Boost libraries in AOSP tree
* usage examples

# Usage
## Applying to AOSP tree and compiling
1. Get given project to AOSP tree by adding it to AOSP manifest or simply cloning, for example:
```
mkdir -p ./vendor/nkh-lab
cd ./vendor/nkh-lab
git clone https://github.com/nkh-lab/aosp-boost.git
```

2. Get Boost sources codes by using corresponding manifest from [manifests] folder.
Manifest file can be copied to repo [local_manifests] folder: (.repo/local_manifests/aosp-boost-1_66_0.xml) or simply linked:
```
mkdir -p ./.repo/local_manifests
cd ./.repo/local_manifests
ln -s ../../vendor/nkh-lab/aosp-boost/manifests/boost-1_66_0.xml boost-1_66_0.xml
```
or included from other manifest:
```
<manifest>
...
  <include name="aosp-boost-1_66_0.xml" />
...
</manifest>
```
After manifest applying use repo sync to fetch Boost source codes.

3. Apply build script to AOSP tree by using symlink:
```
cd ./external/boost
ln -s ../../vendor/nkh-lab/aosp-boost/make/boost-1_66_0.bp Android.bp
```

**All above usage steps can be automated by applying them in AOSP repo manifest.**

## Use Boost libraries
Usage example can be found in the [examples/hello_boost].
It can be compiled via mm (mma) make command or added to whole AOSP build by adding corresponding include in corresponding config file, for example to
device/linaro/hikey/hikey960/device-hikey960.mk:
```
include vendor/nkh-lab/aosp-boost/examples/hello_boost.mk
```
or
```
$(call inherit-product-if-exists, vendor/nkh-lab/aosp-boost/examples/hello_boost.mk)
```
