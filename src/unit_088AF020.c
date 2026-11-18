/* unit_088AF020: 0x088AF020-0x088AF110 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF008 and unit_088AF110.
 *
 * Periodic update while D_09A202C8 is set: every 61 calls, request 2
 * (func_088AF110, reply dropped) and func_088AFAD0 on D_09A201F0; every
 * 301 calls, sets +0x17F of each of the four 0xC8-byte records at
 * D_09A1FDE0 whose entry at +0xB8 func_088B04B4 accepts and whose
 * +0x17E is clear, then clears +0x17E of the four records.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 D_09A202C8;
extern s32 D_09A201E8;
extern s32 D_09A201EC;
extern char D_09A201F0[];
extern char D_09A1FDE0[];
extern u8 D_09A1FF5E;
extern u8 D_09A20026;
extern u8 D_09A200EE;
extern u8 D_09A201B6;

extern void func_088AF110(Id *);
extern void func_088AFAD0(char *);
extern s32 func_088B04B4(char *);

void func_088AF020(void) {
    Id id;
    s32 i;
    char *r;

    if (D_09A202C8 == 0) {
        return;
    }
    if (--D_09A201E8 < 0) {
        D_09A201E8 = 60;
        func_088AF110(&id);
        func_088AFAD0(D_09A201F0);
    }
    if (--D_09A201EC < 0) {
        D_09A201EC = 300;
        i = 0;
        r = D_09A1FDE0;
        do {
            if (func_088B04B4(r + 0xB8)) {
                if (((u8 *) r)[0x17E] == 0) {
                    r[0x17F] = 1;
                }
            }
            i++;
            r += 0xC8;
        } while (i < 4);
        D_09A1FF5E = 0;
        D_09A20026 = 0;
        D_09A200EE = 0;
        D_09A201B6 = 0;
    }
}
