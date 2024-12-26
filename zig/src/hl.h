typedef int32_t RgbValue;

/// Highlighting attribute bits.
///
/// sign bit should not be used here, as it identifies invalid highlight
typedef enum {
  HL_INVERSE         = 0x01,
  HL_BOLD            = 0x02,
  HL_ITALIC          = 0x04,
  // The next three bits are all underline styles
  HL_UNDERLINE_MASK  = 0x38,
  HL_UNDERLINE       = 0x08,
  HL_UNDERCURL       = 0x10,
  HL_UNDERDOUBLE     = 0x18,
  HL_UNDERDOTTED     = 0x20,
  HL_UNDERDASHED     = 0x28,
  // 0x30 and 0x38 spare for underline styles
  HL_STANDOUT      = 0x0040,
  HL_STRIKETHROUGH = 0x0080,
  HL_ALTFONT       = 0x0100,
  // 0x0200 spare
  HL_NOCOMBINE     = 0x0400,
  HL_BG_INDEXED    = 0x0800,
  HL_FG_INDEXED    = 0x1000,
  HL_DEFAULT       = 0x2000,
  HL_GLOBAL        = 0x4000,
} HlAttrFlags;

/// Stores a complete highlighting entry, including colors and attributes
/// for both TUI and GUI.
typedef struct {
  int16_t rgb_ae_attr, cterm_ae_attr;  ///< HlAttrFlags
  RgbValue rgb_fg_color, rgb_bg_color, rgb_sp_color;
  int16_t cterm_fg_color, cterm_bg_color;
  int32_t hl_blend;
  int32_t url;
} HlAttrs;

