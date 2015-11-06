# NWE Study Questions

## Lecture 2 - Data Communications and Data Transmission

1. What is an analog signal? What is a digital signal?
  - Analog: Continuous (Ex: sine wave)
  - Digital: Discrete (Ex: square wave, abrupt changes)

2. What are some examples of analog data? Digital data?
  - Analog: audio/video
  - Digital: binary data, text

3. Which kinds of data can be transported by which kinds of signals? (Hint: See Question 8
below.)
  - Both analog and digital data can be tranmitted by either analog or digital signals

4. Name and briefly explain some transmission impairments.
  - Latency, and delay distortion
  - Attenuation, and attenuation distortion
  - Noise

5. Name some advantages and disadvantages of digital signaling.
  - Digital signaling is less susceptible to noise interference
  - Digital connections are usually cheaper
  - Attenuation may be a greater problem in digital signaling

6. Why is some form of synchronization needed in data transmission?
  - Sender and receiver have to interpret the signal in the same way
    - Encoding and decoding must be coordinated, so that their interpretation of the signal starts and ends at the same point
    - This is achieved with clocking

7. What is half-duplex? Full-duplex?
  - Half-duplex: Only one side can send at any time
  - Full-duplex: Both sides can send at the same time

8. Name some techniques for each of the following 4 cases of transmission – and know which
techniques belong to which case:
  - Digital data → digital signal
    - **Line coding** (= digital baseband modulation)
  - Digital data → analog signal
    - DAC: Digital modulation (= **keying**)
  - Analog data → digital signal
    - ADC: Digitization
  - Analog data → analog signal
    - No change needed
    - Or can be modulated using a form of analog modulation

9. What is the difference between the bit rate and the baud rate? What does each measure? Must they be the same rate? Can they be the same rate? Must they be different rates? Can they be different rates? Why? Give some example encoding forms to support your answers.
  - Bit rate: the rate that *information is transmitted*
    - Unit: bits per second
    - (= data rate)

  - Baud rate: the rate the *signal changes*
    - Unit: baud
    - (= modulation rate)

  - They can be the same rate, but usually aren't
    - Example: Naive digital encoding
      - 0: No voltage, 1: Positive voltage

10. What is NRZ encoding? What are some problems with this form of encoding?
  - Non return to zero (level)
    - 0: Negative voltage, 1: Positive voltage (or usually reversed)
    - Problems: When there's a long sequence of 0's or 1's
      - Clocks get out of sync
      - The baseline may drift and the signal will be interpreted wrong, since the average signal level determines what is a 0 or 1
    - Better: NRZI (Inverted)
      - produces more transitions in the signal (which is good)
        - transition in signal: 1
          - solves the problem of repeated 1's, but not repeated 0's
        - no change: 0
        - (or reversed)

11. What is differential encoding? Name an example. (Hint: Both a general explanation and an
example can be found on slide 39.)
  - NRZ and NRZI are types of differential encoding
    - That means they are based on changes between successive signal elements ('difference')
    - Differential encoding: More reliable to detect transitions even when there's noise or distortion than with absolute signal values

12. What is biphase encoding? Name an example.
  - Biphase: Manchester Encoding
    - Transistions happen in the *middle* of a bit
      - 1: 'low-to-high'
      - 0: 'high-to-low'
    - Solves the problem of repeated 0's and 1's
    - Baud rate is twice the bit rate -> only 50% efficient

13. What encoding does 10 Mbps Ethernet (legacy Ethernet) use?
  - Manchester encoding is used in IEEE 802.3 Legacy Ethernet

14. What is multilevel binary encoding? Name an example.
  - Multilevel encoding uses more than 2 levels of signal:
    - 0: no signal
    - 1: alternating between positive and negative voltage
  - Example: *Bipolar AMI (Alternate Mark Inversion)*, or its opposite: *Pseudoternary*

15. What signaling technique does 100 Mbps Ethernet use? (Note: All forms of 100Base-X
Ethernet use the combination 4B/5B-NRZI, which is the answer here. Some of them use
further modified forms of this signaling that we did not discuss.)
  - 4B/5B Block codes:
    - 4 data bits are represented by a code group of 5 bits
      - this is a single signal element
    - left over combinations mean either
      - start / end of stream delimiter
      - transmit error
      - or invalid codes
    - encoded using NRZI
      - which is differential with higher reliability

16. What block encoding do most forms of Gigabit Ethernet use? (Note: We discussed the
encoding 8B/10B, which is the answer here. Just for your information, the Gigabit Ethernet forms 1000Base-SX, 1000Base-LX, and 1000Base-CX use this signaling. 1000Base-T uses a more complex signaling scheme that we did not discuss.)
  - 8B/10B
    - 8 bits are encoded into 10 pulses

17. What basic characteristics of a wave can be used in modulation to transmit data?
  - Modulation: Varying certain characteristics of a carrier signal in accordance with a message signal
    - Amplitude, ASK
    - Frequency, FSK
    - Phase, PSK

18. What is FSK? ASK? PSK? If you see a picture of each of these, you should be able to
identify which is which.
  - Convert digital data to analog signal (Example: over telephone line via a modem)
    - Amplitude Shift Keying
      - 0: no carrier wave / 1: carrier signal
      - Problem: Gain changes likely produce errors, inefficient
      - Used in optical fiber
    - Frequency Shift Keying
      - 0: Frequency 1 / 1: Frequency 2
        - usually offset by equal, opposite amounts from carrier frequency
      - Used in FM Radio, Coax LAN
    - Phase shift keying
      - Phase shift of 180°
      - Also: Differential PSK (DPSK)
        - 0: keeps phase
        - 1 constantly flips phase
      - Or: Quadrature PSK (QPSK)
        - Shifted by 90° instead of 180°
          - Thus two bits can be represented by one signal element
      - Or: Multilevel PSK (MPSK)
        - Example: 9600 baud modem
          - uses 12 phase angles, of which 4 have 2 amplitude values
          - for a total of 16 different signal elements
      - MPSK/MFSK use bandwidth more efficiently, but increase error probability

19. What does QAM stand for? What two kinds of modulation are combined in QAM?
  - QAM: Quadrature Amplitude Modulation
    - Combination of Amplitude shift keying (ASK) and Phase shift keying (PSK)
    - Two carrier waves offset by 90°, each ASK modulated
    - From Two-level ASK = QPSK; up to 16*16=265 states
    - QAM is used in ADSL and some wireless standards

20. What are the two main methods that can be used to convert analog data into a digital signal?
  - Pulse code modulation (PCM)
    - intervals of analog signal levels are assigned a discrete digital value
      - ideally non-linear (more discrete values near zero ampliude) to better quantize weak signals
    - sampling rate has to be 2x signal frequency

  - Delta modulation (DM)
    - Analog wave approximated by 'up' or 'down' at each sample interval
    - too simple

21. What is the difference between bandwidth and throughput?
  - Bandwidth: *theoretical* amount of data
    - that can be transmitted either over a medium or over the network as a whole
  - Throughput: *actual* measured performance of the link
    - less than the bandwidth

22. What is latency? What is meant by latency jitter?
  - delay time
    - one-way
    - round-trip
  - Latency = Propagation + Transmit + Queue
    - Propagation: Distance / Speed of Light
    - Transmit: Size / Bandwidth
    - Queue: Delay caused by network devices
  - Jitter: *Change* in latency
