# FreeBSD Tips and Tricks

This is a collection of tips and tricks I've found for FreeBSD.

## Mounting USB drives.

FreeBSD won't mount most USB memory sticks on a fresh install. You need to do
the following:

1. Install `ntfs-3g`. Most USB sticks are formated for ntfs, which FreeBSD does not support out of box. This package provides th `ntfs-3g` utility which can mount ntfs partitions like the `mount` command would normally.
1. The `ntfs-3g` packages should also pull the `fusefs-ntfs` package.  If it doesn't then install that also. 
1. Add `fuse_load="YES"` to `/boot/loader.conf`.
1. Reboot, or run `doas kldload fusefs` to load the fuse driver.

Now you should be able to mount ntfs devices using `ntfs-3g [device] [mount point]`.
