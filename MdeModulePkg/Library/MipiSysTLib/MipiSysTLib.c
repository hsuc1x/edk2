/** @file

Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Uefi.h>
#include <Library/MipiSysTLib.h>
#include "mipi_syst.h"

/**
  Invoke initialization function in Mipi Sys-T module to initialize Mipi Sys-T handle.

  @param[in, out]  MipiSystHandle  A pointer to MIPI_SYST_HANDLE structure.
**/
VOID
EFIAPI
InitMipiSystHandle (
  IN OUT VOID  *MipiSystHandle
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  mipi_syst_init (MipiSystH->systh_header, 0, NULL);
  mipi_syst_init_handle (MipiSystH->systh_header, MipiSystH, NULL, 0);
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  mipi_syst_write_debug_string (
    MipiSystH,
    MIPI_SYST_NOLOCATION,
    MIPI_SYST_STRING_GENERIC,
    Severity,
    Len,
    Str
    );
}

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
  )
{
  MIPI_SYST_HANDLE  *MipiSystH;

  MipiSystH = (MIPI_SYST_HANDLE *)MipiSystHandle;
  mipi_syst_write_catalog64_message (
    MipiSystH,
    MIPI_SYST_NOLOCATION,
    Severity,
    CatId
    );
}
