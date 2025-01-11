#include "test/env.h"

static int call_count = 0;

uint8_t fn(UDSServer_t *srv, UDSEvent_t ev, const void *arg) {
    TEST_INT_EQUAL(UDS_EVT_SessionTimeout, ev);
    call_count++;
    return UDS_PositiveResponse;
}

int main() {
    UDSServer_t srv;

    struct {
        const char *tag;
        uint8_t (*fn)(UDSServer_t *srv, UDSEvent_t ev, const void *arg);
        uint8_t sessType;
        int expectedCallCount;
    } p[] = {
        {.tag = "no timeout", .fn = fn, .sessType = kDefaultSession, .expectedCallCount = 0},
        {.tag = "timeout", .fn = fn, .sessType = kProgrammingSession, .expectedCallCount = 1},
        {.tag = "no handler", .fn = NULL, .sessType = kProgrammingSession, .expectedCallCount = 0},
    };

    for (unsigned i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
        ENV_SERVER_INIT(srv);
        srv.fn = p[i].fn;
        srv.sessionType = p[i].sessType;
        ENV_RunMillis(5000);
        TEST_INT_GE(call_count, p[i].expectedCallCount);
        ISOTPMockReset();
    }
}