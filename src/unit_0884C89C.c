/* unit_0884C89C: 0x0884C89C-0x0884C914 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884C89C: 0x0884C89C-0x0884C914 (ULES01213) */

typedef int s32;
typedef unsigned char u8;

extern s32 D_08A62C40;
extern s32 D_089CC000;

extern void func_0884C914(char *);
extern s32 func_088597FC(s32);

s32 func_0884C89C(char *arg0, u8 arg1) {
    if ((s32)(*(u8 *)(arg0 + 0x20C) != 0) != 0) {
        func_0884C914(arg0);
    }
    D_089CC000 = func_088597FC(D_08A62C40);
    if (D_089CC000 != 0) {
        *(u8 *)(arg0 + 0x20C) = 1;
        *(s32 *)(arg0 + 0x210) = D_089CC000;
        *(u8 *)(arg0 + 0x20D) = arg1;
    }
    return *(u8 *)(arg0 + 0x20C) != 0;
}
