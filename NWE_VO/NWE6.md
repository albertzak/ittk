STP & VLANs
^ Spanning Tree Protocol

## STP

Goals:
STP
RSTP
VLANs
VLAN <-> IP Relationship
VLAN Trunking
Inter-VLAN Routing
STP Elections, Switch roles, states, ports

Multiple Switched Paths for redundancy:

Access Layer -> L3 Switches @ Distribution Layer -> L3 Switches @ Core Layer
                              ^ Switching Decisions (Policies) are made here


Example Switching Loop: S1 S2 S3 connected in a triangle with each other

Probmems: Broadcast Storms & MAC-Table Re-writes
Solution: Spanning Tree Protocol (or others)

BPDU "Bridge-PDU" (where Bridge := Switch)
every 2 secs: "Hello BPDU"

Bridge ID (BID)
Priority + Base MAC Address

Switch roles:
- Root Brigde

Port roles:
- Designated Ports (all ports on root bridge are designated ports)
- Root Port (all other switches consider path cost to root bridge to determine )
- Non-designated Port (are blocking)

Switches commmunicate with each other to decide which switch ports should be in blocking state.

Port role "Blocking": only BPDUs are received and analyzed

Path cost: Link speed + "hops"
Port cost

Edge Port: Where end devices are connected to Switch

STP States: Blocking -> (20sec) -> Listening -> (15sec) -> Learning -> (15sec) -> Forwarding ( -> Disabled )
End states: Blocking or Forwarding

= 50sec wait time until network functional after topology change -> unacceptable
Solution: Rapid Spanning Tree Protocol RSTP
RSTP:
- No more Timers
- Forwards on the fly even if not fully negotiated
- Combines states Blocking, Listening and Disabled to one "Discarding" state

## VLANs

Designate ports as belonging to a certain VLAN
VLAN Trunk: Multiple VLANs over one wire
VLAN Tag: L2 Header

Cisco: interface fast 0/1.1
                         ^VLAN Sub-Interface (Logical === Virtual)

Switch Ports:
  - Access Port (is a VLAN)
  - Trunk Port (sends frames with a VLAN Tag attached)

Different VLANs must have separate Gateways configured

Switches don't separate broadcast domains except if switch has VLANs configured

Special Types of VLANs
Default VLAN
Native VLAN: Untagged VLAN on Trunk
Management VLAN
