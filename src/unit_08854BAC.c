/* unit_08854BAC: 0x08854BAC-0x08854BEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
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

void func_08854BAC(s32 arg0, char *arg1) {
    ScePspDateTime t;

    sceRtcGetCurrentClockLocalTime(&t);
    *(u16 *)(arg1 + 2) = t.year;
    *(s8 *)(arg1 + 1) = (s8) t.month;
    *(s8 *)arg1 = (s8) t.day;
}
