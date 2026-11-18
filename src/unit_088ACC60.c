/* unit_088ACC60: 0x088ACC60-0x088ACD38 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088ACC54 and
 * unit_088ACD38.
 *
 * Reset of the state block at 0x09A1DB60 (mode at +4, -1 at +0xC), with
 * the 9 or 8 bytes the caller passes copied when the mode is 1.
 */

typedef unsigned char u8;
typedef int s32;

extern void func_0880C464(void *, s32, s32);
extern int func_0880C084(void *, void *, s32);
typedef struct {
    u8 busy;
    u8 unk1;
    char unk2[2];
    u8 mode;
    char unk5[7];
    s32 unkC;
    char unk10[8];
} State;

extern State D_09A1DB60;
extern char D_09A1DAF4[];
extern char D_09A1DB00[];

void func_088ACC60(u8 mode, void *src) {
    func_0880C464(&D_09A1DB60, 0, sizeof(State));
    D_09A1DB60.mode = mode;
    D_09A1DB60.unkC = -1;
    switch (D_09A1DB60.mode) {
    case 1:
        func_0880C084(D_09A1DAF4, src, 9);
        break;
    }
    D_09A1DB60.busy = 0;
}

void func_088ACCE8(void *src) {
    D_09A1DB60.busy = 1;
    D_09A1DB60.unk1 = 0;
    switch (D_09A1DB60.mode) {
    case 1:
        func_0880C084(D_09A1DB00, src, 8);
        break;
    }
}
