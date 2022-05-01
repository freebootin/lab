# SSH Config File

To specify which ssh key to use with Github add the followng to `~/.ssh/config`.

`Host github.com
  IdentityFile ~/.ssh/*your key here*
  IdentitiesOnly yes'
