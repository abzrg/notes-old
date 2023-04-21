
```sh

mkdir ~/pulic_html
echo 'some html content' >> ~/public_html/index.html

# -----------------

# change the apache config and point out the new document root
vi /etc/httpd/conf/httpd.conf
# and then change DocumentRoot to '/home/<user>/public_html'

# restart the web server
systemctl restart httpd

# ---------------------

# disable selinux
setenforce 0

# or go to selinux config and replace enforcing to disable in the config
vi /etc/selinux/config

# ---------------------

# allow web server to access the current non-root user's content
chmod 755 /home/<user>
chmod 755 /home/<user>/public_html

```
