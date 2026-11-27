/* unit_08812264: 0x08812264-0x08812308 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Sub;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    Sub sub;
    char pad14[0x18 - 0x14];
} Entry;

extern void func_0881246C(char *arg0, s32 arg1);
extern void func_0881253C(char *arg0, u32 arg1, s32 arg2);

void func_08812264(char *arg0, u8 arg1) {
    Entry *e;
    Sub *s;
    s32 flags;
    u32 off;

    e = (Entry *)arg0 + arg1;
    flags = e->unk1;
    if (flags != 0) {
        if ((u8)flags & 2) {
            s = &e->sub;
            if (s->unkC != 0) {
                func_0881246C(arg0, s->unkC);
            }
            off = (u32)(s->unk4 - *(s32 *)(arg0 + 0x450)) >> 7;
        } else {
            off = (u32)(e->sub.unk4 - *(s32 *)(arg0 + 0x450)) >> 7;
        }
        func_0881253C(arg0, off, e->unk2);
        e->unk1 = 0;
    }
}
