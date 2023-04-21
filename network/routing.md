# Routing

## Part 1

you cannot ping a computer with a IP that is not in the current local
network of the current computer, meaning if the current computer has
an IP in a network with IP of `192.168.1.0/24`, then it cannot send ICMP
packets to a computer that has an IP of `10.10.0.0/16` for example. To
make this happen we need to do two things:

- tell the current computer to route this specific IP through one of its interfaces
- tell the destination computer to handle the source computer's network IP

for that we use the IP command

```sh
# source computer (192.168.1.0/24)
ip route 10.10.0.0/24 dev enth09

# destination computer (10.10.0.0/24)
ip route 192.168.0.0/24 dev enp08

# list all the routes
ip route
```

Note that we have set the route for the destination node as well. Because then
it cannot route back its ICMP response packets


## part 2


## 


### default gateway device

which network interface should route non-local ip's (layer 2)

```sh
ip route add default enth0sth  # add default gateway
ip route del default dev ensp0sth # delete the default gateway
```


### default gateway ip

to which ip send the packet when you don't know (layer 3)

each router has a private local ip which is the default gateway for all the devices on that network
however it has one public ip which is given by another router or isp directly and it has a default
gateway that points to that router/isp.


```sh
# set default gateway to a device
ip route add default 192.100.100.1
```

When you connect to the internet through your router, the router assigns an default gateway
to your network interface. (because of dhcp?)

```sh
ip addr show <interface>  | grep inet
```

If you don't have a network manager you can get an ip from dhcp server of the router/isp
by issuing the following command

```sh
sudo dhclient <interface>
```

note that you can set the default gateway when you are connected to the internet
as it is set previously by the router.??


## tracerout

traces the jump between one network to another. each (local?) has a default
gateway ip that eventually sends the packet to it.

```sh
tracerout 4.2.2.4
```


## References

- ??
