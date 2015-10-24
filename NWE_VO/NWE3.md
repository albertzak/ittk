## Digital Data to Analog Signal
(eg. data over phone lines)

digital modulation = keying
shift (of amplitude, frequency or phase)
  - ASK Amplitude shift keying
  - FSK Frequency shift keying (BFSK, binary)
  - PSK Phase shift keying (BPSK, binary)
    - QPSK
    - MPSK ()
    = QAM
  = M*SK MFSK MPSK, more than two frequencies (more efficient, more prone to error)

## Analog Data to Digital Signals
(Analog data) -> Digitizer -> (digital data) -> Modulator -> Analog data

  - PCM Pulse code modulation
    - better
  - DM delta modulation
    - simple: 'if signal above where we are, go up, else go down'

"Sample at least 2x the rate of the signal"


## Analog Data to Analog Signal
  AM / FM / PM (!== shift keying)
  change charactersitics of wave in an analog way



### Bandwidth, Throughput, Latency
  Bandwidth = theoretical
    - digital: bps/Mbps...
    - analog: Hz
  Throughput = actual L1
  "Goodput" Throughput from Application to Application (cisco term)

  Latency = delay (one-way | roundtrip)
  Real problem: (Latency) Jitter

[end L1]

# L2 "Data Link"
[Main topic for this semester]
ARQ: ?
PDU: Frame

## L2 Functions (!)
1. Framing [beginning/end of frames]
2. error control [does the bit stream have errors?, in footer]
3. flow control [slow receivers shouls not get swamped by fast receivers]
4. medium access control [if not full-duplex ethernet, or wireless: who should write?]
5. physical addressing [what are LOCAL (repacked at every intermediary) - source and destination [MAC, ...]]

## Frame
                                      [ this is (usually) the actual frame      ]
                                      [[HEADER]  [DATA (payload)] [TRAILER: FCS]]
([Preamble])[SD: Start Delimiter Flag][[HEADER]  [DATA (payload)] [TRAILER: FCS]][ED: End Delimiter Flag]

## Header
  - Physical Addresses
  - Type of Frame
  - QoS
  - Flow control (ACK, sequence # -ARQ)
  - Congestion control
  - Higher-level signaling Codes: Connect, disconnect, ... before they can pass actual information
  - others, depending on protocol

## Trailer
  - Error control (!)
  - FCS Frame Check Sequence
  - Detection only, no correction (request resend of frame if error)

- L2 Provides data transfer service to 3 (virtual path between L3s)
Types of services provided to L3:
  - connection oriented
  - connectionless [ connection is made at another layer ]
  - acknowledged

## Framing methods
  - Character count [if one character count gets messed up, all following frames will have errors, only used together with other]
  - Flag bytes with byte stuffing ['this particular sequence is a flag that marks the begining of the frame' eg. 0111 1110; problem: if data contains flag byte. solution: escape byte.; kinda legacy because of unicode; used in PPP. ]
  - Start and End flags, with bit stuffing [data is not allowed to contain 111111. bit stuffing: insert extra zero after 5th 1. used in HDLC (many L2 protols are based on HDLC) ]
  - Physical layer coding violations [token ring, 'high-high' transition as delimiter]

  - Preamble [in ethernet: before header / before start frame delimiter: 1 byte: 10101010, used to sync]
      [Preamble][Start Delimiter Flag][[HEADER]  [DATA (payload)] [TRAILER]][End Delimiter Flag]


## Error control
  (not only at L2, ex. L3 TCP + recovery)

  - Information bits [Actual data]
  - Redundant bits
    - error detection (L2)
    - error correction (forward error correction, includes detection)

  k     = number of information bits
  (n-k) = redundant bits (FCS)
  n     = total number of bits
  "n = k + (n-k)"


  - Parity
    Sum 8 bits: 10011001 = 4 = even
    - Even Parity (if is even: zero, odd: one) [yeah, weird]
    - Odd Parity
  - Checksums [not typically used in L2]
  - CRC (L2 <3) [= FCS, usually] (frame check SEQUENCE (not: sum))

## CRC
cyclic redundancy check, done in hardware with XOR

- all bits are considered coefficients to a (high degree) polynomial, either 0 or 1 (=either term is there or not)
- info: (1 + 1 = 10 ==> discard carry  ==> 1 + 1 = 0) <= same => (1 + 1) mod 2 == 0
- yadda yadda



# ARQ [automatic repeat request]
 - is a process that can be defined by protocols, happens in OS
 - ensures that information is delivered in order and without duplication
   - error control
   - flow control
 - mechanisms:
   1. sequence numbers
   2. ACK NAK
   3. Timers / timeouts
   4. windows

 1. "Stop-And-Wait" ['Idle RQ'] - Sender waits for ACK until timeout, then resend
   - slow
   - and what if the ACK is lost? receiver gets two copies of frame
     - solution: add sequence number (alternating 1 bit)
      - problem: timers sync miss - late ack = wrong ack
   - better: "forward ack" = 'what is expected next' [that's how it's usually done]
 2. "Continuous" ARQ
   - "Go-Back-N" sender sends N frames -> window shrinks; sender receives ack -> window expands]
      - usually used because less buffering needed
      - longer sequence numbers
      - ACK is called "Receive Ready (RR)"
        - may also use "Receive not ready (RNR)"
   - NAK == REJ == Reject == Negative Ack
   - good window size: 2^k - 1
   - Full-Duplex: Piggybacking [ack is included in data answer]
 3. "Selective-Repeat" "Selective-Reject"
   - not all following frames are discarded if one is lost, can request just one frame while buffering all previous and next frames
   - sender and receiver have to buffer

Flow control
  - dedicated ???????????


## Media Access Control
  "who can use the medium when"
  - contention based [non-deterministic]
  - controlled [deterministic]

  1. CSMA/CD [ethernet]
    - Carrier Sense Multiple Access with Collision Detection

  2. CSMA/CA [wireless]
    - Carrier Sense Multiple Access with Collision Avoidance

  3. Legacy: Software Token Passing [Token ring, FDDI], deterministic
  4. Polling


## L2 Addressing
  only local L2 network (!)
  (L2) local network !== local area network (L3)
    L3: End to end
    L2: Within Network Borders
  Can be a MAC address (Ethernet) or something else (DLCI)
  Or nothing, on Point to Point (PPP) (address is filled with 11111111)

## HDLC
  is a L2 protocol family
  - the most important L2 protocol
  - many other L2 protocols are based on it

  - sync transmission
  - bit-oriented [bit stuffing 0111 1110]

  - LLC (Logical Link Control) based on HDLC
  - LAPB, LAPF, PPP, LLC, SDLC

  - "3 types of stations"
  - "3 types of transfer modes"
    - NRM, ABM (Async balanced mode is most important), ARM
    - set with a "set-mode" command in frame header

  Frame Structire in HDLC
    - Flag start, 8 bits
    - Addr, 8 bits
    - Ctrl, 8 bits
      - 0: Frame type
      - 1: Frame type
      - 2: type
      - 3: type [00 receive not ready | 01 selective reject]
      - Poll/Final [used in half-duplex to hand over sending rights; or 'checkpointing': "I need an answer right now"]
    - data
    - FCS
    - Flag (can be the start flag of the next frame)

  Types of HDLC Frames: (!)
    Information Frames (I) - actual information is sent in there
    Supervisory Frames (S)
    Unnumbered Frames (U) - disconnect request...

  window size: upto 7 unacked frames at a time
  Phases:
    - Initialize [mode...]
    - Data transfer
    - Disconnect

  Cisco HDLC
    - non-standard
    - has a "protocol type" field in ctrl: "what comes next"
