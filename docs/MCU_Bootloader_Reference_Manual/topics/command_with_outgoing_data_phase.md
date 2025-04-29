# Command with outgoing data phase

The protocol for a command with an outgoing data phase contains:

-   Command packet \(from host\)
-   ReadMemory Response command packet \(to host\)\(kCommandFlag\_HasDataPhase set\)
-   Outgoing data packets \(to host\)
-   Generic response command packet \(to host\)

**Command with outgoing data phase**
![](../images/command_outcoming_data.svg "Command with outgoing data phase")

**Note:**

-   The data phase is considered part of the response command for the outgoing data phase sequence.
-   The host may not send any further packets while the host is waiting for the response to a command.
-   The data phase is aborted if, prior to the start of the data phase, the ReadMemory Response command packet does not contain the kCommandFlag\_HasDataPhase flag.
-   Data phases may be aborted by the host sending the final Generic Response early with a status of kStatus\_AbortDataPhase. The sending side may abort the data phase early by sending a zero-length data packet.
-   The final Generic Response packet sent after the data phase includes the status for the entire operation.

**Parent topic:**[MCU bootloader protocol](../topics/mcu_bootloader_protocol.md)

