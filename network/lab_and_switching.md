# Concepts

- Each device manufactured has a unique MAC address.
- cable: multiple wires
- switch: layer 2 (sometimes there can be found switches that have
limited layer 3 capabilities) only knows the MAC address of the devices

- Connecting different devices to switch through Ethernet cables.
- Ethernet Network Interface/Devices on each of these devices don't have ip
- We can check that:

```
$ ifconfig
...

# or

$ ip addr show
```

The above commands shows that all of the interfaces (except `lo`) only
assigned with a MAC address


- To give an interface on a machine an IP, on that machine issue the following

```
$ ip addr add 198.2.2.20/24 dev ensp098 # /24 deontes the subnet mask of 255.255.255.0
```

- Note that with only switches we could only have local network.

- Switches are cheaper than routers and can manage many more computers.
That said we can have multiple connected to a switch, and that itself is
connected to the Internet via a router


## How switch works:

Although Switch doesn't know about the IP, it can find other computer
on network by sending the packet to all of them. The correct computer
acknowledges that it is the correct destination. (learning process)

- __Learning__: Learning is the process of obtaining the MAC address of
connected devices. When a frame reaches into the port of a switch, the
switch reads the MAC address of the source device from Ethernet frame
and compares it to its MAC address table (also known as CAM (Content
Addressable Memory) table). If the switch cannot find a corresponding
entry in MAC address table, the switch will add the address to the table
with the port number via the Ethernet frame arrived.

- __Ethernet frame__:
  - ((destination address (MAC))(source address (MAC))(data))
  - when you ping, the data will be the icmp packet


- __CAM__: content addressable memory
  - keeps a list of various devices that are connected to it through
  certain port of it.
  - When device A sends out a frame to another device, it's MAC address
  is update in the switch's lookup table.

- __Aging timer__: The aging timer also helps when a device moves to
another switch port. In that case, the address would appear in both
places in the lookup tables. When a frame arrives headed for that
address, the switch can compare the aging timer for both entries and
select the most recent if the entry has not already timed out. Whenever switch updates an entry in the MAC address table, the switch resets the timer for that entry.

- __Address Resolution Protocol (ARP)__: Most often, the initial communication to a switch is an Address Resolution Protocol (ARP) request. The inbound ARP contains the sender’s MAC address, and the switch adds that address to its lookup table. The ARP Response contains the MAC address of the intended target. The ARP response also updates the switch’s lookup table. ARP is Address Resolution Protocol, it is used to resolve IP addresses into MAC addresses, meaning the IP address is already known, but the Mac is not. The reason why we need ARP is because computers need to know both the IP address and the MAC address of a destination before they can start network communication.[^1]

[^1]: [src;](https://nexgent.com/what-is-arp-address-resolution-protocol/)

- __flooding__: If the device is not listed in the mac table the frame would be "flooded" out all interfaces (except the one it came in on) in hopes that it will reach the correct host. If the host receives the frame and responds, the switch will have learnt the devices mac address and will add it to the table. This flooding process is necessary network overhead.


- __Broadcasting__: If a broadcast frame is received with a destination
MAC address ff ff ff ff ff ff, the switch forwards the broadcast frame
out all of the other ports.


So, to summary, switches connect computers to form a local netwrok. Routers
connect various local networks together.

You can use `tcpdump` or `wireshark` to see the network interactions. Search for
`arp` and find all communications of that nature.

## Rsources

- [Networking – Switch Learning and Forwarding](https://www.heelpbook.net/2016/networking-switch-learning-and-forwarding/)
- [jadi](https://www.youtube.com/playlist?list=PL-tKrPVkKKE00meXoxmIy6EgldK5XE-Z_)

