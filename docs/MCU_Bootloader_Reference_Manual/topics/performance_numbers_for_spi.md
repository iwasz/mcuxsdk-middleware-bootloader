# Performance Numbers for SPI

The table below provides reference to the expected performance of write speeds to Flash and RAM memories using the MCU bootloader SPI interface. The numbers were measured on a number of platforms running the MCU bootloader from either the ROM or the RAM \(for flashloaders\).

**Performance numbers SPI**
| SPI Bus Freque ncy (KHz) | Flash Average Writing Speed (KB/s) |||| || Ram Average Writing Speed (KB/s) ||||||
|---|---|---|--- |--- |--- |--- |--- |--- |--- |--- |--- |---|
|| KL27 | KL28 | KL43 | KL80 | K80 | KL03 | KL27 | KL28 | KL43 | KL80 | K80 | KL03 |
| 100 | 7.07 | 7.46 | 7.24 | 6.74 | 6.71 | 6.20 | 8.60 | 9.25 | 9.01 | 8.46 | 8.04 | 6.80 |
| 200 | 11.45 | 12.26 | 11.88 | 11.53 | 10.18 | 8.87 | 15.23 | 17.98 | 17.04 | 16.17 | 14.19 | 10.64 |
| 300 | 13.84 | 15.17 | 14.70 | 15.08 | 12.42 | - | 19.91 | 25.11 | 23.06 | 24.65 | 18.79 | - |
| 400 | 16.42 | 18.09 | 17.23 | 16.91 | 13.74 | - | 25.89 | 32.95 | 31.15 | 28.89 | 23.95 | - |
| 500 | 18.26 | 19.82 | 18.17 | 18.94 | 14.98 | - | 31.47 | 40.10 | 36.61 | 36.61 | 27.83 | - |
| 600 | 18.72 | 20.72 | 19.98 | 20.63 | 15.21 | - | 32.40 | 44.98 | 40.96 | 42.26 | 27.67 | - |
| 800 | 21.19 | 22.06 | 22.27 | 22.04 | 16.11 | - | 39.83 | 50.00 | 51.54 | 49.98 | 30.15 | - |
| 1000 | 22.07 | 23.74 | 23.80 | 22.92 | 15.99 | - | 45.83 | 61.19 | 55.92 | 56.34 | 29.11 | - |
| Default core Freque ncy (MHz) | 48 | 48 | 48 | 48 | 48 | 8 | 48 | 48 | 48 | 48 | 48 | 8 |
| Default bus Freque ncy (MHz) | 24 | 24 | 24 | 24 | 24 | 4 | 24 | 24 | 24 | 24 | 24 | 4 |

**Note:**

1.  Every test covers all flash or RAM regions with 0x0 - 0xf.
2.  Run every test three times and calculate the average.

**Flash Average Writing Speed**
![](../images/spi_flash_average_writing_speed.png "
                Flash Average Writing Speed
            ")

**RAM Average Writing Speed**
![](../images/spi_ram_average_writing_speed.png "
                RAM Average Writing Speed
            ")

**Parent topic:**[SPI Peripheral](../topics/spi_peripheral.md)

