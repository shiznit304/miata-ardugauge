// Updated on 2023-01-11

#define SPEEDUINO_DATA_LEN 123

#define SPEEDUINO_BYTE_SECL               0   // Simple counter, incremented each second
#define SPEEDUINO_STATUS_BITFIELD         1   // Status Register, see single bits below
  #define SPEEDUINO_STATUS_INJ1_BIT         0
  #define SPEEDUINO_STATUS_INJ2_BIT         1
  #define SPEEDUINO_STATUS_INJ3_BIT         2
  #define SPEEDUINO_STATUS_INJ4_BIT         3
  #define SPEEDUINO_STATUS_DFCO_BIT         4 // Deceleration Fuel Cut Off
  #define SPEEDUINO_STATUS_BOOSTCUT_BIT     5
  #define SPEEDUINO_STATUS_TOOTH1_BIT       6 // Tooth Log 1 Ready
  #define SPEEDUINO_STATUS_TOOTH2_BIT       7 // Tooth Log 2 Ready
#define SPEEDUINO_ENGINE_BITFIELD         2   // Engine Register, see single bits below
  #define SPEEDUINO_ENGINE_RUNNING_BIT      0
  #define SPEEDUINO_ENGINE_CRANKING_BIT     1
  #define SPEEDUINO_ENGINE_ASE_BIT          2 // Afterstart Enrichment
  #define SPEEDUINO_ENGINE_WARMUP_BIT       3 // Warmup Enrichment
  #define SPEEDUINO_ENGINE_TPSAE_BIT        4 // TPS-based Acceleration Enrichment
  #define SPEEDUINO_ENGINE_TPSDE_BIT        5 // TPS-based Deceleration Enleanment
  #define SPEEDUINO_ENGINE_MAPAE_BIT        6 // MAP-based Acceleration Enrichment
  #define SPEEDUINO_ENGINE_MAPDE_BIT        7 // MAP-based Deceleration Enleanment
#define SPEEDUINO_DWELL_BYTE              3   // Dwell (ms, divide by 10)
#define SPEEDUINO_MAP_WORD                4   // MAP (kPa, 2 bytes)
#define SPEEDUINO_IAT_BYTE                6   // Intake Air Temperature (Degrees, subtract 40)
#define SPEEDUINO_CLT_BYTE                7   // Coolant Temperature (Degrees, subtract 40)
#define SPEEDUINO_VOLTAGE_BYTE            9   // Battery Voltage (Volts, divide by 10)
#define SPEEDUINO_AFR_BYTE                10  // Air-Fuel Ratio (divide by 10)
#define SPEEDUINO_EGOCORR_BYTE            11  // EGO Correction (%)
#define SPEEDUINO_IATCORR_BYTE            12  // Air Temperature Correction (%)
#define SPEEDUINO_WUECORR_BYTE            13  // Warmup Enrichment Correction (%)
#define SPEEDUINO_RPM_WORD                14  // RPM (2 bytes)
#define SPEEDUINO_AECORR_BYTE             16  // Acceleration Enrichment Correction (%)
#define SPEEDUINO_GAMMAE_BYTE             17  // Gamma Correction (%)
#define SPEEDUINO_CURRENTVE_BYTE          18  // Current VE
#define SPEEDUINO_AFRTARGET_BYTE          19  // AFR Target (divide by 10)
#define SPEEDUINO_PW1_WORD                20  // PulseWidth 1 (ms, divide by 10)
#define SPEEDUINO_TPSDOT_BYTE             22  // TPSdot (%/s, multiply by 10)
#define SPEEDUINO_ADVANCE                 23  // (Degrees BTDC)
#define SPEEDUINO_TPS_BYTE                24  // Throttle Position (%, divide by 2, 0.5% resolution)
#define SPEEDUINO_LOOPSPERSEC_WORD        25  // (Loops/s, 2 bytes)
#define SPEEDUINO_FREERAM_WORD            27  // (Bytes, 2 bytes)
#define SPEEDUINO_BOOSTTARGET             29  // (kPa, multiply by 2)
#define SPEEDUINO_BOOSTDUTY               30  // Boost PWM duty (%)
#define SPEEDUINO_SPARK_BITFIELD          31  // Spark Register, see single bits below
  #define SPEEDUINO_SPARK_HARDLAUNCH_BIT    0 // Launch Control limiter, hard
  #define SPEEDUINO_SPARK_SOFTLAUNCH_BIT    1 // Launch Control limiter, soft
  #define SPEEDUINO_SPARK_HARDLIMIT_BIT     2 // Rev limiter, hard
  #define SPEEDUINO_SPARK_SOFTLIMIT_BIT     3 // Rev limiter, soft
  #define SPEEDUINO_SPARK_BOOSTCUT_BIT      4 
  #define SPEEDUINO_SPARK_ERROR_BIT         5
  #define SPEEDUINO_SPARK_IDLECTRL_BIT      6
  #define SPEEDUINO_SPARK_SYNC_BIT          7 
#define SPEEDUINO_RPMDOT_WORD             32  // RPMdot (rpm/s, 2 bytes)
#define SPEEDUINO_ETHANOLPCT_BYTE         34  // Ethanol content (%, 0 if not used)
#define SPEEDUINO_FLEXCORR_BYTE           35  // Flex fuel Correction (%)
#define SPEEDUINO_FLEXIGNCORR_BYTE        36  // Flex fuel advance correction (Degrees)
#define SPEEDUINO_IDLELOAD_BYTE           37  // Idle valve load (PWM duty or Steps)
#define SPEEDUINO_TESTOUTPUTS_BITFIELD    38  // Test Outputs Register, see single bits below
  #define SPEEDUINO_TESTOUTPUTS_ENABLED_BIT 0
  #define SPEEDUINO_TESTOUTPUTS_ACTIVE_BIT  1
#define SPEEDUINO_02_2_BYTE               39  // Secondary AFR Sensor (divide by 10)
#define SPEEDUINO_BARO_BYTE               40  // Berometric pressure (kPa)
#define SPEEDUINO_CANIN0_WORD             41  // CAN Input 0 (2 bytes)
#define SPEEDUINO_CANIN1_WORD             43  // CAN Input 1 (2 bytes)
#define SPEEDUINO_CANIN2_WORD             45  // CAN Input 2 (2 bytes)
#define SPEEDUINO_CANIN3_WORD             47  // CAN Input 3 (2 bytes)
#define SPEEDUINO_CANIN4_WORD             49  // CAN Input 4 (2 bytes)
#define SPEEDUINO_CANIN5_WORD             51  // CAN Input 5 (2 bytes)
#define SPEEDUINO_CANIN6_WORD             53  // CAN Input 6 (2 bytes)
#define SPEEDUINO_CANIN7_WORD             55  // CAN Input 7 (2 bytes)
#define SPEEDUINO_CANIN8_WORD             57  // CAN Input 8 (2 bytes)
#define SPEEDUINO_CANIN9_WORD             59  // CAN Input 9 (2 bytes)
#define SPEEDUINO_CANIN10_WORD            61  // CAN Input 10 (2 bytes)
#define SPEEDUINO_CANIN11_WORD            63  // CAN Input 11 (2 bytes)
#define SPEEDUINO_CANIN12_WORD            65  // CAN Input 12 (2 bytes)
#define SPEEDUINO_CANIN13_WORD            67  // CAN Input 13 (2 bytes)
#define SPEEDUINO_CANIN14_WORD            69  // CAN Input 14 (2 bytes)
#define SPEEDUINO_CANIN15_WORD            71  // CAN Input 15 (2 bytes)
#define SPEEDUINO_TPSADC_BYTE             73  // TPS ADC Value (0...255)
#define SPEEDUINO_ERROR_BYTE              74  // Error code (Error Number 0:1, Current Error 2:7)
#define SPEEDUINO_LAUNCHCORR_BYTE         75  // Launch Correction (%)
#define SPEEDUINO_PW2_WORD                76  // PulseWidth 2 (ms, divide by 10)
#define SPEEDUINO_PW3_WORD                78  // PulseWidth 3 (ms, divide by 10)
#define SPEEDUINO_PW4_WORD                80  // PulseWidth 4 (ms, divide by 10)
#define SPEEDUINO_STATUS3_BITFIELD        82  // Status3 Register, see single bits below
  #define SPEEDUINO_STATUS3_RESETLOCKON_BIT 0
  #define SPEEDUINO_STATUS3_NITROUSON_BIT   1
  #define SPEEDUINO_STATUS3_FUEL2ACTIVE_BIT 2 // Secondary VE Table
  #define SPEEDUINO_STATUS3_VSSREFRESH_BIT  3
  #define SPEEDUINO_STATUS3_HALFSYNC_BIT    4
  #define SPEEDUINO_STATUS3_NSQUIRTS_BITS   6 // Bits 6:7
#define SPEEDUINO_ENGINEPROTECT_BITFIELD  83  // Engine Protect Register, see single bits below
  #define SPEEDUINO_ENGINEPROTECT_RPM_BIT   0
  #define SPEEDUINO_ENGINEPROTECT_MAP_BIT   1
  #define SPEEDUINO_ENGINEPROTECT_OIL_BIT   2
  #define SPEEDUINO_ENGINEPROTECT_AFR_BIT   3
#define SPEEDUINO_FUELLOAD_WORD           84  // Fuel Table load (kPa or TPS%, 2 bytes)
#define SPEEDUINO_IGNLOAD_WORD            86  // Spark Table load (kPa or TPS%, 2 bytes)
#define SPEEDUINO_INJANGLE_WORD           88  // Injection angle (2 bytes)
#define SPEEDUINO_IDLELOAD_BYTE           90  // DUPLICATE OF ADDRESS 37 - HOPEFULLY WILL BE FIXED IN THE SPEEDUINO FIRMWARE
#define SPEEDUINO_CLIDLETARGET_BYTE       91  // Closed-Loop Idle Target RPM (multiply by 10)
#define SPEEDUINO_MAPDOT_BYTE             92  // MAPdot (kPa/s, multiply by 10)
#define SPEEDUINO_VVT1ANGLE_BYTE          93  // VVT1 Angle (Degrees, SIGNED)
#define SPEEDUINO_VVT1TARGET_BYTE         94  // VVT1 Target Angle (Degrees)
#define SPEEDUINO_VVT1DUTY_BYTE           95  // VVT1 PWM Duty (%)
#define SPEEDUINO_FLEXBOOSTCORR_WORD      96  // Flex fuel Boost Correction, 2 bytes)
#define SPEEDUINO_BAROCORR_BYTE           98  // Barometric Correction (%)
#define SPEEDUINO_ASECORR_BYTE            99  // After Start Enrichment Correction (%)
#define SPEEDUINO_VSS_WORD                100 // Speed reading via VSS (2 bytes)
#define SPEEDUINO_GEAR_BYTE               102 // Current gear
#define SPEEDUINO_FUELPRESSURE_BYTE       103 // (PSI or Bar)
#define SPEEDUINO_OILPRESSURE_BYTE        104 // (PSI or Bar)
#define SPEEDUINO_WMIPW_BYTE              105 // Water-Meth Injection Pulsewidth
#define SPEEDUINO_STATUS4_BITFIELD        106 // Status4 Register, see single bits below
  #define SPEEDUINO_STATUS4_WMIEMPTY_BIT    0 // Water-Meth Tank empty
  #define SPEEDUINO_STATUS4_VVT1ERROR_BIT   1
  #define SPEEDUINO_STATUS4_VVT2ERROR_BIT   2
  #define SPEEDUINO_STATUS4_FAN_BIT         3 // Cooling fan
#define SPEEDUINO_VVT2ANGLE_BYTE          107 // VVT2 Angle (Degree, SIGNED)
#define SPEEDUINO_VVT2TARGET_BYTE         108 // VVT2 Target Angle (Degrees)
#define SPEEDUINO_VVT2DUTY_BYTE           109 // VVT2 PWM Duty (%)
#define SPEEDUINO_OUTPUTSSTATUS_BYTE      110 // Programmable Outputs
#define SPEEDUINO_FUELTEMP_BYTE           111 // Fuel Temperature from Flex Sensor (Degrees, subtract 40)
#define SPEEDUINO_FUELTEMPCORR_BYTE       112 // Fuel Temperature Correction (%)
#define SPEEDUINO_VE1_BYTE                113 // VE from Primary Fuel Table
#define SPEEDUINO_VE2_BYTE                114 // VE from Secondary Fuel Table
#define SPEEDUINO_ADVANCE1_BYTE           115 // Advance from Primary Spark Table (Degrees BTDC)
#define SPEEDUINO_ADVANCE2_BYTE           116 // Advance from Secondary Spark Table (Degrees BTDC)
#define SPEEDUINO_NITROUSSTATUS_BYTE      117 // N2O status, see values below
  #define SPEEDUINO_NITROUSSTATUS_OFF       0
  #define SPEEDUINO_NITROUSSTATUS_STAGE1    1
  #define SPEEDUINO_NITROUSSTATUS_STAGE2    2
  #define SPEEDUINO_NITROUSSTATUS_BOTH      3
#define SPEEDUINO_SDCCARD_BITFIELD        118 // SD Card Register, see single bits below
  #define SPEEDUINO_SDCARD_PRESENT_BIT      0 // SD Card is inserted
  #define SPEEDUINO_SDCARD_TYPE_BIT         1 // SD Card type (0=SD, 1=SDHC)
  #define SPEEDUINO_SDCARD_READY_BIT        2
  #define SPEEDUINO_SDCARD_LOGGING_BIT      3
  #define SPEEDUINO_SDCARD_ERROR            4
  #define SPEEDUINO_SDCARD_VERSION_BIT      5 // SD Card version (0=1.x, 1=2.x)
  #define SPEEDUINO_SDCARD_FS_BIT           6 // SD Card filesystem (0=no FAT16, 1=FAT32)
  #define SPEEDUINO_SDCARD_UNUSED           7
#define SPEEDUINO_EMAP_WORD               119 // EMAP (kPa, 2 bytes)
#define SPEEDUINO_FANDUTY_BYTE            121 // Cooling Fan PWM duty (%)
#define SPEEDUINO_AIRCON_BITFIELD         122 // Air Conditioning register, see single bits below
  #define SPEEDUINO_AIRCON_REQUEST_BIT      0
  #define SPEEDUINO_AIRCON_COMPRESSOR_BIT   1
  #define SPEEDUINO_AIRCON_RPMLOCKOUT_BIT   2
  #define SPEEDUINO_AIRCON_TPSLOCKOUT_BIT   3
  #define SPEEDUINO_AIRCON_TURNINGON_BIT    4
  #define SPEEDUINO_AIRCON_CLTLOCKOUT_BIT   5
  #define SPEEDUINO_AIRCON_FAN_BIT          6
