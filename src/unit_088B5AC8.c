/* unit_088B5AC8: 0x088B5AC8-0x088B5C30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B57A0 and unit_088B5C30.
 *
 * Message builder (kind 0x14) to the address arg1 with the status arg2;
 * on success it lists the accepted 0xC8-byte records at D_09A29364.
 *
 * NonMatching: the image keeps the original code.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A29364[];

extern void memset(void *, s32, s32);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088AFFBC(s32, u16);
extern void func_088AFFE8(s32, u8);
extern void func_088B01BC(s32, Addr8 *);
extern void func_088B0240(s32, char *);
extern void func_088B0284(s32, char *);
extern void func_088B02C8(s32, char *);
extern s32 func_088B04B4(char *);
extern s32 func_088B68FC(void);

/* NonMatching, 99.11 %: the record pointer and the counter of the loop
 * take each other's saved register ($s2 / $s3). Tried: every declaration
 * order of the four locals (char * and Rec * pointer), locals in the
 * block, a for loop, the counter set first, an s32 status cast to u16. */
void func_088B5AC8(Id *arg0, Addr8 *arg1, u16 arg2) {
    char *p;
    s32 i;
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x14);
    func_088AFFBC(h, arg2);
    if (arg2 == 0) {
        func_088AFFE8(h, (u8) func_088B68FC());
        p = D_09A29364;
        i = 0;
        do {
            if (func_088B04B4(p)) {
                func_088B0240(h, p);
                func_088B0284(h, p + 8);
                func_088B02C8(h, p + 0x20);
                func_088AFFE8(h, *(u8 *) (p + 0xC5));
            }
            i++;
            p += 0xC8;
        } while (i < 4);
    }
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
