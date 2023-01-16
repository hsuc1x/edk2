/** @file

Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Uefi.h>
#include <Library/BaseMemoryLib.h>
#include "mipi_syst.h"

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem32 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x10, 4, Data);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem32 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x18, 4, Data);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem64 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x18, 8, Data);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x0, 1, Data);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem16 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x0, 2, Data);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem32 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x0, 4, Data);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  SetMem64 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x0, 8, Data);
}

/**
  Clear data in Trace Hub MMIO addr + 0x30.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
**/
VOID
EFIAPI
SthWriteFlag (
  IN  VOID  *MipiSystHandle
  )
{
  UINT32            Flag;
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  Flag      = 0;

  SetMem32 (MipiSystH->systh_platform.TraceHubPlatformData.MmioAddr + 0x30, 4, Flag);
}

/**
  Get Epoch time.

  @retval UINT64    A numeric number for timestamp.
**/
UINT64
EFIAPI
MipiSystGetEpochUs (
  VOID
  )
{
  UINT64  Epoch;

  Epoch = 1000;

  return Epoch;
}
