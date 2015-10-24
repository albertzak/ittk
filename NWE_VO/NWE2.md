OSI              | TCP/IP Protocol Suite     | Protocol Data Unit    | Responsibility, Protocols

7 Application    |  Application              | Data                  | HTTP, FTP, DNS, DHCP...
6 Presentation   |                           |                       | ASCII, JPEG
5 Session        |                           |                       | SIP, H.323

4 Transport      |  Transport                | Segment (!)           | Segments <=> Data; TCP, UDP

3 Network        |  Internet (!)             | Packet (!)            | Routing; IP, IPX, ICMP

2 Data Link      |  Network Access (!)       | Frame (!)             | Error handling, Switch; Ethernet 802.3, PPP
1 Physical       |                           | Bit                   |


Encapsulation = 'packing the data'
OSI specifies that each layer (starting at L2 and up) adds a header
L2 also adds a trailer ['Frame Check Sequence', often 32bit CRC (Cyclic Redundancy Check)]
Multiple headers on one layer: Example ICMP is wrapped inside IP, both happen at L3

TCP/IP Segmentation happens at (L4) Transport
Fragmentation (L3) != Segmentation (L4)


Segment > Packet > Frame
OSI = X.200
OSI Speak: SAP (Service Access Point) = Interface between Layers

## L1

Physical: Cables, dumb legacy hubs, repeaters etc.
Not: not a NIC, Not an (L2) switch

Exchange of *data* through the *transmission* of *signals*
  Data: Entity that converys meaning
  Signal: Electric/Electromagnetic representation of Data
  Signaling: Physical propagation of a signal along a medium
  Transmission: 'the whole process'

Quality depends on:
  - quality of signal
  - quality of medium

Shared media: Wireless ['air']

"Multiple Access": Original mening: Legacy T-split coaxial; also may mean a switch

half-duplex = only one side can send at one time (!= full-duplex)
ANSI
  - Simplex: sent in one direction, ever (!)
  - Half-duplex: One direction AT A time (!)
  - Full-Duplex: Both direcitons, same time

Signal: Continuous != Discrete [a/d]
  - Attenuation, Attenuation distortion [higher frequencies have greater attenuation = distorts the signal]
  - Noise
  - Latency / delay distortion or jitter [when delay is varying, bigger problem than latency itself]

Encoding
  - coordinated via clocking


Transmission
  - Async
    - independenet clocks
    - start and stop marks
    - short sections, inefficient
    - oversampling is used [much faster reading that actual bitrate]

  - Sync
    - more common today
    - clocks synced regularly
    - sometimes one wire is used as clock
    - more often: changes in signal are used as clock

Digital Data -> digital signal
  - Line coding

Digital Data -> analog signal
  - Digital Modulation
  - keying, shift-keying

Analog data -> digital signal
  - Digitization

Analog data -> analog signal
  - no change, or analog Modulation
  - no keying

Modulation:
  - varying carrier signal in accordance with a message signal
  - no carrier signal on ethernet, because digital signal [baseband transmission]

--

Digital data to Digital Signal
  - Voltage levels
  - why not 0=no voltage; 1=voltage?
    - because DC bad for transmission
    - better: positive and negative voltage
      - called NRZ(-L) 'non return to zero (level)'
    - usually, but not always: HIGH = 0 || LOW = 1
    - bit time == signal time
    - bit rate == baud rate
    - NRZ Problems:
      - clock recovery
      - baseline wander (signal level misinterpreted)

    - NRZI - Inverted
      - produces more changes to signal
      - is a form of differential encoding (changes between successive transmissions)
  - Manchester Encoding
    - signal changes twice as often as the bit
    - baud rate is twice as high as bit rate
    - called biphase
    - used in legacy ethernet (10Mbps)
    - 0 = low-to-high || 1 = high-to-low (or the other way 'round...)
    - Manchester = clock XOR NRZ
    - one low-high pair is one bit

  - Differential Manchester

  - Multilevel - more than 2 levels of signal
    - Bipolar AMI [alternate mark inversion] !== biphase (!)
      - 0 = no signal
      - 1 = high or low, alternating
      - comparison w/ nrz:
        - good: long strings of 1s
        - bad: long strings of 0s
    - pseudoternary
      - like AMI, but zero flips

(i) Data rate = bit rate ['rate of data transmitted'] => bits per second
(i) modulation rate = baud rate ['rate at which signal elemtns are generated'] => baud

  - Scrambling
    - solves long strings of no changes: force flips
    - US: B8ZS = if 8 zeroes after another: substiute for this pattern [depends of what has come before]
      - uses code violations: Signal pattern not allowed in AMI [eg 2 positives or 2 negatives]
      - "if 8 zeroes and a before that there was a one: plug in that sequence:"
        - "000+-0-+" -> receiver has to inprepret as 00000000
    - Europe: 4 zeroes, depends on odd/even numbher of pulses since last subsitution

100Mbps Ethernet 'fast ethernet'
  - 4B -> 5B Code groups
    - every combination of 4 bits, there's a combination of 5 bits defined
    - actually 5 bits are transmitted
    - 80% efficiency

Gigabit Ethernet
  - 8B -> 10B Block codes



(that was all digital data to digital signal)
    
