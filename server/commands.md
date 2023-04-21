You are given an IP and password


```sh
# login
ssh root@ip # and then enter password


# change root password
passwd  # enter new password


# update the system and possibly install web-server
apt update && apt upgrade  # debian based
yum/dnf update  # red-hat based
...

yum install httpd  # httpd = apache
apt install apache # or apache2
apt install nginx  # nginx

# enable web service
systemctl enable httpd --now
# or
systemctl start httpd
systemctl enable httpd


# add a user
adduser <user-name>
passwd user-name


# update firewall setting to allow web connections through port 80
# src: https://linuxconfig.org/how-to-open-http-port-80-on-redhat-7-linux-using-firewall-cmd
firewall-cmd --zone=public --add-port=80/tcp --permanent
firewall-cmd --zone=public --add-port=80/tcp
# note that we need to issue above once without --permanent to tell to do it now, instead of next reload
# reload all firewall service
firewall-cmd --reload
# or
systemctl restart firewalld

# then check if port is added to the iptables rule
# And check whether the port was added to iptables rule:
iptables-save | grep 80
```


