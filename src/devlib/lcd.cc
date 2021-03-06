#include "lcd.h"
#include <lcd.h>

DECLARE(lcdHome);
DECLARE(lcdClear);
DECLARE(lcdDisplay);
DECLARE(lcdCursor);
DECLARE(lcdCursorBlink);
DECLARE(lcdSendCommand);
DECLARE(lcdPosition);
DECLARE(lcdCharDef);
DECLARE(lcdPutchar);
DECLARE(lcdPuts);
DECLARE(lcdPrintf);
DECLARE(lcdInit);

IMPLEMENT(lcdHome) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  ::lcdHome(fd);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdClear) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  ::lcdClear(fd);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdDisplay) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, state);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int state = GET_ARGUMENT_AS_INT32(1);
  
  ::lcdDisplay(fd, state);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdCursor) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, state);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int state = GET_ARGUMENT_AS_INT32(1);
  
  ::lcdCursor(fd, state);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdCursorBlink) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, state);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int state = GET_ARGUMENT_AS_INT32(1);
  
  ::lcdCursorBlink(fd, state);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdSendCommand) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, command);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int command = GET_ARGUMENT_AS_UINT32(1);
  
  ::lcdSendCommand(fd, command);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdPosition) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, x);
  SET_ARGUMENT_NAME(2, y);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int x = GET_ARGUMENT_AS_INT32(1);
  int y = GET_ARGUMENT_AS_INT32(2);
  
  ::lcdPosition(fd, x, y);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdCharDef) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, index);
  SET_ARGUMENT_NAME(2, data);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_ARRAY(2);
  CHECK_ARGUMENT_ARRAY_LENGTH(2, 8);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int index = GET_ARGUMENT_AS_INT32(1);
  v8::Local<v8::Array> data = v8::Local<v8::Array>::Cast(args[2]);
  
  unsigned char ar[8];
  for (int i = 0; i < 8; i++) {
    ar[i] = data->Get(i)->Uint32Value() & 0xFF;
  }
  
  ::lcdCharDef(fd, index, ar);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdPutchar) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, data);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  unsigned int data = GET_ARGUMENT_AS_UINT32(1);
  
  ::lcdPutchar(fd, data);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdPuts) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, string);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_STRING(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::String::Utf8Value data(GET_ARGUMENT_AS_STRING(1));
  #else
    v8::String::AsciiValue data(GET_ARGUMENT_AS_STRING(1));
  #endif
  
  ::lcdPuts(fd, *data);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcdPrintf) {
  return lcdPuts(args);
}

IMPLEMENT(lcdInit) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, rows);
  SET_ARGUMENT_NAME(1, cols);
  SET_ARGUMENT_NAME(2, bits);
  SET_ARGUMENT_NAME(3, rs);
  SET_ARGUMENT_NAME(4, strb);
  SET_ARGUMENT_NAME(5, d0);
  SET_ARGUMENT_NAME(6, d1);
  SET_ARGUMENT_NAME(7, d2);
  SET_ARGUMENT_NAME(8, d3);
  SET_ARGUMENT_NAME(9, d4);
  SET_ARGUMENT_NAME(10, d5);
  SET_ARGUMENT_NAME(11, d6);
  SET_ARGUMENT_NAME(12, d7);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(13);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  CHECK_ARGUMENT_TYPE_INT32(5);
  CHECK_ARGUMENT_TYPE_INT32(6);
  CHECK_ARGUMENT_TYPE_INT32(7);
  CHECK_ARGUMENT_TYPE_INT32(8);
  CHECK_ARGUMENT_TYPE_INT32(9);
  CHECK_ARGUMENT_TYPE_INT32(10);
  CHECK_ARGUMENT_TYPE_INT32(11);
  CHECK_ARGUMENT_TYPE_INT32(12);
  
  int rows = GET_ARGUMENT_AS_INT32(0);
  int cols = GET_ARGUMENT_AS_INT32(1);
  int bits = GET_ARGUMENT_AS_INT32(2);
  int rs = GET_ARGUMENT_AS_INT32(3);
  int strb = GET_ARGUMENT_AS_INT32(4);
  int d0 = GET_ARGUMENT_AS_INT32(5);
  int d1 = GET_ARGUMENT_AS_INT32(6);
  int d2 = GET_ARGUMENT_AS_INT32(7);
  int d3 = GET_ARGUMENT_AS_INT32(8);
  int d4 = GET_ARGUMENT_AS_INT32(9);
  int d5 = GET_ARGUMENT_AS_INT32(10);
  int d6 = GET_ARGUMENT_AS_INT32(11);
  int d7 = GET_ARGUMENT_AS_INT32(12);
  
  int res = ::lcdInit(rows, cols, bits, rs, strb, d0, d1, d2, d3, d4, d5, d6, d7);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(lcd) {
  EXPORT_FUNCTION(lcdHome);
  EXPORT_FUNCTION(lcdClear);
  EXPORT_FUNCTION(lcdDisplay);
  EXPORT_FUNCTION(lcdCursor);
  EXPORT_FUNCTION(lcdCursorBlink);
  EXPORT_FUNCTION(lcdSendCommand);
  EXPORT_FUNCTION(lcdPosition);
  EXPORT_FUNCTION(lcdCharDef);
  EXPORT_FUNCTION(lcdPutchar);
  EXPORT_FUNCTION(lcdPuts);
  EXPORT_FUNCTION(lcdPrintf);
  EXPORT_FUNCTION(lcdInit);
  
  EXPORT_CONSTANT_INT(MAX_LCDS);
}