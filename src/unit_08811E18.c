/* unit_08811E18: 0x08811E18-0x08812144 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u16 w;
    u16 h;
    s32 addr;
    s32 unk8;
    s32 unkC;
} Sub;

typedef struct {
    u8 unk0;
    u8 state;
    u16 size;
    Sub sub;
    u16 unk14;
    u16 pad_16;
} Entry;

extern s32 func_08812308(char *arg0);
extern s32 func_088123C8(char *arg0);
extern s32 func_08812338(char *arg0, s32 arg1);
extern void func_088124D8(char *arg0, u32 arg1, s32 arg2);

s32 func_08811E18(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Entry *e;
    Sub *s;
    s32 r;

    if ((u8)arg1 == 0xFF) {
        arg1 = (u8)func_08812308(arg0);
        if (arg1 == 0xFF) {
            return 0xFF;
        }
    }
    e = (Entry *)arg0 + (u8)arg1;
    if (e->state != 0) {
        return 0xFF;
    }
    *(u16 *)((char *)e + 0xC) = arg4;
    e->unk14 = arg5;
    s = &e->sub;
    switch (*(u16 *)((char *)e + 0xC)) {
    case 0:
    case 1:
    case 2:
        s->w = ((u16)arg2 + 7) / 8 * 8;
        s->h = ((u16)arg3 + 7) / 8 * 8;
        arg2 = (u32)(s->w * s->h * 2) >> 7;
        s->unkC = 0;
        break;
    case 3:
        s->w = ((u16)arg2 + 3) / 4 * 4;
        s->h = ((u16)arg3 + 7) / 8 * 8;
        arg2 = (u32)(s->w * s->h * 4) >> 7;
        s->unkC = 0;
        break;
    case 4:
        s->w = ((u16)arg2 + 31) / 32 * 32;
        s->h = ((u16)arg3 + 7) / 8 * 8;
        arg2 = s->w * s->h / 2 / 128;
        if ((s->unkC = func_088123C8(arg0)) == -1) {
            return 0xFF;
        }
        break;
    case 5:
        s->w = ((u16)arg2 + 15) / 16 * 16;
        s->h = ((u16)arg3 + 7) / 8 * 8;
        arg2 = s->w * s->h / 128;
        if ((s->unkC = func_088123C8(arg0)) == -1) {
            return 0xFF;
        }
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    default:
        return 0xFF;
    }
    if (arg6 == -1) {
        r = func_08812338(arg0, arg2);
        if (r == -1) {
            return 0xFF;
        }
        s->addr = *(s32 *)(arg0 + 0x450) + (r << 7);
    } else {
        r = (u32)arg6 >> 7;
        s->addr = arg6 + *(s32 *)(arg0 + 0x450);
    }
    func_088124D8(arg0, r, arg2);
    e->size = arg2;
    e->state = 3;
    return arg1;
}
