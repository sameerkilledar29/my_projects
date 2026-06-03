#include<stdio.h>
#include"types.h"
#include"encode.h"
#include<string.h>
#include"decode.h"






 OperationType check_operation_type(char *argv[])
{
  if(!(strcmp("-e",argv[1])))
  {
    return e_encode;
  }
  else if(!(strcmp("-d",argv[1])))
  {
    return e_decode;
  }
  else
  {
    return e_unsupported;
  }
}
