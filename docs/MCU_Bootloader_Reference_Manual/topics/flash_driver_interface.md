# Flash driver interface

The flash driver uses the common memory interface to simplify the interaction with flash. It takes care of high level features such as read back verification, flash protection awareness, and so on. The flash memory functions map to the interface functions as so:

```

const memory_region_interface_t g_flashMemoryInterface =
{
    .read = &flash_mem_read,
    .write = &flash_mem_write,
    .fill = &flash_mem_fill,
    .flush = NULL,
    .erase = flash_mem_erase
};

```

Bootloader startup code is responsible for initializing the flash memory.

|API|Description|
|---|-----------|
|flash\_mem\_read\(\)|Performs a normal memory read if the specified region isn't protected from reading.|
|flash\_mem\_write\(\)|Calls the low-level flash\_program\(\) API. Also performs program verification if enabled with the Set Property command.|
|flash\_mem\_fill\(\)|Performs intelligent fill operations on flash memory ranges. If the fill patterns are all 1's, special action is taken. If the range is a whole number of sectors, then those sectors are erased rather than filled. Any part of an all-1's fill that is not sector-aligned and -sized is ignored \(the assumption being that it has been erased to 1's already\). Fills for patterns other than all 1's call into flash\_program\(\).|
|flash\_mem\_erase\(\)|Calls the low-level flash\_erase\(\) API. Also performs erasure verification if enabled with the Set Property command \(Enabled by default\).|

All flash\_mem\_read\(\), flash\_mem\_write\(\), flash\_mem\_fill\(\), and flash\_mem\_erase\(\) check the flash protection status for the sectors being read or programmed or erased and return an appropriate error if the operation is not allowed.

**Parent topic:**[Memory interface](../topics/memory_interface.md)

