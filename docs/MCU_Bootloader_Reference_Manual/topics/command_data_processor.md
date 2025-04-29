# Command/data processor

This component reads complete packets from the abstract packet interface, and interprets them as either command packets or data packets. The actual handling of each command is done by command handlers called by the command processor. The command handler tells the command processor whether a data phase is expected and how much data it is expected to receive.

The command/data processor ignores any unexpected commands or data packets if received. In this instance, the communications link resynchronizes upon reception of the next valid command.

**Parent topic:**[Peripheral interfaces](../topics/peripheral_interfaces.md)

