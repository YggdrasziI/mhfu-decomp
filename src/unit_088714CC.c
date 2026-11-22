/* unit_088714CC: 0x088714CC-0x088714F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;

/* 0x2C-byte record; the function reads fields at 0x77C/0x787 past a record
 * index, so the records are addressed as raw bytes. */
typedef struct {
    u8 b[0x2C];
} Rec2C;

extern void func_09AB31C8(u8);

void func_088714CC(Rec2C *e, u8 i) {
    func_09AB31C8(e[i].b[0x77C + (s8)e[i].b[0x787]]);
}
