# Functional description

The reliable update works by dividing the device memory into two regions: the main application region and backup application region. Only the backup application region is allowed to be updated by the host. Once the backup region is updated with the new firmware image, the reliable update process needs to be initiated . The MCU bootloader here checks the validity and integrity of the new application image in the backup region,and copies the new image to the main application region.


```{include} ../topics/bootloader_workflow_with_reliable_update.md
:heading-offset: 2
```

```{include} ../topics/reliable_update_implementation_types.md
:heading-offset: 2
```

```{include} ../topics/reliable_update_flow.md
:heading-offset: 2
```

**Parent topic:**[Bootloader Reliable Update](../topics/bootloader_reliable_update.md)

