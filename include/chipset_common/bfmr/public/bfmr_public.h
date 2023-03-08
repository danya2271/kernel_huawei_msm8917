/**
    @copyright: Huawei Technologies Co., Ltd. 2016-xxxx. All rights reserved.

    @file: bfmr_public.h

    @brief: define the basic public enum/macros/interface for BFMR (Boot Fail Monitor and Recovery)

    @version: 2.0

    @author: QiDechun ID: 216641

    @date: 2016-08-17

    @history:
*/

#ifndef BFMR_PUBLIC_H
#define BFMR_PUBLIC_H


/*----includes-----------------------------------------------------------------------*/


/*----c++ support-------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*----export prototypes---------------------------------------------------------------*/

typedef enum bfmr_platform_name
{
    COMMON_PLATFORM = 0,
    HISI_PLATFORM,
    QUALCOMM_PLATFORM,
} bfmr_platform_name_e;

typedef enum bfmr_boot_stage
{
    PBL_STAGE = 0,
    BL1_STAGE,        /* BL1 -- bootloader stage 1, it's xloader for hisi, sbl1 for qualcomm*/
    BL2_STAGE,        /* BL2 -- bootloader stage 2, it's fastboot for hisi, lk for qualcomm*/
    KERNEL_STAGE,
    NATIVE_STAGE,
    ANDROID_FRAMEWORK_STAGE,
} bfmr_boot_stage_e;

/*
* coding of boot fail error during entire boot process
*/
typedef enum BFM_ERRNO_CODE
{
    /* BL1 -- bootloader stage 1, it's xloader for hisi, sbl1 for qualcomm*/
    BL1_ERRNO_START = (BL1_STAGE <<24)|(COMMON_PLATFORM<<16),
    BL1_DDR_INIT_FAIL,
    BL1_EMMC_INIT_FAIL,
    BL1_BL2_LOAD_FAIL,
    BL1_BL2_VERIFY_FAIL,
    BL1_WDT,

    /* PL1 -- Platform 1 -- it's only for hisi */
    BL1_PL1_START = (BL1_STAGE <<24)|(HISI_PLATFORM<<16),
    BL1_VRL_LOAD_FAIL,
    BL1_VRL_VERIFY_FAIL,

    /* PL2 -- Platform 2 -- it's only for qualcomm */
    BL1_PL2_START = (BL1_STAGE <<24)|(QUALCOMM_PLATFORM<<16),
    BL1_ERROR_GROUP_BOOT,
    BL1_ERROR_GROUP_BUSES,
    BL1_ERROR_GROUP_BAM,
    BL1_ERROR_GROUP_BUSYWAIT,
    BL1_ERROR_GROUP_CLK,
    BL1_ERROR_GROUP_CRYPTO,
    BL1_ERROR_GROUP_DAL,
    BL1_ERROR_GROUP_DEVPROG,
    BL1_ERROR_GROUP_DEVPROG_DDR,
    BL1_ERROR_GROUP_EFS,
    BL1_ERROR_GROUP_EFS_LITE,
    /*BL1_ERROR_GROUP_FLASH; --- move to common errno*/
    BL1_ERROR_GROUP_HOTPLUG,
    BL1_ERROR_GROUP_HSUSB,
    BL1_ERROR_GROUP_ICB,
    BL1_ERROR_GROUP_LIMITS,
    BL1_ERROR_GROUP_MHI,
    BL1_ERROR_GROUP_PCIE,
    BL1_ERROR_GROUP_PLATFOM,
    BL1_ERROR_GROUP_PMIC,
    BL1_ERROR_GROUP_POWER,
    BL1_ERROR_GROUP_PRNG,
    BL1_ERROR_GROUP_QUSB,
    BL1_ERROR_GROUP_SECIMG,
    BL1_ERROR_GROUP_SECBOOT,
    BL1_ERROR_GROUP_SECCFG,
    BL1_ERROR_GROUP_SMEM,
    BL1_ERROR_GROUP_SPMI,
    BL1_ERROR_GROUP_SUBSYS,
    BL1_ERROR_GROUP_TLMM,
    BL1_ERROR_GROUP_TSENS,
    BL1_ERROR_GROUP_HWENGINES,
    BL1_ERROR_GROUP_IMAGE_VERSION,
    BL1_ERROR_GROUP_SECURITY,
    BL1_ERROR_GROUP_STORAGE,
    BL1_ERROR_GROUP_SYSTEMDRIVERS,
    /*1_ERROR_GROUP_DDR, --- move to common errno*/
    BL1_ERROR_GROUP_EXCEPTIONS,
    BL1_ERROR_GROUP_MPROC,

    /* BL2 -- bootloader stage 2, it's fastboot for hisi, lk for qualcomm*/
    BL2_ERRNO_START = (BL2_STAGE <<24)|(COMMON_PLATFORM<<16),
    BL2_EMMC_INIT_FAIL,
    BL2_PANIC,
    BL2_WDT,

    /* PL1 -- Platform 1 -- it's only for hisi */
    BL2_PL1_START = (BL2_STAGE <<24)|(HISI_PLATFORM<<16),
    BL2_PL1_OCV_ERROR,
    BL2_PL1_BAT_TEMP_ERROR,
    BL2_PL1_MISC_ERROR,
    BL2_PL1_DTIMG_ERROR,
    BL2_PL1_LOAD_OTHER_IMGS_ERRNO,
    BL2_PL1_KERNEL_IMG_ERROR,
    BL2_BR_POWERON_BY_SMPL,
    BL2_FASTBOOT_S_LOADLPMCU_FAIL,
    BL2_FASTBOOT_S_IMG_VERIFY_FAIL,
    BL2_FASTBOOT_S_SOC_TEMP_ERR,

    /* PL2 -- Platform 2 -- it's only for qualcomm */
    BL2_PL2_START = (BL2_STAGE <<24)|(QUALCOMM_PLATFORM<<16),
    BL2_MMC_INIT_FAILED,
    BL2_QSEECOM_START_ERROR,
    BL2_RPMB_INIT_FAILED,
    BL2_LOAD_SECAPP_FAILED,
    BL2_ABOOT_DLKEY_DETECTED,
    BL2_ABOOT_NORMAL_BOOT_FAIL,

    /* kernel stage's bootFail errors */
    KERNEL_ERRNO_START = (KERNEL_STAGE <<24)|(COMMON_PLATFORM<<16),
    KERNEL_AP_PANIC,
    KERNEL_EMMC_INIT_FAIL,
    KERNEL_AP_WDT,
    KERNEL_PRESS10S,
    KERNEL_BOOT_TIMEOUT,
    KERNEL_AP_COMBINATIONKEY,

    KERNEL_PL1_START = (KERNEL_STAGE <<24)|(HISI_PLATFORM<<16),
    KERNEL_AP_S_ABNORMAL,
    KERNEL_AP_S_TSENSOR0,
    KERNEL_AP_S_TSENSOR1,
    KERNEL_LPM3_S_GLOBALWDT,
    KERNEL_G3D_S_G3DTSENSOR,
    KERNEL_LPM3_S_LPMCURST,
    KERNEL_CP_S_CPTSENSOR,
    KERNEL_IOM3_S_IOMCURST,
    KERNEL_ASP_S_ASPWD,
    KERNEL_CP_S_CPWD,
    KERNEL_IVP_S_IVPWD,
    KERNEL_ISP_S_ISPWD,
    KERNEL_AP_S_DDR_UCE_WD,
    KERNEL_AP_S_DDR_FATAL_INTER,
    KERNEL_AP_S_DDR_SEC,
    KERNEL_AP_S_MAILBOX,
    KERNEL_CP_S_MODEMDMSS,
    KERNEL_CP_S_MODEMNOC,
    KERNEL_CP_S_MODEMAP,
    KERNEL_CP_S_EXCEPTION,
    KERNEL_CP_S_RESETFAIL,
    KERNEL_CP_S_NORMALRESET,
    KERNEL_CP_S_ABNORMAL,
    KERNEL_LPM3_S_EXCEPTION,
    KERNEL_HIFI_S_EXCEPTION,
    KERNEL_HIFI_S_RESETFAIL,
    KERNEL_ISP_S_EXCEPTION,
    KERNEL_IVP_S_EXCEPTION,
    KERNEL_IOM3_S_EXCEPTION,
    KERNEL_TEE_S_EXCEPTION,
    KERNEL_MMC_S_EXCEPTION,
    KERNEL_CODECHIFI_S_EXCEPTION,
    KERNEL_CP_S_RILD_EXCEPTION,
    KERNEL_CP_S_3RD_EXCEPTION,
    KERNEL_IOM3_S_USER_EXCEPTION,
    KERNEL_OCBC_S_WD,
    KERNEL_AP_S_NOC,
    KERNEL_AP_S_RESUME_SLOWY,
    KERNEL_AP_S_F2FS,
    KERNLE_AP_S_BL31_PANIC,
    KERNLE_HISEE_S_EXCEPTION,
    KERNEL_AP_S_PMU,
    KERNEL_AP_S_SMPL,
    KERNLE_AP_S_SCHARGER,

    KERNEL_PL2_START = (KERNEL_STAGE <<24)|(QUALCOMM_PLATFORM<<16),
    KERNEL_MODEM_PANIC,
    KERNEL_VENUS_PANIC,
    KERNEL_WCNSS_PANIC,
    KERNEL_SENSOR_PANIC,

    /* natvie stage's bootFail errors */
    NATIVE_ERRNO_START = (NATIVE_STAGE <<24)|(COMMON_PLATFORM<<16),
    SYSTEM_MOUNT_FAIL,
    SECURITY_FAIL,
    CRITICAL_SERVICE_FAIL_TO_START,
    DATA_MOUNT_FAILED_AND_ERASED,
    DATA_MOUNT_RO, /* added by qidechun */
    DATA_NOSPC, /* added by qidechun, NOSPC means data partition is full */
    VENDOR_MOUNT_FAIL,
    NATIVE_PANIC,

    /* android frameworkl stage's bootFail errors */
    ANDROID_FRAMEWORK_ERRNO_START = (ANDROID_FRAMEWORK_STAGE <<24)|(COMMON_PLATFORM<<16),
    SYSTEM_SERVICE_LOAD_FAIL,
    PREBOOT_BROADCAST_FAIL,
    VM_OAT_FILE_DAMAGED,
    PACKAGE_MANAGER_SETTING_FILE_DAMAGED,

    BOOTUP_SLOWLY = 0x7ffffffd,
    POWEROFF_ABNORMAL = 0x7ffffffe,
    BFM_ERRNO_MAX_COUNT,
} bfmr_bootfail_errno_e;

/*
* coding of boot stage during entire boot process
*/
typedef enum BFM_BOOT_STAGE_CODE
{
    /* BL1 -- bootloader stage 1, it's xloader for hisi, sbl1 for qualcomm*/
    BL1_STAGE_START = ((BL1_STAGE <<24)|(COMMON_PLATFORM<<16)) + 0x1,
    BL1_STAGE_DDR_INIT_START,
    BL1_STAGE_EMMC_INIT_START,
    BL1_STAGE_BL2_LOAD_START,
    BL1_STAGE_END,

    BL1_PL1_STAGE_START = (BL1_STAGE <<24)|(HISI_PLATFORM<<16),
    BL1_PL1_STAGE_DDR_INIT_FAIL,
    BL1_PL1_STAGE_DDR_INIT_OK,
    BL1_PL1_STAGE_EMMC_INIT_FAIL,
    BL1_PL1_STAGE_EMMC_INIT_OK,

    BL1_PL1_STAGE_RD_VRL_FAIL,
    BL1_PL1_STAGE_CHECK_VRL_ERROR,
    BL1_PL1_STAGE_IMG_TOO_LARGE,
    BL1_PL1_STAGE_READ_FASTBOOT_FAIL,
    BL1_PL1_STAGE_LOAD_HIBENCH_FAIL,
    BL1_PL1_STAGE_SEC_VERIFY_FAIL,
    BL1_PL1_STAGE_GET_FASTBOOTSIZE_FAIL,
    BL1_PL1_STAGE_FASTBOOTSIZE_ERROR,
    BL1_PL1_STAGE_VRL_CHECK_ERROR,
    BL1_PL1_SECURE_VERIFY_ERROR,

    BL1_PL2_STAGE_START = (BL1_STAGE <<24)|(QUALCOMM_PLATFORM<<16),
    BL1_PL2_STAGE_AUTH_QSEE,
    BL1_PL2_STAGE_AUTH_DEVCFG,
    BL1_PL2_STAGE_AUTH_DBG_POLICY,
    BL1_PL2_STAGE_AUTH_RPM_FW,
    BL1_PL2_STAGE_AUTH_APP_SBL,

    /* BL2 -- bootloader stage 2, it's fastboot for hisi, lk for qualcomm*/
    BL2_STAGE_START = ((BL2_STAGE <<24)|(COMMON_PLATFORM<<16)),
    BL2_STAGE_EMMC_INIT_START,
    BL2_STAGE_EMMC_INIT_FAIL,
    BL2_STAGE_EMMC_INIT_OK,
    BL2_STAGE_END,

    BL2_PL1_STAGE_START = (BL2_STAGE <<24)|(HISI_PLATFORM<<16),
    BL2_PL1_STAGE_DDR_INIT_START,
    BL2_PL1_STAGE_DISPLAY_INIT_START,
    BL2_PL1_STAGE_PRE_BOOT_INIT_START,
    BL2_PL1_STAGE_LD_OTHER_IMGS_START,
    BL2_PL1_STAGE_LD_KERNEL_IMG_START,
    BL2_PL1_STAGE_BOOT_KERNEL_START,

    BL2_PL2_STAGE_START = (BL2_STAGE <<24)|(QUALCOMM_PLATFORM<<16),
    BL2_PL2_STAGE_PLATFORM_INIT,
    BL2_PL2_STAGE_TARGET_INIT,
    BL2_PL2_STAGE_APPS_START,
    BL2_PL2_STAGE_APPS_ABOOT_START,
    BL2_PL2_STAGE_APPS_ABOOT_CHECK_BOOT,
    BL2_PL2_STAGE_APPS_ABOOT_CHECK_DDRSCREEN,
    BL2_PL2_STAGE_APPS_ABOOT_FASTBOOT,

    /* kernel stage */
    KERNEL_STAGE_START = (KERNEL_STAGE <<24)|(COMMON_PLATFORM<<16),
    KERNEL_EARLY_INITCALL,
    KERNEL_PURE_INITCALL,
    KERNEL_CORE_INITCALL_SYNC,
    KERNEL_POSTCORE_INITCALL,
    KERNEL_POSTCORE_INITCALL_SYNC,
    KERNEL_ARCH_INITCALL,
    KERNEL_ARCH_INITCALLC,
    KERNEL_SUBSYS_INITCALL,
    KERNEL_SUBSYS_INITCALL_SYNC,
    KERNEL_FS_INITCALL,
    KERNEL_FS_INITCALL_SYNC,
    KERNEL_ROOTFS_INITCALL,
    KERNEL_DEVICE_INITCALL,
    KERNEL_DEVICE_INITCALL_SYNC,
    KERNEL_LATE_INITCALL,
    KERNEL_LATE_INITCALL_SYNC,
    KERNEL_CONSOLE_INITCALL,
    KERNEL_SECURITY_INITCALL,
    KERNEL_BOOTANIM_COMPLETE,

    /* native stage */
    NATIVE_STAGE_START = (NATIVE_STAGE <<24)|(COMMON_PLATFORM<<16),
    STAGE_INIT_START,
    STAGE_ON_EARLY_INIT,
    STAGE_ON_INIT,
    STAGE_ON_EARLY_FS,
    STAGE_ON_FS,
    STAGE_ON_POST_FS,
    STAGE_ON_POST_FS_DATA,
    STAGE_ON_EARLY_BOOT,
    STAGE_ON_BOOT,

    /* android framework start stage */
    ANDROID_FRAMEWORK_STAGE_START = (ANDROID_FRAMEWORK_STAGE <<24)|(COMMON_PLATFORM<<16),
    STAGE_ZYGOTE_START,
    STAGE_VM_START,
    STAGE_PHASE_WAIT_FOR_DEFAULT_DISPLAY,
    STAGE_PHASE_LOCK_SETTINGS_READY,
    STAGE_PHASE_SYSTEM_SERVICES_READY,
    STAGE_PHASE_ACTIVITY_MANAGER_READY,
    STAGE_PHASE_THIRD_PARTY_APPS_CAN_START,

    STAGE_BOOT_SUCCESS = 0x7FFFFFFF,
} bfmr_detail_boot_stage_e;


/*----export macroes-----------------------------------------------------------------*/

#define bfmr_is_bl1_errno(x) (((x) & (0xFF <<24)) ==  (BL1_STAGE <<24))
#define bfmr_is_bl2_errno(x) (((x) & (0xFF <<24)) ==  (BL2_STAGE <<24))
#define bfmr_is_kernel_errno(x) (((x) & (0xFF <<24)) ==  (KERNEL_STAGE <<24))
#define bfmr_is_native_errno(x) (((x) & (0xFF <<24)) ==  (NATIVE_STAGE <<24))
#define bfmr_is_android_framework_errno(x) (((x) & (0xFF <<24)) ==  (ANDROID_FRAMEWORK_STAGE <<24))

#define bfmr_is_boot_success(x) ((x) == STAGE_BOOT_SUCCESS)
#define bfmr_is_bl1_stage(x) ((((x) & (0xFF <<24)) ==  (BL1_STAGE <<24)) && ! bfmr_is_boot_success(x))
#define bfmr_is_bl2_stage(x) (((x) & (0xFF <<24)) ==  (BL2_STAGE <<24))
#define bfmr_is_kernel_stage(x) (((x) & (0xFF <<24)) ==  (KERNEL_STAGE <<24))
#define bfmr_is_native_stage(x) (((x) & (0xFF <<24)) ==  (NATIVE_STAGE <<24))
#define bfmr_is_android_framework_stage(x) (((x) & (0xFF <<24)) ==  (ANDROID_FRAMEWORK_STAGE <<24))

#define bfmr_get_boot_stage_from_bootfail_errno(x) ((((unsigned int)(x)) >> 24) & (0xFF))

#define BFMR_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define BFMR_MIN(a, b) (((a) < (b)) ? (a) : (b))


/*----global variables----------------------------------------------------------------*/


/*----export function prototypes-------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif

