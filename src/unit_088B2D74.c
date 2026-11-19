/* unit_088B2D74: 0x088B2D74-0x088B2ED4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2C20 and unit_088B2ED4.
 *
 * Collects the 8-byte addresses of the accepted records at D_09A2851C +
 * 0x116C whose byte at +0xC5 is clear and counts the others. When the
 * count equals D_09A299A9 the record arg0 moves to its next phase; else
 * its timer +0xC runs down and, when it expires, either moves to the next
 * phase (no retries left at +0x14) or restarts the timer and replies with
 * func_088B2300 to each collected address.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    Addr8 addr;
    char unk8[0xBD];
    u8 unkC5;
    char padC6[2];
} Rec;

extern char D_09A2851C[];
extern u16 D_09A28BF0;
extern u8 D_09A299A9;

extern void func_0880C464(void *, s32, s32);
extern s32 func_088B04B4(void *);
extern void func_088B2300(Id *, Addr8 *, u16);

void func_088B2D74(u8 *arg0) {
    Addr8 *q;
    s32 j;
    Addr8 buf[4];
    Id a;
    s32 i;
    s32 n;
    char *p;
    Addr8 *dst;

    func_0880C464(buf, 0, sizeof(buf));
    n = 0;
    i = 0;
    p = D_09A2851C;
    dst = buf;
    do {
        if (func_088B04B4(p + 0x116C)) {
            if (((Rec *) (p + 0x116C))->unkC5 != 0) {
                n++;
            } else {
                *dst = ((Rec *) (p + 0x116C))->addr;
                dst++;
            }
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    if (n == D_09A299A9) {
        arg0[0x22]++;
        arg0[0x23] = 0;
        return;
    }
    if (--*(s32 *) (arg0 + 0xC) >= 0) {
        return;
    }
    if (*(s32 *) (arg0 + 0x14) <= 0) {
        arg0[0x22]++;
        arg0[0x23] = 0;
    } else {
        *(s32 *) (arg0 + 0xC) = 0x3C;
        --*(s32 *) (arg0 + 0x14);
        j = 0;
        q = buf;
        do {
            if (func_088B04B4(q)) {
                func_088B2300(&a, q, D_09A28BF0);
            }
            j++;
            q++;
        } while (j < 4);
    }
}
