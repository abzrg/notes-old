# Internet Protocol (IP), netmask, and subnetting

## IP

IPv4: 32  bit (4 byte) -> $2^32 - 1 \approx = 4B$
IPv6: 128 bit (6 byte) -> a really big number


## Netmask

divides the ip into two parts:
- network (the same for all the devices in the network)
- host (different for any two device in the network)

essentially let's you specify the maximum number of ip in a local network

```
255.255.255.0 = /24            (24 number of ones in ip)
1x8.1x8.1x8.100000000 = /25    (25 number of ones in ip)
```

checkout the ip calculator online


## Class of networks


## Private IP


A few decades ago number of devices has passed the 4B. To conserve unique public IP's
the idea of private IP comes to rescue. Since many devices don't need to talk to internet
we can assign them a range of ip that is free and is not assigned to any device on internet.
With that many devices can have in a local network and connect to the internet via a router.
that router may be assigned a public IP and routes the requests of any device with NAT.


## two special un-accessible IP

- network:   x.x.x.00000000
  - local (private) network's ip (192.168.0.0 in a class c network of 192.168.0.0/24)
- broadcast: x.x.x.11111111

## misc.

- We desire to have the smallest possible class network. because the broadcast
  packet will be send to all devices on that network. This can cause some amount
  of overhead?


## Resources

- [IP address](https://en.wikipedia.org/wiki/IP_address)
