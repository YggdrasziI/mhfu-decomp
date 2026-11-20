/* unit_088B25B4: 0x088B25B4-0x088B269C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B24E4 and unit_088B269C.
 *
 * Request 0x24 for arg1 with the 16-bit value arg2, then returns through arg0 the 20 bytes
 * at +4 of the reply when func_088B012C returns 0, zeroes otherwise (as
 * func_088B1204).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, char *);
extern void func_088B0010(s32, u16);

void func_088B25B4(Id *arg0, char *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x24);
    func_088B0010(h, arg2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
