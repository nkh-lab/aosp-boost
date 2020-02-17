hello_boost.mk invocation examples (e.g. in device/linaro/hikey/hikey960/device-hikey960.mk)
```
include vendor/aosp-boost/examples/hello_boost.mk
```
or
```
$(call inherit-product-if-exists, vendor/aosp-boost/examples/hello_boost.mk)
```
