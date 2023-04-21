# Commands that needs to be run when moving to a new machine


```sh

# Set the user name and email
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com


# Set the editor
git config --global core.editor vim


# Enable colors
$ git config --global color.ui true


# On unix based set autocrlf to input
$ git config --global core.autocrlf input
```

## Connect to Github

```sh
# 1. Check keys to reuse
ls -alhF ~/.ssh/


# if no files like ~/.ssh/id_rsa and ~/.ssh/id_rsa.pub found then


# 2. Generate key pair
$ ssh-keygen -t rsa -b 4096 -C "your_email@example.com"


# 3. $ eval "$(ssh-agent -s)"
$ ssh-add ~/.ssh/id_rsa


# 4. Paste public key to GitHub i.e. copy the content of ~/.ssh/id_rsa.pub into GitHub -> Personal Settings -> SSH and GPG keys -> New SSH Key


5. test
$ ssh -T git@github.com
```

## Resources:
- [src](https://gist.github.com/qin-yu/bc26a2d280ee2e93b2d7860a1bfbd0c5)
- [Getting started, first time git setup](https://git-scm.com/book/en/v2/Getting-Started-First-Time-Git-Setup)
- [adding new ssh key](https://help.github.com/en/github/authenticating-to-github/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)
