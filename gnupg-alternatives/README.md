# GnuPG Alternatives
While setting up a FreeBSD box and installing `gpg` on it I noticed it also pulled 74mb of libraries and also the `gnutils` and `glibc`. This got me wondering if there was a non-GNU implementation of OpenPGP I could use instead. After some Google-fu it would seem there really isn't. At least not a drop in replacement.

Someone else already wrote about this problem [here](https://tdem.in/post/pgp-alternatives/), and provided some partial alternatives:

- [reop - reasonable expectation of privacy](https://flak.tedunangst.com/post/reop): Abondonware?
- [signify](https://man.openbsd.org/signify.1): Only signs, doesn't encrypt.
- [minisign](https://github.com/jedisct1/minisign): Only signs.
- [sigtool](https://github.com/opencoff/sigtool): Signs and encrypts. Most promising.
- [sequoia](https://sequoia-pgp.org/): More of a library than a tool.
- [age](https://github.com/FiloSottile/age): Encrypts, terrible interface though.
- [akm](https://github.com/tdemin/akm): Wrapper script for age. Tries to fix age's UI problem.
