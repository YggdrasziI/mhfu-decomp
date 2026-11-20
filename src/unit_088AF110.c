/* unit_088AF110: 0x088AF110-0x088AF1D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF020 and unit_088AF1D4.
 *
 * Request 2, then returns through arg0 the 20 bytes at +4 of the reply when
 * func_088B012C returns 0, zeroes otherwise (as func_088AE718).
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, s32);

void func_088AF110(Id *arg0) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
