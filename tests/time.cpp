#include "tlvm-tests.h"
#include "tlvm_internal.h"

TEST(SetClockspeed, Time, 0.0f,
     // initialisation
     {
      tlvmInitContext(&m_data.context);
     },
     // cleanup
     {
      tlvmTerminateContext(&m_data.context);
     },
     // test
     {
          ASSERT(tlvmSetClockspeed(m_data.context, TLVM_MHZ(2,0)) == TLVM_SUCCESS);
          ASSERT(m_data.context->m_Clockspeed == TLVM_MHZ(2, 0));
     },
     // data
     {
      tlvmContext* context;
     }
    );

TEST(Time, Time, 0.0f,
     // initialisation
     {
      m_data.memory[0] = TLVM_NOP;
      m_data.memory[1] = TLVM_HLT;

      tlvmInitContext(&m_data.context);
      tlvmInit8080(m_data.context);
      tlvmSetClockspeed(m_data.context, TLVM_MHZ(2,0));
      tlvmSetMemory(m_data.context, m_data.memory, 0, 256, TLVM_FLAG_READ);
     },
     // cleanup
     {
      tlvmTerminateContext(&m_data.context);
     },
     // test
     {
      tlvmRun(m_data.context);
     },
     // data
     {
      tlvmContext* context;
      tlvmByte     memory[256];
     }
    );