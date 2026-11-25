/* unit_08841908: 0x08841908-0x08841AB4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_08841908: C++ for the (bool) casts that keep the sltu flag tests. Speed setting. */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" char *D_089CC438;
extern "C" s32 D_09A4F0C4;
extern "C" s32 D_0893ABAC[];

extern "C" char *func_088DCEBC(s32, s32);
extern "C" void func_08841AB4(char *, char *, s32, u16);
extern "C" void func_08832B98(char *, s32);
extern "C" void func_08845270(char *, s32, s16, s32, s32);

extern "C" void func_08841908(char *p) {
    char *list[4];
    char **lp;
    s32 n;
    s32 i;
    s32 y;
    char *e;
    u16 idx;
    s32 v;

    if (*(s32 *)(p + 0x1194) & 0x20) return;
    list[0] = *(char **)(p + 0x530);
    lp = &list[1];
    n = 1;
    for (i = 0; i < 4; i++) {
        if (i == *(u8 *)(D_089CC438 + 0x28)) continue;
        e = func_088DCEBC(D_09A4F0C4, i);
        if (e == 0) continue;
        if ((bool)(*(s32 *)(e + 4) & 1) == 0) continue;
        if ((bool)*(u8 *)(D_089CC438 + (u8)i * 0x8C + 0x30) != 0 || *(u8 *)(e + 0x1E8) == 0xC) {
            *lp++ = e;
            n++;
        }
    }
    lp = list;
    y = 0x38;
    for (i = n; i > 0; i--) {
        func_08841AB4(p, *lp, 8, y);
        lp++;
        y += 0x14;
    }
    func_08832B98(p, 1);
    lp = list;
    y = 0x40;
    for (; n > 0; n--) {
        idx = *(u16 *)(*lp + 0x1E6);
        v = *(s16 *)(p + 0x56C + idx * 2);
        if (v >= 0) {
            func_08845270(p, 0xE, y, v, D_0893ABAC[idx & 3]);
        }
        lp++;
        y += 0x14;
    }
    func_08832B98(p, 0);
}
