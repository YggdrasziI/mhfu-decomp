/* unit_088B21D0: 0x088B21D0-0x088B22AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B20C4 and unit_088B22AC.
 *
 * Request 0x23 with the byte arg1, then returns through arg0 the 20 bytes
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
extern void func_088AFFE8(s32, u8);

void func_088B21D0(Id *arg0, u8 arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 0x23);
    func_088AFFE8(h, arg1);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
