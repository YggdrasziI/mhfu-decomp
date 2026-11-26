/* unit_0884E7FC: 0x0884E7FC-0x0884E858 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884E7FC (ULES01213)
 *
 * Returns 1 when the byte at +0x214 of D_09A4F0D0 is set; otherwise returns
 * 1 when func_0884E858 rejects the request range (req+4 + req+0xC, req+8),
 * 0 when it accepts it.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern char *D_09A4F0D0;
extern s32 func_0884E858(char *, u32, s32);

s32 func_0884E7FC(char *p, char *req) {
    if (*(u8 *)(D_09A4F0D0 + 0x214) != 0 ||
        (*(u8 *)(D_09A4F0D0 + 0x214) == 0 &&
         func_0884E858(p, *(u32 *)(req + 4) + *(u32 *)(req + 0xC), *(s32 *)(req + 8)) == 0)) {
        return 1;
    }
    return 0;
}
