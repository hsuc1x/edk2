/** @file

Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef MIPI_SYST_LIB_H_
#define MIPI_SYST_LIB_H_

#include <Uefi.h>

/**
  Invoke initialization function in Mipi Sys-T module to initialize Mipi Sys-T handle.

  @param[in, out]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
**/
VOID
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
**/
VOID
EFIAPI
WriteDebug (
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
**/
VOID
EFIAPI
WriteCatalog (
  IN  VOID    *MipiSystHandle,
  IN  UINT32  Severity,
  IN  UINT64  CatId
  );

#endif // MIPI_SYST_LIB_H_
