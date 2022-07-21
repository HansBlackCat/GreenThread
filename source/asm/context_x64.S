#ifdef __APPLE__
    #define SET_CONTEXT _set_context
    #define SWITCH_CONTEXT _switch_context
#else
    #define SET_CONTEXT set_context
    #define SWITCH_CONTEXT _switch_context
#endif

.global SET_CONTEXT
.global SWITCH_CONTEXT

.text
.align 4

SET_CONTEXT:
    
.text
.align 4

SWITCH_CONTEXT: