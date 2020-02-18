Example of the Android.bp symlink in /external/boost/libs where boost libraries are placed:
```sh
/external/boost/libs$ ls -als
total 260
4 drwxr-xr-x 65 nikolay nikolay 4096 лют 13 11:29 .
4 drwxr-xr-x  4 nikolay nikolay 4096 лют 13 11:25 ..
4 drwxr-xr-x 10 nikolay nikolay 4096 лют 13 10:23 algorithm
4 drwxr-xr-x  7 nikolay nikolay 4096 лют 13 10:23 align
0 lrwxrwxrwx  1 nikolay nikolay   29 лют 13 11:29 Android.bp -> ../aosp-boost/make/boost-1_66_0.bp
...
```
