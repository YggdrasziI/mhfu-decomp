/* unit_088A2338: 0x088A2338-0x088A2378 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A0D258;
extern int func_088A177C(char *);
extern int func_088A178C(char *);

s32 func_088A2338(char *arg0) {
    s32 temp_s0;

    func_088A177C(&D_09A0D258);
    temp_s0 = *(s32 *)(arg0 + 0x54);
    func_088A178C(&D_09A0D258);
    return temp_s0;
}
