/* unit_0884C914: 0x0884C914-0x0884C9B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884C914: 0x0884C914-0x0884C9B8 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 *D_089CC000;
extern s32 D_08A62C40;

extern int func_088596C8(s32, char *, s32, s32);
extern int func_0885980C(s32, char *);

void func_0884C914(char *arg0) {
    s32 n;

    if ((s32)(*(u8 *)(arg0 + 0x20C) != 0) == 0) {
        return;
    }
    n = D_089CC000 - *(s32 **)(arg0 + 0x210);
    if (n != 0) {
        D_089CC000 += 2;
        func_088596C8(D_08A62C40, *(char **)(arg0 + 0x210), n + 2, *(u8 *)(arg0 + 0x20D));
        func_0885980C(D_08A62C40, (char *)D_089CC000);
    }
    D_089CC000 = 0;
    *(s32 **)(arg0 + 0x210) = 0;
    *(u8 *)(arg0 + 0x20C) = 0;
}
