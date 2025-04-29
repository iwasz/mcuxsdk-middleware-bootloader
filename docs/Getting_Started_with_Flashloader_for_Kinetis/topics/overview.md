# Overview

This document describes the steps required to program a user application image into Kinetis flash memory, utilizing the standardized MCU bootloader command interface. In the factory, the device boots from flash memory and loads the flashloader into RAM. Running from RAM, the flashloader has access to the entire flash array for placement of the user application. After the user application is programmed into flash memory, the flashloader is no longer available.


```{include} ../topics/flashloader.md
:heading-offset: 1
```

```{include} ../topics/host_utilities.md
:heading-offset: 1
```

