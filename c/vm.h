#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "compiler.h"
#include "object.h"
#include "table.h"
#include "value.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
    ObjFunction* function;
    uint8_t* ip;
    Value* slots;
} CallFrame;

typedef struct {
    CallFrame frames[FRAMES_MAX];
    int frameCount;

    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
    Table globals;
    Table strings;
    struct Obj* objects;
} VM;

typedef enum {
    INTERPERET_OK,
    INTERPERET_COMPILE_ERROR,
    INTERPERET_RUNTIME_ERROR
} InterperetResult;

extern VM vm;

void initVM();
void freeVM();
InterperetResult interperet(const char* source);
void push(Value value);
Value pop();

#endif