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

## LS Colors, Dircolors, and terminal colors.

The GNU implementation of `dircolors` isn't in the FreeBSD repos. Instead you will have to use `opendircolors`, which does almost the same thing. The `opendircolors` implementation does not include the `-p` option that GNU `dircolors` uses to generate the template file that `dircolors` reads from. This means you either have to make your own, or copy someone elses.

Steps to make this work (assuming using `bash` as a login shell):

1. Use `pkg install opendircolors` to get `dircolors`.
1. Find a copy of and existing `.dircolors` file or make your own.
1. Add `eval $(dircolors -b ~/path/to/.dircolors)` followed by `alias ls='ls -h --color` to your `.bashrc`.
1. Restart `bash` and you should now have working colors for `ls`.

I havn't tried it myself, but this should work for `zsh` also.
