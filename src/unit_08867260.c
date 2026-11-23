/* unit_08867260: 0x08867260-0x088673CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* unit_08867260: 0x08867260-0x088673CC (ULES01213) */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad[0x80258];
    void *ptr[48];   /* 0x80258 */
    s32 size[48];    /* 0x80318 */
    u8 state[48];    /* 0x803D8 */
    u16 id[48];      /* 0x80408 */
} Obj;

extern s32 D_09A0B540;
extern s32 func_08898694(s32, s32, s32);
extern void func_08898748(s32, s32);
extern void memcpy(void *, void *, u32);

void func_08867260(Obj *arg0, s32 arg1, s32 arg2) {
    u8 dst;
    u8 src;
    s32 i;

    func_08898694(D_09A0B540, 0x19, 0x41000);
    dst = arg1 * 8;
    src = arg2 * 8;
    for (i = 0; i < 8; i++) {
        u8 s = src;
        if (arg0->id[s] != 0xFFFF) {
            u8 d = dst;
            memcpy(arg0->ptr[d], arg0->ptr[s], arg0->size[d]);
            arg0->id[d] = arg0->id[s];
            arg0->state[d] = 3;
            arg0->id[s] = 0xFFFF;
            arg0->state[s] = 0;
        }
        dst++;
        src++;
    }
    func_08898748(D_09A0B540, 0x19);
}
