Multiplexing

Wave Division, Frequency Division, etc.
2 Types of most important Multiplexing: TDM / Time Division
"Time Slots"


(1) - Deterministic TDM "Synchronous"
    - Characteristics
      - Fixed length time slots
      - No Addressing needed
      - No Buffering needed
      - Order is maintained
      - Bad utilization of trunk
      - Transparent protocol
      - Connection-oriented
      - Good for similar timed traffic (voice) "iso-chronous"
    - Switching Form: Circuit Switching ('telephone switchboard')
    - Tech:
      - ISDN
      - PDH
      - SONET/SDH


(2) - Statistical TDM "Asynchronous" "STDM" (Statistical TDM, != Synchronous)
    - Switching Form: Packet Switching
    - Characteristics
      - Variable length/delays = different size frames
      - Users can send whenever they want -> Needs Buffers
      - Good utilization of trunk "Statistically dimensioned"
      - Needs Addressing
    - Technology:
      - Either: Datagram Principle
        - IP, AppleTalk: Connectionless
      - Or: Virtual Call Principle
        - X.25, Frame Relay, ATM: Connection-oriented

Switched Virtual Circuit SVC (setup/teardown)
Permanent Virtual Circuit PVC (preconfigured)



Legacy WAN Technologies
  - HDLC, PPP, ISDN, X.25, Frame Relay, ATM, PDH, SDH/SONET
  - Ethernet is replacing all of these WAN Technologies
  - PSTN (Public Switched Telephone Network) = "Festnetz"
  - Last mile = local loop: Connecting customer to CO (Central Office)
  (!)
  - DCE: Data Communications Equipment - connects subscribers to local loop (DCE) - Provider has Clock "clock enable" ("Provider's things") "clock side"
  - DTE: Data Termination Equipment - connects to DCE (Router or End Device) "terminal side"
  - Cable: One side DCE, other side DTE
  - CPE: Customer Premises Equipment - modelms, DSL routers, CSU/DSU, ...
  - Line of Demarcation "Line where the ownership changes"
  - UNI: User-Network Interface
  - NNI: Network-Network Interface
  - 
