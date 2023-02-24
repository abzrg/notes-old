
```sh
ssh-keygen -t ed25519 -C "your_email@example.com"

# Add key to ssh agent
eval "$(ssh-agent -s)"

# Edit ssh user config file
open ~/.ssh/config

# And add the following

"
Host *.github.com
  AddKeysToAgent yes
  #UseKeychain yes # only if you setup passphrase
  IdentityFile ~/.ssh/id_ed25519
"
```
