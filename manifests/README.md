Boost manifest can be put to local_manifests: .repo/local_manifests/aosp-boost-1_72_0.xml
For example it could be linked from .repo to current project:
```
ln -s ../../vendor/nkh-lab/aosp-boost/manifests/boost-1_66_0.xml boost-1_66_0.xml
```
or included from other manifest:
```
<?xml version="1.0" encoding="UTF-8"?>
<manifest>

  <include name="aosp-boost-1_66_0.xml" />

</manifest>
```
