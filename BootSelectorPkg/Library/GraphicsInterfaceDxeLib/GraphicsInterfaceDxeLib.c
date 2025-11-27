#include <Uefi.h>
#include <Base.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/GraphicsOutput.h>

#include <Include/Library/GraphicsInterfaceDxeLib.h>

void
EFIAPI
SetBltBuffer (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *Output
)
{

}

EFI_STATUS
EFIAPI
RenderScene (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput,
  OUT EFI_SCREEN_COORDINATE *ScreenCoord,
  OUT EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput
)
{
  EFI_STATUS Status;

  Status = TextOutput->ClearScreen (TextOutput);

  Status = TextOutput->OutputString (TextOutput, L"Preparing for BootSelector\r\n");

  return Status;
}

EFI_STATUS
EFIAPI
InitializeGop (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput,
  OUT EFI_SCREEN_COORDINATE *ScreenCoord,
  OUT EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput
)
{
  EFI_STATUS Status;

  Status = gBS->AllocatePool (
    EfiLoaderCode,
    sizeof (EFI_GRAPHICS_OUTPUT_PROTOCOL),
    (void **)&GraphicsOutput
  );

  Status =gBS->AllocatePool (
    EfiLoaderCode,
    sizeof (EFI_SCREEN_COORDINATE),
    (void **)&ScreenCoord
  );

  Status = gBS->AllocatePool (
    EfiLoaderCode,
    sizeof (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL),
    (void **)&TextOutput
  );

  return Status;
}

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
GraphicsDxeEntry (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_STATUS Status;
  EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput = NULL;
  EFI_SCREEN_COORDINATE *ScreenCoord = NULL;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput = NULL;

  Status = InitializeSystemTable (
    SystemTable
  );

  Status = InitializeGop (
    GraphicsOutput,
    ScreenCoord,
    TextOutput
  );

  RenderScene (GraphicsOutput, ScreenCoord, TextOutput);

  return Status;
}
