# The elftosb utility options

Table 4 shows the command line options used to create the i.MX RT bootable image.

**elftosb utility options**

|Option|Description|
|---|---|
|\-f|Specify the bootable image format <br/> To create the i.MX RT bootable image, the usage for family argument “\-f” is: “\-f imx” To create the SB file, the usage is: “\-f kinetis”|
|\-c|Command file to generate corresponding bootable image For example, “\-c program\_flexspi\_nor\_hyperflash.bd”|
|\-o|Output file path <br/> For example, “\-o ivt\_flashloader.bin”|
|\-V|Print extra detailed log information|
|\-?|Print help info|

**Parent topic:**[Description of the elftosb utility](../topics/description_of_the_elftosb_utility.md)

