/* unit_08879FA4: 0x08879FA4-0x0887A34C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xA4];
    s16 state;  /* 0xA4 */
    s16 unkA6;
    s16 timer;  /* 0xA8 */
    s16 delay;  /* 0xAA */
    s16 unkAC;
    s16 count;  /* 0xAE */
    u8 padB0[0xC8 - 0xB0];
    s32 handle; /* 0xC8 */
} Obj;

extern char *D_089CC438;
extern char *D_08A62CB4;
extern s32 D_08A62D8C;
extern s32 D_09A4F0C4;

extern char *func_088DCEBC(s32, u8);
extern s32 func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088854A0(s32, s32, s32);
extern u16 func_0884FB6C(char *p);
extern void func_0885058C(char *, s32);

s32 func_08879FA4(Obj *obj) {
    s32 n;

    func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    if (obj->delay > 0) {
        obj->delay--;
    }
    switch (obj->state) {
    case 0:
        if (--obj->timer < 0) {
            obj->state++;
            obj->timer = 10;
            func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 1:
        if (--obj->timer < 0) {
            obj->state++;
            obj->timer = 10;
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 2:
        if (--obj->timer < 0) {
            obj->state++;
            obj->timer = 10;
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 3:
        if (--obj->timer < 0) {
            obj->state++;
            obj->timer = 10;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 4:
        if (--obj->timer < 0) {
            obj->state++;
            obj->timer = 10;
            obj->count = 0;
        }
        break;
    case 5:
        if (*(s32 *)(D_08A62CB4 + 0x14) <= 0) {
            func_088854A0(D_08A62D8C, obj->handle, 0);
            obj->state++;
            obj->timer = 10;
            func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
            break;
        }
        n = 1;
        if (func_0884FB6C(D_089CC438) & 0x4000) {
            n = *(s32 *)(D_08A62CB4 + 0x14);
        }
        *(s32 *)(D_08A62CB4 + 0x14) -= n;
        func_0885058C(D_089CC438, n);
        if (obj->count == 0) {
            obj->handle = func_08883988(D_08A62D8C, 0, 8, 0, 0, 0, 0, 0, 0);
            obj->count++;
        }
        break;
    case 6:
        if (obj->delay > 0) {
            if (!(func_0884FB6C(D_089CC438) & 0x4000)) {
                break;
            }
        }
        obj->state++;
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
