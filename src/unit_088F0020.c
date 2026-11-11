/* unit_088F0020: 0x088F0020-0x088F0088 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_089CC438;
extern s32 D_09CFBBC8;
extern int func_08853E20(s32);
extern int func_09C26678(s32);

s32 func_088F0020(char *arg0) {
    *(s8 *)(arg0 + 0xD) = 0;
    *(s8 *)(arg0 + 0x10) = 0;
    func_08853E20(D_089CC438);
    func_09C26678(D_09CFBBC8);
    *(s8 *)(arg0 + 0xA72D) = 0;
    *(s8 *)(arg0 + 0xA72C) = 0;
    *(s8 *)(arg0 + 0xA72B) = 0;
    return 0;
}
