/* unit_08853C88: 0x08853C88-0x08853E20 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
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

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern s32 sceWlanGetEtherAddr(u8 *);
extern int sceRtcGetCurrentClockLocalTime(ScePspDateTime *);
extern char *func_0885151C(char *, u16);
extern int func_08816730(s32, char *, s32, char *);
extern int func_08853E20(char *);
extern char *D_08A631A0;
extern u16 D_089ACAE8;
extern s32 D_089CBBE8;

void func_08853C88(char *arg0) {
    u8 mac[8];
    ScePspDateTime t;

    memset(arg0 + 0x4A58, 0, 0x62D00);
    memcpy(arg0 + 0x67758, arg0 + 0x4A0, 0x12);
    sceWlanGetEtherAddr(mac);
    sceRtcGetCurrentClockLocalTime(&t);
    arg0[0x679A0] = mac[3];
    arg0[0x679A1] = mac[4];
    arg0[0x679A2] = mac[5];
    arg0[0x679A3] = t.year;
    arg0[0x679A4] = ((t.month & 0xF) << 4) + ((t.day & 0x1E) >> 1);
    arg0[0x679A5] = ((t.day & 1) << 7) + (t.minute & 0x1F);
    arg0[0x679A6] = (t.second & 0x3F) + ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x300) >> 2);
    arg0[0x679A7] = *(s32 *)(D_08A631A0 + 0xF7A554);
    *(u16 *)(arg0 + 0x677F2) = 0;
    *(u16 *)(arg0 + 0x677F4) = 0;
    *(u16 *)(arg0 + 0x677F6) = 0;
    func_08816730(D_089CBBE8, arg0 + 0x6778C, 0x62, func_0885151C(arg0, D_089ACAE8));
    func_08853E20(arg0);
}
