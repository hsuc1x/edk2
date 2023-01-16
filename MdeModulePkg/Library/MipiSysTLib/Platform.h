/** @file

Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef MIPI_SYST_PLATFORM_H_
#define MIPI_SYST_PLATFORM_H_

typedef struct {
  UINT8    *MmioAddr;
} TRACE_HUB_PLATFORM_SYST_DATA;

struct mipi_syst_platform_handle {
  TRACE_HUB_PLATFORM_SYST_DATA    TraceHubPlatformData;
};

/**
  Write 4 bytes to Trace Hub MMIO addr + 0x10.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD32Ts (
  IN  VOID    *MipiSystHandle,
  IN  UINT32  Data
  );

/**
  Write 4 bytes to Trace Hub MMIO addr + 0x18.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD32Mts (
  IN  VOID    *MipiSystHandle,
  IN  UINT32  Data
  );

/**
  Write 8 bytes to Trace Hub MMIO addr + 0x18.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD64Mts (
  IN  VOID    *MipiSystHandle,
  IN  UINT64  Data
  );

/**
  Write 1 byte to Trace Hub MMIO addr + 0x0.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD8 (
  IN  VOID   *MipiSystHandle,
  IN  UINT8  Data
  );

/**
  Write 2 bytes to Trace Hub MMIO mmio addr + 0x0.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD16 (
  IN  VOID    *MipiSystHandle,
  IN  UINT16  Data
  );

/**
  Write 4 bytes to Trace Hub MMIO addr + 0x0.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD32 (
  IN  VOID    *MipiSystHandle,
  IN  UINT32  Data
  );

/**
  Write 8 bytes to Trace Hub MMIO addr + 0x0.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Data            Data to be written.
**/
VOID
EFIAPI
SthWriteD64 (
  IN  VOID    *MipiSystHandle,
  IN  UINT64  Data
  );

/**
  Clear data in Trace Hub MMIO addr + 0x30.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
**/
VOID
EFIAPI
SthWriteFlag (
  IN  VOID  *MipiSystHandle
  );

/**
  Get Epoch time.

  @retval UINT64    A numeric number for timestamp.
**/
UINT64
EFIAPI
MipiSystGetEpochUs (
  VOID
  );

#define MIPI_SYST_PLATFORM_CLOCK()  MipiSystGetEpochUs ()

#ifndef MIPI_SYST_PCFG_ENABLE_PLATFORM_STATE_DATA
#define MIPI_SYST_OUTPUT_D32TS(MipiSystHandle, Data)   SthWriteD32Ts ((MipiSystHandle), (Data))
#define MIPI_SYST_OUTPUT_D32MTS(MipiSystHandle, Data)  SthWriteD32Mts ((MipiSystHandle), (Data))
#define MIPI_SYST_OUTPUT_D64MTS(MipiSystHandle, Data)  SthWriteD64Mts ((MipiSystHandle), (Data))
#define MIPI_SYST_OUTPUT_D8(MipiSystHandle, Data)      SthWriteD8 ((MipiSystHandle), (Data))
#define MIPI_SYST_OUTPUT_D16(MipiSystHandle, Data)     SthWriteD16 ((MipiSystHandle), (Data))
#define MIPI_SYST_OUTPUT_D32(MipiSystHandle, Data)     SthWriteD32 ((MipiSystHandle), (Data))
  #if defined (MIPI_SYST_PCFG_ENABLE_64BIT_IO)
#define MIPI_SYST_OUTPUT_D64(MipiSystHandle, Data)  SthWriteD64 ((MipiSystHandle), (Data))
  #endif
#define MIPI_SYST_OUTPUT_FLAG(MipiSystHandle)  SthWriteFlag ((MipiSystHandle))
#endif

#endif // MIPI_SYST_PLATFORM_H_
