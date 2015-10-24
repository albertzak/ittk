MUX - Multiplexer

Eingänge
e0 ->
e1 ->     -> y ------> ...
e2 ->
e3 ->
      ^  ^
      a1 a0      <- Adressleitungen
       0  0 = 0
       0  1 = 1
       1  0 = 2
       1  1 = 3


DEMUX - Demultiplexer

... -----> e ->       -> a1
                      -> a2
                      -> a3
                      -> a4
                 ^  ^
                 a1 a0



DEC - Decoder
erzeugt 1 aus n code
"kompakter code in weniger kompakten code umsetzen" (gegenteil: encoding)

        -> l0
-> b0   -> l1
-> b1   -> l2
        -> l3




Abtasten = sampling = signal zu einem Zeitpunkt (statt Zeitraum wie in der transparenten Phase bei Latch)
