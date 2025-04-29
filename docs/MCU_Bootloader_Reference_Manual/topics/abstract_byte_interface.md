# Abstract byte interface

This interface gives the framing packetizer a common interface for the peripherals that use framing packets \(see framing packetizer \).

The abstract byte interface inherits the abstract control interface.

```
struct PeripheralByteInterface
{
    status_t (*init)(const peripheral_descriptor_t * self);
    status_t (*write)(const peripheral_descriptor_t * self, const uint8_t *buffer, uint32_t byteCount);
};

```
**Abstract byte interface**
|Interface|Description|
|---------|-----------|
|init\(\)|Initialize the interface|
|write\(\)|Write the requested number of bytes|

**Note:** The byte interface has no read\(\) member. Interface reads are performed in an interrupt handler at the packet level.

**Parent topic:**[Peripheral interfaces](../topics/peripheral_interfaces.md)

