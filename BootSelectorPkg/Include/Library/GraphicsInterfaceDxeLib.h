#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

typedef struct _EFI_SCREEN_COORDINATE {
  UINTN SourceX;
  UINTN SourceY;
  UINTN DestinationX;
  UINTN DestinationY;
  UINTN Width;
  UINTN Height;
} EFI_SCREEN_COORDINATE;

void
EFIAPI
SetBltBuffer (
  IN EFI_GRAPHICS_OUTPUT_PROTOCOL *Output
);

EFI_STATUS
EFIAPI
RenderScene (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput,
  OUT EFI_SCREEN_COORDINATE *ScreenCoord,
  OUT EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput
);

EFI_STATUS
EFIAPI
InitializeGop (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput,
  OUT EFI_SCREEN_COORDINATE *ScreenCoord,
  OUT EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *TextOutput
);

EFI_STATUS
EFIAPI
InitializeSystemTable (
  IN EFI_SYSTEM_TABLE *SystemTable
);

EFI_STATUS
EFIAPI
GraphicsDxeEntry (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
);


#endif
