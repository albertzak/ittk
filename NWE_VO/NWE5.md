Slash Subnet Notation
/24 <- means that 24 bits are set to 1:
255.255.255.0
 4 + 4 + 4    = 24 bits set

Hosts have routing tables: "This interface is Network 192.168.1.x", "127.0.0.0 is to myself"

Why L3 fragmentation? Make packets fin into the network's MTU (Maximum Transmission Unit)
(!= L4 Segmentation, takes data stream and splits it)

IP header fields for fragemntation:
 - identification "belongs to which packet?"
 - fragment offset "where to put this fragment?" - divided by 8 (!)
 - flags "are there more fragments coming? (MF, more fragments)" or "don't fragment flag (DF)"

[ end of IP ]

ICMP = Internet Control Message Protocol (L3)
ICMP is encapsulated by IP (both on same layer 3, but ICMP lies above IP)

- Control Messages (!) [not all ICMP messages are error messages]
- Error Messages

ping: echo request - echo reply

ICMP Header: 8 bytes, first 4: TYPE, CODE, CHECKSUM
Code depends on Type, not all types have codes

[ end of ICMP ]

ARP = Address resolution protocol
IP to MAC lookup via broadcast

[ end of ARP ]
[ jump back down to L2 and L1 ]

# Ethernet

specified at L2 and L1

[ see slide annotations ]
