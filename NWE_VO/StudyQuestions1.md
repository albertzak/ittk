# NWE Study Questions

## Lecture 1 - Network Protocols, Network Layers and Models

1. What are network protocols?
    - Network protocols are rules
    - Those rules explain how different technologies from different vendors work together
    - All of these are standardized by various organizations like ISO

2. Why do we need networking protocols and standards?
    - Compatibility and interoperability of devices from different companies
    - Safety, especially concerning high voltages
    - Security

3. Name a few organizations which define network standards and protocols.
    - IETF (Internet Engineering Task Force)
    - ITU-T (International Telecommunication Union, Telecommunication Standardization Sector) (previously CCITT)
    - IEEE (Institute of Electrical and Electronics Engineers)
    - TIA (Telecommunications Industry Association)
    - ISO (International Organization for Standardization)
    - ANSI (American National Standards Institute)
    - ETSI (European Telecommunications Standards Institute)

4. What are some purposes of network models and layers?
    - Point of reference
    - Models define layers
    - Models describe protocols, devices
    - Layers provide separation of concerns, reducing complexity
    - Layers define functionalities and protocols
    - Modularity, Interoperability, Standard interfaces

5. Name 2 network models which are commonly used, which we have discussed.
    - OSI reference model
    - TCP/IP Model

6. How many layers are in the OSI network model and what are their names in order? (Be sure
to know this!)
    - 7 Layers _"All People Seem To Need Data Processing"_
      - L7: Application
      - L6: Presentation
      - L5: Session
      - L4: Transport
      - L3: Network
      - L2: Data Link
      - L1: Physical

7. For each OSI layer, describe briefly what the layer defines or what happens at that layer. (Be
sure to know this!)
    - L7: Application
      - _Interface_ between network and actual application software
    - L6: Presentation
      - Organization, formatting, encryption, compression of data
    - L5: Session
      - Management of data flows between endpoints
    - L4: Transport
      - Segmentation
      - Connection handling
      - Error _recovery_
      - Flow control (prevents a fast sender from overwhelming a slow receiver)
    - L3: Network
      - Logical Adressing
      - Routing
      - Path determination
    - L2: Data Link
      - Defines rules for using the medium
      - _Recognition_ of transmission errors
      - Physical Adressing (MAC)
      - Preparation of Data Frames for transmission (FCS "Frame check sum", Trailer)
    - L1: Physical
      - Cables, connectors, "Media"
      - How bits are transmitted (Coding)


8. What does PDU stand for?
    - Protocol Data Unit

9. What are the names of the PDUs as generally referred to for TCP/IP for each OSI layer from
L4 down to L1? (Be sure to know this!)
    - L4 Transport <=> Transport. PDU: **Segment**
    - L3 Network <=> Internet. PDU: **Packet**
    - L2 Data Link <=> Network Access. PDU: **Frame**
    - L1 Physical <=> Network Access. PDU: **Bit**

10. Name some network devices and the OSI layer at which each operates.
    - **Firewall Appliances** - Anywhere from L3 Network to L7 Application
    - **Routers** - L3 Network
    - **Switches, Legacy Bridges** L2 Data Link
    - **Hubs, Repeater** L1 Physical

11. What is encapsulation? What is decapsulation? Describe these two processes. Which of
these two processes happens at the sender and which happens at the receiver? (Be sure to
know this!)
    - The sender
      - Application software and Users produce data at the top layer
      - Data is divided into smaller pieces that can be handled easily
        - This is called Segmentation
      - As data is passed down through the layers, it is encapsulated at every layer
        - Every layer attaches a Header
          - L2 also adds a trailer
          - L1 sends it over the medium
    - The receiver removes the headers in reverse order
      - and passes the de-encapsulated information up to the next layer for further processing

12. How do the layers of the 2 network models compare?
  - OSI L5-L7 Session, Presentation, Application <=> TCP/IP Application
  - OSI L4 Transport <=> TCP/IP Transport
  - OSI L3 Network <=> TCP/IP Internet
  - OSI L2 Data Link <=> TCP/IP Network Access
  - OSI L1 Physical <=> (TCP/IP Network Access)
