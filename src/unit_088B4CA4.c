/* unit_088B4CA4: 0x088B4CA4-0x088B4D78 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B4C64 and unit_088B4D78.
 *
 * Message builder (kind 0x16, the console address D_09A2887C), as
 * func_088B4950.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A2887C[];

extern void memset(void *, s32, s32);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, s32);
extern void func_088B0240(s32, char *);

void func_088B4CA4(Id *arg0) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 0x16);
    func_088B0240(h, D_09A2887C);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
