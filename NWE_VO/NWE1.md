PDU = Protocol Data Unit
Network Protocols = "Rules" - Why?
  + Interoperability, Compatibility
  + Safety (Power)
  + Security

de facto = first used, then defined
de jure = first defined, then used

Organizations:
  IEEE (802.3 = Internet...) [Institute of Electrical and Electronics Engineers]
  IETF (IP, TCP...) [Internet Engineering Task Force] <3
  ITU-T (International Telecommunication Union)
  ISO (International Organization for Standardization) $$$
  ANSI (American National Standards Institute)
  ETSI

Models define: Funtionality/Protocols/Devices at each layer

Models: OSI + TCP/IP
  OSI: 7 Layers [Numbered]
  TCP/IP: 4 Layers [Named]

Why Models?
  + Point of Reference
  + Interoperability
  + Standard Interface [bewteen Layers]
  + Less complex [for Troubleshooting / Understanding - who's doing what?]

OSI "Open System Interconnection", est. 1977

L7 Application => Interface between Network and Application ['The real App/UI is acutally above L7']
L6 Presentaion => Formatting, organization, encryption, compression ['Model']
L5 Session     => Flow Establishment/Management, "Transactional Flows"
L4 Transport   => TCP/UDP, Segmentation of data, Connection establishment/termination, Error recovery, Flow control
L3 Network     => Logical Adressing: Routing, Path determination
L2 Data Link   => Frames: Preparation, Error handling, Physical Adressing: Which machined are allwoed to use the medium at which time?
L1 Physical    => Bits: Cables, Connectors, How bits are transmitted

Eselsbrücke: "All People Seem To Need Data Processing"
Application, Presentation, Session, Transport, Network, Data Link, Physical


TCP/IP "Protocol *Suite*" [Conglomeration]

L7, L6, L5 == Application
L4 == Transport
L3 == Internet
L1, L2 == Network Access
