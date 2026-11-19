/* unit_088B1AE0: 0x088B1AE0-0x088B1BC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1A94 and unit_088B1BC4.
 *
 * Counts an attempt in arg0[0x22]; when func_088B6BC4 is ready, builds a
 * 0x14-byte result with func_088B1CA8 from D_09A28B98, D_09A28BF0 and
 * D_09A28878 and, when it is valid, queues it with func_088B1C34 and copies
 * the 0x318-byte buffer of func_088AFE78 behind it (as func_088B42C0).
 * Otherwise stores error 0x8002 / 0x8003 in arg0 and moves it to phase 2.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad[0x11];
} Res14;

typedef struct {
    s16 unk0[0x18C];
} Blk318;

extern char D_09A28B98[];
extern u16 D_09A28BF0;
extern u8 D_09A28878;

extern char *func_088AFE78(void);
extern s32 func_088B6BC4(void);
extern void func_088B1CA8(Res14 *, char *, u16, u8);
extern char *func_088B6BFC(Res14 *, void (*)(s32), s32);
extern void func_088B1C34(s32);

void func_088B1AE0(u8 *arg0) {
    Res14 res;
    char *src;
    char *dst;

    src = func_088AFE78();
    arg0[0x22]++;
    if (func_088B6BC4() != 0) {
        func_088B1CA8(&res, D_09A28B98, D_09A28BF0, D_09A28878);
        if (res.unk2 != 0) {
            dst = func_088B6BFC(&res, func_088B1C34, 0);
            dst[1] = 1;
            *(Blk318 *) (dst + 0x24) = *(Blk318 *) src;
        } else {
            *(u16 *) (arg0 + 0x26) = 0x8003;
            arg0[0x21] = 2;
            arg0[0x22] = 0;
        }
    } else {
        *(u16 *) (arg0 + 0x26) = 0x8002;
        arg0[0x21] = 2;
        arg0[0x22] = 0;
    }
}
