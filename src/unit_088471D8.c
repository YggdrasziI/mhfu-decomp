/* unit_088471D8: 0x088471D8-0x08847418 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} Rect;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Slot;

extern Rect D_08939370;
extern Rect D_08939388;
extern char D_0893AA5C[];
extern u8 D_0899D19E[];
extern s32 D_089CC438;

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern Slot *func_08856884(s32, s32);

void func_088471D8(char *arg0, u16 x, u16 y, u16 w, u16 h, u8 idx) {
    Rect *l = &D_08939370;
    Rect *r = &D_08939388;
    u32 color;

    if (idx == 0xFF) {
        color = 0xFF808080;
    } else {
        color = *(u32 *) &D_0893AA5C[D_0899D19E[func_08856884(D_089CC438, idx)->unk0 * 0x18] * 4];
    }
    func_0882AF70(arg0, x + l->unk4, y, w - l->unk4 - r->unk4, h, 0x27);
    func_0882AF70(arg0, x + w - r->unk4, y, r->unk4, h, 0x28);
    if (*(u8 *)(*(char **)(arg0 + 0x530) + 0x1E8) != 10) {
        func_0882BE60(arg0, x, y, l->unk4, h, ((u8 *) &color)[0], ((u8 *) &color)[1], ((u8 *) &color)[2], 0x26);
    } else {
        func_0882AF70(arg0, x, y, l->unk4, h, 0x25);
        if (idx != 0xFF && func_08856884(D_089CC438, idx)->unk0 != 0x80) {
            func_0882BE60(arg0, x + 1, y, 0x10, h, ((u8 *) &color)[0], ((u8 *) &color)[1], ((u8 *) &color)[2], 0x19C);
            if (idx == *(u8 *)(*(char **)(arg0 + 0x530) + 0x5F6)) {
                func_0882A9DC(arg0, x + 3, y, 0x17F);
                func_0882A9DC(arg0, x + 0xC, y, 0x180);
            }
        }
    }
}
