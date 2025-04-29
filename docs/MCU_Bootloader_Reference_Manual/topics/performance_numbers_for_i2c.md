# Performance numbers for I2C

The table below provides reference to the expected performance of write speeds to Flash and RAM memories using the MCU bootloader I2C interface. The numbers have been measured on a number of platforms running the MCU bootloader from either ROM or RAM \(for flashloaders\).

**Performance numbers for I2C**
| I2C Bus Freque ncy (KHz) | Flash Average Writing Speed (KB/s)|||| || Ram Average Writing Speed (KB/s) ||||||
|---|---|---|--- |--- |--- |--- |--- |--- |--- |--- |--- |---|
|| KL27 | KL28 | KL43 | KL80 | K80 | KL03 | KL27 | KL28 | KL43 | KL80 | K80 | KL03 |
| 100 | 6.42 | 6.29 | 6.42 | 6.7 | 6.39 | 6.08 | 7.67 | 7.27 | 7.7 | 7.91 | 7.38 | 6.13 |
| 200 | 10.24 | 10.08 | 10.13 | 10.58 | 9.82 | 8.75 | 14.02 | 13.25 | 13.78 | 14.15 | 13.43 | 10.1 |
| 300 | 12.86 | 11.84 | 11.95 | 13.11 | 11.85 | 9.69 | 18.04 | 17.51 | 17.92 | 18.98 | 17.61 | 11.9 |
| 400 | 15.54 | 14.06 | 14.39 | 14.74 | 13.44 | 10.24 | 23.2 | 22.39 | 21.82 | 24.19 | 22.04 | 12.82 |
| 500 | 15.86 | 16.13 | 15.96 | 16.94 | 14.65 | - | 24.61 | 27.9 | 26.5 | 30.26 | 26.93 | - |
| 600 | 18.14 | 16.51 | 16.4 | 17.19 | 15.19 | - | 29.44 | 28.64 | 27.05 | 30.96 | 27.57 | - |
| 800 | 19.5 | - | 18.51 | 19.22 | 16.26 | - | 34.44 | - | 33.38 | 38.36 | 32.72 | - |
| 1000 | 20.48 | - | 20.03 | 21.35 | 17.71 | - | 37.64 | - | 41.04 | 45.38 | 33.65 | - |
| Default core Freque ncy (MHz) | 48 | 48 | 48 | 48 | 48 | 8 | 48 | 48 | 48 | 48 | 48 | 8 |
| Default bus Freque ncy (MHz) | 24 | 24 | 24 | 24 | 24 | 4 | 24 | 24 | 24 | 24 | 24 | 4 |
**Note:**

1.  Every test covers all flash or RAM regions with 0x0 - 0xf.
2.  Run every test three times and calculate the average.

**Flash Average Writing Speed**
![](../images/i2c_flash_average_writing_speed.png "
                Flash Average Writing Speed
            ")

**RAM Average Writing Speed**
![](../images/i2c_ram_average_writing_speed.png "
                RAM Average Writing Speed
            ")

**Parent topic:**[I2C peripheral](../topics/i2c_peripheral.md)

