# BD file

Each BD file consists of the following four blocks: options, sources, constants, section

-   The image paths are defined in the “sources” block.
-   The constant variables are defined in the “constants” block.
-   The memory configuration and programming-related operations are defined in the “section” block.

The elftosb utility supports two types of BD files. The first type of file is used for the i.MX RT bootable image generation. The “-f imx” option is mandatory during boot image generation using the elftosb utility. The second type of file contains commands that are used for memory programming. The “-f kinetis” flag is mandatory in this use case.