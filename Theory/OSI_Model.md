# Networking

## OSI Model

### **Application**

At the very top of the OSI Reference Model stack of layers, we find the Application layer which is implemented by the network applications. These applications produce the data, which has to be transferred over the network. This layer also serves as a window for the application services to access the network and for displaying the received information to the user. 

Example: Application – Browsers, Skype Messenger, etc. 

### **Presentation**
The presentation layer is also called the Translation layer. The data from the application layer is extracted here and manipulated as per the required format to transmit over the network. 

## Functions of Presentation

* **Translation:** For example, ASCII to EBCDIC.
* **Encryption/ Decryption:** Data encryption translates the data into another form or code. The encrypted data is known as the ciphertext and the decrypted data is known as plain text. A key value is used for encrypting as well as decrypting data.
* **Compression:** Reduces the number of bits that need to be transmitted on the network.

### **Session**

This layer is responsible for the establishment of connection, maintenance of sessions, and authentication, and also ensures security.

#### Functions of Session Layer

* **Session establishment, maintenance, and termination:** The layer allows the two processes to establish, use and terminate a connection.
* **Synchronization:** This layer allows a process to add checkpoints that are considered synchronization points in the data. These synchronization points help to identify the error so that the data is re-synchronized properly, and ends of the messages are not cut prematurely and data loss is avoided.
* **Dialog Controller:** The session layer allows two systems to start communication with each other in half-duplex or full-duplex.

### **Transport**

The transport layer provides services to the application layer and takes services from the network layer. The data in the transport layer is referred to as Segments. It is responsible for the End to End Delivery of the complete message. The transport layer also provides the acknowledgment of the successful data transmission and re-transmits the data if an error is found.

* **At the sender’s side:** The transport layer receives the formatted data from the upper layers, performs Segmentation, and also implements Flow & Error control to ensure proper data transmission. It also adds Source and Destination port numbers in its header and forwards the segmented data to the Network Layer. The sender needs to know the port number associated with the receiver’s application. 


* **At the receiver’s side:** Transport Layer reads the port number from its header and forwards the Data which it has received to the respective application. It also performs sequencing and reassembling of the segmented data. 


### **Network**

The network layer works for the transmission of data from one host to the other located in different networks. It also takes care of packet routing i.e. selection of the shortest path to transmit the packet, from the number of routes available. The sender & receiver’s IP addresses are placed in the header by the network layer. 

#### Functions of Network Layer

* **Routing:** The network layer protocols determine which route is suitable from source to destination. This function of the network layer is known as routing.
* **Logical Addressing:** To identify each device on Internetwork uniquely, the network layer defines an addressing scheme. The sender & receiver’s IP addresses are placed in the header by the network layer. Such an address distinguishes each device uniquely and universally.


### **Data Link**

The data link layer is responsible for the node-to-node delivery of the message. The main function of this layer is to make sure data transfer is error-free from one node to another, over the physical layer. When a packet arrives in a network, it is the responsibility of the DLL to transmit it to the Host using its MAC address. 
The Data Link Layer is divided into two sublayers: 

* **Logical Access Control Layer:** Logical Link Control (LLC) provides the logic for the data link as it controls the synchronization, multiplexing, flow control, and even error-checking functions of DLL (Data Link Layer). 

* **Media Access Control Layer:** 
  * It provides an abstraction of the physical layer to the LLC and upper layers of the OSI network.
  * It is responsible for encapsulating frames so that they are suitable for transmission via the physical medium.
  * It resolves the addressing of source station as well as the destination station, or groups of destination stations.
  * It performs multiple access resolutions when more than one data frame is to be transmitted. It determines the channel access methods for transmission.
  * It also performs collision resolution and initiating retransmission in case of collisions.
  * It generates the frame check sequences and thus contributes to protection against transmission errors.

MAC Address is a 12-digit hexadecimal number (6-Byte binary number), which is mostly represented by Colon-Hexadecimal notation. The First 6 digits (say 00:40:96) of the MAC Address identify the manufacturer, called OUI (Organizational Unique Identifier). IEEE Registration Authority Committee assigns these MAC prefixes to its registered vendors. The rightmost six digits represent Network Interface Controller, which is assigned by the manufacturer. 

### **Physical Layer**  

The physical layer contains information in the form of bits. It is responsible for transmitting individual bits from one node to the next. When receiving data, this layer will get the signal received and convert it into 0s and 1s and send them to the Data Link layer, which will put the frame back together. Ex: Hub, Repeater, Modem, and Cables are Physical Layer devices. 

#### Functions of Physical Layer

* **Bit synchronization:** The physical layer provides the synchronization of the bits by providing a clock. This clock controls both sender and receiver thus providing synchronization at the bit level.
* **Bit rate control:** The Physical layer also defines the transmission rate i.e. the number of bits sent per second.
* **Physical topologies:** Physical layer specifies how the different, devices/nodes are arranged in a network i.e. bus, star, or mesh topology.
* **Transmission mode:** Physical layer also defines how the data flows between the two connected devices. The various transmission modes possible are Simplex, half-duplex and full-duplex.

## TCP/IP Protocol

* **Application:**
* **Presentation:**
* **Session:**
* **Transport:**
* **Internet:**
* **Network Access:**