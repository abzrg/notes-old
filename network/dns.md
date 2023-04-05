# DNS (Domain Name System)

Services on the internet that map domain names to actual ip addresses.


> The Domain Name System is a hierarchical and distributed naming system for
> computers, services, and other resources in the Internet or other Internet
> Protocol networks. It associates various information with domain names
> assigned to each of the associated entities. -- wikipedia


```
[ my computer ] --> [ isp ] --> [ the internet ]

                       ^             ^
                       ^             DNS is here
                       ^
                       checks for various domains and maybe returns wrong ip
                       with intention of censorship
```


- /etc/host file
  - maps names to ips so that you can, for example, just ping names instead of ips




- `nslookup` command gives you ip address, given a domain name

  ```
  $ nslookup google.com

  Server:         192.168.1.1
  Address:        192.168.1.1#53

  Non-authoritative answer:
  Name:   google.com
  Address: 216.239.38.120
  ```

- `ping` command also gives you ip address?

  ```
  $ ping google.com

  PING google.com (216.239.38.120): 56 data bytes
  ...
  ```

- rfs packet standard
  - reply codes
        - 0: No error
        - 3: No website ?

  - recursive flag in rfc means: hey current server, if you couldn't find the
  domain name, ask others

- You can buy domain name from nic (network information center) companies

> The Network Information Center (NIC), also known as InterNIC from 1993 until
> 1998, was the organization primarily responsible for Domain Name System (DNS)
> -- wikipedia


- You can assign multiple ip's to a domain name? (cloudflare?)

- what does cloudflare do?


## Learning Resources

- [Domain Name System](https://en.wikipedia.org/wiki/Domain_Name_System)
- [DOMAIN NAMES - IMPLEMENTATION AND SPECIFICATION (rfc)](https://www.ietf.org/rfc/rfc1035.txt)
- [Introduction to DNS -- Jadi (persian)](https://youtu.be/uZNhP17K_gQ)
