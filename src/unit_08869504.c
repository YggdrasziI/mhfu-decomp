/* unit_08869504: 0x08869504-0x08869564 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08869504 */
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

extern s32 func_088564F8(char *);

s32 func_08869504(char *arg0) {
    u16 id = *(u16 *)(D_089CC438 + 0x6AF0E);
    s32 cur = func_088564F8(D_089CC438);

    if (cur == id) {
        return 0;
    }
    return (*(s32 *)(arg0 + 0x28) & 0x1000) == 0;
}
