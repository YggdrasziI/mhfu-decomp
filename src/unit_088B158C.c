/* unit_088B158C: 0x088B158C-0x088B1668 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1584 and unit_088B1668.
 *
 * Request 8 with arg1, then returns through arg0 the 20 bytes at +4 of the
 * reply when func_088B012C returns 0, zeroes otherwise (as func_088B1204).
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088AFE78(void);
extern void func_0880C464(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, char *);
extern void func_088B02C8(s32, char *);

void func_088B158C(Id *arg0, char *arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 8);
    func_088B02C8(h, arg1);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
