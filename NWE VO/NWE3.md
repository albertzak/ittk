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
