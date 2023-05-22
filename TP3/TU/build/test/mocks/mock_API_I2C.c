/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_API_I2C.h"

static const char* CMockString_I2C_HW_init = "I2C_HW_init";

typedef struct _CMOCK_I2C_HW_init_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  _Bool ReturnVal;
  int CallOrder;

} CMOCK_I2C_HW_init_CALL_INSTANCE;

static struct mock_API_I2CInstance
{
  char I2C_HW_init_IgnoreBool;
  _Bool I2C_HW_init_FinalReturn;
  char I2C_HW_init_CallbackBool;
  CMOCK_I2C_HW_init_CALLBACK I2C_HW_init_CallbackFunctionPointer;
  int I2C_HW_init_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE I2C_HW_init_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_API_I2C_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.I2C_HW_init_CallInstance;
  if (Mock.I2C_HW_init_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_I2C_HW_init);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.I2C_HW_init_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_API_I2C_Init(void)
{
  mock_API_I2C_Destroy();
}

void mock_API_I2C_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

_Bool I2C_HW_init(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_I2C_HW_init_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_I2C_HW_init);
  cmock_call_instance = (CMOCK_I2C_HW_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.I2C_HW_init_CallInstance);
  Mock.I2C_HW_init_CallInstance = CMock_Guts_MemNext(Mock.I2C_HW_init_CallInstance);
  if (Mock.I2C_HW_init_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.I2C_HW_init_FinalReturn;
    memcpy((void*)(&Mock.I2C_HW_init_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(_Bool[sizeof(cmock_call_instance->ReturnVal) == sizeof(_Bool) ? 1 : -1])); /* add _Bool to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.I2C_HW_init_CallbackBool &&
      Mock.I2C_HW_init_CallbackFunctionPointer != NULL)
  {
    _Bool cmock_cb_ret = Mock.I2C_HW_init_CallbackFunctionPointer(Mock.I2C_HW_init_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.I2C_HW_init_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.I2C_HW_init_CallbackFunctionPointer(Mock.I2C_HW_init_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void I2C_HW_init_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_I2C_HW_init_CALL_INSTANCE));
  CMOCK_I2C_HW_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_HW_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.I2C_HW_init_CallInstance = CMock_Guts_MemChain(Mock.I2C_HW_init_CallInstance, cmock_guts_index);
  Mock.I2C_HW_init_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.I2C_HW_init_IgnoreBool = (char)1;
}

void I2C_HW_init_CMockStopIgnore(void)
{
  if(Mock.I2C_HW_init_IgnoreBool)
    Mock.I2C_HW_init_CallInstance = CMock_Guts_MemNext(Mock.I2C_HW_init_CallInstance);
  Mock.I2C_HW_init_IgnoreBool = (char)0;
}

void I2C_HW_init_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_I2C_HW_init_CALL_INSTANCE));
  CMOCK_I2C_HW_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2C_HW_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.I2C_HW_init_CallInstance = CMock_Guts_MemChain(Mock.I2C_HW_init_CallInstance, cmock_guts_index);
  Mock.I2C_HW_init_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(_Bool[sizeof(cmock_to_return) == sizeof(_Bool) ? 1 : -1])); /* add _Bool to :treat_as_array if this causes an error */
}

void I2C_HW_init_AddCallback(CMOCK_I2C_HW_init_CALLBACK Callback)
{
  Mock.I2C_HW_init_IgnoreBool = (char)0;
  Mock.I2C_HW_init_CallbackBool = (char)1;
  Mock.I2C_HW_init_CallbackFunctionPointer = Callback;
}

void I2C_HW_init_Stub(CMOCK_I2C_HW_init_CALLBACK Callback)
{
  Mock.I2C_HW_init_IgnoreBool = (char)0;
  Mock.I2C_HW_init_CallbackBool = (char)0;
  Mock.I2C_HW_init_CallbackFunctionPointer = Callback;
}
