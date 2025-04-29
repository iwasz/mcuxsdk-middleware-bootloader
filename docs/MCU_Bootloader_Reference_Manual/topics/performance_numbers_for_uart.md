# Performance Numbers for UART

The table below provides reference to the expected performance of write speeds to Flash and RAM memories using the MCU bootloader SPI interface. The numbers have been measured on a number of platforms running the MCU bootloader either from ROM or the RAM \(in case of flashloaders\).

**Performance numbers for UART**
|**UART Baud Rate**|**Flash Average Writing Speed \(KB/s\)**|||| |||**Ram Average Writing Speed \(KB/s\)**|||||||
|---|---|---|--- |--- |--- |--- |--- |--- |--- |--- |--- |---|---|---|
||KL27|KL28|KL43|KL80|K80|KL03|KS22|KL27|KL28|KL43|KL80|K80|KL03|KS22|
|19200|1.47|1.47|1.43|1.47|1.46|1.43|1.45|1.51|1.52|1.48|1.52|1.52|1.49|1.51|
|38400|2.81|2.82|2.75|2.82|2.79|2.81|2.75|2.99|3.03|2.95|3.03|3.03|2.9|3.00|
|57600|4.07|4.07|3.97|4.08|4.01|-|3.93|4.46|4.53|4.4|4.54|4.51|-|4.47|
|115200|7.3|7.31|7.12|7.35|7.1|-|6.88|8.69|8.97|8.65|8.98|8.85|-|8.73|
|230400|12.14|-|11.83|12.27|11.42|-|11.01|16.57|-|16.77|17.58|16.73|-|16.65|
|Default core Frequency \(MHz\)|48|48|48|48|48|8|48|48|48|48|48|48|8|48|
|Default bus Frequency \(MHz\)|24|24|24|24|24|4|24|24|24|24|24|24|4|24|

**Note:**

1.  Every test covers all flash or RAM region with 0x0 - 0xf.
2.  Run every test three times and calculate the average.

**Flash Average Writing Speed**
![](../images/flash_average_writing_speed.png "
                Flash Average Writing Speed
            ")

**RAM Average Writing Speed**
![](../images/average_ram_writing_speed.png "
                RAM Average Writing Speed
            ")

**Parent topic:**[UART peripheral](../topics/uart_peripheral.md)

