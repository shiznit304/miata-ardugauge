/* ----- Speeduino data addresses     */
#define SPEEDUINO_ENGINE_BITFIELD         2
  #define SPEEDUINO_ENGINE_RUNNING_BIT    0
  #define SPEEDUINO_ENGINE_CRANKING_BIT   1
  #define SPEEDUINO_ENGINE_ASE_BIT        2
  #define SPEEDUINO_ENGINE_WARMUP_BIT     3
  #define SPEEDUINO_ENGINE_TPSAE_BIT      5
#define SPEEDUINO_MAP_WORD                4
#define SPEEDUINO_IAT_BYTE                6   // - 40
#define SPEEDUINO_CLT_BYTE                7   // - 40
#define SPEEDUINO_VOLTAGE_BYTE            9   // x 10
#define SPEEDUINO_AFR_BYTE                10  // x 10
#define SPEEDUINO_EGOCORR_BYTE            11  // %
#define SPEEDUINO_IATCORR_BYTE            12  // %
#define SPEEDUINO_WUECORR_BYTE            13  // %
#define SPEEDUINO_RPM_WORD				        14
#define SPEEDUINO_TAECORR_BYTE            16  // %
#define SPEEDUINO_GAMMAE_BYTE             17  // %
#define SPEEDUINO_CURRENTVE_BYTE          18
#define SPEEDUINO_AFRTARGET_BYTE          19  // x 10
#define SPEEDUINO_TPSDOT_BYTE             22  // / 10
#define SPEEDUINO_TPS_BYTE                24  // x 2
#define SPEEDUINO_LOOPSPERSEC_WORD        25
#define SPEEDUINO_FREERAM_WORD            27
#define SPEEDUINO_SPARK_BITFIELD          31
  #define SPEEDUINO_SPARK_HARDLAUNCH_BIT  0
  #define SPEEDUINO_SPARK_SOFTLAUNCH_BIT  1
  #define SPEEDUINO_SPARK_HARDLIMIT_BIT   2
  #define SPEEDUINO_SPARK_SOFTLIMIT_BIT   3
  #define SPEEDUINO_SPARK_BOOSTCUT_BIT    4
  #define SPEEDUINO_SPARK_ERROR_BIT       5
  #define SPEEDUINO_SPARK_IDLECTRL_BIT    6
  #define SPEEDUINO_SPARK_SYNC_BIT        7
#define SPEEDUINO_IDLELOAD_BYTE           37 // %
#define SPEEDUINO_BARO_BYTE               40 // kPa
#define SPEEDUINO_OILPRESSURE_BYTE        104 // kPa
/* ----- Speeduino addresses end  ----- */

#define SERIAL_UPDATE_MS  100

//#define TEST // De-comment to enter test mode

/* ----- Engine status ----- */
#define ENGINE_OFF		0 
#define ENGINE_WARMUP	1
#define ENGINE_RUN		2

#define IDLE_RPM_ENTER  1000
#define IDLE_RPM_EXIT   1100
#define IDLE_DELAY_MS   2000
/* ----- Engine status end ----- */

/* ----- OLED display pages ----- */
#define PAGE_AUTO       0 // Must be the first page
#define PAGE_RPM_MAP    1
#define PAGE_AFRGRAPH   2 // Must be the last page
/* ----- OLED pages end     ----- */
