/* unit_088CF1B0: 0x088CF1B0-0x088CF210 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern char D_089AF274;
extern char D_089AF2BC;

s32 func_088CF1B0(s32 arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((((arg1 & 0xFFFF) * 4) + (&D_089AF274 + ((arg2 & 0xFFFF) * 0xC))));
}

s32 func_088CF1E0(s32 arg0, s32 arg1, s32 arg2) {
    return *(s32 *)((((arg1 & 0xFFFF) * 4) + (&D_089AF2BC + ((arg2 & 0xFFFF) * 0xC))));
}
