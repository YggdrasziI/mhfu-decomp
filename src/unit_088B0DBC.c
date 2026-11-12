/* unit_088B0DBC: 0x088B0DBC-0x088B0E04 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088B14C0(s32);
extern int func_088B6A08(s32, s32, s32);

s32 func_088B0DBC(s32 arg0, s32 arg1) {
    char sp1C[0x14];

    func_088B14C0((s32) sp1C);
    func_088B6A08(0, arg0, arg1);
    return 0;
}
