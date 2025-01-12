#pragma once

typedef enum UDSEvent {
    // Common Event ----------------- Argument Type
    UDS_EVT_Err, // UDSErr_t *

    // Server Event ----------------- Argument Type
    UDS_EVT_DiagSessCtrl,         // UDSDiagSessCtrlArgs_t *
    UDS_EVT_EcuReset,             // UDSECUResetArgs_t *
    UDS_EVT_ReadDataByIdent,      // UDSRDBIArgs_t *
    UDS_EVT_ReadMemByAddr,        // UDSReadMemByAddrArgs_t *
    UDS_EVT_CommCtrl,             // UDSCommCtrlArgs_t *
    UDS_EVT_SecAccessRequestSeed, // UDSSecAccessRequestSeedArgs_t *
    UDS_EVT_SecAccessValidateKey, // UDSSecAccessValidateKeyArgs_t *
    UDS_EVT_WriteDataByIdent,     // UDSWDBIArgs_t *
    UDS_EVT_RoutineCtrl,          // UDSRoutineCtrlArgs_t*
    UDS_EVT_RequestDownload,      // UDSRequestDownloadArgs_t*
    UDS_EVT_RequestUpload,        // UDSRequestUploadArgs_t *
    UDS_EVT_TransferData,         // UDSTransferDataArgs_t *
    UDS_EVT_RequestTransferExit,  // UDSRequestTransferExitArgs_t *
    UDS_EVT_SessionTimeout,       // NULL
    UDS_EVT_DoScheduledReset,     // enum UDSEcuResetType *
    UDS_EVT_RequestFileTransfer,  // UDSRequestFileTransferArgs_t *

    // Client Event
    UDS_EVT_Poll,             // NULL
    UDS_EVT_SendComplete,     //
    UDS_EVT_ResponseReceived, //
    UDS_EVT_Idle,             // NULL

} UDSEvent_t;

typedef enum {
    UDS_FAIL = -1, // 通用错误
    UDS_OK = 0,    // 成功

    // Negative Response Codes (NRCs) as defined in ISO14229-1:2020
    UDS_PositiveResponse = 0,
    // 0x01 to 0x0F are reserved by ISO14229-1:2020
    UDS_NRC_GeneralReject = 0x10,
    UDS_NRC_ServiceNotSupported = 0x11,
    UDS_NRC_SubFunctionNotSupported = 0x12,
    UDS_NRC_IncorrectMessageLengthOrInvalidFormat = 0x13,
    UDS_NRC_ResponseTooLong = 0x14,
    // 0x15 to 0x20 are reserved by ISO14229-1:2020
    UDS_NRC_BusyRepeatRequest = 0x21,
    UDS_NRC_ConditionsNotCorrect = 0x22,
    UDS_NRC_RequestSequenceError = 0x24,
    UDS_NRC_NoResponseFromSubnetComponent = 0x25,
    UDS_NRC_FailurePreventsExecutionOfRequestedAction = 0x26,
    // 0x27 to 0x30 are reserved by ISO14229-1:2020
    UDS_NRC_RequestOutOfRange = 0x31,
    // 0x32 is reserved by ISO14229-1:2020
    UDS_NRC_SecurityAccessDenied = 0x33,
    UDS_NRC_AuthenticationRequired = 0x34,
    UDS_NRC_InvalidKey = 0x35,
    UDS_NRC_ExceedNumberOfAttempts = 0x36,
    UDS_NRC_RequiredTimeDelayNotExpired = 0x37,
    UDS_NRC_SecureDataTransmissionRequired = 0x38,
    UDS_NRC_SecureDataTransmissionNotAllowed = 0x39,
    UDS_NRC_SecureDataVerificationFailed = 0x3A,
    // 0x3B to 0x4F are reserved by ISO14229-1:2020
    UDS_NRC_CertficateVerificationFailedInvalidTimePeriod = 0x50,
    UDS_NRC_CertficateVerificationFailedInvalidSignature = 0x51,
    UDS_NRC_CertficateVerificationFailedInvalidChainOfTrust = 0x52,
    UDS_NRC_CertficateVerificationFailedInvalidType = 0x53,
    UDS_NRC_CertficateVerificationFailedInvalidFormat = 0x54,
    UDS_NRC_CertficateVerificationFailedInvalidContent = 0x55,
    UDS_NRC_CertficateVerificationFailedInvalidScope = 0x56,
    UDS_NRC_CertficateVerificationFailedInvalidCertificate = 0x57,
    UDS_NRC_OwnershipVerificationFailed = 0x58,
    UDS_NRC_ChallengeCalculationFailed = 0x59,
    UDS_NRC_SettingAccessRightsFailed = 0x5A,
    UDS_NRC_SessionKeyCreationOrDerivationFailed = 0x5B,
    UDS_NRC_ConfigurationDataUsageFailed = 0x5C,
    UDS_NRC_DeAuthenticationFailed = 0x5D,
    // 0x5E to 0x6F are reserved by ISO14229-1:2020
    UDS_NRC_UploadDownloadNotAccepted = 0x70,
    UDS_NRC_TransferDataSuspended = 0x71,
    UDS_NRC_GeneralProgrammingFailure = 0x72,
    UDS_NRC_WrongBlockSequenceCounter = 0x73,
    // 0x74 to 0x77 are reserved by ISO14229-1:2020
    UDS_NRC_RequestCorrectlyReceived_ResponsePending = 0x78,
    // 0x79 to 0x7D are reserved by ISO14229-1:2020
    UDS_NRC_SubFunctionNotSupportedInActiveSession = 0x7E,
    UDS_NRC_ServiceNotSupportedInActiveSession = 0x7F,
    // 0x80 is reserved by ISO14229-1:2020
    UDS_NRC_RpmTooHigh = 0x81,
    UDS_NRC_RpmTooLow = 0x82,
    UDS_NRC_EngineIsRunning = 0x83,
    UDS_NRC_EngineIsNotRunning = 0x84,
    UDS_NRC_EngineRunTimeTooLow = 0x85,
    UDS_NRC_TemperatureTooHigh = 0x86,
    UDS_NRC_TemperatureTooLow = 0x87,
    UDS_NRC_VehicleSpeedTooHigh = 0x88,
    UDS_NRC_VehicleSpeedTooLow = 0x89,
    UDS_NRC_ThrottlePedalTooHigh = 0x8A,
    UDS_NRC_ThrottlePedalTooLow = 0x8B,
    UDS_NRC_TransmissionRangeNotInNeutral = 0x8C,
    UDS_NRC_TransmissionRangeNotInGear = 0x8D,
    // 0x8E is reserved by ISO14229-1:2020
    UDS_NRC_BrakeSwitchNotClosed = 0x8F,
    UDS_NRC_ShifterLeverNotInPark = 0x90,
    UDS_NRC_TorqueConverterClutchLocked = 0x91,
    UDS_NRC_VoltageTooHigh = 0x92,
    UDS_NRC_VoltageTooLow = 0x93,
    UDS_NRC_ResourceTemporarilyNotAvailable = 0x94,

    /* 0x95 to 0xEF are reservedForSpecificConditionsNotCorrect */
    /* 0xF0 to 0xFE are vehicleManufacturerSpecificConditionsNotCorrect */
    /* 0xFF is ISOSAEReserved */

    // The following values are not defined in ISO14229-1:2020
    UDS_ERR_TIMEOUT = 0x100,      // A request has timed out
    UDS_ERR_DID_MISMATCH,         // The response DID does not match the request DID
    UDS_ERR_SID_MISMATCH,         // The response SID does not match the request SID
    UDS_ERR_SUBFUNCTION_MISMATCH, // The response SubFunction does not match the request SubFunction
    UDS_ERR_TPORT,                // Transport error. Check the transport layer for more information
    UDS_ERR_RESP_TOO_SHORT,       // The response is too short
    UDS_ERR_BUFSIZ,               // The buffer is not large enough
    UDS_ERR_INVALID_ARG,          // The function has been called with invalid arguments
    UDS_ERR_BUSY,                 // The client is busy and cannot process the request
    UDS_ERR_MISUSE,               // The library is used incorrectly
} UDSErr_t;

enum UDSDiagnosticSessionType {
    kDefaultSession = 0x01,
    kProgrammingSession = 0x02,
    kExtendedDiagnostic = 0x03,
    kSafetySystemDiagnostic = 0x04,
};

/**
 * @brief LEV_RT_
 * @addtogroup ecuReset_0x11
 */
enum UDSECUResetType {
    kHardReset = 1,
    kKeyOffOnReset = 2,
    kSoftReset = 3,
    kEnableRapidPowerShutDown = 4,
    kDisableRapidPowerShutDown = 5,
};

typedef uint8_t UDSECUReset_t;

/**
 * @addtogroup securityAccess_0x27
 */
enum UDSSecurityAccessType {
    kRequestSeed = 0x01,
    kSendKey = 0x02,
};

/**
 * @addtogroup communicationControl_0x28
 */
enum UDSCommunicationControlType {
    kEnableRxAndTx = 0,
    kEnableRxAndDisableTx = 1,
    kDisableRxAndEnableTx = 2,
    kDisableRxAndTx = 3,
};

/**
 * @addtogroup communicationControl_0x28
 */
enum UDSCommunicationType {
    kNormalCommunicationMessages = 0x1,
    kNetworkManagementCommunicationMessages = 0x2,
    kNetworkManagementCommunicationMessagesAndNormalCommunicationMessages = 0x3,
};

/**
 * @addtogroup routineControl_0x31
 */
enum RoutineControlType {
    kStartRoutine = 1,
    kStopRoutine = 2,
    kRequestRoutineResults = 3,
};

/**
 * @addtogroup requestFileTransfer_0x38
 */
enum FileOperationMode {
    kAddFile = 1,
    kDeleteFile = 2,
    kReplaceFile = 3,
    kReadFile = 4,
    kReadDir = 5,
};

/**
 * @addtogroup controlDTCSetting_0x85
 */
enum DTCSettingType {
    kDTCSettingON = 0x01,
    kDTCSettingOFF = 0x02,
};

// ISO-14229-1:2013 Table 2
#define UDS_MAX_DIAGNOSTIC_SERVICES 0x7F

#define UDS_RESPONSE_SID_OF(request_sid) (request_sid + 0x40)
#define UDS_REQUEST_SID_OF(response_sid) (response_sid - 0x40)

#define UDS_NEG_RESP_LEN 3U
#define UDS_0X10_REQ_LEN 2U
#define UDS_0X10_RESP_LEN 6U
#define UDS_0X11_REQ_MIN_LEN 2U
#define UDS_0X11_RESP_BASE_LEN 2U
#define UDS_0X23_REQ_MIN_LEN 4U
#define UDS_0X23_RESP_BASE_LEN 1U
#define UDS_0X22_RESP_BASE_LEN 1U
#define UDS_0X27_REQ_BASE_LEN 2U
#define UDS_0X27_RESP_BASE_LEN 2U
#define UDS_0X28_REQ_BASE_LEN 3U
#define UDS_0X28_RESP_LEN 2U
#define UDS_0X2E_REQ_BASE_LEN 3U
#define UDS_0X2E_REQ_MIN_LEN 4U
#define UDS_0X2E_RESP_LEN 3U
#define UDS_0X31_REQ_MIN_LEN 4U
#define UDS_0X31_RESP_MIN_LEN 4U
#define UDS_0X34_REQ_BASE_LEN 3U
#define UDS_0X34_RESP_BASE_LEN 2U
#define UDS_0X35_REQ_BASE_LEN 3U
#define UDS_0X35_RESP_BASE_LEN 2U
#define UDS_0X36_REQ_BASE_LEN 2U
#define UDS_0X36_RESP_BASE_LEN 2U
#define UDS_0X37_REQ_BASE_LEN 1U
#define UDS_0X37_RESP_BASE_LEN 1U
#define UDS_0X38_REQ_BASE_LEN 4U
#define UDS_0X38_RESP_BASE_LEN 3U
#define UDS_0X3E_REQ_MIN_LEN 2U
#define UDS_0X3E_REQ_MAX_LEN 2U
#define UDS_0X3E_RESP_LEN 2U
#define UDS_0X85_REQ_BASE_LEN 2U
#define UDS_0X85_RESP_LEN 2U

enum UDSDiagnosticServiceId {
    kSID_DIAGNOSTIC_SESSION_CONTROL = 0x10,
    kSID_ECU_RESET = 0x11,
    kSID_CLEAR_DIAGNOSTIC_INFORMATION = 0x14,
    kSID_READ_DTC_INFORMATION = 0x19,
    kSID_READ_DATA_BY_IDENTIFIER = 0x22,
    kSID_READ_MEMORY_BY_ADDRESS = 0x23,
    kSID_READ_SCALING_DATA_BY_IDENTIFIER = 0x24,
    kSID_SECURITY_ACCESS = 0x27,
    kSID_COMMUNICATION_CONTROL = 0x28,
    kSID_READ_PERIODIC_DATA_BY_IDENTIFIER = 0x2A,
    kSID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER = 0x2C,
    kSID_WRITE_DATA_BY_IDENTIFIER = 0x2E,
    kSID_INPUT_CONTROL_BY_IDENTIFIER = 0x2F,
    kSID_ROUTINE_CONTROL = 0x31,
    kSID_REQUEST_DOWNLOAD = 0x34,
    kSID_REQUEST_UPLOAD = 0x35,
    kSID_TRANSFER_DATA = 0x36,
    kSID_REQUEST_TRANSFER_EXIT = 0x37,
    kSID_REQUEST_FILE_TRANSFER = 0x38,
    kSID_WRITE_MEMORY_BY_ADDRESS = 0x3D,
    kSID_TESTER_PRESENT = 0x3E,
    kSID_ACCESS_TIMING_PARAMETER = 0x83,
    kSID_SECURED_DATA_TRANSMISSION = 0x84,
    kSID_CONTROL_DTC_SETTING = 0x85,
    kSID_RESPONSE_ON_EVENT = 0x86,
};
