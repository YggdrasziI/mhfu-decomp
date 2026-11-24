/* unit_088506A4: 0x088506A4-0x08850704 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

/* func_088506A4: index of the first 12-byte entry whose flag byte is zero,
 * among the func_08850EC4() entries of the block at arg0 + 0x4A0;
 * 0xFFFF when there is none. */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 flag;
    u8 pad[11];
} Entry;

typedef struct {
    u8 pad[0xA8];
    Entry ent[1];
} Block;

extern s16 func_08850EC4(char *arg0);

u16 func_088506A4(char *arg0) {
    Block *p = (Block *)(arg0 + 0x4A0);
    s16 n = func_08850EC4(arg0);
    s16 i;

    for (i = 0; i < n; i++) {
        if (p->ent[i].flag == 0) {
            return i;
        }
    }
    return 0xFFFF;
}
