/* unit_08829A48: 0x08829A48-0x08829B58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A62C7C;
extern s32 func_088564F8(char *);
extern s32 func_0886A30C(char *, s32);
extern s32 func_0886E578(char *, s32, u16);
extern s32 func_0886F78C(char *);

s32 func_08829A48(s32 arg0, s32 arg1) {
    s32 id;
    s32 r;
    s32 i;

    if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) != 0) {
        return 0;
    }
    id = *(u16 *)(D_089CC438 + 0x6AF0E);
    r = func_088564F8(D_089CC438);
    if (r != (u16)id) {
        return 0;
    }
    if (func_0886A30C(D_08A62C7C, 1) != 0) {
        return 0;
    }
    i = 0;
    do {
        if (func_0886E578(D_08A62C7C, arg1, i) < 0) {
            continue;
        }
        if ((*(s32 *)(D_08A62C7C + 0x28) & 0x10) != 0) {
            if ((u16)arg1 == 0x3A0 && func_0886F78C(D_08A62C7C) < 2000) {
                continue;
            }
        }
        return 1;
    } while (++i < 2);
    return 0;
}
