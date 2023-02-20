/** @file

Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef MIPI_SYST_LIB_H_
#define MIPI_SYST_LIB_H_

#include <Uefi.h>

/**
  Invoke initialization function in Mipi Sys-T module to initialize Mipi Sys-T handle.

  @param[in, out]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.

  @retval EFI_SUCCESS               MIPI_SYST_HANDLE instance was initialized.
  @retval EFI_INVALID_PARAMETER     On entry, MipiSystHandle is a NULL pointer.
**/
EFI_STATUS
EFIAPI
InitMipiSystHandle (
  IN OUT VOID  *MipiSystHandle
  );

/**
  Invoke write_debug_string function in Mipi Sys-T module.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Severity        An error level to decide whether to enable Trace Hub data.
  @param[in]  Len             Length of data buffer.
  @param[in]  Str             A pointer to data buffer.

  @retval EFI_SUCCESS               Data in buffer was processed.
  @retval EFI_ABORTED               No data need to be written to Trace Hub.
  @retval EFI_INVALID_PARAMETER     On entry, MipiSystHandle is a NULL pointer.
**/
EFI_STATUS
EFIAPI
MipiSystWriteDebug (
  IN        VOID    *MipiSystHandle,
  IN        UINT32  Severity,
  IN        UINT16  Len,
  IN CONST  CHAR8   *Str
  );

/**
  Invoke catalog_write_message function in Mipi Sys-T module.

  @param[in]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
  @param[in]  Severity        An error level to decide whether to enable Trace Hub data.
  @param[in]  CatId           Catalog Id.

  @retval EFI_SUCCESS      Data in buffer was processed.
**/
EFI_STATUS
EFIAPI
MipiSystWriteCatalog (
  IN  VOID    *MipiSystHandle,
  IN  UINT32  Severity,
  IN  UINT64  CatId
  );

#endif // MIPI_SYST_LIB_H_
