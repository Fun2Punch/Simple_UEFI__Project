#ifndef __SYSTEM_MANAGER_LIB_H__
#define __SYSTEM_MANAGER_LIB_H__

EFI_STATUS
EFIAPI
InitializeSystemTable (
  IN EFI_SYSTEM_TABLE *SystemTable
);

EFI_STATUS
EFIAPI
SystemManagementEntry (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
);

#endif
