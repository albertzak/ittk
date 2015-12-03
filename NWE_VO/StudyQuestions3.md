# NWE Study Questions

## Lecture 3 - L2, The Data Link Layer

1. Name and explain some important L2 (Data Link Layer) tasks (i.e., problems that L2 must solve and which L2 functions are related to the solution of each of these problems). (Hint: See slide 4.) (Important!)
  - Framing (beginning (header) / end (footer) of frame)
  - Recognize transmission errors with Frame check sum in frame footer
  - Flow control (fast senders should avoid overwhelming slow receivers)
  - Media access control (legacy coax ethernet or wireless)

2. What is the PDU at L2? (Answer: Frame. The label “PDU” is not used here, but you should know this from Lecture 1, and there is a lot of discussion of frames here. I hope you know this already! This is important!)
  - Frame

3. Be able to draw a basic (generic) frame (see slide 5) and name the 3 main parts. (Important!)
  - [Header] [Data / Payload] [Footer / FCS]

4. What is the main function of the frame trailer? (Important!)
  - Error control: CRC Frame check sequence

5. What is framing? Name and explain some framing methods. (Important!) (What is byte
stuffing? What is bit stuffing? Why are they used? Why is code violation sometimes used
intentionally?)
  - Encapsulating data to transmit over media
    - needs something to distiguish frames from each other
      - Character count
        - Problem: Bad things happen after transmission errors
        - Problem: Can't request re-sends of frames
      - Flag bytes with byte stuffing
        - Problem: what if the payload contains the start/end frame delimiters?
      - solution 2: byte stuffing: "start flag" "end flag"
        - Problem: Escaping of escaping of escaping...
      - Flag bytes with bit stuffing
        - Ex.: "five 1s are always followed by a 0", has to be decoded at the receiver side



6. What does FCS mean? What is it used for?
  - Frame check sequence
  - is a checksum of the frame header + payload
  - used for detecting transmission errors

7. What is the main type of error control used in frames today? Where in the frame is it found?
  - FCS
  - Related question: What does CRC mean and what is it used for?
    - Cyclic Redundancy Check, used for calculating the FCS

8. What is the mathematical basis of the CRC? How does a computer calculate the CRC?
  - No details are required here! These questions are meant generally. Answer: The mathematical basis is binary polynomials. The computer performs CRC calculations using logic gates and bit shifting.

9. What does ARQ stand for and why is it used? (Hint: Slide 58)
  - Automatic Repeat Request
  - ARQ checks the FCS and requests retransmission on error
  - Also used at other layers

10. Name some different forms of ARQ. (Important!) If a form of ARQ is explained or pictured,
be able to recognize which one it is.
  - Stop-And-Wait: Sender waits for ACK before next transmission
  - Go-Back-N: Sliding window, send up to n frames before waiting for ACK
  - Selective-Repeat, Selective-Reject

11. What are sequence numbers and ACKs and why and how are they used? What other
mechanisms are used by ARQ? (Hint: slide 102)
12. Name 2 main techniques used for flow control. (Hint: slide 103)
13. What is media access control?
14. What form of media access control does Ethernet use? (Answer: CSMA/CD. In the Ethernet
section you will be asked to explain this!)
15. What kind of addressing is used at L2? Where are L2 addresses relevant? (See Slide 108 for
the answers.) (Important!)
