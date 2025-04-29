# Overview

These are the release notes for the i.MX RT1170 Flashloader. For additional information and getting started instructions, check [Getting Started](getting_started.md) section of this document.

The device Flashloader is an application that is loaded into the internal RAM of the device. The Flashloader is designed to work as a second stage bootloader for this device. It detects communication on one of the supported peripherals \(USB-HID or LPUART\), downloads a user application, and writes the application to external serial NOR. The Flashloader is initially loaded by MfgTool which then helps in programming the flash. Alternately, the Flashloader can also be loaded using blhost command-line application and blhost application can be used for flash programming.

This release includes the PC-hosted MfgTool application. This application is used for downloading user-applications to flash devices in both development and production phase. This release also includes elftosb command-line application. It is used to generate a bootable image for the device ROM and generate a programmable image supported by the Flashloader.



