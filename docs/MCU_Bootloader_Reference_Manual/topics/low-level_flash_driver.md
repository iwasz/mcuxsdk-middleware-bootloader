# Low-level flash driver

The low-level flash driver \(LLFD\) handles erase and write operations on a word basis. It cannot perform writes of less than a full word.

The bootloader startup code is responsible for initializing and shutting down the LLFD.

**Parent topic:**[Memory interface](../topics/memory_interface.md)

