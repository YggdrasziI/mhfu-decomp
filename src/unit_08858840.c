/* unit_08858840: 0x08858840-0x088588BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08858840: fills a 0x88-byte record with the current local date and
 * two 16-bit values, then passes it to func_08858904. */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* layout of ScePspDateTime in pspsdk (psptypes.h) */
typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u32 microsecond;
} ScePspDateTime;

typedef struct {
    u8 day;      /* 0x00 */
    u8 month;    /* 0x01 */
    u16 year;    /* 0x02 */
    u16 unk4;    /* 0x04 */
    u16 unk6;    /* 0x06 */
    u8 pad[0x80];
} Rec_08858840;

extern int memset(void *, s32, s32);
extern int sceRtcGetCurrentClockLocalTime(ScePspDateTime *);
extern void func_08858904(s32, Rec_08858840 *);

void func_08858840(s32 arg0, s32 arg1, s32 arg2) {
    Rec_08858840 r;
    ScePspDateTime t;

    memset(&r, 0, sizeof(r));
    r.unk4 = arg1;
    r.unk6 = arg2;
    sceRtcGetCurrentClockLocalTime(&t);
    r.year = t.year;
    r.month = t.month;
    r.day = t.day;
    func_08858904(arg0, &r);
}
