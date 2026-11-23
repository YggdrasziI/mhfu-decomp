/* unit_088675BC: 0x088675BC-0x088676D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088675BC (ULES01213): field layout unknown, raw offsets. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 kind;     /* 0x0 */
    u8 pad[3];
    s32 id;      /* 0x4 */
} Entry_088675BC;

typedef struct {
    char pad0[0x800A8];
    Entry_088675BC ent[(0x8022C - 0x800A8) / 8]; /* 0x800A8 */
    char pad_e[4];
    s32 total1;                                  /* 0x8022C */
    char pad1[0x80244 - 0x80230];
    s32 total2;                                  /* 0x80244 */
    char pad2[0x80318 - 0x80248];
    s32 value[(0x803D8 - 0x80318) / 4];          /* 0x80318 */
    u8 state[(0x80408 - 0x803D8)];               /* 0x803D8 */
    u16 slot[1];                                 /* 0x80408 */
} Obj_088675BC;

void func_088675BC(Obj_088675BC *arg0, u16 arg1) {
    if (arg0->state[arg1] != 0) {
        if (arg0->state[arg1] == 4) {
            arg0->value[arg1] = 0;
        } else {
            Entry_088675BC *e = &arg0->ent[arg1];
            if (e->id != -1) {
                goto end;
            }
            switch (e->kind) {
            case 1:
                arg0->total1 -= arg0->value[arg1];
                break;
            case 2:
                arg0->total2 -= arg0->value[arg1];
                break;
            }
            arg0->value[arg1] = 0;
        }
end:
        arg0->state[arg1] = 0;
        arg0->slot[arg1] = 0xFFFF;
    }
}
