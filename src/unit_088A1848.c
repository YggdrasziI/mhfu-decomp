/* unit_088A1848: 0x088A1848-0x088A18B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0D254;
extern char D_09A0D258;
extern char D_09A0D25C;
extern void func_088A173C(void *);
extern void func_088A177C(void *);
extern void func_088A178C(void *);
extern void func_088A18B8(void);
extern s32 func_088A18E8(s32);
extern s32 func_088A407C(void);

void func_088A1848(s32 arg0) {
    func_088A173C(&D_09A0D25C);
    func_088A173C(&D_09A0D258);
    func_088A177C(&D_09A0D258);
    func_088A18B8();
    func_088A18E8(0x7F);
    func_088A407C();
    func_088A178C(&D_09A0D258);
    D_09A0D254 = arg0;
}
