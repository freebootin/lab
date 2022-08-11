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

Normally `less` prints escape sequences like `ESC[36m` raw on FreeBSD. You can fix this with the `-r` option. Alias `less` to `less -r`.

For preprocessing, `lesspipe` is avalible for FreeBSD. While the package is called `lesspipe`, the actual executable is called `lesspipe.sh`, even though it contains a shebang line. You can use th regular Linux setup just use `lesspipe.sh` and change the absolute path values to BSD ones.

## Time and NTPD

When you install FreeBSD you can select and option to enable ntpd at boot.  This does not add time sync though.  You should check `/etc/rc.conf` for the line `ntpd_sync_on_start="YES"` and add it if it's not there.

## Power Management

This [site](https://vermaden.wordpress.com/2018/11/28/the-power-to-serve-freebsd-power-management/) has lots of information about power management on FreeBSD.

## WiFi Setup
The wifi setup from the FreeBSD handbook doesn't tell you everything you need. I found this five year old forum [post](https://muc.lists.freebsd.questions.narkive.com/f06viB9L/iwm-drives-does-not-work-for-intel-wireless-ac-3165) that filled in the blanks for me.

1. First the your networks SSID and password.
1. Identify your wifi driver using `sysctl net.wlan.devices`. If you get blank output then you need to find and install your wifi driver. 
1. Add an entry for your wifi network to `/etc/wpa_supplicant.conf`, creating the file if it does not exist. The entry should look like:
`network={
    ssid="myssid"
    psk="mypassword"
}`
1. Add these entries to `/etc/rc.conf`; `wlans_ath0="iwn0"` and `ifconfig_wlan0="WPA SYNCDHCP"`
1. Then create the wlan interface with `ifconfig wlan0 create wlandev iwn0` followed by `ifconfig wlan0 up`.
1. Now run `wpa_supplicant -B -c /etc/wpa_supplicant.conf -i wlan0 -P /var/run/wpa_supplicant/wlan0.pid`. The last part from `-P` on might not be necessary.
1. If you have a DHCP client running this last part might not be necessary. For a static address use `ifconfig wlan0 inet 192.168.10.3/24` using your IP and subnet mask. Or for DHCP use `dhclient wlan0`.
1. Might need to add these to `/etc/rc.conf`; `ifconfig_wlan0="DHCP"` and `wlans_iwn0="wlan0"`.
