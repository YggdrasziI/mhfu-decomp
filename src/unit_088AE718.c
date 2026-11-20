/* unit_088AE718: 0x088AE718-0x088AE814 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE694 and unit_088AE814.
 *
 * The request of func_088AE598 with kind 0xC and arg1 (record arg2), then
 * returns through arg0 the 20 bytes at +4 of the reply when func_088B012C
 * returns 0, zeroes otherwise.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A28884;
extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern void func_088B00DC(s32, char *, u16);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, s32);
extern void func_088B0284(s32, char *);

void func_088AE718(Id *arg0, s32 arg1, char *arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0xC);
    func_088B0284(h, &D_09A28884);
    func_088B00DC(h, arg2, *(u16 *) (arg2 + 0x300));
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
