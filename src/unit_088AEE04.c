/* unit_088AEE04: 0x088AEE04-0x088AEEB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AEDA0 and unit_088AEEB8.
 *
 * Request 0x8006 with arg1 (func_088AEEB8), after the set-up of
 * func_088B01BC with arg0. The 20 bytes at +4 of the reply are copied to a
 * local that is not used afterwards.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088B01BC(s32, s32);
extern void func_088AEEB8(s32, s32);
extern void func_088AFFBC(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);

void func_088AEE04(s32 arg0, s32 arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg0);
    func_088AEEB8(h, arg1);
    func_088AFFBC(h, 0x8006);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
}
