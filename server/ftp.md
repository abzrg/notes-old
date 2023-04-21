To install ftp server


```sh
yum install vsftpd
```

## Open/add ftp and ftp-data ports via/to firewall


```sh

# firewall-cmd --permanent --zone=public --add-port=20/tcp  # tcp
# firewall-cmd --zone=public --add-port=20/tcp  # tcp
# firewall-cmd --zone=public --add-port=21/tcp  # tcp-data

# or add-service to it
firewall-cmd --permanent --zone=public --add-service=ftp
firewall-cmd --zone=public --add-service=ftp
```


## ftp clients

- commandline:
  - lftp
  - sftp (over ssh?)

- graphical:
  - filezilla


## Rsync

rsync is faster.
