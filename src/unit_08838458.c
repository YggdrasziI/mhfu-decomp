/* unit_08838458: 0x08838458-0x08838640 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * The local key is 12 bytes on the stack (fields at 1 and 2 written here);
 * the two extra words are padding needed for the frame layout (hypothesis).
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    s32 unk4;
    s32 unk8;
} Key;

extern char *D_08A631A0;
extern s32 D_08A62C54;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B04E48[];
extern char D_0893B220;

extern s32 func_0885DC30(s32, u8 *);
extern void func_08890E38(char *, s8);
extern char *func_09A7B790(s32, u16);
extern s32 func_08890E48(char *, char *);
extern void func_08891474(char *, s16, s16, char *, ...);

void func_08838458(char *arg0, u16 kind, u16 id, s32 x, s32 y) {
    Key key;
    s32 lang = *(s32 *)(D_08A631A0 + 0xF7A574);
    u8 flags;
    s32 sel;
    u16 *e;

    if (kind == 6) {
        return;
    }
    if (kind == 5) {
        return;
    }
    key.unk1 = kind;
    key.unk2 = id;
    flags = func_0885DC30(D_08A62C54, (u8 *)&key);
    sel = 0xFF;
    if ((flags & 3) != 3) {
        if (flags & 1) {
            switch (flags & 0xC) {
            case 4:
                sel = 7;
                break;
            case 8:
                sel = 5;
                break;
            default:
                sel = 3;
                break;
            }
        } else {
            switch (flags & 0xC) {
            case 4:
                sel = 6;
                break;
            case 8:
                sel = 4;
                break;
            default:
                sel = 2;
                break;
            }
        }
    } else if ((flags & 0xC) != 0xC) {
        if (flags & 4) {
            sel = 1;
        } else {
            sel = 0;
        }
    }
    if (sel == 0xFF) {
        return;
    }
    func_08890E38(D_08A631A8, 5);
    e = &D_09B04E48[sel];
    x = (u16)x - (func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, *e)) * 14 >> 1);
    x = (u16)x;
    if (lang == 2 && sel == 7) {
        x = (u16)(x + 14);
    } else if (lang == 4 && sel == 5) {
        x = (u16)(x + 7);
    }
    func_08891474(D_08A631A8, (s16)x, (s16)y, &D_0893B220, func_09A7B790(D_09B22D70, *e));
}
