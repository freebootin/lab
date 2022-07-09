# Getting Xorg to work on FreeBSD

This is gonna be an on going log cataloging my problems and fixes for using xorg on FreeBSD.

## ThinkPad t480

1. Install `xorg`
1. Install `drm-kmod`. Use binary, port fails to build.
1. Add `kern.vty=vt` to `/boot/loader.conf`. Not sure if necessary.
1. Create driver config file `/usr/local/etc/X11/xorg.conf.d/driver-intel.conf`. Add:
```
Section "Device"
Identifier "Card0"
Driver "modesetting"
EndSection
```
1. Use `kldload /boot/modules/i915kms.ko` to manually load the driver.
1. Try `startx` to see if `xorg` works.
1. If it does, add `kld_list="/boot/modules/i915kms.ko"` to `/etc/rc.conf` so it loads at boot.

I got most of this from [this thread](https://forums.freebsd.org/threads/error-ee-no-screens-found-ee-on-intel-and-vesa-xorg-drivers.79534/).

One poster mentioned that all this messing around with `xorg` is common with Linux things and that the BSD way is much more straight forward. I am wondering if BSD is to Linux what Linux is to Windows?
