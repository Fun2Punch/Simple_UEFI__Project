#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Base.h>
#include <Library/PrintLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Library/SystemManagerLib.h>

EFI_STATUS
EFIAPI
InitializeSystemTable (
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  gST = SystemTable;
  gBS = SystemTable->BootServices;

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
SystemManagementEntry (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_STATUS Status;

  Print (L"This is My System Manager DXE Driver Entry Point\r\n");

  Status = InitializeSystemTable (SystemTable);

  return Status;
}
