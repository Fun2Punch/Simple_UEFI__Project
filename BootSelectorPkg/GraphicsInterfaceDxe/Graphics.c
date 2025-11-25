#include <Uefi.h>
#include <Base.h>
#include <UefiBootServicesTableLib.h>
#include <Graphics.h>

#include <Include/Library/GraphicsLib.h>

void
EFIAPI
SetBltBuffer (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *Output
)
{
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL Pixel;

  
}

EFI_STATUS
EFIAPI
RenderScene (
  VOID
)
{

}

EFI_STATUS
EFIAPI
InitializeGop (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput,
  OUT EFI_SCREEN_COORDINATE *ScreenCoord,
  OUT EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput
)
{

  GraphicsOutput = gBS->AllocatePool (
    EfiLoaderCode,
    sizeof (EFI_GRAPHICS_OUTPUT_PROTOCOL),
    (void **)&GraphicsOutput
  );

  ScreenCoord = gBS->AllocatePool (
    EfiLoaderCode,
    sizeof (EFI_SCREEN_COORDINATE),
    (void **)&ScreenCoord
  );

  TextOutput = gBS->AllocatePool (
    EfiLoaderCode,
    sizeof (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL),
    (void **)&TextOutput
  );
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
  EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput;
  EFI_SCREEN_COORDINATE *ScreenCoord;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput;

  Status = InitializeSystemTable (
    SystemTable
  );

  Status = InitializeGop (
    GraphicsOutput,
    ScreenCoord,
    TextOutput
  );
  
}
