# elftosb utility options

The below table shows the command line options used to create the i.MX RT bootable image.

**elftosb utility options**

| Option | Description |
| --- | --- |
| -f | Specify the bootable image format<p>To create the i.MX RT bootable image, the usage for family argument “-f” is: “-f imx” <p>To create the SB file, the usage is: “-f kinetis” |
| -c | Command file to generate corresponding bootable image <p>For example, “-c program_flexspi_nor_hyperflash.bd” |
| -o | Output file path<p>For example, “-o ivt_flashloader.bin” |
| -V | Print extra detailed log information |
| -? | Print help info |