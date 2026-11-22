/* unit_08892E7C: 0x08892E7C-0x08892F18 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Opens a font through the sceLibFont imports (names from the import table).
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    s32 pad0[5];
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    char pad1C[0xA8 - 0x1C];
} FontStyle;

extern char D_089AD380[];
extern s32 sceFontNewLib(void *params, s32 *err);
extern s32 sceFontGetNumFontList(s32 lib, s32 *err);
extern s32 sceFontFindOptimumFont(s32 lib, FontStyle *style, s32 *err);
extern s32 sceFontOpen(s32 lib, s32 index, s32 mode, s32 *err);
extern s32 sceFontGetFontInfo(s32 font, void *info);
extern void memset(void *, s32, s32);

void func_08892E7C(s32 *arg0) {
    s32 err;
    FontStyle style;

    arg0[0] = sceFontNewLib(D_089AD380, &err);
    sceFontGetNumFontList(arg0[0], &err);
    memset(&style, 0, sizeof(FontStyle));
    style.unk14 = 0;
    style.unk16 = 0;
    style.unk1A = 1;
    arg0[1] = sceFontFindOptimumFont(arg0[0], &style, &err);
    arg0[2] = sceFontOpen(arg0[0], arg0[1], 0, &err);
    err = sceFontGetFontInfo(arg0[2], arg0 + 3);
}
