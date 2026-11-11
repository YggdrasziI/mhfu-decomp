/* unit_088AB028: 0x088AB028-0x088AB068 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int sceNetAdhocPdpDelete(s32, s32);

s32 func_088AB028(s32 *arg0) {
    s32 temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 >= 0) {
        sceNetAdhocPdpDelete(temp_a0, 0);
        *arg0 = -1;
    }
    return 0;
}
