# Notes on Git/Github

1. Setup a `.gitconfig` file in `$HOME`. You are gonna need this to save your user settings accross machines.
1. Remember to a `~/.ssh/config` file pointing github to the right key.
1. Generate a new ssh key for each machine you access github on.

If you have your `.gitconfig` and `~/.ssh/config` and seeming everything else working and your commits are being uploaded, but your commits arn't being shown on your contributions bar, check the commit dates.  The time on the machine you commited from might be out of sync. This seems to throw off github's contributions graph.
