/* unit_0884CDBC: 0x0884CDBC-0x0884CDE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884CDBC: 0x0884CDBC-0x0884CDE4 (ULES01213) */

typedef int s32;
typedef unsigned char u8;

u8 func_0884CDBC(char *arg0, s32 arg1, u8 arg2) {
    if (*(u8 *)(arg0 + 0x214) == 0) {
        *(u8 *)(arg0 + 0x215) = arg2;
        *(s32 *)(arg0 + 0x218) = arg1;
        *(u8 *)(arg0 + 0x214) = 1;
        return *(u8 *)(arg0 + 0x214);
    }
    return 0;
}
