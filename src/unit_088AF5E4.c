/* unit_088AF5E4: 0x088AF5E4-0x088AF6EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF500 and unit_088AF6EC.
 *
 * Request 6 for the 8-byte key arg1 with D_09A201F8, D_09A20210 and the
 * status arg2 (func_088AFFBC), then returns through arg0 the 20 bytes at
 * +4 of the reply when func_088B012C returns 0, zeroes otherwise (as
 * func_088AE718).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A201F8[];
extern char D_09A20210[];

extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, char *);
extern void func_088B0284(s32, char *);
extern void func_088B02C8(s32, char *);
extern void func_088AFFBC(s32, u16);

void func_088AF5E4(Id *arg0, char *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 6);
    func_088B0284(h, D_09A201F8);
    func_088B02C8(h, D_09A20210);
    func_088AFFBC(h, arg2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
