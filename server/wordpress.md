# Wordpress

- wordpress
- php
- mysql


## Installing


Download the wordpress tarball from the internet

```sh
# in server

# install wget
apt install wget

# download
wget -c <wordpress.tar.gz>
# extract
tar xzfv <wordpress.tar.gz>
# remove previous content if you don't need them
rm -rf ~/public_html/*
# move all the contents in the wordpress to there
mv wordpress/* ~/public_html
```

At this point we web server does not show the wordpress stuff because we don't
have php on our server

```sh
yum -y install php
# restart apache
systemctl restart httpd


# install php-mysql: a module for php applications that use mysql databases
yum -y install php-mysql

```

Finally install mysql (knowns as mariadb) and start it's server

```sh
# install
yum -y install mariadb-server mariadb

# start/enable server
systemctl enable --now maridadb-server
```

and then run the following command:

```sh
mysql-secure-installation
```


## LAMP server

- Linux
- Apache
- Mysql
- Php
