/* unit_088A2204: 0x088A2204-0x088A2244 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A0D258;
extern int func_088A177C(char *);
extern int func_088A178C(char *);
extern int func_088A2244(s32);

void func_088A2204(s32 arg0) {
    func_088A177C(&D_09A0D258);
    func_088A2244(arg0);
    func_088A178C(&D_09A0D258);
}
