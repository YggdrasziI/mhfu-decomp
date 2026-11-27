/* unit_08819128: 0x08819128-0x08819450 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08819128: draw an entry for a kind and id (a record box for kind 1
 * above 0x18, else a text box picked from the flags at 0x528).
 *
 * NonMatching (98.84 %): only the saved registers of the copy of p.x and of
 * j are swapped (s2/s3) after the first call. The s16 pair is a local
 * structure: its members get the `seh` copies after the call that plain s16
 * locals never get. */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern u16 D_0893B144[];
extern u16 D_0893B158[];
extern u16 D_0893B16C[];
extern u16 D_0893B180[];
extern u16 D_0893B194[];
extern u16 D_0893B1A8[];
extern u8 D_0899D198[][24];
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AC864;
extern s32 D_09B22D70;
extern u16 *D_0893AF34[];

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08819450(char *, u16, s32, s32, s32);
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern s32 func_088303A0(char *, u8);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern char *func_0885151C(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);
extern void func_0882FC50(char *, u16 *, char *, s32);

typedef struct XY {
    s16 x;
    s16 y;
} XY;

void func_08819128(char *arg0, u8 kind, u16 id, s32 arg3) {
    u8 *rec;
    char *s;
    u16 *box;
    XY p;
    s32 by;
    s32 flags;
    s32 j;

    if (kind < 8 && id != 0xFFFF) {
        if (kind == 1 && id > 0x18) {
            flags = *(s32 *)(arg0 + 0x528);
            p.x = 0x48;
            p.y = 0x28;
            if (flags & 0x200) {
                p.y += 0x60;
            } else if (flags & 0x800) {
                p.x += 0x90;
                p.y += 0xA0;
            }
            func_0882DCA0(arg0, p.x, p.y, 0x100, 0x40, 0xFF);
            by = p.y;
            j = id - 0x18;
            func_08819450(arg0, j, (s16)(p.x + 0x30), (s16)(by + 9), arg3);
            rec = D_0899D198[j];
            func_0882E2C0(arg0, j, p.x + 0xA, by + 8, 0x20, 0x20, 1, 0xFF);
            func_08890E38(D_08A631A8, func_088303A0(arg0, rec[2]));
            func_08890DE8(D_08A631A8, 0xC, 0xC);
            s = func_0885151C(D_089CC438, D_089AC864);
            func_088920A8(D_08A631A8, p.x + 8, by + 0x2A, s, rec[2] + 1);
            func_08890E38(D_08A631A8, 0);
        } else {
            flags = *(s32 *)(arg0 + 0x528);
            if (flags & 0x200) {
                if (flags & 0x10) {
                    box = D_0893B158;
                } else {
                    box = D_0893B144;
                }
            } else if (flags & 0x100) {
                box = D_0893B158;
            } else if (kind == 3 && *(u16 *)(arg0 + 0x5FC) == 8) {
                box = D_0893B1A8;
            } else if (kind == 3 && id < 9) {
                box = D_0893B194;
            } else if (kind == 3 && *(u16 *)(arg0 + 0x5FC) >= 9) {
                box = D_0893B180;
            } else {
                box = D_0893B16C;
            }
            switch (kind) {
            default:
                s = func_0885151C(D_089CC438, D_0893AF34[kind][id]);
                break;
            case 4:
            case 5:
                s = func_09A7B790(D_09B22D70, D_0893AF34[kind][id]);
                break;
            }
            func_0882FC50(arg0, box, s, 0xFF);
        }
    }
}
