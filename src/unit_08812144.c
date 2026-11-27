/* unit_08812144: 0x08812144-0x08812264 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 pad0;
    u8 state;
    u16 count;
    s32 size;
    s32 addr;
    u8 pad[0xC];
} Entry;

extern s32 func_08812308(char *arg0);
extern s32 func_08812338(char *arg0, u32 arg1);
extern void func_088124D8(char *arg0, u32 arg1, s32 arg2);

u8 func_08812144(char *arg0, u8 arg1, s32 arg2, s32 arg3) {
    Entry *e;
    u32 n;
    s32 r;
    u32 blk;
    s32 *p;

    if (arg1 == 0xFF) {
        arg1 = func_08812308(arg0);
        if (arg1 == 0xFF) {
            return 0xFF;
        }
    }
    e = (Entry *)arg0 + arg1;
    if (e->state != 0) {
        return 0xFF;
    }
    n = (u32)(arg2 + 0x7F) >> 7;
    p = &e->size;
    if (arg3 == -1) {
        r = func_08812338(arg0, n);
        if (r == -1) {
            return 0xFF;
        }
        p[1] = *(s32 *)(arg0 + 0x450) + (r << 7);
        blk = r;
    } else {
        p[1] = arg3 + *(s32 *)(arg0 + 0x450);
        blk = (u32)arg3 >> 7;
    }
    func_088124D8(arg0, blk, n);
    e->count = n;
    e->state = 5;
    e->size = n << 7;
    return arg1;
}
