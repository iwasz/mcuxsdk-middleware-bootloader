# Response packet

The responses are carried using the same command packet format wrapped with the framing packet data. The types of responses include:

-   GenericResponse
-   GetPropertyResponse
-   ReadMemoryResponse
-   FlashReadOnceResponse
-   FlashReadResourceResponse

**GenericResponse:** After the MCU bootloader has processed a command, the bootloader sends a generic response with the status and command tag information to the host. The generic response is the last packet in the command protocol sequence. The generic response packet contains the framing packet data and the command packet data \(with generic response tag = 0xA0\) and a list of parameters \(defined in the next section\). The parameter count field in the header is always set to 2, for the status code and command tag parameters.

**GenericResponse parameters**
|Byte \#|Parameter|Descripton|
|:-----:|:--------|:---------|
|0 - 3|Status code|The Status codes are errors encountered during the execution of a command by the target. If a command succeeds, then a kStatus\_Success code is returned.|
|4 - 7|Command tag|The Command tag parameter identifies the response to the command sent by the host.|

**GetPropertyResponse:** The GetPropertyResponse packet is sent by the target in response to the host query that uses the GetProperty command. The GetPropertyResponse packet contains the framing packet data and the command packet data with the command/response tag set to the GetPropertyResponse tag value \(0xA7\).

The parameter count field in the header is set to greater than 1 to always include the status code and one or many property values.

**GetPropertyResponse parameters**
|Byte \#|Value|Parameter|
|:-----:|:---:|:--------|
|0 - 3| |Status code|
|4 - 7| |Property value|
|. . .| |. . .|
| | |Can be up to a maximum of six property values, limited to the size of the 32-bit command packet and property type.|

**ReadMemoryResponse:** The ReadMemoryResponse packet is sent by the target in a response to the host sending a ReadMemory command. The ReadMemoryResponse packet contains the framing packet data and the command packet data with the command/response tag set to the ReadMemoryResponse tag value \(0xA3\) and the flags field is set to kCommandFlag\_HasDataPhase \(1\).

The parameter count set to 2 for the status code and the data byte count parameters shown here.

**ReadMemoryResponse parameters**
|Byte \#|Parameter|Descripton|
|:-----:|:--------|:---------|
|0 - 3|Status code|The status of the associated Read Memory command.|
|4 - 7|Data byte count|The number of bytes sent in the data phase.|

**FlashReadOnceResponse:**The FlashReadOnceResponse packet is sent by the target in response to the host sending a FlashReadOnce command. The FlashReadOnceResponse packet contains the framing packet data and the command packet data with the command/response tag set to a FlashReadOnceResponse tag value \(0xAF\) and the flags field set to 0. The parameter count is set to 2 plus *the number of words* requested to be read in the FlashReadOnceCommand.

**FlashReadOnceResponse parameters**
|Byte \#|Value|Parameter|
|------|---|---|
|0 – 3||Status Code|
|4 – 7||Byte count to read|
|…||…|
|||Can be up to 20 bytes of requested read data.|

The FlashReadResourceResponse packet is sent by the target in response to the host sending a FlashReadResource command. The FlashReadResourceResponse packet contains the framing packet data and command packet data with the command/response tag set to a FlashReadResourceResponse tag value \(0xB0\) and the flags field set to kCommandFlag\_HasDataPhase \(1\).

**FlashReadResourceResponse parameters**
|Byte \#|Value|Parameter|
|---|--|--|
|0 – 3||Status Code|
|4 – 7||Data byte count|

**Parent topic:**[Bootloader packet types](../topics/bootloader_packet_types.md)

