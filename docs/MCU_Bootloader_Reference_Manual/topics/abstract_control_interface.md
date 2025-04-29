# Abstract control interface

This control interface provides a common method to initialize and shutdown peripheral drivers. It also provides the means to perform the active peripheral detection. No data transfer functionality is provided by this interface. That is handled by the interfaces that inherit the control interface.

The main reason this interface is separate from the byte and packet interfaces is to show the commonality between the two. It also allows the driver to provide a single control interface structure definition that can be easily shared.

```

struct PeripheralDescriptor {
    //! @brief Bit mask identifying the peripheral type.
    //!
    //! See #_peripheral_types for a list of valid bits.
    uint32_t typeMask;
    //! @brief The instance number of the peripheral.
    uint32_t instance;
    //! @brief Configure pinmux setting for the peripheral.
    void (*pinmuxConfig)(uint32_t instance, pinmux_type_t pinmux);
    //! @brief Control interface for the peripheral.
    const peripheral_control_interface_t * controlInterface;
    //! @brief Byte-level interface for the peripheral.
    //!
    //! May be NULL because not all periperhals support this interface.
    const peripheral_byte_inteface_t * byteInterface;
    //! @brief Packet level interface for the peripheral.
    const peripheral_packet_interface_t * packetInterface;
};
struct PeripheralControlInterface
{
    bool (*pollForActivity)(const PeripheralDescriptor * self);
    status_t (*init)(const PeripheralDescriptor * self, BoatloaderInitInfo * info);
    void (*shutdown)(const PeripheralDescriptor * self);
    void (*pump)(const peripheral_descriptor_t *self);
}
```
**Abstract control interface**
|Interface|Description|
|---------|-----------|
|pollForActivity\(\)|Check whether communications has started.|
|init\(\)|Fully initialize the driver.|
|shutdown\(\)|Shutdown the fully initialized driver.|
|pump|Provide execution time to driver.|

**Parent topic:**[Peripheral interfaces](../topics/peripheral_interfaces.md)

