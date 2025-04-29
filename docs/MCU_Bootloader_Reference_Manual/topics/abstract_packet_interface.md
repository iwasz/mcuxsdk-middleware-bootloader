# Abstract packet interface

The abstract packet interface inherits the abstract control interface.

```
status_t (*init)(const peripheral_descriptor_t *self);
status_t (*readPacket)(const peripheral_descriptor_t *self,
                       uint8_t **packet,
                       uint32_t *packetLength,
                       packet_type_t packetType);
status_t (*writePacket)(const peripheral_descriptor_t *self,
                        const uint8_t *packet,
                        uint32_t byteCount,
                        packet_type_t packetType);
void (*abortDataPhase)(const peripheral_descriptor_t *self);
status_t (*finalize)(const peripheral_descriptor_t *self);
uint32_t (*getMaxPacketSize)(const peripheral_descriptor_t *self);
void (*byteReceivedCallback)(uint8_t byte);

```
**Abstract packet interface**
|Interface|Description|
|---------|-----------|
|init\(\)|Initialize the peripheral.|
|readPacket\(\)|Read a full packet from the peripheral.|
|writePacket\(\)|Send a complete packet to the peripheral.|
|abortDataPhase\(\)|Abort receiving of data packets.|
|finalize\(\)|Shut down the peripheral when done with use.|
|getMaxPacketSize|Returns the current maximum packet size.|
|byteReceivedCallback|Notification of received byte.|

**Parent topic:**[Peripheral interfaces](../topics/peripheral_interfaces.md)

