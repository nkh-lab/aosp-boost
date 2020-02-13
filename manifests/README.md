Boost manifest can be put to local_manifests or included from other manifest:
```
.repo/local_manifests/aosp-boost-1_72_0.xml
```
or
```
<?xml version="1.0" encoding="UTF-8"?>
<manifest>

  <include name="aosp-boost-1_72_0.xml" />

</manifest>
```
