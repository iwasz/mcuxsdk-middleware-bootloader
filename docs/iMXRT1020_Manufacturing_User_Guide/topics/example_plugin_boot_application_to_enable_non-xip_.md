# Example Plugin boot application to enable non-XIP boot on FlexSPI NOR

The Non-XIP boot case is not natively supported by some i.MX RT Boot ROM devices. In this case, a simple plugin boot image can be created to enable non-XIP boot case for these boot devices.

The basic flow of how Plugin boot works is as follows:

Here are the example codes for plugin boot application for RT10xx FlexSPI NOR boot.

```
#define BOOT_IMAGE_LOAD_BASE 0x60008000
enum
{
    kTag_HAB_IVT = 0xd1,
};
typedef struct _hab_hdr
{
    uint8_t tag;
    uint8_t len[2];
    uint8_t version;
} hab_hdr_t;
typedef struct _hab_ivt
{
    hab_hdr_t hdr;
    uint32_t entry;
    uint32_t reserved1;
    uint32_t dcd;
    uint32_t boot_data;
    uint32_t self;
    uint32_t csf;
    uint32_t reserved2;
} hab_ivt_t;
//!@brief Boot data structure
typedef struct _boot_data
{
    uint32_t start;
    uint32_t length;
    uint32_t plugin;
    uint32_t reserved;
} boot_data_t;
//!@brief Boot Image header, including both IVT and BOOT_DATA
typedef struct _boot_image_hdr
{
    hab_ivt_t ivt;
    boot_data_t boot_data;
} boot_image_hdr_t;
/*!@brief Plugin Download function
 *
 * This function is used to copy non-xip boot image from Flash to RAM
 *
 */
bool plugin_download(void **start, size_t *bytes, uint32_t *ivt_offset)
{
    bool result = false;
    const boot_image_hdr_t *boot_hdr;
    //Search IVT
    uint32_t ivt_offset_list[3] = {0, 0x400, 0x1000};
    uint32_t search_index = 0;
    while (search_index < sizeof(ivt_offset_list) / sizeof(ivt_offset_list[0]))
    {
        boot_hdr = (const boot_image_hdr_t *)(ivt_offset_list[search_index] +
                                              BOOT_IMAGE_LOAD_BASE);
        if (boot_hdr->ivt.hdr.tag != kTag_HAB_IVT)
        {
            search_index++;
            continue;
        }
        *start = (void *)boot_hdr->boot_data.start;
        *bytes = boot_hdr->boot_data.length;
        *ivt_offset = boot_hdr->ivt.self - boot_hdr->boot_data.start;
        uint32_t *dst = (uint32_t *)boot_hdr->boot_data.start;
        uint32_t *src = (uint32_t *)((uint32_t)boot_hdr - *ivt_offset);
        size_t remaining_length = ((*byte + 3) & ~0x03) / 4;
        while (remaining_length--)
        {
            *dst++ = *src++;
        }
        result = true;
        break;
    }
    return result;
}
```

**Parent topic:**[Plugin boot application](../topics/plugin_boot_application.md)

