


## ssh config

```sh
# /etc/ssh/sshd_config

...
PermitRottLogin no  # set this to no
...
```

NOTE: After this change restart the ssh daemon and don't exit current
shell.

```sh
systemctl restart sshd
```

open another shell and try to login with a non-root user. this
way you can, sort of, make sure you didn't have any mistake in changing
the ssh configuration.


Another important thing: add the non-root user to the sudo/wheel group
so that it can run commands that needs super user access. Make sure you
do this in the root shell.


```sh
# in root shell

usermod -aG wheel <user>  # sometimes the group is called 'wheel' and sometimes 'sudo'
```


