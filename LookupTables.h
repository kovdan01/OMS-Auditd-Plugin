/*
    microsoft-oms-auditd-plugin

    Copyright (c) Microsoft Corporation

    All rights reserved.

    MIT License

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the ""Software""), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef AUOMS_LOOKUPTABLES_H
#define AUOMS_LOOKUPTABLES_H

#include <string>
#include <vector>
#include <unordered_map>

// Names and values obtained from /usr/include/libaudit.h and /usr/include/linux/audit.h
enum class RecordType: int {
    UNKNOWN                   = -1,
    GET                       = 1000,
    SET                       = 1001,
    LIST                      = 1002,
    ADD                       = 1003,
    DEL                       = 1004,
    USER                      = 1005,
    LOGIN                     = 1006,
    WATCH_INS                 = 1007,
    WATCH_REM                 = 1008,
    WATCH_LIST                = 1009,
    SIGNAL_INFO               = 1010,
    ADD_RULE                  = 1011,
    DEL_RULE                  = 1012,
    LIST_RULES                = 1013,
    TRIM                      = 1014,
    MAKE_EQUIV                = 1015,
    TTY_GET                   = 1016,
    TTY_SET                   = 1017,
    SET_FEATURE               = 1018,
    GET_FEATURE               = 1019,
    FIRST_USER_MSG            = 1100,
    LAST_USER_MSG             = 1199,
    USER_AUTH                 = 1100,
    USER_ACCT                 = 1101,
    USER_MGMT                 = 1102,
    CRED_ACQ                  = 1103,
    CRED_DISP                 = 1104,
    USER_START                = 1105,
    USER_END                  = 1106,
    USER_AVC                  = 1107,
    USER_CHAUTHTOK            = 1108,
    USER_ERR                  = 1109,
    CRED_REFR                 = 1110,
    USYS_CONFIG               = 1111,
    USER_LOGIN                = 1112,
    USER_LOGOUT               = 1113,
    ADD_USER                  = 1114,
    DEL_USER                  = 1115,
    ADD_GROUP                 = 1116,
    DEL_GROUP                 = 1117,
    DAC_CHECK                 = 1118,
    CHGRP_ID                  = 1119,
    TEST                      = 1120,
    TRUSTED_APP               = 1121,
    USER_SELINUX_ERR          = 1122,
    USER_CMD                  = 1123,
    USER_TTY                  = 1124,
    CHUSER_ID                 = 1125,
    GRP_AUTH                  = 1126,
    SYSTEM_BOOT               = 1127,
    SYSTEM_SHUTDOWN           = 1128,
    SYSTEM_RUNLEVEL           = 1129,
    SERVICE_START             = 1130,
    SERVICE_STOP              = 1131,
    GRP_MGMT                  = 1132,
    GRP_CHAUTHTOK             = 1133,
    MAC_CHECK                 = 1134,
    ACCT_LOCK                 = 1135,
    ACCT_UNLOCK               = 1136,
    FIRST_DAEMON              = 1200,
    LAST_DAEMON               = 1299,
    DAEMON_START              = 1200,
    DAEMON_END                = 1201,
    DAEMON_ABORT              = 1202,
    DAEMON_CONFIG             = 1203,
    DAEMON_RECONFIG           = 1204,
    DAEMON_ROTATE             = 1205,
    DAEMON_RESUME             = 1206,
    DAEMON_ACCEPT             = 1207,
    DAEMON_CLOSE              = 1208,
    DAEMON_ERR                = 1209,
    FIRST_EVENT               = 1300,
    LAST_EVENT                = 1399,
    SYSCALL                   = 1300,
    PATH                      = 1302,
    IPC                       = 1303,
    SOCKETCALL                = 1304,
    CONFIG_CHANGE             = 1305,
    SOCKADDR                  = 1306,
    CWD                       = 1307,
    EXECVE                    = 1309,
    IPC_SET_PERM              = 1311,
    MQ_OPEN                   = 1312,
    MQ_SENDRECV               = 1313,
    MQ_NOTIFY                 = 1314,
    MQ_GETSETATTR             = 1315,
    KERNEL_OTHER              = 1316,
    FD_PAIR                   = 1317,
    OBJ_PID                   = 1318,
    TTY                       = 1319,
    EOE                       = 1320,
    BPRM_FCAPS                = 1321,
    CAPSET                    = 1322,
    MMAP                      = 1323,
    NETFILTER_PKT             = 1324,
    NETFILTER_CFG             = 1325,
    SECCOMP                   = 1326,
    PROCTITLE                 = 1327,
    FEATURE_CHANGE            = 1328,
    REPLACE                   = 1329,
    KERN_MODULE               = 1330,
    FANOTIFY                  = 1331,
    FIRST_SELINUX             = 1400,
    LAST_SELINUX              = 1499,
    AVC                       = 1400,
    SELINUX_ERR               = 1401,
    AVC_PATH                  = 1402,
    MAC_POLICY_LOAD           = 1403,
    MAC_STATUS                = 1404,
    MAC_CONFIG_CHANGE         = 1405,
    MAC_UNLBL_ALLOW           = 1406,
    MAC_CIPSOV4_ADD           = 1407,
    MAC_CIPSOV4_DEL           = 1408,
    MAC_MAP_ADD               = 1409,
    MAC_MAP_DEL               = 1410,
    MAC_IPSEC_ADDSA           = 1411,
    MAC_IPSEC_DELSA           = 1412,
    MAC_IPSEC_ADDSPD          = 1413,
    MAC_IPSEC_DELSPD          = 1414,
    MAC_IPSEC_EVENT           = 1415,
    MAC_UNLBL_STCADD          = 1416,
    MAC_UNLBL_STCDEL          = 1417,
    MAC_CALIPSO_ADD           = 1418,
    MAC_CALIPSO_DEL           = 1419,
    FIRST_APPARMOR            = 1500,
    LAST_APPARMOR             = 1599,
    AA                        = 1500,
    APPARMOR_AUDIT            = 1501,
    APPARMOR_ALLOWED          = 1502,
    APPARMOR_DENIED           = 1503,
    APPARMOR_HINT             = 1504,
    APPARMOR_STATUS           = 1505,
    APPARMOR_ERROR            = 1506,
    FIRST_KERN_CRYPTO_MSG     = 1600,
    LAST_KERN_CRYPTO_MSG      = 1699,
    FIRST_KERN_ANOM_MSG       = 1700,
    LAST_KERN_ANOM_MSG        = 1799,
    ANOM_PROMISCUOUS          = 1700,
    ANOM_LINK                 = 1702,
    INTEGRITY_FIRST_MSG       = 1800,
    INTEGRITY_LAST_MSG        = 1899,
    INTEGRITY_DATA            = 1800,
    INTEGRITY_METADATA        = 1801,
    INTEGRITY_STATUS          = 1802,
    INTEGRITY_HASH            = 1803,
    INTEGRITY_PCR             = 1804,
    INTEGRITY_RULE            = 1805,
    KERNEL                    = 2000,
    FIRST_ANOM_MSG            = 2100,
    LAST_ANOM_MSG             = 2199,
    ANOM_LOGIN_FAILURES       = 2100,
    ANOM_LOGIN_TIME           = 2101,
    ANOM_LOGIN_SESSIONS       = 2102,
    ANOM_LOGIN_ACCT           = 2103,
    ANOM_LOGIN_LOCATION       = 2104,
    ANOM_MAX_DAC              = 2105,
    ANOM_MAX_MAC              = 2106,
    ANOM_AMTU_FAIL            = 2107,
    ANOM_RBAC_FAIL            = 2108,
    ANOM_RBAC_INTEGRITY_FAIL  = 2109,
    ANOM_CRYPTO_FAIL          = 2110,
    ANOM_ACCESS_FS            = 2111,
    ANOM_EXEC                 = 2112,
    ANOM_MK_EXEC              = 2113,
    ANOM_ADD_ACCT             = 2114,
    ANOM_DEL_ACCT             = 2115,
    ANOM_MOD_ACCT             = 2116,
    ANOM_ROOT_TRANS           = 2117,
    FIRST_ANOM_RESP           = 2200,
    LAST_ANOM_RESP            = 2299,
    RESP_ANOMALY              = 2200,
    RESP_ALERT                = 2201,
    RESP_KILL_PROC            = 2202,
    RESP_TERM_ACCESS          = 2203,
    RESP_ACCT_REMOTE          = 2204,
    RESP_ACCT_LOCK_TIMED      = 2205,
    RESP_ACCT_UNLOCK_TIMED    = 2206,
    RESP_ACCT_LOCK            = 2207,
    RESP_TERM_LOCK            = 2208,
    RESP_SEBOOL               = 2209,
    RESP_EXEC                 = 2210,
    RESP_SINGLE               = 2211,
    RESP_HALT                 = 2212,
    FIRST_USER_LSPP_MSG       = 2300,
    LAST_USER_LSPP_MSG        = 2399,
    USER_ROLE_CHANGE          = 2300,
    ROLE_ASSIGN               = 2301,
    ROLE_REMOVE               = 2302,
    LABEL_OVERRIDE            = 2303,
    LABEL_LEVEL_CHANGE        = 2304,
    USER_LABELED_EXPORT       = 2305,
    USER_UNLABELED_EXPORT     = 2306,
    DEV_ALLOC                 = 2307,
    DEV_DEALLOC               = 2308,
    FS_RELABEL                = 2309,
    USER_MAC_POLICY_LOAD      = 2310,
    ROLE_MODIFY               = 2311,
    USER_MAC_CONFIG_CHANGE    = 2312,
    FIRST_CRYPTO_MSG          = 2400,
    CRYPTO_TEST_USER          = 2400,
    CRYPTO_PARAM_CHANGE_USER  = 2401,
    CRYPTO_LOGIN              = 2402,
    CRYPTO_LOGOUT             = 2403,
    CRYPTO_KEY_USER           = 2404,
    CRYPTO_FAILURE_USER       = 2405,
    CRYPTO_REPLAY_USER        = 2406,
    CRYPTO_SESSION            = 2407,
    CRYPTO_IKE_SA             = 2408,
    CRYPTO_IPSEC_SA           = 2409,
    LAST_CRYPTO_MSG           = 2499,
    FIRST_VIRT_MSG            = 2500,
    VIRT_CONTROL              = 2500,
    VIRT_RESOURCE             = 2501,
    VIRT_MACHINE_ID           = 2502,
    VIRT_INTEGRITY_CHECK      = 2503,
    VIRT_CREATE               = 2504,
    VIRT_DESTROY              = 2505,
    VIRT_MIGRATE_IN           = 2506,
    VIRT_MIGRATE_OUT          = 2507,
    LAST_VIRT_MSG             = 2599,
    FIRST_USER_MSG2           = 2100,
    LAST_USER_MSG2            = 2999,
    MAX_MSG_ID                = 2999,

    FIRST_AUOMS_MSG           = 10000,
    LAST_AUOMS_MSG            = 19999,
    AUOMS_PROCESS_INVENTORY   = 10000,
    AUOMS_DROPPED_RECORDS     = 10001,
    AUOMS_SYSCALL_METRICS     = 10002,
    AUOMS_FRAGMENT            = 11309,
    AUOMS_SYSCALL             = 14688,
    AUOMS_CONNECT             = 10042,
};

// This enum mirrors the auparse_type_t found in auparse-defs.h
// The values here must appear in the same order as their counterpart in the definition of auparse_type_t
enum class field_type_t: int {
    UNKNOWN = -1,
    UNCLASSIFIED = 0,
    UID,
    GID,
    SYSCALL,
    ARCH,
    EXIT,
    ESCAPED,
    PERM,
    MODE,
    SOCKADDR,
    FLAGS,
    PROMISC,
    CAPABILITY,
    SUCCESS,
    A0,
    A1,
    A2,
    A3,
    SIGNAL,
    LIST,
    TTY_DATA,
    SESSION,
    CAP_BITMAP,
    NFPROTO,
    ICMPTYPE,
    PROTOCOL,
    ADDR,
    PERSONALITY,
    SECCOMP,
    OFLAG,
    MMAP,
    MODE_SHORT,
    MAC_LABEL,
    PROCTITLE,
    HOOK,
    NETACTION,
    MACPROTO,
    IOCTL_REQ,
    ESCAPED_KEY
};

enum class MachineType: int {
    UNKNOWN = -1,
    X86 = 0,
    X86_64 = 1
};

/*
 * These numbers are obtained from /usr/include/linux/elf-em.h and /usr/include/linux/audit.h
 */
enum class ArchType: uint32_t {
    UNKNOWN = 0,
    I386 = 3 | 0x40000000,
    X86_64 = 62 | 0x40000000| 0x80000000,
};

class LookupTables {
public:
    static void Initialize();

    static inline std::string RecordTypeCodeToString(RecordType code) {
        try {
            return s_record_type_code_to_name.at(static_cast<size_t>(code));
        } catch (std::out_of_range&) {
            return "UNKNOWN[" + std::to_string(static_cast<int>(code)) + "]";
        }
    }

    static inline RecordType RecordTypeNameToCode(const std::string& name) {
        auto i = s_record_type_name_to_code.find(name);
        if (i != s_record_type_name_to_code.end()) {
            return i->second;
        }
        return RecordType::UNKNOWN;
    }

    static inline field_type_t FieldNameToType(const std::string& name) {
        auto i = s_field_name_to_type.find(name);
        if (i != s_field_name_to_type.end()) {
            return i->second;
        }
        return field_type_t::UNCLASSIFIED;
    }

    static field_type_t FieldNameToType(RecordType rtype, const std::string_view& name, const std::string_view& val);

    static MachineType ArchToMachine(const std::string_view& arch);
    static std::string SyscallToName(MachineType mtype, int syscall, int a0);

    static std::string MachineToName(MachineType mt);

private:
    static std::unordered_map<std::string, RecordType> s_record_type_name_to_code;
    static std::vector<std::string> s_record_type_code_to_name;
    static std::unordered_map<std::string, field_type_t> s_field_name_to_type;
    static std::unordered_map<ArchType, MachineType> s_arch_to_machine;
    static std::unordered_map<std::string, ArchType> s_arch_name_to_type;
    static std::vector<std::string> s_machine_to_name;
    static std::vector<std::vector<std::string>> s_syscall_lookup;
};

#endif //AUOMS_LOOKUPTABLES_H
