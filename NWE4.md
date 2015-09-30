L3

segmentation (L4) != fragmentation (L3)


## IP
  - primary L3 protocol
  - IPv4 IPv6
  - Why internetwork protocol? To combine different L2 networks
  - 3 Main Functions of IP
    - Packet transport service to L4
    - Logical Adressing
    - Fragmentation
    ! (IP is __NOT a routing protocol__ - it is a routed protocol)
      - routers speak routing protocols with each other, but that's not part of IP
  - NOT in IP:
    - No Reliability
    - No ACK
    - No Error control (except header checksum)
    - NO Retransmission
    - No Flow control


## Packet transport
  - packet switching (!= circuit switching) (!= L2 switching)
    - "router = gateway = packet switch"
  - end: host; gateway is also a host
  - connectionless & best-effort

### IP Header
  - length at least 20 bytes (+ multiple of 4 bytes = 32 bits)
  - (1) IP Version: first header field
  - (2) IHL: Internet header length: how long is the header (how many 4 byte multiples, to save space. min 5)
  - (..) QoS
  - (3) Total length in bytes (16 bits field length; max total length 2^16-1 = 65 535 bytes)
  - (4) Protocol field: what protocol is packed next? (like cisco hdlc) (tcp: 6) (udp: 17) (icmp: ?)
  - (5) 32bit source
  - (6) 32bit destination
     (i) inverse order of L2 addresses [destinaion first]
  - (7) TTL Time to live (255 - decremented at every router; packet dropped if zero)

   - Options:
     - "Security"
     - "(Strict|Loose) Source routing"

  - NOT in header: Subnet mask

## IP Addressing
  - logical: hierarchical logical grouping of networks (like real world address)
  - parts: "network" and "host" (separated by subnet mask or prefix length)
    - subnet mask: 255.0.0.0 (whole bytes are either zeroes or ones)
    - or: 255.255.128.0
    - after zeroes no more ones
    - 1: network portion
    - 0: host portion
    - logical AND to get network address
      IP           192.168.50.223    11000000 10101000 00110010 11011111 AND
      Subnet mask  255.255.255.0     11111111 11111111 11111111 00000000 =
      Network Addr 192.168.50.0      11000000 10101000 00110010 00000000
      ^ classfull = split at octets (today: classless, anything goes)

  - IP address may indicate: host, multicast, broadcast, network address
    - limited broadcast: 255.255.255.255
    - directed broadcast: to any network; filtered

  - 32 bits = 4 bytes = octets
  - notation: dotted decimal; or not separated in hex or binary

  - each network has a broadcast address: where all host bits are binary ones, eg .255.255
  - limited broadcast: 255.255.255.255
  - loopback addr: 127.0.0.0 - 127.255.255.255; usually .1

  - Classful Addressing: [legacy thing, needed for the test haha]
    A = big networks           subnet: 255.0.0.0 (class A subnet)
    B = middle-sized companied         255.255.0.0
    C = small companies                255.255.255.0

    if first bit of IP is zero: class A (0_______) * 1 – 127
    if 2nd bit of IP is zero: class B (10______) * 128 – 191
    if 2nd bit of IP is zero: class B (110_____) * 192 – 223
    ^ all unicast

    if 4th bit is zero: class D "multicast" * 224 – 239
    ^ multicast

    class E: 1111 xxxx * 240 – 255
    ^ reserved

      1   2   3   4   5   6   7   8
    128 192 224 240 248 252 254 255
    128  64  32  16   8   4   2   1
    ___ ___ ___ ___ ___ ___ ___ ___

  - Classless addressing
    "interesting octet"

  - Prefix length = slash notation
    instead of writing out the whole subnet mask
    /8 = 255.0.0.0
    /16 = 255.255.0.0
    /24 = 255.255.255.0

  - (i) 2^32 addresses -> ICANN -> Regional Internet Registries (RIR)

  - Private addresses
    10.0.0.0 - 10.255.255.255 = one class A network
    172.16.0.0 - 172.31.255.255 = 16 class B networks
    192.168.0.0 - 192.168.255.255 = 256 class C networks

  - Link-local addresses
    - devices give themselves addresses to be able to reach themselves
      - "yeah, nice idea, but please solve your DHCP problem"
    - 169.254.0.0/16

  - Subnetting
    - separate networks without classes
    - VLSM = variable length subnet mask
    - CIDR = classless interdomain routing

  - Gateway
    - if packet addressed to a host outside of source network, it must be routed by a gateway
    - via ip header: source address, destination address
