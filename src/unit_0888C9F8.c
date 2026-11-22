/* unit_0888C9F8: 0x0888C9F8-0x0888CC10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 id;
    u16 size;
    u16 flags;
} Entry;

extern char *D_089CBBE4;
extern char *D_089CC438;
typedef struct {
    u16 flags;
    u16 pad;
    s32 ptr;
} Res;
extern Res *D_09A4F0D0;
extern Entry D_0893843C[];
extern u16 D_0893843E[];
extern s32 func_088B89B0(s32, s32);
extern u8 func_0888CC10(char *);

s32 func_0888C9F8(char *arg0) {
    char *s = arg0 + 0xA0;
    char *g = D_089CBBE4;
    s32 ret;
    s32 i;
    Entry *e = 0;
    s32 p;
    Res *r;

    if (*(u8 *)(arg0 + 0x13A) != 0 && (*(u16 *)(g + 0xA72) & 1) &&
        *(u8 *)(D_089CC438 + 0x480) == 0) {
        return 1;
    }
    ret = 0;
    switch (*(u8 *)(arg0 + 0x9C)) {
    case 0:
        *(s32 *)(s + 0x40) = 0;
        for (i = 0; D_0893843C[i].id != 0xFFFF; i++) {
            if (*(u8 *)(s + 0x4E) == D_0893843C[i].id) {
                r = D_09A4F0D0;
                if (r->flags & 2) {
                    p = r->ptr;
                } else {
                    p = 0;
                }
                if (p != 0) {
                    *(s32 *)(s + 0x40) = func_088B89B0(p, D_0893843E[i * 3] + 6);
                    *(u8 *)(s + 0x9C) = i;
                    e = &D_0893843C[*(u8 *)(s + 0x9C)];
                    break;
                }
            }
        }
        if (*(s32 *)(s + 0x40) == 0) {
            ret = 1;
            break;
        }
        if (e->flags & 4) {
            *(u8 *)(s + 0x9A) = 1;
        }
        *(s16 *)(arg0 + 0x94) = 0;
        if (*(u8 *)(g + 0xA7A) == 1) {
            *(s16 *)(arg0 + 0x96) = 0;
        } else {
            *(s16 *)(arg0 + 0x96) = 2;
        }
        *(u8 *)(arg0 + 0x9C) = 1;
    case 1:
        func_0888CC10(arg0);
        if (*(s16 *)(arg0 + 0x96) != 0) {
            *(s16 *)(arg0 + 0x96) = *(s16 *)(arg0 + 0x96) - 1;
            break;
        }
        *(u8 *)(arg0 + 0x9C) = 2;
    case 2:
        if (func_0888CC10(arg0) == 0) {
            *(s16 *)(arg0 + 0x94) = *(s16 *)(arg0 + 0x94) + 1;
            break;
        }
        *(u8 *)(arg0 + 0x9C) = 3;
    case 3:
        *(s16 *)(arg0 + 0x94) = 0;
        ret = 1;
        break;
    default:
        break;
    }
    return ret;
}
