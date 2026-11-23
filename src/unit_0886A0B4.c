/* unit_0886A0B4: 0x0886A0B4-0x0886A2D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_0886A0B4: picks a weighted random entry from a table. */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern u16 **D_09CD3CF0[];
extern u16 **D_09CE470C[];
extern int func_08856D60(char *o, u8 v);
extern char *func_088DCEBC(s32, u8);

static inline s32 func_sel(char *a0) {
    if (*(u8 *)(D_089CC438 + 0x480) != 0) {
        return 0;
    }
    return *(s8 *)(*(char **)(a0 + 0x4C) + 0x45);
}

void func_0886A0B4(char *arg0, s32 arg1) {
    u16 **tbls;
    u16 *p;
    u16 *q;
    s32 sum;
    s32 r;
    s32 acc;

    tbls = D_09CD3CF0[*(s8 *)(*(char **)(arg0 + 0x68) + 0x1C)];
    if (func_sel(arg0) != 0) {
        if (func_sel(arg0) == 1) {
            if (func_08856D60(D_089CC438, 0x1F) == 0) {
                p = tbls[0];
            } else {
                p = tbls[1];
            }
        } else {
            p = tbls[2];
        }
        sum = 0;
        for (q = p; *q != 0xFF; q += 2) {
            sum += *q;
        }
        if ((u16)arg1 == 0xFF) {
            r = ((u8 *)(arg0 + 0x11D))[*(u8 *)(D_089CC438 + 0x28)] % sum;
        } else {
            r = ((u8 *)(arg0 + 0x11D))[(u16)arg1] % sum;
        }
        acc = 0;
        q = p;
        while (*q != 0xFF) {
            acc += *q++;
            if (r < acc) {
                break;
            }
            q++;
        }
        if ((u16)arg1 == 0xFF) {
            *(u16 *)(D_089CC438 + 0x6AF0E) = *q;
        } else {
            u16 v = *(u16 *)(D_089CC438 + 0x6AF0E);
            *(u16 *)(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)) + 0x29A) = v;
        }
    } else if ((u16)arg1 == 0xFF) {
        if (*(u8 *)(D_089CC438 + 0x480) == 0) {
            *(u16 *)(D_089CC438 + 0x6AF0E) = **(u16 **)((char *)D_09CE470C + *(u8 *)(D_089CC438 + 0x6AF10) * 8);
        } else {
            *(u16 *)(D_089CC438 + 0x6AF0E) = *(u16 *)(D_089CC438 + 0x484);
        }
    } else {
        u16 v = *(u16 *)(D_089CC438 + 0x6AF0E);
        *(u16 *)(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)) + 0x29A) = v;
    }
}
