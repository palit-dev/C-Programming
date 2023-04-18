# Data Link Layer
 It is responsible for the node-to-node delivery of data. Its major role is to ensure error-free transmission of information. DLL is also responsible to encode, decode and organize the outgoing and incoming data. 
 The data link layer is further divided into two sub-layers, which are as follows:

* **Logical Link Control:** This sublayer of the data link layer deals with multiplexing, the flow of data among applications and other services, and LLC is responsible for providing error messages and acknowledgments as well. 

* **Media Access Control:** MAC sublayer manages the device’s interaction, responsible for addressing frames, and also controls physical media access.

## Functions of Data Link Layer
1. **Framing:** The packet received from the Network layer is known as a frame in the Data link layer. At the sender’s side, DLL receives packets from the Network layer and divides them into small frames, then, sends each frame bit-by-bit to the physical layer. It also attaches some special bits (for error control and addressing) at the header and end of the frame. At the receiver’s end, DLL takes bits from the Physical layer organizes them into the frame, and sends them to the Network layer. 

2. **Addressing:** The data link layer encapsulates the source and destination’s MAC address/ physical address in the header of each frame to ensure node-to-node delivery. MAC address is the unique hardware address that is assigned to the device while manufacturing. 

3. **Error Control:** Data can get corrupted due to various reasons like noise, attenuation, etc. So, it is the responsibility of the data link layer, to detect the error in the transmitted data and correct it using error detection and correction techniques respectively. DLL adds error detection bits into the frame’s header, so that receiver can check received data is correct or not.

4. **Flow Control:** If the receiver’s receiving speed is lower than the sender’s sending speed, then this can lead to an overflow in the receiver’s buffer and some frames may get lost. So, it’s the responsibility of DLL to synchronize the sender’s and receiver’s speeds and establish flow control between them. 

5. **Access Control:** When multiple devices share the same communication channel there is a high probability of collision, so it’s the responsibility of DLL to check which device has control over the channel and CSMA/CD and CSMA/CA can be used to avoid collisions and loss of frames in the channel. 

## Flow Control

### Stop and Wait ARQ
The Stop and Wait Automatic Repeat Request (ARQ) is used for noisy channels or links and it manages the flow and error control between the sender and the receiver. The stop and wait ARQ protocol sends a data frame and then waits for an acknowledgment or ACK from the receiver. The ACK means that the receiver has successfully received the data frame. After the sender receives the ACK from the receiver, it sends the next data frame.

### Go Back N ARQ
Go Back N Automatic Repeat Request (ARQ) is a sliding window protocol in which multiple frames are sent from sender to receiver at once. The number of frames that are sent at one depends upon the size of the window that is taken. The Receiver window in Go Back N ARQ protocol is always of size 1. This means that the receiver takes at most 1 frame at a single time.

When ACK for first frame is received, it slides the transmiting window by one frame and trasnmits it. If no ACK is received, it retransmits the entire window.

### Selective Repeat ARQ
 In the selective repeat ARQ, we only resend the data frames that are damaged or lost. If any frame is lost or damaged then the receiver sends a negative acknowledgment (NACK) to the sender and if the frame is correctly received, it sends back an acknowledgment (ACK). As we only resend the selected damaged frames so we name this technique the Selective Repeat ARQ technique. The ACK and the NACK have the sequence number of the frame that helps the sender to identify the lost frame.

## Medium Access Protocols
Multiple Access Protocols operate in the Medium Access Control sublayer (MAC sublayer) of the OSI(Open Systems Interconnection) model. These protocols enable several nodes or users to share a network channel.

### Pure Aloha
 In pure Aloha, each station transmits data to a channel without determining if the channel is idle or not. Hence, the probability of a collision is high, and the data frame may be lost. When any station sends a data frame to a channel, the pure Aloha waits for the receiver's acknowledgment. If the receiver's acknowledgment is not received within the given time, the station waits for a random amount of time, known as the backoff time (Tb). The Vulnerable time for any station must be twice the transmission time because to stop the collision of frames, we must make sure that no other station starts its transmission between Tt time before and Tt time after the transmitting station. The efficiency of Pure Aloha is 18.4%.

### Slotted Aloha
In slotted Aloha, the shared channel is split into fixed time intervals called slots. As a result, if a station wants to send a frame to a shared channel, it can only do so at the start of the slot, and only one frame can be sent to each slot. Additionally, the station must wait until the beginning of the slot for the subsequent transmission if it is unable to transfer data at the beginning of the slot. However, sending a frame at the start of two or more station time slots still carries the risk of a collision. The Vulnerable Time in the case of Slotted Aloha is equal to the transmission time of the station. It is because we bound the transmission of stations with the slots. The efficiency of Slotted Aloha is 36.8%.

#### CSMA
CSMA stands for Carrier Sense Multiple Access (CSMA). 
* If any device wants to send data then the device first sense or listens to the network medium to check whether the shared network is free or not. If the channel is found idle then the device will transmit its data.
* This sense reduces the chance of collision in the network but this method is not able to eliminate the collision.
* Carrier Sense Multiple Access (CSMA) is a protocol that senses or listens to the medium before any transmission of data in the medium.
* CSMA is used in Ethernet networks where two or more network devices are connected. 

In the CSMA vulnerable time is considered as the propagation time and Tp is used to denote it.

##### Types of CSMA Access Modes

* **1-Persistent:** If the channel is busy, the station keeps sensing the channel and it will trasnmit the data, the moment it is free.
* **Non-Persistent:** If the channel is busy, it will wait for a random amount of time before sensing again. However, it will transmit the data the moment the channel is free.
* **p-Persistent:** If the channel is busy, it will wait for a random amount of time before sensing again. However, when the channel is free, it will transmit the data with p probability.

##### Variations of CSMA Protocol


* **CSMA/CD:** CSMA/CD protocol works with the medium access control layer of the network. That’s why the station senses the channel before transmission of data and if the station founds the channel idle then the station transmits its data frames to check whether data transmission is successful in the network or not. If the station successfully the data frame sent then it will again send the next frame. If the station detects a collision in the network, then in CSMA/CD the station will send the stop/jam signal to all the stations connected in the network to terminate their transmission of data. Then the station waits for a random amount of time for the transmission of data.

* **CSMA/CA:** Carrier Sense Multiple Access/Collision Avoidance is used in Wireless network because its difficult to detect a collision in Wireless medium. Hence, it tries to avoid collisions by sending Clear To Send (CTS) and Ready To Send (RTS) signals and wating for random amount of Interframe Space and Contention Window.

## Framing

* **Byte Stuffing:** If the pattern of the flag byte is present in the message byte, there should be a strategy so that the receiver does not consider the pattern as the end of the frame. In byte stuffing, a special byte called the escape character (ESC) is stuffed before every byte in the message with the same pattern as the flag byte. If the ESC sequence is found in the message byte, then another ESC byte is stuffed before it.

* **Bit Stuffing:** In a data link frame, the delimiting flag sequence generally contains six or more consecutive 1s. In order to differentiate the message from the flag in case of the same sequence, a single bit is stuffed in the message. Whenever a 0 bit is followed by five consecutive 1bits in the message, an extra 0 bit is stuffed at the end of the five 1s. When the receiver receives the message, it removes the stuffed 0s after each sequence of five 1s. The un-stuffed message is then sent to the upper layers.