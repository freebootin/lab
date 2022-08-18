# Notes for using the `pkgsrc` package manager.

## Random tips from a reddit post:
level 2
[deleted]
·
5 yr. ago

Hmm, I would actually recommend Portage for that use-case... but only if the OS's you're creating packages for, and deploying to, are Gentoo Linux as well. Mainly because, as I have said elsewhere in the thread, Gentoo Prefix has been problematic in my personal experience.

If you decide to go with pkgsrc though, that might not be a bad route. For example, you could copy-and-paste an existing pkg's files, but alter the Makefile's source-code URL to point to your own, modified sources instead. Or perhaps use the existing files, but just add-in your changes as patches, which pkgsrc will then apply each time you build the software - and which will then generate packages you can ship-off to those remote machines.

Random, un-asked for tips off the top off my head:

    When running $pkgsrc/bootstrap/bootstrap, make sure you specify a path like /opt/pkg, because things will go weird if you build pkgs in "/home/kittycats/pkg/" but the remote machines install to /opt/pkg, for example.

    $pkgsrc/pkgtools/pkgdiff is your friend when it comes to generating patches you can stick into $pkgsrc/pkg-category/your-package/patches. Just make sure to run bmake makepatchsum afterwards.

    If you're going to be using a privileged pkgsrc setup (in other words, you need root to install the pkgs), pkgsrc uses `su' by default and will prompt you each time you want to install something on your build-machine. There's a way to get pkgsrc to authenticate using 'sudo' so that you won't be annoyed by being prompted for your password too much.

    In /etc/mk.conf or ~/pkg/mk.conf, you can use something like PACKAGES=/some/directory to tell pkgsrc where to put all your compiled pkgs. You can then take this directory, ship it, and then on the machines you wanna install the pkgs on, you can pkg_add your way to great glory. (Or perhaps set the PKG_PATH environment variable, or use pkgtools/pkgin, etc.)

    If you modified an existing package and it installs more or less files than before, you'll be wondering why make install will explode. It's because there are PLIST files that tell pkgsrc what files are expected, and they will need to be regenerated. To do so, something like this might save you: bmake clean; bmake stage-install; bmake print-PLIST > PLIST; bmake clean; bmake install.
