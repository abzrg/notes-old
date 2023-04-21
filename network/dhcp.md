# Dynamic Host Configuration Protocol (DHCP)

(DHCP) is a client/server protocol that automatically provides an
Internet Protocol (IP) host with its IP address and other related
configuration information such as the subnet mask and default gateway.

DHCP can be implemented on networks ranging in size from residential
networks to large campus networks and regional ISP networks.[2] Many
routers and residential gateways have DHCP server capability. Most
residential network routers receive a unique IP address within the
ISP network. Within a local network, a DHCP server assigns a local IP
address to each device.

DHCP services exist for networks running Internet Protocol version
4 (IPv4), as well as version 6 (IPv6). The IPv6 version of the DHCP
protocol is commonly called DHCPv6.

- dhcp client: port 68
- dhcp server: port 67


Note that at this point the client does not have an IP and the
communication is done in layer 2, through Ethernet and switches.


## Discovery

The client sends a broadcast to all the computer in the network, and the
first one that is a dhcp server responds.

- Discover (client)
  - Only knows its MAC address
  - broadcasts to other computers (destination of `ff:...:ff`)
- Offer (server)
  - server is hosted by ISP?
  - Knows its and client's MAC address
  - Offers an IP address
- Request (client)
- `ACK` (server)
  - Most of the time you'll get the IP (`ACK`). On very rare occasions you won't (`NAK`)


- There are further customization options.
- There is a Transaction ID that acts as an cookie during communication.

![DHCP Discovery](./DHCP_session.svg)


## Server on Linux

There is the `isc-dhcp-server` program (only few kilobytes) that does the job.
server is started upon installation by `systemd`. The configuration is in
`/etc/defaults/isc-dhcp-server` and `/etc/dhcp/dhcpd.conf`.

you can specify a range IP's and specify in detail how should the server
treat a certain device (in layer 2).


## Misc.

- On client side one can release (give back) its IP

  ```
  $ sudo dhclinet -r enth0
  ```

- To get an IP again

  ```
  $ sudo dhclient enth0
  ```

- In `tcpdump` or `wireshark` you can search for a `dhcp` packets.

## CAUTION

One should not run unauthorized (set in server configuration) dhcp
client in a network That is because then you'll provide them IP. Your
IP may not be valid. Many hacks are done through DHCP, so just don't do
that.

Many switches will block you when they notice you are responding a DHCP
request.

SO! REMEMBER TO UNINSTALL YOUR DHCP DAEMON.


## History

DHCP was first defined in RFC 1531 in October 1993, but due to errors in
the editorial process was almost immediately reissued as RFC 1541.

Four years later the DHCPINFORM message type[5] and other small changes
were added by RFC 2131, which as of 2021 remains the core of the
standard for IPv4 networks, with updates in RFC 3396, RFC 4361, RFC
5494, and RFC 6842.[6]

DHCPv6 was initially described by RFC 3315 in 2003. After updates by
many subsequent RFCs,[7] it was replaced with RFC 8415, which merged in
prefix delegation, and stateless address autoconfiguration.


## Resources

- [Jadi's course]()
- [Dynamic Host Configuration Protocol (DHCP) Microsoft](https://learn.microsoft.com/en-us/windows-server/networking/technologies/dhcp/dhcp-top#:~:text=Dynamic%20Host%20Configuration%20Protocol%20(DHCP)%20is%20a%20client%2Fserver,subnet%20mask%20and%20default%20gateway.)
- [DHCP -- Wikipedia](https://en.wikipedia.org/wiki/Dynamic_Host_Configuration_Protocol)
- [DHCP -- Ubuntu](https://ubuntu.com/server/docs/network-dhcp)
