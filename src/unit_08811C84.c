/* unit_08811C84: 0x08811C84-0x08811E18 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Initialises a manager: EDRAM address and size, 46 slots of 0x18 bytes
 * (id, in-use flag), 0x200 cleared words, then four calls to func_08811E18.
 * sceGeEdramGetAddr / sceGeEdramGetSize take no argument (pspsdk).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void *sceGeEdramGetAddr(void);
extern u32 sceGeEdramGetSize(void);
extern void func_08811E18(s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    u8 id;
    u8 used;
    u8 pad[0x16];
} Slot;

typedef struct {
    Slot slot[0x2E];
    s32 edramAddr; /* 0x450 */
    s32 edramSize; /* 0x454 */
    s32 words[0x200]; /* 0x458 */
    s32 count; /* 0xC58 */
} Mgr;

void func_08811C84(Mgr *m) {
    s32 i;

    m->edramAddr = (s32)sceGeEdramGetAddr();
    m->edramSize = (s32)sceGeEdramGetSize();
    for (i = 0; i < 0x2E; i++) {
        m->slot[i].id = i;
        m->slot[i].used = 0;
    }
    for (i = 0; i < 0x200; i++) {
        m->words[i] = 0;
    }
    m->count = 0;
    func_08811E18((s32)m, 0, 0x200, 0x110, 1, 0, -1);
    func_08811E18((s32)m, 1, 0x200, 0x110, 1, 0, -1);
    func_08811E18((s32)m, 2, 0x200, 0x110, 0, 0, -1);
    func_08811E18((s32)m, 0x2D, 0x100, 0x20, 3, 0, 0x1F8000);
}
