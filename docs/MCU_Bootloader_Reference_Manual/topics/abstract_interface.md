# Abstract interface

The bootloader uses a common, abstract interface to implement the memory read/write/fill commands. This is to keep the command layer from having to know the details of the memory map and special routines.

This shared memory interface structure is used for both the high-level abstract interface, as well as low-level entries in the memory map.

```
struct MemoryInterface
{
    status_t (*init)(void);
    status_t (*read)(uint32_t address, uint32_t length, uint8_t * buffer);
    status_t (*write)(uint32_t address, uint32_t length, const uint8_t * buffer);
    status_t (*fill)(uint32_t address, uint32_t length, uint32_t pattern);
    status_t (*flush)(void);
    status_t (*erase)(uint32_t address, uint32_t length)
}
```

The global bootloader context contains a pointer to the high-level abstract memory interface, which is one of the MemoryInterface structures. The internal implementation of this abstract interface uses a memory map table, referenced from the global bootloader context that describes the various regions of memory that are accessible and provides region-specific operations.

The high-level functions are implemented to iterate over the memory map entries until it finds the entry for the specified address range. Read and write operations are not permitted to cross region boundaries, and an error is returned if such an attempt is made.

The BootloaderContext::memoryMap member is set to an array of these structures:

```
struct MemoryMapEntry
{
    uint32_t startAddress;
    uint32_t endAddress;
    bool isExecutable;
    const MemoryInterface * interface;
};
```

This array must be terminated with an entry with all fields set to zero.

The same MemoryInterface structure is also used to hold the memory-type-specific operations.

Note that the MemoryMapEntry::endAddress field must be set to the address of the last byte of the region, because a <= comparison is used.

During bootloader startup, the memory map is copied into RAM and modified to match the actual sizes of flash and RAM on the chip.

**Parent topic:**[Memory interface](../topics/memory_interface.md)

