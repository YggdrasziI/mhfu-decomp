/* unit_088C0594: 0x088C0594-0x088C05FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

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

extern int sceRtcGetCurrentClockLocalTime(ScePspDateTime *);

void func_088C0594(s32 arg0, char *arg1) {
    ScePspDateTime t;

    sceRtcGetCurrentClockLocalTime(&t);
    *(s32 *)arg1 = (s32) (((u8) t.second << 0x18) + (((u8) t.minute << 0x10) + ((u8) t.day + ((u8) t.hour << 8))));
    *(s32 *)(arg1 + 4) = (s32) ((u8) t.year + ((u8) t.month << 8));
}
