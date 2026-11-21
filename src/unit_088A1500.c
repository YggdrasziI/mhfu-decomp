/* unit_088A1500: 0x088A1500-0x088A1554 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088A4504(s32 *);

s32 func_088A1500(s32 *arg0) {
    s32 sp14[7];

    sp14[0] = arg0[0];
    sp14[1] = arg0[1];
    sp14[2] = arg0[2];
    sp14[3] = arg0[3];
    sp14[4] = arg0[3];
    sp14[5] = arg0[4];
    sp14[6] = arg0[5];
    func_088A4504(sp14);
    return 0;
}
