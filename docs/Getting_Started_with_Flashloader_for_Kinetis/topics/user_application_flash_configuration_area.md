# User application: Flash configuration area

The Flash Configuration Area \(0x400-0x40F\) must be populated with known values as per the specific Kinetis platform reference manual. In particular, values of the FSEC \(0x40C\) and FOPT \(0x40D\) locations may prevent future writes to the Kinetis flash. In the user application code, the vector table should begin at offset 0x410. If any other code is linked to begin at offset 0x410, the default erased value \(0xFF\) of these locations makes the device secure. However, mass erase is enabled.

