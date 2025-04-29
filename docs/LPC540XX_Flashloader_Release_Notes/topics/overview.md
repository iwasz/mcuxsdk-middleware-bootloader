# Overview

These are the release notes for the LPC540xx/LPC54S0xx Flashloader. For additional information and getting started instructions, check [Getting Started](getting_started_001.md) section of this document.

The device Flashloader is an application that is loaded into the internal RAM of the device. The Flashloader is designed to work as a second stage bootloader for this device. It detects communication on one of the supported peripherals \(USB-HID or UART\), downloads a user application, and writes the application to external serial NOR device. The Flashloader is initially loaded by MfgTool which then helps in programming the flash.

This release includes the PC-hosted blhost application. This blhost is used for downloading user-application to flash device in both development and production phase while device is running flashloader application and connected to PC Host.

